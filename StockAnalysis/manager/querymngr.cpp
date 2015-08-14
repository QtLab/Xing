#include <QDebug>
#include <QMetaObject>
#include <QThread>
#include "util/log.h"
#include "querymngr.h"
#include "util/log.h"
QueryMngr::QueryMngr(QObject *parent) : QObject(parent) , mCurrentInterval(1000)
{

}

QueryMngr::~QueryMngr()
{
}

void QueryMngr::start()
{
    moveToThread(&mThread);
    initRequestTimer();
    mThread.start();
}

void QueryMngr::sendRequest()
{
    if(!mSendingQueue.isEmpty()) {
        if(mCurrentInterval<3000){
            mCurrentInterval += 300;
        }
        mRequestTimer.setInterval(mCurrentInterval);
        TrQuery *query = mSendingQueue.dequeue();
        query->request();
    } else if(mRequestTimer.isActive()) {
        mRequestTimer.stop();
        mCurrentInterval = 1000;
        qCDebug(queryMngr)<<"Sending Queue is empty, so stop Request Timer";
    }
}

void QueryMngr::requestQuery(TrQuery *query)
{
    qCDebug(queryMngr)<<query->getTrName()<<" is requested"<<endl;
    query->moveToThread(&mThread);
    mQueryList.append(query);
    mSendingQueue.append(query);
    connect(query, SIGNAL(workDone()), this, SLOT(queryDone()));
    connect(query, SIGNAL(scheduleNextQuery()), this, SLOT(onScheduleNextRequest()));
    QMetaObject::invokeMethod(this, "checkAndRestartTimer", Qt::QueuedConnection);
}

void QueryMngr::queryDone()
{
    QObject* sender = QObject::sender();
    if(sender != NULL) {
        TrQuery* query = qobject_cast<TrQuery *>(sender);
        qCDebug(queryMngr)<<"query for "<<query->getTrName()<<" is done"<<endl;
        if(mQueryList.contains(query)) {
            mQueryList.removeOne(query);
        } else {
            qCWarning(queryMngr)<<"mQueryList doesn't contain sender - "<<qPrintable(sender->objectName());
        }
    } else {
        qCWarning(queryMngr)<<"sender is NULL";
    }
}

void QueryMngr::onScheduleNextRequest()
{
    QObject* sender = QObject::sender();
    if(sender !=NULL) {
        TrQuery* query = qobject_cast<TrQuery*>(sender);
        if(mQueryList.contains(query)) {
            mSendingQueue.enqueue(query);
            checkAndRestartTimer();
        } else {
            qCDebug(queryMngr)<<"sender is not contained in mQueryList";
        }
    } else {
        qCDebug(queryMngr)<<"sender is NULL";
    }
}

void QueryMngr::initRequestTimer()
{
    mRequestTimer.moveToThread(&mThread);
    connect(&mRequestTimer, SIGNAL(timeout()), this, SLOT(sendRequest()));
    QMetaObject::invokeMethod(&mRequestTimer, "start", Qt::QueuedConnection,Q_ARG(int,mCurrentInterval));
}

void QueryMngr::checkAndRestartTimer()
{
    if(mThread.isRunning()) {
        if(!mRequestTimer.isActive()) {
            mRequestTimer.start(mCurrentInterval);
            qCDebug(queryMngr)<<"mRequestTimer is restarted";
        }
    } else {
        qCDebug(queryMngr)<<"Thread is not running";
    }
}

