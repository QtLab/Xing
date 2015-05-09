#include "t8430.h"

T8430::T8430(QObject *parent) : QObject(parent)
{

}

T8430::~T8430()
{

}

void T8430::request(const QWidget &widget, MODE mode)
{
    t8430InBlock pckInBlock;
    memset(&pckInBlock, ' ', sizeof(pckInBlock));

    switch(mode) {
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

    IXingAPI::GetInstance()->request((HWND)widget.winId(), NAME_t8430, &pckInBlock, sizeof(pckInBlock), FALSE, " ", -1);

}

void T8430::responseReceived(LPRECV_PACKET packet)
{
    LPt8430OutBlock pOutBlock;
    int numOfItem = packet->nDataLength/sizeof(t8430OutBlock);
    for(int i = 0; i<numOfItem; i++) {
        pOutBlock = (LPt8430OutBlock)(packet->lpData + (sizeof(t8430OutBlock) * i)); //데이터를 가져오기 위한 Block을 설장한다.

    }
}

