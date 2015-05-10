#include "t8430.h"

T8430::T8430(const QWidget &widget, MODE mode, QObject *parent) : TrQuery(widget, parent),m_mode(mode)
{

}

T8430::~T8430()
{

}

void T8430::sendRequest()
{
    t8430InBlock pckInBlock;
    memset(&pckInBlock, ' ', sizeof(pckInBlock));

    switch(m_mode) {
    case ALL:
        memcpy(pckInBlock.gubun, "0", sizeof(pckInBlock.gubun));
        break;
    case KOSPI:
        memcpy(pckInBlock.gubun, "1", sizeof(pckInBlock.gubun));
        break;
    case KOSDAQ:
        memcpy(pckInBlock.gubun, "2", sizeof(pckInBlock.gubun));
        break;
    }

    IXingAPI::GetInstance()->request(m_hwnd, NAME_t8430, &pckInBlock, sizeof(pckInBlock), FALSE, " ", -1);

}

void T8430::responseReceived(LPRECV_PACKET packet)
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
    emit workDone(itemList);
}

