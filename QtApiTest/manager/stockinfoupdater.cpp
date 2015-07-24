#include "stockinfoupdater.h"
StockInfoUpdater::StockInfoUpdater(QueryMngr *queryMngr, QObject *parent) : QObject(parent),mQueryMngr(queryMngr)
{

}

StockInfoUpdater::~StockInfoUpdater()
{

}

const QMap<QString, StockInfo *> StockInfoUpdater::getStockInfoMap()
{
    return mStockInfoMap;
}

void StockInfoUpdater::update()
{
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
            mStockInfoMap.insert(info->shcode(), info);
            if(mStockInfoUpdatingMap.size()==0) {
                emit updateDone();
            }
            item->deleteLater();
            query->deleteLater();
        }
    }
}

