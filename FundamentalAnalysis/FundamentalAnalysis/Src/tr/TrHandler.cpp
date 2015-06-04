#include "stdafx.h"
#include "TrHandler.h"
#include "../util/fieldutil.h"
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

void TrHandler::addTrQuery(TrQuery* query)
{
    int requestId = sendRequest(query);
    mQueryMap.insert(requestId, query);
}

void TrHandler::messageReceived(LPMSG_PACKET packet)
{
    if(mQueryMap.contains(packet->nRqID)) {
        QString msg("messageReceived");
        QString appendMsg;
        QString receivedMsg = GET_STRING_FROM_FIELD_WITH_LENGTH((char*)packet->lpszMessageData, packet->nMsgLength);
        printLog(msg.append(receivedMsg));
        TrQuery* query = mQueryMap.value(packet->nRqID);
        emit query->messageReceived(receivedMsg);
        IXingAPI::GetInstance()->ReleaseMessageData((LPARAM)packet);
    }
}

void TrHandler::errorReceived(LPMSG_PACKET packet)
{
    if(mQueryMap.contains(packet->nRqID)) {
        QString msg("errorReceived");
        QString receivedMsg = GET_STRING_FROM_FIELD_WITH_LENGTH((char*)packet->lpszMessageData, packet->nMsgLength);
        printLog(msg.append(receivedMsg));

        TrQuery* query = mQueryMap.value(packet->nRqID);
        emit query->errorReceived(receivedMsg);

        IXingAPI::GetInstance()->ReleaseMessageData((LPARAM)packet);
    }
}

void TrHandler::releaseReceived(int reqId)
{
    if(mQueryMap.contains(reqId)) {
        TrQuery* query = mQueryMap.value(reqId);
        mQueryMap.remove(reqId);
        if(query->isFinished())
            query->deleteLater();
        IXingAPI::GetInstance()->ReleaseRequestData(reqId);
    }
}

