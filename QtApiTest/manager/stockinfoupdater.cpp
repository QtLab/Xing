#include "stockinfoupdater.h"
StockInfoUpdater::StockInfoUpdater(QWidget *parent) : QWidget(parent)
{

}

StockInfoUpdater::~StockInfoUpdater()
{

}

void StockInfoUpdater::update()
{
    T8430Query *query = T8430Query::createQuery();
    connect(query, SIGNAL(workDone()), this, SLOT(t8430QueryDone()));
    mQueryMngr.requestQuery(query);
}

void StockInfoUpdater::t8430QueryDone()
{

}

