#include <QMetaObject>
#include <QDate>
#include "trquery.h"

TrQuery::TrQuery(const QString& trName, QObject *parent) : QObject(parent), mTrName(trName), mTrInfo(trName)
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

TrItem *TrQuery::getTrItemFromReceivedData(int occurIndex)
{
    TrBlockInfo* outBlockInfo = trInfo()->getOutBlock();
    TrItem* item = createItem();
    foreach(QString fieldName , outBlockInfo->getFieldNameList())
    {
        QString value = xaquery()->GetFieldData(outBlockInfo->getBlockName(),fieldName, 0);
        TrFieldInfo* fieldInfo = outBlockInfo->getField(fieldName);
        switch(fieldInfo->getDataType()) {
        case TrFieldInfo::CHAR:
            item->setProperty(fieldName.toLocal8Bit(), value);
            break;
        case TrFieldInfo::LONG:
            item->setProperty(fieldName.toLocal8Bit(), value.toLong());
            break;
        case TrFieldInfo::LONGLONG:
            item->setProperty(fieldName.toLocal8Bit(), value.toLongLong());
            break;
        case TrFieldInfo::FLOAT:
            item->setProperty(fieldName.toLocal8Bit(), value.toFloat());
            break;
        case TrFieldInfo::DATE:
            item->setProperty(fieldName.toLocal8Bit(), QDate::fromString(value, "yyyyMMdd"));
            break;
        case TrFieldInfo::TIME:
            item->setProperty(fieldName.toLocal8Bit(), QTime::fromString(value, "hhmmss"));
            break;
        default:
            item->setProperty(fieldName.toLocal8Bit(), value);
        }
    }
    return item;
}

void TrQuery::request()
{
    TrBlockInfo* info = mTrInfo.getInBlock();
    foreach(QString fieldName, info->getFieldNameList()) {
        mXaQuery->SetFieldData(info->getBlockName().toLocal8Bit(), fieldName, 0, str(this->property(fieldName.toLocal8Bit())).toLocal8Bit());
    }
    mXaQuery->Request(false);
}

void TrQuery::onReceiveMsg(bool bIsSystemError, const QString &msgCode, const QString &msg)
{
    emit ReceiveMsg(msg);
}



