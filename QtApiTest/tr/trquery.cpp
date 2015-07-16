#include "trquery.h"

TrQuery::TrQuery(const QString& trName, QObject *parent) : QObject(parent), mTrName(trName)
{
    mXaQuery = XAQuery::newTrInstance(trName, this);
    connect(mXaQuery, SIGNAL(ReceiveMessage(QString)), this, SLOT(onReceiveMsg(QString)));
    connect(mXaQuery, SIGNAL(ReceiveData(QString)), this, SLOT(onReceiveData(QString)));
    connect(mXaQuery, SIGNAL(ReceiveChartRealData(QString)), this, SLOT(onReceiveChartRealData(QString)));
}

TrQuery::~TrQuery()
{

}

XAQuery* TrQuery::xaquery()
{
    return mXaQuery;
}

void TrQuery::onReceiveMsg(const QString &msg)
{
    emit ReceiveMsg(msg);
}


