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
    mSendingTimer = new QTimer();
    connect(mSendingTimer, SIGNAL(timeout()), this, SLOT(sendQuery()));
    exec();
}

void TrTester::testDone()
{
    QObject* sender = QObject::sender();
    if(sender!=NULL) {
        TrQuery* query = qobject_cast<TrQuery*>(sender);
        qDebug()<<query->toString();
        mQueryList.removeOne(query);
        query->deleteLater();;
        if(mQueryList.size()==0) {
            emit testOver();
        }
    }
}

void TrTester::runTest()
{
    QList<TrQuery*>::iterator iter;
    for(iter = mQueryList.begin(); iter<mQueryList.end(); iter++) {
        connect(*iter, SIGNAL(workDone()), this, SLOT(testDone()));
        connect(*iter, SIGNAL(scheduleNextQuery()), this, SLOT(onScheduleNextQuery()));
        mWaitingQueryList.push_back(*iter);
    }
    QMetaObject::invokeMethod(this,"sendQuery", Qt::QueuedConnection);
}

void TrTester::sendQuery()
{
    if(!mWaitingQueryList.isEmpty()) {
        TrQuery* query = mWaitingQueryList.first();
        mWaitingQueryList.removeOne(query);
        query->request();
        if(mWaitingQueryList.size()>0) {
            mSendingTimer->singleShot(1000, this, SLOT(sendQuery()));
        }
    }
}

void TrTester::onScheduleNextQuery()
{
    QObject* sender = QObject::sender();
    if(sender!=NULL) {
        TrQuery* query = qobject_cast<TrQuery*>(sender);
        mWaitingQueryList.append(query);
        if(!mSendingTimer->isActive()) {
             mSendingTimer->singleShot(1000, this, SLOT(sendQuery()));
        }
    }
}
