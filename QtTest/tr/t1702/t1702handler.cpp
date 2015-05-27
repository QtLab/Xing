#include "t1702handler.h"
#include <stdlib.h>
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
    memset(&pckInBlock, ' ', sizeof(pckInBlock));
    memcpy(pckInBlock->shcode, query->getShcode().toLocal8Bit(), sizeof(pckInBlock->shcode));
    memcpy(pckInBlock->todt, query->getToDate().toString("yyyyMMdd").toLocal8Bit(), sizeof(pckInBlock->todt));
    QString volvalgb = QString::number(query->getVolvalgb());
    memcpy(pckInBlock->volvalgb, volvalgb.toLocal8Bit(), sizeof(pckInBlock->volvalgb));
    QString msmdgb = QString::number(query->getMsmdgb());
    memcpy(pckInBlock->msmdgb, msmdgb.toLocal8Bit(), sizeof(pckInBlock->msmdgb));
    QString cumulgb = QString::number(query->getCumulgb());
    memcpy(pckInBlock->cumulgb, cumulgb.toLocal8Bit(), sizeof(pckInBlock->cumulgb));
    return pckInBlock;
}

void T1702Handler::handleT1702OutBlock(LPRECV_PACKET packet)
{
    T1702Query* query = getQuery(packet->nRqID);
    LPt1702OutBlock outblock = (LPt1702OutBlock)packet->lpData;
    QDate cts_date = QDate::fromString(QString::fromLocal8Bit(outblock->cts_date, sizeof(outblock->cts_date)), "yyyyMMdd");
    QString cts_idx = QString::fromLocal8Bit(outblock->cts_idx, sizeof(outblock->cts_idx));
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
        QDate date = QDate::fromString(QString::fromLocal8Bit(pOutBlock->date, sizeof(pOutBlock->date)), "yyyyMMdd");
        if(date<query->getFromDate()){
            return true;
        }
        T1702Item* item = new T1702Item(query);
        item->setDate(date);
        item->setClose(changeStringToLong(pOutBlock->close, sizeof(pOutBlock->close)));
        if(pOutBlock->sign[0]=='2')
            item->setSign(T1702Item::SIGN(2));
        else if(pOutBlock->sign[1]=='5')
            item->setSign(T1702Item::SIGN(5));
        item->setChange(changeStringToLong(pOutBlock->change, sizeof(pOutBlock->change)));
        item->setDiff(changeStringToFloat(pOutBlock->diff, sizeof(pOutBlock->diff)));
        item->setVolume(changeStringToLong(pOutBlock->volume, sizeof(pOutBlock->volume)));
        item->setAmt0000(changeStringToLong(pOutBlock->amt0000, sizeof(pOutBlock->amt0000)));
        item->setAmt0001(changeStringToLong(pOutBlock->amt0001, sizeof(pOutBlock->amt0001)));
        item->setAmt0002(changeStringToLong(pOutBlock->amt0002, sizeof(pOutBlock->amt0002)));
        item->setAmt0003(changeStringToLong(pOutBlock->amt0003, sizeof(pOutBlock->amt0003)));
        item->setAmt0004(changeStringToLong(pOutBlock->amt0004, sizeof(pOutBlock->amt0004)));
        item->setAmt0005(changeStringToLong(pOutBlock->amt0005, sizeof(pOutBlock->amt0005)));
        item->setAmt0006(changeStringToLong(pOutBlock->amt0006, sizeof(pOutBlock->amt0006)));
        item->setAmt0007(changeStringToLong(pOutBlock->amt0007, sizeof(pOutBlock->amt0007)));
        item->setAmt0008(changeStringToLong(pOutBlock->amt0008, sizeof(pOutBlock->amt0008)));
        item->setAmt0009(changeStringToLong(pOutBlock->amt0009, sizeof(pOutBlock->amt0009)));
        item->setAmt0010(changeStringToLong(pOutBlock->amt0010, sizeof(pOutBlock->amt0010)));
        item->setAmt0011(changeStringToLong(pOutBlock->amt0011, sizeof(pOutBlock->amt0011)));
        item->setAmt0018(changeStringToLong(pOutBlock->amt0018, sizeof(pOutBlock->amt0018)));
        item->setAmt0088(changeStringToLong(pOutBlock->amt0088, sizeof(pOutBlock->amt0088)));
        item->setAmt0099(changeStringToLong(pOutBlock->amt0099, sizeof(pOutBlock->amt0099)));
        query->addT1702Item(item);
    }
    t1702InBlock* pckInBlock = makeT1702InBlock(trQuery);
    memset(pckInBlock->cts_date, query->getCtsDate().toString("yyyyMMdd").toLocal8Bit(), sizeof(pckInBlock->cts_date));
    memset(pckInBlock->cts_idx, query->getCtsIdx().toLocal8Bit(), sizeof(pckInBlock->cts_idx));
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

