#include "t1516query.h"

T1516Query::T1516Query(QObject *parent) : TrQuery(TrQuery::T1516, tr("t1516"), parent),_upcode(tr("")), _gubun(tr(""))
{

}

T1516Item *T1516Query::createItem()
{
    return new T1516Item();
}

bool T1516Query::hasNextData()
{
    QString value = xaquery()->GetFieldData(tr("t1516OutBlock"), tr("shcode"));
    return !mItemMap.contains(value);
}

void T1516Query::onReceiveData(const QString &trCode)
{
    TrBlockInfo* outBlockInfo1 = trInfo()->getOutBlock1();
    int blockCnt = xaquery()->GetBlockCount(outBlockInfo1->getBlockName());
    for(int i = 0; i<blockCnt; i++) {
        TrItem *item = getTrItemFromReceivedData(outBlockInfo1, i);
        T1516Item* t1516Item = qobject_cast<T1516Item*>(item);
        mItemMap.insert(t1516Item->shcode(), t1516Item);
    }
    if(hasNextData()) {
        setCts();
        setNextQuery(true);
        emit scheduleNextQuery();
        xaquery()->ClearBlockdata(outBlockInfo1->getBlockName());
    }else{
        emit workDone();
        xaquery()->clearBlockdata(outBlockInfo1->getBlockName());
    }
}

void T1516Query::onReceiveChartRealData(const QString &trCode)
{

}

T1516Query::~T1516Query()
{

}

T1516Query *T1516Query::createQuery(const QString &upcode, MARKET_TYPE marketType, QObject *parent)
{
    T1516Query* query = new T1516Query();
    query->setUpcode(upcode);
    if(marketType != NONE)
        query->setGubun(QString::number(qobject_cast<int>(marketType)));
    return query;
}

QString T1516Query::toString()
{
    QString desc;
    QTextStream stream(&desc);
    stream<<"T1516 Result[START]"<<endl;
    foreach(T1516Item* item, getResult()){
        stream<<item->toString()<<endl;
    }
    stream<<"T1516 Result[END]"<<endl;
    return desc;
}

QMap<QString, T1516Item *> T1516Query::getResult()
{
    return mItemMap;
}

