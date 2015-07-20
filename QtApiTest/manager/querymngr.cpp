#include <QDebug>
#include <QMetaObject>
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

void QueryMngr::doJob()
{
    qDebug()<<"doJob() - "<<QThread::currentThreadId();
}

void QueryMngr::doTimeoutJob()
{
    qDebug()<<"doTimeoutJob()";
}

void QueryMngr::initRequestTimer()
{
    mRequestTimer.moveToThread(&mThread);
    connect(&mRequestTimer, SIGNAL(timeout()), this, SLOT(doTimeoutJob()));
    QMetaObject::invokeMethod(&mRequestTimer, "start", Qt::QueuedConnection,Q_ARG(int,1000));
}

