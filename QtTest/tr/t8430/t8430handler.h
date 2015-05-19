#ifndef T8430HANDLER_H
#define T8430HANDLER_H

#include <QObject>
#include "tr/t8430/t8430query.h"
class T8430Handler : public TrHandler
{
    Q_OBJECT
public:
    explicit T8430Handler(QObject *parent = 0);
    ~T8430Handler();

protected:
    virtual int sendRequest(TrQuery* query);
    virtual T8430Query* getQuery(int reqId) override;

public slots:
    virtual void dataReceived(LPRECV_PACKET packet);
    virtual void messageReceived(LPMSG_PACKET packet);
    virtual void errorReceived(LPMSG_PACKET packet);
    virtual void releaseReceived(int reqId);
};

#endif // T8430HANDLER_H
