#ifndef TRHANDLER_H
#define TRHANDLER_H

#include <QObject>
#include <QThread>
#include <QMap>
#include "xing/xaquery.h"
#include "tr/trquery.h"
template < typename T >
class TrHandler : public QObject
{
    Q_OBJECT;
public:
    explicit TrHandler(QObject *parent=0);
    ~TrHandler();
protected:
    long changeStringToLong(char * strLong, int length);
    virtual int sendRequest(T query)=0;
    void printLog(const QString& log);
    QMap<int,T> mQueryMap;
private:

public slots:
    virtual void addTrQuery(T query);
    virtual void dataReceived(LPRECV_PACKET packet)=0;
    virtual void messageReceived(LPMSG_PACKET packet)=0;
    virtual void errorReceived(LPMSG_PACKET packet)=0;
    virtual void releaseReceived(int reqId)=0;
};

#endif // TRHANDLER_H
