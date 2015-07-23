#include <QDebug>
#include "trtest.h"

TrTest::TrTest(QueryMngr *queryMngr, QObject *parent):QObject(parent),mQueryMngr(queryMngr)
{

}

TrTest::~TrTest()
{

}

void TrTest::start()
{
   T1102Query* query1102 = T1102Query::createQuery();
   T8430Query* query8430 = T8430Query::createQuery();
   T1702Query* query1702 = T1702Query::createQuery();

   connect(query1102, &T1102Query::workDone, this, &TrTest::testDone);
   connect(query8430, &T8430Query::workDone, this, &TrTest::testDone);
   connect(query1702, &T1702Query::workDone, this, &TrTest::testDone);
   mQueryMngr->requestQuery(query1102);
   mQueryMngr->requestQuery(query8430);
   mQueryMngr->requestQuery(query1702);
}

void TrTest::testDone()
{
   QObject* sender = QObject::sender();
   if(sender != NULL) {
       TrQuery* query = qobject_cast<TrQuery *>(sender);
       switch(query->getTrType()) {
       case TrQuery::T1102:
       {
            T1102Query *t1102Query = qobject_cast<T1102Query *>(query);
            handleT1102Result(t1102Query);
       }
            break;
       case TrQuery::T8430:
       {
           T8430Query *t8430Query = qobject_cast<T8430Query *>(query);
           handleT8430Result(t8430Query);
       }
           break;
       case TrQuery::T1702:
       {
           T1702Query *t1702Query = qobject_cast<T1702Query *>(query);
           handleT1702Result(t1702Query);

       }

      }
   }
}

void TrTest::handleT1102Result(T1102Query *query)
{
    T1102Item* item = query->getResult();
    qDebug()<<item->toString()<<endl;
    item->deleteLater();
    query->deleteLater();
}

void TrTest::handleT8430Result(T8430Query *query)
{
    QList<T8430Item *> itemList = query->getResult();
    qDebug()<<"T8430 Result [START]";
    foreach(T8430Item *item, itemList) {
        qDebug()<<item->toString()<<endl;
        item->deleteLater();
    }
    itemList.clear();
    query->deleteLater();
    qDebug()<<"T8430 Result [END]";

}

void TrTest::handleT1702Result(T1702Query *query)
{
   QList<T1702Item *> itemList = query->getResult();
   qDebug()<<"T1702 Result [START]";
    foreach(T1702Item *item, itemList) {
        qDebug()<<item->toString()<<endl;
        item->deleteLater();
    }
    itemList.clear();
    query->deleteLater();
    qDebug()<<"T1702 Result [END]";
}

