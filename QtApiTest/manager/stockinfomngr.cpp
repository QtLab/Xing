#include "stockinfomngr.h"
#include <QDebug>
#include "tr/t8430/t8430query.h"
StockInfoMngr::StockInfoMngr(QObject *parent):QThread(parent)
{

}

StockInfoMngr::~StockInfoMngr()
{

}

QList<StockInfo *> StockInfoMngr::getStockInfoList()
{
    QList<StockInfo *> stockInfoList;
    return stockInfoList;
}

void StockInfoMngr::update()
{
    T8430Query* query = T8430Query::createQuery(T8430Query::ALL);
    connect(query, SIGNAL(ReceiveMsg(QString)), this, SLOT(onReceiveMsg(QString)));
    trRequest(query);
}

void StockInfoMngr::onReceiveMsg(const QString &msg)
{
    emit notifyMsg(msg);
}

void StockInfoMngr::trRequest(TrQuery *query)
{
    mQueryList.append(query);
    query->moveToThread(this);
    QMetaObject::invokeMethod(query,"request", Qt::QueuedConnection);

}

