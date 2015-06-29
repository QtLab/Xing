#include "xaquery.h"
#include "tr/t8430/t8430.h"
#include "tr/t8430/t8430handler.h"
#include "tr/t1702/t1702handler.h"
#include "util/objectfactory.h"

XAQueryMngr::XAQueryMngr(QObject *parent) : QThread(parent)
{
    ObjectFactory::registerClass<T8430Handler>();
    ObjectFactory::registerClass<T1702Handler>();
}

XAQueryMngr::~XAQueryMngr()
{

}

void XAQueryMngr::requestQuery(TrQuery *query)
{
    TrHandler* handler;
    if(!mHandlerMap.contains(query->getName())){
        QString name = query->getName();
        name.replace(0, 1, 'T');
        name.append("Handler");
        handler = static_cast<TrHandler*>(ObjectFactory::createObject(name.toLocal8Bit()));
        mHandlerMap.insert(query->getName(), handler);
    }
    handler->addTrQuery(query);
}

void XAQueryMngr::handleResponse(WPARAM wparam, LPARAM lparam)
{
    switch(wparam){
        case REQUEST_DATA:
        {
            LPRECV_PACKET lpRecvPacket = (LPRECV_PACKET)lparam;
            //mHandlerMap[lpRecvPacket->szTrCode]->dataReceived(lpRecvPacket);
            QMetaObject::invokeMethod(mHandlerMap[lpRecvPacket->szTrCode],"dataReceived", Qt::QueuedConnection, Q_ARG(LPRECV_PACKET, lpRecvPacket));
            break;
        }
        case MESSAGE_DATA:
        {
            LPMSG_PACKET pMsg = (LPMSG_PACKET)lparam;
            QList<TrHandler*> trHandlerList = mHandlerMap.values();
            foreach(TrHandler* handler, trHandlerList){
                QMetaObject::invokeMethod(handler, "messageReceived", Qt::QueuedConnection, Q_ARG(LPMSG_PACKET,pMsg));
            }
            break;
        }
        case SYSTEM_ERROR_DATA:
        {
            LPMSG_PACKET pMsg = (LPMSG_PACKET)lparam;
            QList<TrHandler*> trHandlerList = mHandlerMap.values();
            foreach(TrHandler* handler, trHandlerList){
                QMetaObject::invokeMethod(handler, "errorReceived", Qt::QueuedConnection, Q_ARG(LPMSG_PACKET,pMsg));
            }
            break;
        }
        case RELEASE_DATA:
        {
            QList<TrHandler*> trHandlerList = mHandlerMap.values();
            foreach(TrHandler* handler, trHandlerList){
                QMetaObject::invokeMethod(handler, "releaseReceived", Qt::QueuedConnection, Q_ARG(int,lparam));
            }
            break;
        }
    }
}



