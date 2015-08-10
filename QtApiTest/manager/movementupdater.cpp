#include <QtSql/QSqlQuery>
#include <QtSql/QSqlRecord>
#include <QtSql/QSqlError>
#include <QDateTime>
#include <QDate>
#include "util/log.h"
#include "movementupdater.h"
#include "tr/t1702/t1702Query.h"
#include "manager/stockinfomngr.h"
MovementUpdater::MovementUpdater(QueryMngr *queryMngr, QObject *parent) : QObject(parent), mQueryMngr(queryMngr),sStockStartDate(2004,1,2)

{

}

MovementUpdater::~MovementUpdater()
{

}

void MovementUpdater::update()
{
    if(!mThread.isRunning()){
        moveToThread(&mThread);
        mThread.start();
    }
    QMetaObject::invokeMethod(this, "updateStart", Qt::QueuedConnection);
}

void MovementUpdater::t1702QueryDone()
{
    QObject* sender = QObject::sender();
    if(sender != NULL) {
        T1702Query *query = qobject_cast<T1702Query *>(sender);
        if(query != NULL) {
            QList<T1702Item *> list = query->getResult();
            foreach(T1702Item *item, list) {
                saveToDB(item);
                item->deleteLater();
            }
            mUpdatingQueryMap.remove(query->shcode());
            query->deleteLater();
            if(mUpdatingQueryMap.size()==0)
                emit updateDone();
        }
    }
}

void MovementUpdater::updateStart()
{
    qCDebug(movementUpdater)<<"Update Start time"<<QDateTime::currentDateTime().toString(Qt::ISODate);
    QList<QString> shcodeList = StockInfoMngr::getInstance()->getShcodeList();
    int i = 2;
    foreach(QString shcode, shcodeList){
        requestMovementData(shcode);
        if(i==0)
            break;
        else
            i--;
    }
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
    } else {
        qCDebug(movementUpdater)<<tr("Movement_%1 table created").arg(shcode);
    }
}

void MovementUpdater::errorQuery(QSqlQuery *query)
{
    qCWarning(movementUpdater)<<"QueryError : "<<query->lastError()<<endl<<query->executedQuery();
}

void MovementUpdater::requestMovementData(const QString &shcode)
{
    createStockMovementTable(shcode);
    QDate today = QDate::currentDate();
    QDate fromDay = getLastUpdatedDateFromDatabase(shcode);
    T1702Query *query = T1702Query::createQuery(shcode, fromDay, today, T1702Query::AMOUNT, T1702Query::PURE_BUY, T1702Query::DAILY);
    connect(query, SIGNAL(workDone()), this, SLOT(t1702QueryDone()));
    mUpdatingQueryMap.insert(shcode, query);
    mQueryMngr->requestQuery(query);
}

QDate MovementUpdater::getLastUpdatedDateFromDatabase(const QString &shcode)
{
    QSqlQuery lastDateQry;
    lastDateQry.prepare(tr("SELECT max(`Date`) FROM Movement_%1").arg(shcode));
    if(lastDateQry.exec()) {
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


