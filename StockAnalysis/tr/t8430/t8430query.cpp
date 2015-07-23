#include <QDebug>
#include <QTextStream>
#include "t8430query.h"

T8430Query::T8430Query(QObject *parent) : TrQuery(TrQuery::T8430, tr("t8430"),parent)
{

}

T8430Item *T8430Query::createItem()
{
   return new T8430Item();
}

void T8430Query::onReceiveData(const QString &trCode)
{
   TrBlockInfo* outBlockInfo = trInfo()->getOutBlock();
   int blockCnt = xaquery()->GetBlockCount(outBlockInfo->getBlockName());
   QList<T8430Item*> itemList;
   for(int i = 0; i<blockCnt; i++) {
       TrItem* item = getTrItemFromReceivedData(outBlockInfo, i);
       itemList.append(qobject_cast<T8430Item*>(item));
   }
   QList<T8430Item*>::const_iterator iter;
   for(iter = itemList.cbegin(); iter<itemList.end(); iter++) {
       qDebug()<<(*iter)->toString();
   }
   workDone();
   xaquery()->ClearBlockdata(outBlockInfo->getBlockName());
}

void T8430Query::onReceiveChartRealData(const QString &trCode)
{

}

T8430Query *T8430Query::createQuery(const QString &gubun, QObject *parent)
{
   T8430Query *query = new T8430Query(parent);
   query->setGubun(gubun);
   return query;
}

T8430Query::~T8430Query()
{

}

QString T8430Query::toString()
{
    QString desc;
    QTextStream stream(&desc);
    stream<<"T8430 Result[START]"<<endl;
    foreach(T8430Item* item, getResult()){
       stream<<item->toString()<<endl;
    }
    stream<<"T8430 Result[END]"<<endl;
    return desc;
}

QList<T8430Item *> T8430Query::getResult()
{
   return mItemList;
}
