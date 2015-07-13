#ifndef T8430ITEM_H
#define T8430ITEM_H

#include <QObject>
#include <QList>
#include <QString>
#include "tr/tritem.h"
class T8430Item : public TrItem
{
    Q_OBJECT
    Q_PROPERTY(QString hname MEMBER _hname READ hname)
    Q_PROPERTY(QString shcode MEMBER _shcode READ shcode)
    Q_PROPERTY(QString expcode MEMBER _expcode READ expcode)
    Q_PROPERTY(bool isETF MEMBER _isETF READ isETF)
    Q_PROPERTY(long uplmtprice MEMBER _uplmtprice READ uplmtprice)
    Q_PROPERTY(long dnlmtprice MEMBER _dnlmtprice READ dnlmtprice)
    Q_PROPERTY(long jniclose MEMBER _jniclose READ jniclose)
    Q_PROPERTY(QString memedan MEMBER _memedan READ memedan)
    Q_PROPERTY(long recprice MEMBER _recprice READ recprice)
    Q_PROPERTY(bool isKOSPI MEMBER _isKOSPI READ isKOSPI)

public:
    explicit T8430Item(QObject *parent=0);
    ~T8430Item();

    QString hname() {return _hname;}
    QString shcode() { return _shcode;}
    QString expcode() { return _expcode;}
    bool isETF() { return _isETF;}
    long uplmtprice() { return _uplmtprice;}
    long dnlmtprice() { return _dnlmtprice; }
    long jniclose() { return _jniclose; }
    QString memedan() { return _memedan;}
    long recprice() { return _recprice; }
    bool isKOSPI() { return _isKOSPI;}

private:
    QString _hname;     //종목명
    QString _shcode;    //단축코드
    QString _expcode;   //확장코드
    bool _isETF;        //ETF구분
    long _uplmtprice;   //상한가
    long _dnlmtprice;   //하한가
    long _jniclose;     //전일가
    QString _memedan;   //주문수량단위
    long _recprice;     //기준가
    bool _isKOSPI;      //구분(1:코스피2:코스닥)
};

#endif // T8430ITEM_H
