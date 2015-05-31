#ifndef T1702HANDLER_H
#define T1702HANDLER_H

#include <QObject>
#include "tr/t1702/t1702.h"
#include "tr/TrHandler.h"
#include "tr/TrQuery.h"
#include "tr/t1702/t1702query.h"
class T1702Handler : public TrHandler
{
    Q_OBJECT
public:
    explicit T1702Handler(QObject *parent=0);
    ~T1702Handler();

protected:
    virtual int sendRequest(TrQuery* trQuery);
    virtual T1702Query *getQuery(int reqId) override;
    t1702InBlock* makeT1702InBlock(TrQuery* trQuery);
    void handleT1702OutBlock(LPRECV_PACKET packet);
    bool handleT1702OutBlock1(LPRECV_PACKET packet);

public slots:
    virtual void dataReceived(LPRECV_PACKET packet);
};

#endif // T1702HANDLER_H
