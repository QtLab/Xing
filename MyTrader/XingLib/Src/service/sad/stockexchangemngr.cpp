#include <QMetaObject>
#include <QDateTime>
#include <QtSql/QSqlQuery>
#include "stockexchangemngr.h"
#include "logger/log.h"


StockExchangeMngr::StockExchangeMngr(QObject *parent) : QObject(parent)
{
    qRegisterMetaType<WarehouseInfo>("WarehouseHistoryMap");
    moveToThread(&mThread);
    mThread.start();
}

StockExchangeMngr::~StockExchangeMngr()
{

}

void StockExchangeMngr::requestStockExchangeInfo(const QString &shcode)
{
    QMetaObject::invokeMethod(this, "makeStockExchangeInfo", Qt::QueuedConnection, Q_ARG(QString, shcode));

}

void StockExchangeMngr::requestWarehouseHistory(const QString &shcode)
{
    QMetaObject::invokeMethod(this, "makeWarehouseHistory", Qt::QueuedConnection, Q_ARG(QString, shcode));
}

void StockExchangeMngr::makeWarehouseHistory(const QString &shcode)
{
    qCDebug(stockExchangeMngr)<<"start makeWarehouseHistory at "<<QDateTime::currentDateTime().toString(Qt::ISODate);
    WarehouseInfo *map = mWarehouseHistoryCache.value(shcode);
    if(map != NULL) {
        emit responseWarehouseHistory(map);
    } else {
        map = new WarehouseInfo();
        map->insert(PEF, WarehouseHistory::createWarehouseHistory(shcode, PEF));
        map->insert(INVESTMENT_C, WarehouseHistory::createWarehouseHistory(shcode, INVESTMENT_C));
        map->insert(INSURANCE, WarehouseHistory::createWarehouseHistory(shcode, INSURANCE));
        map->insert(INVESTMENT_T, WarehouseHistory::createWarehouseHistory(shcode, INVESTMENT_T));
        map->insert(BANK, WarehouseHistory::createWarehouseHistory(shcode, BANK));
        map->insert(ALLFINANZ, WarehouseHistory::createWarehouseHistory(shcode, ALLFINANZ));
        map->insert(NPF, WarehouseHistory::createWarehouseHistory(shcode, NPF));
        map->insert(CORP, WarehouseHistory::createWarehouseHistory(shcode, CORP));
        map->insert(INDIVISUAL, WarehouseHistory::createWarehouseHistory(shcode, INDIVISUAL));
        map->insert(REGISTERED_FOREIGNER, WarehouseHistory::createWarehouseHistory(shcode, REGISTERED_FOREIGNER));
        map->insert(NON_REGISTERED_FOREIGNER, WarehouseHistory::createWarehouseHistory(shcode, NON_REGISTERED_FOREIGNER));
        map->insert(NATIONAL, WarehouseHistory::createWarehouseHistory(shcode, NATIONAL));
        map->insert(INSTITUTION, WarehouseHistory::createWarehouseHistory(shcode, INSTITUTION));
        map->insert(FORCES, WarehouseHistory::createWarehouseHistory(shcode, FORCES));

        emit responseWarehouseHistory(map);
        mWarehouseHistoryCache.insert(shcode, map);
    }
    qCDebug(stockExchangeMngr)<<"end makeWarehouseHistory at "<<QDateTime::currentDateTime().toString(Qt::ISODate);
}

void StockExchangeMngr::makeStockExchangeInfo(const QString &shcode)
{
    StockExchangeInfo * exchangeInfo = mStockExchangeInfoMap.value(shcode);
    if(exchangeInfo==NULL){
        exchangeInfo = new StockExchangeInfo(shcode);
        mStockExchangeInfoMap.insert(shcode, exchangeInfo);
    }
    emit responseStockExchangeInfo(exchangeInfo);
}

