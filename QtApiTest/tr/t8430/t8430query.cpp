#include <QDebug>
#include "t8430query.h"

T8430Query::T8430Query(QObject *parent) : TrQuery(tr("t8430"),parent)
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
       TrItem* item = getTrItemFromReceivedData(i);
       itemList.append(qobject_cast<T8430Item*>(item));
   }
   QList<T8430Item*>::const_iterator iter;
   for(iter = itemList.cbegin(); iter<itemList.end(); iter++) {
       qDebug()<<(*iter)->toString();
   }
   queryDone(itemList);
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
   return tr("T8430Query");
}
