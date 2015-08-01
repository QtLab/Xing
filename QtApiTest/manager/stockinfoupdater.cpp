#include <QtSql/QSqlQuery>
#include <QtSql/QSqlRecord>
#include <QtSql/QSqlError>
#include <QDebug>
#include "stockinfoupdater.h"
#include "util/log.h"
StockInfoUpdater::StockInfoUpdater(QueryMngr *queryMngr, QObject *parent) : QObject(parent),mQueryMngr(queryMngr),ZeroDate(0,0,0)
{
}

StockInfoUpdater::~StockInfoUpdater()
{

}

void StockInfoUpdater::update()
{
    moveToThread(&mThread);
    mThread.start();
    qCDebug(stockInfoUpdater)<<"Update Start time"<<QDateTime::currentDateTime().toString(Qt::ISODate);
    createTable();
    T8430Query *query = T8430Query::createQuery();
    connect(query, SIGNAL(workDone()), this, SLOT(t8430QueryDone()));
    mQueryMngr->requestQuery(query);
}

void StockInfoUpdater::t8430QueryDone()
{
    QObject* sender = QObject::sender();
    if(sender != NULL) {
        T8430Query *query = qobject_cast<T8430Query *>(sender);
        if(query != NULL) {
            QList<T8430Item *> list = query->getResult();
            foreach(T8430Item *item, list) {
                StockInfo *stockInfo = new StockInfo();
                stockInfo->setShcode(item->shcode());
                stockInfo->setHname(item->hname());
                stockInfo->setExpcode(item->expcode());
                stockInfo->setETF(item->etfgubun()==tr("1"));
                stockInfo->setKOSPI(item->gubun()==tr("1"));
                mStockInfoUpdatingMap.insert(stockInfo->shcode(), stockInfo);
                item->deleteLater();
            }
            query->deleteLater();
            foreach(StockInfo *info , mStockInfoUpdatingMap.values()) {
                T1102Query *query = T1102Query::createQuery(info->shcode());
                connect(query, SIGNAL(workDone()), this, SLOT(t1102QueryDone()));
                mQueryMngr->requestQuery(query);
            }
        }
    }
}

void StockInfoUpdater::t1102QueryDone()
{
    QObject* sender = QObject::sender();
    if(sender != NULL) {
        T1102Query *query = qobject_cast<T1102Query *>(sender);
        if(query!=NULL) {
            T1102Item* item = query->getResult();
            StockInfo *info = mStockInfoUpdatingMap.value(item->shcode());
            QList<QString> propertyList = item->getPropertyList();
            foreach(QString propertyName, propertyList) {
                info->setProperty(propertyName.toLocal8Bit(), item->property(propertyName.toLocal8Bit()));
            }
            mStockInfoUpdatingMap.remove(info->shcode());
            if(checkCondition(info))
                saveToDB(info);
            qCDebug(stockInfoUpdater)<<info->hname()<<" is updated"<<endl;
            if(mStockInfoUpdatingMap.size()==0) {
                qCDebug(stockInfoUpdater)<<"Update End time"<<QDateTime::currentDateTime().toString(Qt::ISODate);
                emit updateDone();
            }
            item->deleteLater();
            query->deleteLater();
        }
    }
}

