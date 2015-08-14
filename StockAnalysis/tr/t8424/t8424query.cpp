#include "t8424query.h"

T8424Query::T8424Query(QObject *parent) : TrQuery(TrQuery::T8424, tr("t8424"), parent)
{

}

T8424Item *T8424Query::createItem()
{
    return new T8424Item();
}

void T8424Query::onReceiveData(const QString &trCode)
{
    TrBlockInfo* outBlockInfo = trInfo()->getOutBlock();
    int blockCnt = xaquery()->GetBlockCount(outBlockInfo->getBlockName());
    for(int i = 0; i<blockCnt; i++) {
        TrItem* item = getTrItemFromReceivedData(outBlockInfo, i);
        mItemList.append(qobject_cast<T8424Item*>(item));
    }
    workDone();
    xaquery()->ClearBlockdata(outBlockInfo->getBlockName());

}

void T8424Query::onReceiveChartRealData(const QString &trCode)
{

}

T8424Query::~T8424Query()
{

}

T8424Query *T8424Query::createQuery(MARKET_TYPE upType, QObject *parent)
{
    T8424Query *query = new T8424Query(parent);
    query->setGubun(QString::number(static_cast<int>(upType)));
    return query;
}

QString T8424Query::toString()
{
    QString desc;
    QTextStream stream(&desc);
    stream<<"T8424 Result[START]"<<endl;
    foreach(T8424Item* item, getResult()) {
        stream<<item->toString()<<endl;
    }
    stream<<"T8424 Result[END]"<<endl;
    return desc;
}

QList<T8424Item *> T8424Query::getResult()
{
    return mItemList;
}

