#include <QDebug>
#include <QTextStream>
#include "t1102query.h"


T1102Query::T1102Query(QObject *parent) : TrQuery(TrQuery::T1102, tr("t1102"), parent)
{

}

T1102Item *T1102Query::createItem()
{
    return new T1102Item();
}

void T1102Query::onReceiveData(const QString &trCode)
{
    TrBlockInfo* outblockInfo = trInfo()->getOutBlock();
    mResult = qobject_cast<T1102Item *>(getTrItemFromReceivedData(outblockInfo, 0));
    emit workDone();
    xaquery()->ClearBlockdata(outblockInfo->getBlockName());
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

QString T1102Query::toString()
{
    QString desc;
    QTextStream stream(&desc);
    stream<<"T1102 Result[START]"<<endl;
    stream<<mResult->toString()<<endl;
    stream<<"T1102 Result[END]"<<endl;
    return desc;
}

T1102Item *T1102Query::getResult()
{
   return mResult;
}

