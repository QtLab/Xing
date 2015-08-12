#include <Windows.h>
#include <util/log.h>
#include "xingthread.h"

XingThread::XingThread(QObject *parent) : QThread(parent)
{

}

XingThread::~XingThread()
{

}

void XingThread::run()
{
    qDebug()<<tr("Thread-%1 started").arg((long)currentThreadId());
    CoInitialize(NULL);
    exec();
}

