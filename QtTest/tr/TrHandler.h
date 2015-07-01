#ifndef TRHANDLER_H
#define TRHANDLER_H

#include <QObject>
#include <QThread>
#include <QMap>
#include <QDate>
#include "xing/xaquery.h"
#include "tr/trquery.h"


class TrHandler : public QObject
{
    Q_OBJECT;
public:
    explicit TrHandler(QObject *parent=0);
    ~TrHandler();
protected:
    virtual int sendRequest(TrQuery* query)=0;
    virtual TrQuery* getQuery(int reqId) = 0;
    void printLog(const QString& log);
    void changeReqId(int fromId, int toId);
    QMap<int,TrQuery*> mQueryMap;
private:

public slots:

    virtual void addTrQuery(TrQuery* query);
    virtual void dataReceived(LPRECV_PACKET packet)=0;
    virtual void messageReceived(LPMSG_PACKET packet);
    virtual void errorReceived(LPMSG_PACKET packet);
    virtual void releaseReceived(int reqId);

signals:
    void postRequest(HWND hWnd, LPCTSTR pszCode, LPVOID lpData, int nDataSize, BOOL bNext=FALSE, const char* pszNextKey="", int nTimeOut=30);
};

#endif // TRHANDLER_H
