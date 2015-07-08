#ifndef T1102HANDLER_H
#define T1102HANDLER_H

#include <QObject>
#include "tr/trhandler.h"
#include "tr/t1102/t1102query.h"

class T1102Handler : public TrHandler
{
    Q_OBJECT
public:
    explicit T1102Handler(QObject *parent=0);
    ~T1102Handler();
protected:
    virtual int sendRequest(TrQuery* trQuery);
    virtual T1102Query *getQuery(int reqId) override;

public slots:
    virtual void dataReceived(LPRECV_PACKET packet);
};

#endif // T1102HANDLER_H
