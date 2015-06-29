#include "t8430handler.h"
#include "util/fieldutil.h"
T8430Handler::T8430Handler(QObject *parent) : TrHandler(parent)
{

}

T8430Handler::~T8430Handler()
{

}

int T8430Handler::sendRequest(TrQuery* trQuery)
{
    T8430Query* query = static_cast<T8430Query*>(trQuery);
    t8430InBlock pckInBlock;
    INIT_BLOCK(&pckInBlock,sizeof(t8430InBlock));

    switch(query->getMode()) {
    case T8430Query::ALL:
        SET_FIELD(pckInBlock.gubun, "0");
        break;
    case T8430Query::KOSPI:
        SET_FIELD(pckInBlock.gubun, "1");
        break;
    case T8430Query::KOSDAQ:
        SET_FIELD(pckInBlock.gubun, "2");
        break;
    }

    return IXingAPI::GetInstance()->Request(query->getHWnd(), NAME_t8430, &pckInBlock, sizeof(pckInBlock), FALSE, " ", -1);
}

T8430Query *T8430Handler::getQuery(int reqId)
{
    return static_cast<T8430Query*>(mQueryMap.value(reqId));
}

void T8430Handler::dataReceived(LPRECV_PACKET packet)
{
    LPt8430OutBlock pOutBlock;
    QList<T8430Item*> itemList;
    T8430Query* query = getQuery(packet->nRqID);
    int numOfItem = packet->nDataLength/sizeof(t8430OutBlock);
    for(int i = 0; i<numOfItem; i++) {
        pOutBlock = (LPt8430OutBlock)(packet->lpData + (sizeof(t8430OutBlock) * i)); //데이터를 가져오기 위한 Block을 설장한다.
        T8430Item* item = new T8430Item(pOutBlock, query);
        itemList.push_back(item);
    }
    query->setFinished();
    emit query->workDone(itemList);
}

