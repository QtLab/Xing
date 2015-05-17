#include "xaquery.h"

XAQuery::XAQuery(QObject *parent) : QObject(parent)
{

}

XAQuery::~XAQuery()
{

}

void XAQuery::requestQuery(TrHandler *query)
{
    int requestId = query->sendRequest();
    mQueryMap.insert(requestId, query);
}

void XAQuery::dataReceived(LPRECV_PACKET packet)
{
    TrHandler* query = mQueryMap.value(packet->nRqID);
    mQueryMap.remove(packet->nRqID);
    query->dataReceived(packet);
    if(query->hasMoreRequest()){
        int requestId = query->sendRequest();
        mQueryMap.insert(requestId, query);
    }
}

void XAQuery::messageReceived(LPMSG_PACKET packet)
{
    mQueryMap[packet->nRqID]->messageReceived(packet);
}

void XAQuery::errorReceived(LPMSG_PACKET packet)
{
    mQueryMap[packet->nRqID]->errorReceived(packet);
}

void XAQuery::releaseReceived(int requestId)
{
    mQueryMap[requestId]->releaseReceived();
}



