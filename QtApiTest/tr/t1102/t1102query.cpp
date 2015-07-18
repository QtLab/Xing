#include <QDebug>
#include "t1102query.h"


T1102Query::T1102Query(QObject *parent) : TrQuery(tr("t1102"), parent)
{

}

T1102Item *T1102Query::createItem()
{
    return new T1102Item();
}

void T1102Query::onReceiveData(const QString &trCode)
{
    TrBlockInfo* outBlockInfo = trInfo()->getOutBlock();
    TrItem* item = createItem();
    foreach(QString fieldName , outBlockInfo->getFieldNameList())
    {
        if(fieldName == "ftradmdvag")
            qDebug()<<fieldName;
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
    qDebug()<<item->toString();
}

void T1102Query::onReceiveChartRealData(const QString &trCode)
{

}

T1102Query *T1102Query::createQuery(const QString &shcode, QObject *parent)
{
    T1102Query *query = new T1102Query(parent);
    query->setShcode(shcode);
    return query;
}

T1102Query::~T1102Query()
{
}

void T1102Query::setShcode(const QString &shcode)
{
    _shcode = shcode;
}

QString T1102Query::shcode()
{
    return _shcode;
}

T1102Query *T1102Query::getQuery()
{
    return this;
}

QString T1102Query::toString()
{
    return tr("T1102Query");
}

