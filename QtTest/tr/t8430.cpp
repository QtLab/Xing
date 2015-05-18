
#include "t8430.h"

T8430Handler::T8430Handler(QObject *parent) : TrHandler(parent)
{

}

T8430Handler::~T8430Handler()
{

}

QList<LPt8430Item> T8430Handler::handleData(LPRECV_PACKET packet)
{

    return itemList;
}

int T8430Handler::sendRequest(T8430Query* query)
{
    t8430InBlock pckInBlock;
    memset(&pckInBlock, ' ', sizeof(pckInBlock));

    switch(query->mMode) {
    case T8430Query::ALL:
        memcpy(pckInBlock.gubun, "0", sizeof(pckInBlock.gubun));
        break;
    case T8430Query::KOSPI:
        memcpy(pckInBlock.gubun, "1", sizeof(pckInBlock.gubun));
        break;
    case T8430Query::KOSDAQ:
        memcpy(pckInBlock.gubun, "2", sizeof(pckInBlock.gubun));
        break;
    }

    return IXingAPI::GetInstance()->Request(m_hwnd, NAME_t8430, &pckInBlock, sizeof(pckInBlock), FALSE, " ", -1);
}

void T8430Handler::dataReceived(LPRECV_PACKET packet)
{
    LPt8430OutBlock pOutBlock;
    QList<LPt8430Item> itemList;
    int numOfItem = packet->nDataLength/sizeof(t8430OutBlock);
    for(int i = 0; i<numOfItem; i++) {
        LPt8430Item item = new t8430Item();
        pOutBlock = (LPt8430OutBlock)(packet->lpData + (sizeof(t8430OutBlock) * i)); //데이터를 가져오기 위한 Block을 설장한다.
        item->hname = pOutBlock->hname;
        item->shcode = pOutBlock->shcode;
        item->expcode = pOutBlock->expcode;
        if(!strcmp("1", pOutBlock->etfgubun)){
            item->isETF = true;
        } else {
            item->isETF = false;
        }
        item->uplmtprice = changeStringToLong(pOutBlock->uplmtprice, 8);
        item->dnlmtprice = changeStringToLong(pOutBlock->dnlmtprice, 8);
        item->jniclose = changeStringToLong(pOutBlock->jnilclose, 8);
        item->memedan = pOutBlock->memedan;
        item->recprice = changeStringToLong(pOutBlock->recprice, 8);
        if(!strcmp("1", pOutBlock->gubun)){
            item->isKOSPI = true;
        } else {
            item->isKOSPI = false;
        }
        itemList.push_back(item);
    }
    T8430Query* query = mQueryMap.value(packet->nRqId);
    query->workDone(itemList);
}

void T8430Handler::messageReceived(LPMSG_PACKET packet)
{
    if(mQueryMap.contains(packet->nRqId)) {
        QString msg("messageReceived");
        printLog(msg.append(packet->lpszMessageData));

        T8430Query* query = mQueryMap.value(packet->nRqId);
        query->messageReceived(packet->lpszMessageData);

        IXingAPI::GetInstance()->ReleaseMessageData((LPARAM)packet);
    }
}

void T8430Handler::errorReceived(LPMSG_PACKET packet)
{
    if(mQueryMap.contains(packet->nRqId)) {
        QString msg("errorReceived");
        printLog(msg.append(packet->lpszMessageData));

        T8430Query* query = mQueryMap.value(packet->nRqId);
        query->errorReceived(packet->lpszMessageData);

        IXingAPI::GetInstance()->ReleaseMessageData((LPARAM)packet);
    }
}

void T8430Handler::releaseReceived(int reqId)
{
    if(mQueryMap.contains(reqId)) {
        T8430Query* query = mQueryMap.value(reqId);
        mQueryMap.remove(reqId);
        query->deleteLater();
        IXingAPI::GetInstance()->ReleaseRequestData(reqId);
    }
}




T8430Query *T8430Query::createQuery(const QWidget &requester, T8430Query::MODE mode, QObject *parent)
{
    T8430Query* query = new T8430Query(requester, parent);
    query->mMode = mode;
    return query;
}

T8430Query::T8430Query(const QWidget &requester, QObject *parent) : TrQuery(requester,NAME_t8430, parent)
{

}
