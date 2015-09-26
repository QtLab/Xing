#include <QMetaObject>
#include <QDate>
#include <QDebug>
#include "trquery.h"
#include "util/log.h"

TrQuery::TrQuery(const QString& trName, QObject *parent) : QObject(parent), mTrName(trName), mTrInfo(trName), _next(false)
{
    mXaQuery = XAQuery::newTrInstance(trName, this);
    connect(mXaQuery, SIGNAL(ReceiveMessage(bool,QString,QString)), this, SLOT(onReceiveMsg(bool,QString,QString)));
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
    {
        QDate date = value.toDate();
        return date.toString(tr("yyyyMMdd"));
    }
    case QMetaType::QTime:
    {
        QTime time = value.toTime();
        return time.toString(tr("hhmmss"));
    }
    default:
    {
        return value.toString();
    }
    }
}

XAQuery *TrQuery::xaquery()
{
    return mXaQuery;
}

TrMetaInfo *TrQuery::trInfo()
{
    return &mTrInfo;
}

QString TrQuery::getTrName()
{
    return mTrName;
}

TrItem *TrQuery::getTrItemFromReceivedData(TrBlockInfo *outBlockInfo, int occurIndex)
{
    TrItem* item = createItem();
    foreach(QString fieldName , outBlockInfo->getFieldNameList())
    {
        QString value = xaquery()->GetFieldData(outBlockInfo->getBlockName(),fieldName, occurIndex );
        TrFieldInfo* fieldInfo = outBlockInfo->getField(fieldName);
        bool result = false;
        switch(fieldInfo->getDataType()) {
        case TrFieldInfo::CHAR:
            result = item->setProperty(fieldName.toLocal8Bit(), value);
            break;
        case TrFieldInfo::LONG:
            result = item->setProperty(fieldName.toLocal8Bit(), value.toLong());
            break;
        case TrFieldInfo::LONGLONG:
            result = item->setProperty(fieldName.toLocal8Bit(), value.toLongLong());
            break;
        case TrFieldInfo::FLOAT:
            result = item->setProperty(fieldName.toLocal8Bit(), value.toFloat());
            break;
        case TrFieldInfo::DATE:
            result = item->setProperty(fieldName.toLocal8Bit(), QDate::fromString(value, "yyyyMMdd"));
            break;
        case TrFieldInfo::TIME:
            result = item->setProperty(fieldName.toLocal8Bit(), QTime::fromString(value, "hhmmss"));
            break;
        default:
            result = item->setProperty(fieldName.toLocal8Bit(), value);
        }
        if(!result) {
            qCWarning(trQuery)<<"setProperty for "<<fieldName<<" failed"<<endl;
        }
    }
    return item;
}

void TrQuery::request()
{
    QString debugMsg;
    QTextStream stream(&debugMsg);
    TrBlockInfo* info = mTrInfo.getInBlock();
    stream<<mTrName<<" for "<<this->property("shcode").toString()<<" is requested with ";
    foreach(QString fieldName, info->getFieldNameList()) {
        mXaQuery->SetFieldData(info->getBlockName().toLocal8Bit(), fieldName, 0, str(this->property(fieldName.toLocal8Bit())).toLocal8Bit());
        stream<<"("<<fieldName<<":"<<str(this->property(fieldName.toLocal8Bit()))<<"),";
    }
    stream<<endl;
    qCDebug(trQuery)<<debugMsg;
    mXaQuery->Request(isNextQuery());
}

void TrQuery::onReceiveMsg(bool bIsSystemError, const QString &msgCode, const QString &msg)
{
    emit ReceiveMsg(msg);
}


