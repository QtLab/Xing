#include <QMetaObject>
#include <QDebug>
#include <QTimer>
#include "trtester.h"

TrTester::TrTester(QObject *parent) : QThread(parent)
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
    connect(&mSession, SIGNAL(onLogin(QString,QString)), this, SLOT(runTest()));
    if(mSession.Init()) {
       if(mSession.ConnectServer(true)) {
           mSession.Login(tr("seuki77"), tr("folken77"), "", 0, false);
       }
    }

}

void TrTester::run()
{
    mSendingTimer = new Timer();
    connect(timer, SIGNAL(timeout()), this, SLOT(sendQuery()));
}

void TrTester::testDone()
{
    QObject* sender = QObject::sender();
    if(sender!=NULL){
        TrQuery* query = qobject_cast<TrQuery*>(sender);
        qDebug()<<query->toString();
        mQueryList.removeOne(query);
        query->deleteLater();;
        if(mQueryList.size()==0){
            emit testOver();
        }
    }
}

void TrTester::runTest()
{
    QList<TrQuery*>::iterator iter;
    for(iter = mQueryList.begin(); iter<mQueryList.end(); iter++) {
        connect(*iter, SIGNAL(workDone()), this, SLOT(testDone()));
    mWaitingQueryList.push_back(*iter);
    }
    mSendingTimer->start(0);
}

void TrTester::sendQuery()
{
    if(!mWaitingQueryList.isEmpty()){
    TrQuery* query = mWaitingQueryList.pop_front();
        query->request();
        if(mWaitingQueryList.size()>0) {
            mSendingTimer->start(1000);
        }
    }
}



Worker::Worker(QObject *parent):QObject(parent)
{

}

void Worker::onTimeout()
{

}
