#include <QtSql/QSqlQuery>
#include <QtSql/QSqlRecord>
#include <QtSql/QSqlError>
#include <QDateTime>
#include <QDate>
#include "util/log.h"
#include "movementupdater.h"
#include "tr/t1702/t1702Query.h"
#include "tr/t1516/t1516query.h"
MovementUpdater::MovementUpdater(QueryMngr *queryMngr, QObject *parent) : QObject(parent), mQueryMngr(queryMngr),sStockStartDate(2004,1,2), mMarketEndTime(15,30), totalNumOfShcode(0)

{

}

MovementUpdater::~MovementUpdater()
{

}

void MovementUpdater::updateByShcode(const QString &shcode)
{
	mUpdatingShcodeList.append(shcode);
	QMetaObject::invokeMethod(this, "updateStart", Qt::QueuedConnection);
}

void MovementUpdater::updateByShcodeList(QList<QString> shcodeList)
{
    mUpdatingShcodeList.append(shcodeList);
    QMetaObject::invokeMethod(this, "updateStart", Qt::QueuedConnection);
}

void MovementUpdater::updateByUpcode(const QString &upcode)
{
    T1516Query *query = T1516Query::createQuery(upcode, MARKET_TYPE_NONE);
    connect(query, SIGNAL(workDone()), this, SLOT(t1516QueryDone()));
	mQueryMngr->requestQuery(query);
	mRequestedUpcodeList.append(query);
}

void MovementUpdater::t1702QueryDone()
{
    QObject* sender = QObject::sender();
    if(sender != NULL) {
        T1702Query *query = qobject_cast<T1702Query *>(sender);
        if(query != NULL) {
            if(mUpdatingShcodeList.size()!=0) {
                qCDebug(movementUpdater)<<"Movement update "<<totalNumOfShcode-mUpdatingShcodeList.size()<<"/"<<totalNumOfShcode;
                nextRequest();
            }
            QList<TrItem *> list = query->getResult();
            foreach(TrItem *trItem, list) {
				T1702Item *item = qobject_cast<T1702Item *>(trItem);
                saveToDB(item);
            }
            query->deleteLater();
            if(mUpdatingShcodeList.size()==0)
                emit updateDone();
        }
    }
}

void MovementUpdater::t1516QueryDone()
{
    QObject* sender = QObject::sender();
    if(sender != NULL) {
        T1516Query* query = qobject_cast<T1516Query*>(sender);
        if(query != NULL) {
            QList<TrItem*> itemList = query->getResult();
			foreach(TrItem* trItem, itemList) {
				T1516Item *item = qobject_cast<T1516Item *>(trItem);
				mUpdatingShcodeList.append(item->shcode());
			}
            mRequestedUpcodeList.removeOne(query);
			query->deleteLater();
            if(mRequestedUpcodeList.size()==0) {
                QMetaObject::invokeMethod(this, "updateStart", Qt::QueuedConnection);
            }
        }
    }
}

void MovementUpdater::updateStart()
{
    qCDebug(movementUpdater)<<"Update Start time"<<QDateTime::currentDateTime().toString(Qt::ISODate);
    totalNumOfShcode = mUpdatingShcodeList.size();
    nextRequest();
}
void MovementUpdater::saveToDB(T1702Item *item)
{
    QSqlQuery qry;
    QString qryString = QString("SELECT COUNT(*) FROM Movement_%1 WHERE `date`='%2'").arg(item->shcode()).arg(item->date().toString(tr("yyyyMMdd")));
    qry.prepare(qryString);
    if(qry.exec()) {
        if(qry.next()) {
            if(qry.value(0).toInt()==0) {	//Row is not existed, So insert
                QString insertString = item->getSqlInsertStr();
                qry.prepare(insertString);
            } else {	//Row is existed, So update
                QString updateString = item->getSqlUpdateStr();
                qry.prepare(updateString);
            }
            if(!qry.exec()) {
                errorQuery(&qry);
            }
        }
    } else {
        errorQuery(&qry);
    }

}

