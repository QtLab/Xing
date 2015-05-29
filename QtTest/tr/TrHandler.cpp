#include "TrHandler.h"
#include <QDebug>

TrHandler::TrHandler(QObject *parent):QObject(parent)
{

}
TrHandler::~TrHandler()
{

}


void TrHandler::printLog(const QString &log)
{
    const QMetaObject* metaObj = metaObject();
    qDebug()<<"["<<metaObj->className()<<"] "<<log;
}

void TrHandler::changeReqId(int fromId, int toId)
{
    TrQuery* query = mQueryMap.value(fromId);
    mQueryMap.remove(fromId);
    mQueryMap.insert(toId, query);
}

void TrHandler::addTrQuery(TrQuery* query)
{
    int requestId = sendRequest(query);
    mQueryMap.insert(requestId, query);
}

