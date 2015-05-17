#ifndef XAQUERY_H
#define XAQUERY_H

#include <QObject>
#include <QMap>
#include <QThread>
#include "xing/IXingAPI.h"
#include "tr/TrQuery.h"

class XAQuery : public QObject
{
    Q_OBJECT
public:
    XAQuery();
    ~XAQuery();

protected:

private:
    QMap<int, TrQuery*> mQueryMap;

signals:

public slots:
    void requestQuery(TrQuery* query);
    void dataReceived(LPRECV_PACKET packet);
    void messageReceived(LPMSG_PACKET packet);
    void errorReceived(LPMSG_PACKET packet);
    void releaseReceived(int requestId);
};

#endif // XAQUERY_H
