#ifndef T1702QUERY_H
#define T1702QUERY_H

#include <QObject>
#include <QString>
#include <QDate>

#include "tr/trquery.h"
#include "tr/t1702/t1702item.h"
class T1702Query : public TrQuery
{
    Q_OBJECT
    Q_PROPERTY(QString shcode MEMBER _shcode READ shcode)
    Q_PROPERTY(QDate todt MEMBER _todt READ todt)
    Q_PROPERTY(QString volvalgb MEMBER _volvalgb READ volvalgb)
    Q_PROPERTY(QString msmdgb MEMBER _msmdgb READ msmdgb)
    Q_PROPERTY(QString cumulgb MEMBER _cumulgb READ cumulgb)
    Q_PROPERTY(long cts_idx MEMBER _cts_idx READ cts_idx)
    Q_PROPERTY(QString cts_date MEMBER _cts_date READ cts_date)

public:
    typedef enum { AMOUNT_OF_MONEY=0, AMOUNT=1, PRICE=2 } T1702_UNIT; //0:금액, 1: 수량, 2: 단가
    typedef enum { PURE_BUY=0, BUY=1, SELL=2 } T1702_TYPE;	//0:순매수, 1:매수, 2:매도
    typedef enum { DAILY=0, CUMUL=1 } T1702_CUMUL_TYPE; 	//0:일간, 1:누적

    static T1702Query *createQuery(const QString& shcode=tr("005930"), const QDate& fromdate = QDate(2014,7,17), const QDate& todate=QDate(2015,7,17), T1702_UNIT unit=AMOUNT, T1702_TYPE type=PURE_BUY, T1702_CUMUL_TYPE cumul = DAILY, QObject* parent = 0);

    ~T1702Query();
    QString shcode() {
        return _shcode;
    }
    QDate todt() {
        return _todt;
    }
    QString volvalgb() {
        return _volvalgb;
    }
    QString msmdgb() {
        return  _msmdgb;
    }
    QString cumulgb() {
        return _cumulgb;
    }
    long cts_idx() {
        return _cts_idx;
    }
    QString cts_date() {
        return _cts_date;
    }
    virtual QString toString() override;
    QList<T1702Item *> getResult();
protected:
    explicit T1702Query(QObject *parent = 0);
    virtual T1702Item *createItem() override;
signals:
public slots:
    virtual void onReceiveData(const QString& trCode);
    virtual void onReceiveChartRealData(const QString& trCode);

private:
    QString _shcode;
    QDate _todt;
    QDate _fromdate;
    QString _volvalgb;
    QString _msmdgb;
    QString _cumulgb;
    long _cts_idx;
    QString _cts_date;
    QList<T1702Item*> mItemList;
};

#endif // T1702QUERY_H
