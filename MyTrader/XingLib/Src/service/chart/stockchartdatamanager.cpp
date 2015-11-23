#include <QMetaType>
#include "core/util/xingthread.h"
#include "service/chart/stockchartdatamanager.h"
#include "service/chart/util/ModifiedPrice.h"
#include "service/info/stockinfomngr.h"
StockChartDataManager::StockChartDataManager(QueryMngr* queryMngr, QObject *parent) : 
QObject(parent), mQueryMngr(queryMngr), mWorkThread(new XingThread)
{
	
}

StockChartDataManager::~StockChartDataManager()
{
	mWorkThread->deleteLater();
}

void StockChartDataManager::start()
{
	moveToThread(mWorkThread);
	mWorkThread->start();
}

void StockChartDataManager::requestStockData(const QString &shcode, TIME_UNIT timeUnit, const QDate& startDate, const QDate& endDate, bool modified_price)
{
	QString gubun;
	switch (timeUnit)
	{
	case DAILY:
		gubun = "2";
		break;
	case WEEKLY:
		gubun = "3";
		break;
	case MONTHLY:
		gubun = "4";
		break;
	default:
		gubun = "2";
		break;
	}
	T8413Query *query = T8413Query::createQuery(shcode, gubun, 2000, startDate, endDate, true);
	connect(query, SIGNAL(workDone()), this, SLOT(onReceivedStockData()));
	mQueryMngr->requestQuery(query);
	mQueryMap.insert(query, modified_price);
}

void StockChartDataManager::requestStockData(const QString& shcode, TIME_UNIT timeUnit, bool modified_price)
{
	QString gubun;
	switch (timeUnit)
	{
	case DAILY:
		gubun = "2";
		break;
	case WEEKLY:
		gubun = "3";
		break;
	case MONTHLY:
		gubun = "4";
		break;
	default:
		gubun = "2";
		break;
	}
	auto listingDate = StockInfoMngr::getInstance()->getStockInfo(shcode)->listdate();
	auto startDate = QDate(2004, 1, 2);
	listingDate = listingDate > startDate ? listingDate : startDate;
	auto query = T8413Query::createQuery(shcode, gubun, 2000, listingDate,QDate::currentDate(), true);
	connect(query, SIGNAL(workDone()), this, SLOT(onReceivedStockData()));
	mQueryMngr->requestQuery(query);
	mQueryMap.insert(query, modified_price);
}

void StockChartDataManager::onReceivedStockData()
{
	QObject *sender = QObject::sender();
	if (sender != nullptr)
	{
		T8413Query *query = qobject_cast<T8413Query*>(sender);
		if (query != nullptr)
		{
			auto modified_price_requested = mQueryMap.value(query);
			ModifiedPrice modified_price;
			auto itemList = query->getResult();
			auto it = itemList.end();
			StockPriceData *data = new StockPriceData(query->shcode(), itemList.size());
			while (it != itemList.begin())	// reverse iterating to apply modified price.
			{
				--it;
				auto t8413Item = qobject_cast<T8413Item*>(*it);
				QDateTime dateTime;
				dateTime.setDate(t8413Item->date());
				dateTime.setTime(QTime(15, 0, 0));
				if (modified_price_requested)
				{
					data->addData
						(dateTime
						, modified_price(t8413Item->open(), t8413Item->rate())
						, modified_price(t8413Item->high(), t8413Item->rate())
						, modified_price(t8413Item->low(), t8413Item->rate())
						, modified_price(t8413Item->close(), t8413Item->rate())
						, t8413Item->jdiff_vol());
				} else
				{
					data->addData(
						dateTime	
						, t8413Item->open()
						, t8413Item->high()
						, t8413Item->low()
						, t8413Item->close()
						, t8413Item->jdiff_vol());
				}
			}
			query->deleteLater();
			emit responseStockData(data);
		}
	}
}