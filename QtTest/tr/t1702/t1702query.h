#ifndef T1702QUERY_H
#define T1702QUERY_H

#include <QObject>
#include "tr/TrQuery.h"
#include "tr/t1702/t1702item.h"
class T1702Query : public TrQuery
{
    Q_OBJECT
public:
    typedef enum {AMOUNT_OF_MONEY=0, QUANTITY=1, PRICE=2} REQUEST_UNIT; //금액, 수량, 단가
    typedef enum {NET_BUY=0, BUY=1, SELL=2} REQUEST_TYPE; //순매수, 매수, 매도
    typedef enum {DAILY=0, CUMULATIVE=1} REQUEST_OPTION; //누적, 일간
    ~T1702Query();
    static T1702Query *createQuery(const QWidget& requester
                                   , const QString& shcode, const QDate& todt,
                                   REQUEST_UNIT unit, REQUEST_TYPE type, REQUEST_OPTION option, QObject *parent=0
                                   );
protected:
    explicit T1702Query(const QWidget& requester,const QString& shcode, const QDate& todt,
                        REQUEST_UNIT unit, REQUEST_TYPE type, REQUEST_OPTION option, QObject *parent=0);

    QString getShcode();
    QDate getDate();
    REQUEST_UNIT getUnit();
    REQUEST_TYPE getType();
    REQUEST_OPTION getOption();

private:
    QString mShcode;
    QDate mToDate;

    REQUEST_UNIT mUnit;
    REQUEST_TYPE mType;
    REQUEST_OPTION mOption;

signals:
    void workDone(QList<T1702Item*> list);
};

#endif // T1702QUERY_H
