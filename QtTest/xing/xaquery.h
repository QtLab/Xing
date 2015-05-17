#ifndef XAQUERY_H
#define XAQUERY_H

#include <QObject>
#include <QMap>
#include <QThread>
#include "xing/IXingAPI.h"
#include "tr/TrHandler.h"

class XAQuery : public QThread
{
    Q_OBJECT
public:
    XAQuery();
    ~XAQuery();

protected:

private:
    QMap<int, TrHandler*> mQueryMap;

signals:

public slots:
    void requestQuery(TrHandler* query);
    void dataReceived(LPRECV_PACKET packet);
    void messageReceived(LPMSG_PACKET packet);
    void errorReceived(LPMSG_PACKET packet);
    void releaseReceived(int requestId);
};

#endif // XAQUERY_H
