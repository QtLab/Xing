#ifndef T8430ITEM_H
#define T8430ITEM_H

#include <QObject>
#include <QList>
#include <QString>
#include "../Src/tr/tritem.h"
#include "../Src/tr/t8430/t8430.h"
class T8430Item : public TrItem
{
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
    virtual QList<QString> getPropertyList() override;
    virtual QList<QString> getPropertyNameList() override;
    virtual QString getPropertyByName(const QString& name) override;
private:
    QString mHname;
    QString mShcode;
    QString mExpcode;
    bool bIsETF;
    long mUplmtprice;
    long mDnlmtprice;
    long mJniclose;
    QString mMemedan;
    long mRecprice;
    bool bIsKOSPI;
};

#endif // T8430ITEM_H
