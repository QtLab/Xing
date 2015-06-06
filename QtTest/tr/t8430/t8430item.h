#ifndef T8430ITEM_H
#define T8430ITEM_H

#include <QObject>
#include <QList>
#include <QString>
#include "tr/tritem.h"
#include "tr/t8430/t8430.h"
class T8430Item : public TrItem
{
    Q_OBJECT
    Q_PROPERTY(QString hname MEMBER mHname READ hname)
    Q_PROPERTY(QString shcode MEMBER mShcode READ shcode)
    Q_PROPERTY(QString expcode MEMBER mExpcode READ expcode)
    Q_PROPERTY(bool isETF MEMBER bIsETF READ isETF)
    Q_PROPERTY(long uplmtprice MEMBER mUplmtprice READ uplmtprice)
    Q_PROPERTY(long dnlmtprice MEMBER mDnlmtprice READ dnlmtprice)
    Q_PROPERTY(long jniclose MEMBER mJniclose READ jniclose)
    Q_PROPERTY(QString memedan MEMBER mMemedan READ memedan)
    Q_PROPERTY(long recprice MEMBER mRecprice READ recprice)
    Q_PROPERTY(bool isKOSPI MEMBER bIsKOSPI READ isKOSPI)

public:
    explicit T8430Item(LPt8430OutBlock outblock, QObject *parent=0);
    ~T8430Item();

    QString hname() {return mHname;}
    QString shcode() { return mShcode;}
    QString expcode() { return mExpcode;}
    bool isETF() { return bIsETF;}
    long uplmtprice() { return mUplmtprice;}
    long dnlmtprice() { return mDnlmtprice; }
    long jniclose() { return mJniclose; }
    QString memedan() { return mMemedan;}
    long recprice() { return mRecprice; }
    bool isKOSPI() { return bIsKOSPI;}

private:
    QString mHname;     //종목명
    QString mShcode;    //단축코드
    QString mExpcode;   //확장코드
    bool bIsETF;        //ETF구분
    long mUplmtprice;   //상한가
    long mDnlmtprice;   //하한가
    long mJniclose;     //전일가
    QString mMemedan;   //주문수량단위
    long mRecprice;     //기준가
    bool bIsKOSPI;      //구분(1:코스피2:코스닥)
};

#endif // T8430ITEM_H
