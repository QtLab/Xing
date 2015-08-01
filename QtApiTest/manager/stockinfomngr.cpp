#include <QtSql/QSqlQuery>
#include <QtSql/QSqlRecord>
#include <QtSql/QSqlError>
#include "stockinfomngr.h"
#include "util/log.h"

StockInfoMngr* StockInfoMngr::sInstance = NULL;
StockInfoMngr::StockInfoMngr(QObject *parent) : QObject(parent)
{

}

StockInfoMngr *StockInfoMngr::getInstance()
{
    if(sInstance==NULL) {
        sInstance = new StockInfoMngr();
    }
    return sInstance;
}

StockInfoMngr::~StockInfoMngr()
{

}

QList<QString> StockInfoMngr::getShcodeList()
{
    QList<QString> shcodeList;
    QSqlQuery qry;
    qry.prepare("SELECT shcode FROM StockInfoTable");
    if(qry.exec()) {
        while(qry.next()) {
            const QString shcode = qry.value(tr("shcode")).toString();
            shcodeList.append(shcode);
        }
    } else {
        errorQuery(&qry);
    }
    return shcodeList;
}

StockInfo *StockInfoMngr::getStockInfo(const QString &shcode)
{
    StockInfo *stockInfo = mStockInfoMap.value(shcode);
    if(stockInfo != NULL)
        return stockInfo;
    QSqlQuery qry;
    qry.prepare(tr("SELECT * FROM StockInfoTable WHERE `shcode`=%1").arg(shcode));
    if(qry.exec()) {
        if(qry.next()) {
            stockInfo = new StockInfo();
            stockInfo->setPropertyFromQuery(&qry);
            mStockInfoMap.insert(shcode, stockInfo);
            return stockInfo;
        }
    } else {
        errorQuery(&qry);
    }
    return NULL;
}

void StockInfoMngr::errorQuery(QSqlQuery *query)
{
    qCWarning(stockInfoMngr)<<"QueryError : "<<query->lastError()<<endl<<query->executedQuery();

}

