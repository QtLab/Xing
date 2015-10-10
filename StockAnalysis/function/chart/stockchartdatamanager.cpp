#include "stockchartdatamanager.h"
#include "function/chart/util/ModifiedPrice.h"
StockChartDataManager::StockChartDataManager(QueryMngr* queryMngr, QObject *parent) : 
QObject(parent), mQueryMngr(queryMngr)
{

}

StockChartDataManager::~StockChartDataManager()
{

}

void StockChartDataManager::start()
{
	moveToThread(&mWorkThread);
	mWorkThread.start();
}

void StockChartDataManager::requestStockData(const QString shcode, TIME_UNIT timeUnit, const QDate& startDate, const QDate& endDate, bool modified_price)
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

void StockChartDataManager::onReceivedStockData()
{
	QObject *sender = QObject::sender();
	if (sender != nullptr)
	{
		T8413Query *query = qobject_cast<T8413Query*>(sender);
		if (query != nullptr)
		{
			StockPriceHistory *history = new StockPriceHistory(query->shcode());
			bool modified_price_requested = mQueryMap.value(query);
			ModifiedPrice modified_price;
			QList<TrItem*> itemList = query->getResult();
			QList<TrItem *>::iterator it = itemList.end();
			while (it != itemList.begin())	// reverse iterating to apply modified price.
			{
				--it;
				T8413Item* t8413Item = qobject_cast<T8413Item*>(*it);
				StockPrice *price = new StockPrice();
				if (modified_price_requested)
				{
					price->date = t8413Item->date();
					price->open = modified_price(t8413Item->open(), t8413Item->rate());
					price->high = modified_price(t8413Item->high(), t8413Item->rate());
					price->low = modified_price(t8413Item->low(), t8413Item->rate());
					price->close = modified_price(t8413Item->close(), t8413Item->rate());
					price->volume = t8413Item->jdiff_vol();
				} else
				{
					price->date = t8413Item->date();
					price->open = t8413Item->open();
					price->high = t8413Item->high();
					price->low = t8413Item->low();
					price->close = t8413Item->close();
					price->volume = t8413Item->jdiff_vol();
				}
				history->prependPrice(price);
			}
			query->deleteLater();
			emit responseStockData(history);
		}
	}
}