void StockInfoUpdater::createTable()
{
    QSqlQuery query;
    query.prepare("CREATE TABLE IF NOT EXISTS StockInfoTable (shcode CHAR(6) UNIQUE PRIMARY KEY, hname VARCHAR(30), expcode VARCHAR(12), isETF BOOLEAN, isKOSPI BOOLEAN, price INTEGER(8), sign CHAR(1), `change` INTEGER(8), diff FLOAT(8), volume BIGINT(12), recprice INTEGER(8), avg INTEGER(8), uplmtprice INTEGER(8), dnlmtprice INTEGER(8), jnilvolume BIGINT(12), volumediff BIGINT(12), open INTEGER(8), opentime TIME, high INTEGER(8),hightime TIME, high52w INTEGER(8), high52wdate DATE,low INTEGER(8), lowtime TIME, low52w INTEGER(8), low52wdate DATE, exhratio FLOAT(8), per FLOAT(8), pbrx FLOAT(8), listing BIGINT(12), jkrate INTEGER(8), memedan CHAR(5), offernocd1 CHAR(3), bidnocd1 CHAR(3), offerno1 CHAR(6), bidno1 CHAR(6), dvol1 INTEGER(8), svol1 INTEGER(8), dcha1 INTEGER(8), scha1 INTEGER(8), ddiff1 FLOAT(8), sdiff1 FLOAT(8), offernocd2 CHAR(3), bidnocd2 CHAR(3), offerno2 CHAR(6), bidno2 CHAR(6), dvol2 INTEGER(8), svol2 INTEGER(8), dcha2 INTEGER(8), scha2 INTEGER(8), ddiff2 FLOAT(8), sdiff2 FLOAT(8), offernocd3 CHAR(3), bidnocd3 CHAR(6), offerno3 CHAR(6), bidno3 CHAR(6), dvol3 INTEGER(8), svol3 INTEGER(8), dcha3 INTEGER(8), scha3 INTEGER(8), ddiff3 FLOAT(8), sdiff3 FLOAT(8), offernocd4 CHAR(3), bidnocd4 CHAR(3), offerno4 CHAR(6), bidno4 CHAR(6), dvol4 INTEGER(8), svol4 INTEGER(8), dcha4 INTEGER(8), scha4 INTEGER(8), ddiff4 FLOAT(8), sdiff4 FLOAT(8), offernocd5 CHAR(3), bidnocd5 CHAR(3), offerno5 CHAR(6), bidno5 CHAR(6), dvol5 INTEGER(8), svol5 INTEGER(8), dcha5 INTEGER(8), scha5 INTEGER(8), ddiff5 FLOAT(8), sdiff5 FLOAT(8), fwdvl BIGINT(12), ftradmdcha BIGINT(12), ftradmddiff FLOAT(8), fwsvl BIGINT(12), ftradmscha BIGINT(12), ftradmsdiff FLOAT(8), vol FLOAT(8), value BIGINT(12), jvolume BIGINT(12), highyear INTEGER(8), highyeardate DATE, lowyear INTEGER(8), lowyeardate DATE, target INTEGER(8), capital BIGINT(8), abscnt BIGINT(12), parprice INTEGER(8), gsmm CHAR(2), subprice INTEGER(8), total BIGINT(12), listdate DATE, name VARCHAR(10), bfsales BIGINT(12), bfoperatingincome BIGINT(12), bfordinaryincome BIGINT(12), bfnetincome BIGINT(12), bfeps FLOAT(15), name2 VARCHAR(10), bfsales2 BIGINT(12), bfoperatingincome2 BIGINT(12), bfordinaryincome2 BIGINT(12), bfnetincome2 BIGINT(12), bfeps2 FLOAT(15), salert FLOAT(9), opert FLOAT(9), ordrt FLOAT(9), netrt FLOAT(9), epsrt FLOAT(9), info1 VARCHAR(10), info2 VARCHAR(10), info3 VARCHAR(10), info4 VARCHAR(12), janginfo VARCHAR(10), t_per FLOAT(8), tonghwa CHAR(3), dval1 BIGINT(18), sval1 BIGINT(18), dval2 BIGINT(18), sval2 BIGINT(18), dval3 BIGINT(18), sval3 BIGINT(18),dval4 BIGINT(18), sval4 BIGINT(18), dval5 BIGINT(18), sval5 BIGINT(18), davg1 INTEGER(8), savg1 INTEGER(8), davg2 INTEGER(8), savg2 INTEGER(8), davg3 INTEGER(8), savg3 INTEGER(8), davg4 INTEGER(8), savg4 INTEGER(8), davg5 INTEGER(8), savg5 INTEGER(8),  ftradmdval BIGINT(18), ftradmsval BIGINT(18), ftradmdavg INTEGER(8), ftradmsavg INTEGER(8), info5 VARCHAR(8), spac_gubun CHAR(1), issueprice INTEGER(8), alloc_gubun CHAR(1), alloc_text VARCHAR(8), shterm_text VARCHAR(10))");
    if(!query.exec()) {
        errorQuery(&query);
        return;
    } else {
        qCDebug(stockInfoUpdater)<< "StockInfoTable is created";
        return;
    }
}

void StockInfoUpdater::saveToDB(StockInfo *info)
{
    QSqlQuery qry;
    QString qryString = QString("SELECT COUNT(*) FROM StockInfoTable WHERE shcode='%1'").arg(info->shcode());
    qry.prepare(qryString);
    if(qry.exec()) {
        if(qry.next()) {
            if(qry.value(0).toInt()==0) {
                QString insertString = info->getSqlInsertStr();
                qry.prepare(insertString);
            } else {
                QString updateString = info->getSqlUpdateStr();
                qry.prepare(updateString);
            }
        }
    } else {
        errorQuery(&qry);
    }

}

void StockInfoUpdater::errorQuery(QSqlQuery *query)
{
    qCWarning(stockInfoUpdater)<<"QueryError : "<<query->lastError()<<endl<<query->executedQuery();
}

bool StockInfoUpdater::checkCondition(StockInfo *info)
{
   if((info->listdate()!=ZeroDate)||(!info->isETF()))
       return true;
   else
       return false;
}

