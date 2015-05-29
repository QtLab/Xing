#include <stdlib.h>
#include "t1702handler.h"
#include "util/fieldutil.h"
T1702Handler::T1702Handler(QObject *parent)
{

}

T1702Handler::~T1702Handler()
{

}

int T1702Handler::sendRequest(TrQuery *trQuery)
{
    t1702InBlock* pckInBlock = makeT1702InBlock(trQuery);
    int requestId = IXingAPI::GetInstance()->Request(trQuery->getHWnd(), NAME_t1702, pckInBlock, sizeof(pckInBlock), FALSE, " ", -1);
    delete pckInBlock;
    return requestId;
}

T1702Query *T1702Handler::getQuery(int reqId)
{
    return static_cast<T1702Query*>(mQueryMap.value(reqId));
}

t1702InBlock *T1702Handler::makeT1702InBlock(TrQuery *trQuery)
{
    T1702Query* query = static_cast<T1702Query*>(trQuery);
    t1702InBlock* pckInBlock = new t1702InBlock();
    INIT_BLOCK(pckInBlock);
    SET_FIELD(pckInBlock->shcode, query->getShcode());
    SET_FIELD(pckInBlock->todt, query->getToDate());
    SET_FIELD(pckInBlock->volvalgb, query->getVolvalgb());
    SET_FIELD(pckInBlock->msmdgb, query->getMsmdgb());
    SET_FIELD(pckInBlock->cumulgb, query->getCumulgb());
    return pckInBlock;
}

void T1702Handler::handleT1702OutBlock(LPRECV_PACKET packet)
{
    T1702Query* query = getQuery(packet->nRqID);
    LPt1702OutBlock outblock = (LPt1702OutBlock)packet->lpData;
    QDate cts_date = GET_DATE_FROM_FIELD(outblock->cts_date);
    QString cts_idx = GET_STRING_FROM_FIELD(outblock->cts_idx);
    query->setCtsDate(cts_date);
    query->setCtsIdx(cts_idx);
}

bool T1702Handler::handleT1702OutBlock1(LPRECV_PACKET packet)
{
    LPt1702OutBlock1 pOutBlock;
    T1702Query* query = getQuery(packet->nRqID);
    int numOfItem = packet->nDataLength/sizeof(t1702OutBlock1);
    for(int i = 0; i<numOfItem; i++) {
        pOutBlock=(LPt1702OutBlock1)(packet->lpData+(sizeof(t1702OutBlock1)*i));
        QDate date = GET_DATE_FROM_FIELD(pOutBlock->date);
        if(date<query->getFromDate()){
            return true;
        }
        T1702Item* item = new T1702Item(pOutBlock, query);

        query->addT1702Item(item);
    }
    t1702InBlock* pckInBlock = makeT1702InBlock(query);
    SET_FIELD(pckInBlock->cts_date, query->getCtsDate());
    SET_FIELD(pckInBlock->cts_idx, query->getCtsIdx());
    int requestId = IXingAPI::GetInstance()->Request(query->getHWnd(), NAME_t1702, pckInBlock, sizeof(pckInBlock), FALSE, " ", -1);
    changeReqId(packet->nRqID, requestId);
    return false;
}

void T1702Handler::dataReceived(LPRECV_PACKET packet)
{
    QString blockName = QString::fromLocal8Bit(packet->szBlockName, sizeof(packet->szBlockName));
    if(!blockName.compare("t1702OutBlock")){
        handleT1702OutBlock(packet);
    } else if(!blockName.compare("t1702OutBlock1")) {
        handleT1702OutBlock1(packet);
    }
}

void T1702Handler::messageReceived(LPMSG_PACKET packet)
{

}

void T1702Handler::errorReceived(LPMSG_PACKET packet)
{

}

void T1702Handler::releaseReceived(int reqId)
{

}

