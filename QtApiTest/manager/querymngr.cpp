#include <QDebug>
#include <QMetaObject>
#include "util/log.h"
#include "querymngr.h"

QueryMngr::QueryMngr(QObject *parent) : QObject(parent)
{
    moveToThread(&mThread);
    mThread.start();
    initRequestTimer();
 }

QueryMngr::~QueryMngr()
{

}

void QueryMngr::start()
{
    qDebug()<<"doTimeoutJob()";
}

void QueryMngr::requestQuery(TrQuery *query)
{
    query->moveToThread(&mThread);
    mQueryList.append(query);
    connect(query, SIGNAL(workDone()), this, SLOT(queryDone()));
    connect(query, SIGNAL(scheduleNextQuery()), this, SLOT(onScheduleNextRequest()));
    if(!mRequestTimer.isAc)
}

void QueryMngr::onScheduleNextRequest()
{
    QObject* sender = QObject::sender();
    if(sender !=NULL) {
        TrQuery* query = qobject_cast<TrQuery*>(sender);
        if(mQueryList.contains(query)) {
            mSendingQueue.enqueue(query);
            if(!mRequestTimer.isActive()){
                mRequestTimer.start(1000);
            }else {
                qCDebug(queryMngr)<<"mRequestTimer restart";
            }
        }else {
            qCDebug(queryMngr)<<"sender is not contained in mQueryList";
        }
    }else {
        qCDebug(queryMngr)<<"sender is NULL";
    }
}

void QueryMngr::initRequestTimer()
{
    mRequestTimer.moveToThread(&mThread);
    connect(&mRequestTimer, SIGNAL(timeout()), this, SLOT(start()));
    QMetaObject::invokeMethod(&mRequestTimer, "start", Qt::QueuedConnection,Q_ARG(int,1000));
}

