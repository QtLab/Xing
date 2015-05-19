#ifndef T8430ITEM_H
#define T8430ITEM_H

#include <QObject>
#include <QString>
class T8430Item
{
    Q_OBJECT
    Q_PROPERTY(QString mHname READ hname WRITE setHName)
    Q_PROPERTY(QString mShcode READ shcode WRITE setShcode)
    Q_PROPERTY(QString mExpcode READ expcode WRITE setExpcode)
    Q_PROPERTY(bool bIsETF READ isETF WRITE setAsETF)
    Q_PROPERTY(long mUplmtprice READ uplmtprice WRITE setUplmtprice)
    Q_PROPERTY(long mDnlmtprice READ dnlmtprice WRITE setDnlmtprice)
    Q_PROPERTY(long mJniclose READ jniclose WRITE setJniclose)
    Q_PROPERTY(QString mMemedan READ memedan WRITE setMemedan)
    Q_PROPERTY(long mRecprice READ recprice WRITE setRecprice)
    Q_PROPERTY(bool bIsKOSPI READ isKOSPI WRITE setAsKOSPI)

public:
    T8430Item();
    ~T8430Item();

    QString hname() {return mHname;}
    void setHName(const QString& hname) {mHname=hname;}

    QString shcode() { return mShcode;}
    void setShcode(const QString& shcode){mShcode = shcode;}

    QString expcode() { return mExpCode;}
    void setExpCode(const QString& expcode) {mExpcode = expcode;}

    bool isETF() { return bIsETF;}
    void setAsETF(bool etf){ bIsETF = etf;}

    long uplmtprice() { return mUplmtprice;}
    void setUplmtprice(long price) {mUplmtprice = price;}

    long dnlmtprice() { return mDnlmtprice; }
    void setDnlmtprice(long price) { mDnlmtprice = price;}

    long jniclose() { return mJniclose; }
    void setJniclose(long jniclose) { mJniclose = jniclose;}

    QString memedan() { return mMemedan;}
    void setMemedan(const QString& memedan) { mMemedan = memedan;}

    long recprice() { return mRecprice; }
    void setRecprice(long recprice){ mRecprice = recprice;}

    bool isKOSPI() { return bIsKOSPI;}
    void setAsKOSPI(bool isKospi) { bIsKOSPI = isKospi;}

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