void MovementUpdater::createStockMovementTable(const QString &shcode)
{
    QSqlQuery query;
    query.prepare(tr("CREATE TABLE IF NOT EXISTS Movement_%1 ( `date` DATE UNIQUE PRIMARY KEY, `close` INTEGER(8), `sign` CHAR(1), `change` INTEGER(8), `diff` FLOAT(8), `volume` BIGINT(12),`amt0000` BIGINT(12), `amt0001` BIGINT(12), `amt0002` BIGINT(12), `amt0003` BIGINT(12), `amt0004` BIGINT(12), `amt0005` BIGINT(12), `amt0006` BIGINT(12), `amt0007` BIGINT(12), `amt0008` BIGINT(12), `amt0009` BIGINT(12), `amt0010` BIGINT(12), `amt0011` BIGINT(12), `amt0018` BIGINT(12), `amt0088` BIGINT(12), `amt0099` BIGINT(12))").arg(shcode));
    if(!query.exec()) {
        errorQuery(&query);
    }
}

void MovementUpdater::errorQuery(QSqlQuery *query)
{
    qCWarning(movementUpdater)<<"QueryError : "<<query->lastError()<<endl<<query->executedQuery();
}

void MovementUpdater::nextRequest()
{
    bool success = false;
    do {
        success = requestMovementData(mUpdatingShcodeList.at(0));
        mUpdatingShcodeList.removeAt(0);
    }
    while(!success);
}

bool MovementUpdater::requestMovementData(const QString &shcode)
{
    createStockMovementTable(shcode);
    QTime currentTime = QTime::currentTime();
    QDate today = QDate::currentDate();
    QDate fromDay = getLastUpdatedDateFromDatabase(shcode);
    StockInfo *stockInfo = StockInfoMngr::getInstance()->getStockInfo(shcode);
    QDate firstUpdatedDay = getFirstUpdatedDateFromDatabase(shcode);
    if(currentTime<mMarketEndTime)				//장중에 업데이트 시에는 전날 기준으로
        today.addDays(-1);
	if (!((firstUpdatedDay == sStockStartDate) || (stockInfo->listdate().daysTo(firstUpdatedDay)<7))) {		//saveToDB가 중간에 끊긴 경우, 상장일과 거래일은 다를 수 있다.
        fromDay = stockInfo->listdate()>sStockStartDate?stockInfo->listdate():sStockStartDate;
    }

    if(fromDay == QDate::currentDate())
        return false;
    T1702Query *query = T1702Query::createQuery(shcode, fromDay, today, T1702Query::AMOUNT, T1702Query::PURE_BUY, T1702Query::DAILY);
    connect(query, SIGNAL(workDone()), this, SLOT(t1702QueryDone()));
    mQueryMngr->requestQuery(query);
    return true;
}

QDate MovementUpdater::getLastUpdatedDateFromDatabase(const QString &shcode)
{
    QSqlQuery lastDateQry;
    lastDateQry.prepare(tr("SELECT max(`Date`) FROM Movement_%1").arg(shcode));    if(lastDateQry.exec()) {
        if(lastDateQry.next()) {
            if(!lastDateQry.isNull(0))
                return lastDateQry.value(0).toDate();
        }
    } else {
        errorQuery(&lastDateQry);
    }
    StockInfo *stockInfo = StockInfoMngr::getInstance()->getStockInfo(shcode);
    QDate listDate =  stockInfo->listdate();
    if(listDate>sStockStartDate)
        return listDate;
    else
        return sStockStartDate;
}

QDate MovementUpdater::getFirstUpdatedDateFromDatabase(const QString &shcode)
{
    QSqlQuery lastDateQry;
    lastDateQry.prepare(tr("SELECT min(`Date`) FROM Movement_%1").arg(shcode));
    if(lastDateQry.exec()) {
        if(lastDateQry.next()) {
            if(!lastDateQry.isNull(0))
                return lastDateQry.value(0).toDate();
        }
    } else {
        errorQuery(&lastDateQry);
    }
    return QDate::currentDate();
}


