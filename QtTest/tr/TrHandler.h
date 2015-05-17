#ifndef TRHANDLER_H
#define TRHANDLER_H

#include <QObjec>
#include <QThread>
#include <xing/xaquery.h>
#include <tr/trquery.h>
class TrHandler : public QObject
{
    Q_OBJECT;
public:
    explicit TrHandler(QObject *parent=0);
    ~TrHandler();
protected:
    long changeStringToLong(char * strLong, int length);
    virtual int sendRequest()=0;
private:

public slots:
    virtual void addTrQuery(TrQuery& query);
    virtual void dataReceived(LPRECV_PACKET packet)=0;
    virtual void messageReceived(LPMSG_PACKET packet)=0;
    virtual void errorReceived(LPMSG_PACKET packet)=0;
    virtual void releaseReceived(int requestId)=0;
    virtual bool hasMoreRequest()=0;
};

#endif // TRHANDLER_H
