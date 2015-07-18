#include <QMetaObject>
#include <QDate>
#include "trquery.h"

TrQuery::TrQuery(const QString& trName, QObject *parent) : QObject(parent), mTrName(trName), mTrInfo(trName)
{
    mXaQuery = XAQuery::newTrInstance(trName, this);
    connect(mXaQuery, SIGNAL(ReceiveMessage(QString)), this, SLOT(onReceiveMsg(QString)));
    connect(mXaQuery, SIGNAL(ReceiveData(QString)), this, SLOT(onReceiveData(QString)));
    connect(mXaQuery, SIGNAL(ReceiveChartRealData(QString)), this, SLOT(onReceiveChartRealData(QString)));
}

TrQuery::~TrQuery()
{

}

QString TrQuery::str(const QVariant &value)
{
    switch(value.type()) {
    case QMetaType::QDate:
        QDate date = value.toDate();
        return date.toString(tr("yyMMdd"));
    case QMetaType::QTime:
        QTime time = value.toTime();
        return time.toString(tr("hhmmss"));
    default:
        return value.toString();
    }
}

XAQuery* TrQuery::xaquery()
{
    return mXaQuery;
}

QString TrQuery::getTrName()
{
    return mTrName;
}

void TrQuery::request()
{
    TrBlockInfo* info = mTrInfo.getInBlock();
    const QMetaObject *metaObject = this->metaObject();
    foreach(QString fieldName, info->getFieldNameList()){
        mXaQuery->SetFieldData(info->getBlockName(), fieldName, 0, str(metaObject->property(fieldName)));
    }
    mXaQuery->Request(false);
}

void TrQuery::onReceiveMsg(const QString &msg)
{
    emit ReceiveMsg(msg);
}

void TrQuery::onReceiveData(const QString &trCode)
{

}

void TrQuery::onReceiveChartRealData(const QString &trCode)
{

}


