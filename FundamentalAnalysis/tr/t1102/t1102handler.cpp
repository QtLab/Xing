#include "t1102handler.h"
#include "tr/t1102/t1102.h"
#include "tr/t1102/t1102item.h"
#include "util/fieldutil.h"
T1102Handler::T1102Handler(QObject *parent) : TrHandler(parent)
{

}

T1102Handler::~T1102Handler()
{

}

int T1102Handler::sendRequest(TrQuery *trQuery)
{
    T1102Query* query = qobject_cast<T1102Query*>(trQuery);
    t1102InBlock pckInBlock;
    INIT_BLOCK(&pckInBlock, sizeof(t1102InBlock));

    SET_FIELD(pckInBlock.shcode, query->getShcode());

    return IXingAPI::GetInstance()->Request(query->getHWnd(), NAME_t1102, &pckInBlock, sizeof(pckInBlock), FALSE, " ", -1);
}

T1102Query *T1102Handler::getQuery(int reqId)
{
    return qobject_cast<T1102Query*>(mQueryMap.value(reqId));
}

void T1102Handler::dataReceived(LPRECV_PACKET packet)
{
    LPt1102OutBlock pOutBlock;
    T1102Query* query = getQuery(packet->nRqID);
    pOutBlock = (LPt1102OutBlock)packet->lpData;
    T1102Item* item = new T1102Item(pOutBlock, this);
    query->setFinished();
    emit query->workDone(item);
}

