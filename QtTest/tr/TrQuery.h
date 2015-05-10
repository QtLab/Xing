#ifndef TRHANDLER_H
#define TRHANDLER_H

#include <QObjec>
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
    virtual void responseReceived(LPRECV_PACKET packet)=0;
};

#endif // TRHANDLER_H
