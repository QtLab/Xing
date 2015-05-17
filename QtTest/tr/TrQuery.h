#ifndef TRHANDLER_H
#define TRHANDLER_H

#include <QObjec>
#include <QThread>
#include <xing/xaquery.h>
class TrQuery : public QObject
{
    Q_OBJECT;
public:
    explicit TrQuery(const QWidget& widget, QObject *parent=0);
    ~TrQuery();
protected:
    long changeStringToLong(char * strLong, int length);
    const HWND m_hwnd;
private:

public slots:
    virtual int sendRequest()=0;
    virtual void dataReceived(LPRECV_PACKET packet)=0;
    virtual void messageReceived(LPMSG_PACKET packet)=0;
    virtual void errorReceived(LPMSG_PACKET packet)=0;
    virtual void releaseReceived(int requestId)=0;
    virtual bool hasMoreRequest()=0;
};

#endif // TRHANDLER_H
