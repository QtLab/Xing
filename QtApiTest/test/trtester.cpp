#include <QMetaObject>
#include <QDebug>
#include "trtester.h"

TrTester::TrTester(QObject *parent) : QObject(parent)
{

}

TrTester::~TrTester()
{

}

void TrTester::addQuery(TrQuery *query)
{
    query->moveToThread(this);
    mQueryList.append(query);
}

void TrTester::startTest()
{
    QList<TrQuery*>::iterator iter;
    for(iter = mQueryList.begin(); iter<mQueryList.end(); iter++) {
        connect(iter, SIGNAL(workDone()), this, SLOT(testDone));
        QMetaObject::invokeMethod(iter, "request", Qt::QueuedConnection);
    }
}

void TrTester::testDone()
{
    QObject* sender = QObject::sender();
    if(sender!=null){
        TrQuery* query = qobject_cast<TrQuery*>(sender);
        qDebug()<<query->toString();
        mQueryList.removeOne(query);
        query->deleteLater();;
        if(mQueryList.size()==0){
            emit::testOver();
        }
    }
}

