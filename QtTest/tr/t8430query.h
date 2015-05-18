#ifndef T8430QUERY_H
#define T8430QUERY_H

#include <QObject>
#include "tr/t8430.h"
#include "tr/trquery.h"
typedef struct _T8430Item
{
    QString hname;
    QString shcode;
    QString expcode;
    bool isETF;
    long uplmtprice;
    long dnlmtprice;
    long jniclose;
    QString memedan;
    long recprice;
    bool isKOSPI;
} t8430Item, *LPt8430Item;

class T8430Query : public TrQuery
{
    Q_OBJECT
public:
    typedef enum { ALL=0, KOSPI, KOSDAQ } MODE;

    static T8430Query *createQuery(const QWidget& requester,MODE mode,QObject *parent = 0);

    MODE getMode(){ return mMode;}
    ~T8430Query();
protected:
    explicit T8430Query(const QWidget& requester,QObject *parent = 0);

private:
    MODE mMode;
signals:
    void workDone(QList<LPt8430Item> list);
};

#endif // T8430QUERY_H
