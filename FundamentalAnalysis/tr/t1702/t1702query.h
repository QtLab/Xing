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
    static T1702Query *createQuery(const QWidget* requester
                                   , const QString& shcode, const QDate& fromdt, const QDate& todt,
                                   REQUEST_UNIT unit, REQUEST_TYPE type, REQUEST_OPTION option, QObject *parent=0
                                   );
protected:
    explicit T1702Query(HWND winId, const QString& shcode,const QDate& fromdt, const QDate& todt,
                        REQUEST_UNIT unit, REQUEST_TYPE type, REQUEST_OPTION option, QObject *parent=0);

public:
    QString getShcode();
    QDate getToDate();
    QDate getFromDate();
    REQUEST_UNIT getVolvalgb();
    REQUEST_TYPE getMsmdgb();
    REQUEST_OPTION getCumulgb();
    void addT1702Item(T1702Item* item);

    void setCtsIdx(const QString& cts_idx);
    QString getCtsIdx();

    void setCtsDate(const QDate& cts_date);
    QDate getCtsDate();

    QList<T1702Item*> getResultList();

private:
    QString mShcode;
    QDate mToDate;
    QDate mFromDate;
    REQUEST_UNIT mUnit;
    REQUEST_TYPE mType;
    REQUEST_OPTION mOption;

    QString m_cts_idx;
    QDate m_cts_date;

    QList<T1702Item*> mResultList;
signals:
    void workDone(QList<T1702Item*> list);
};

#endif // T1702QUERY_H
