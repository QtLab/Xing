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
    QString _hname;     //�����
    QString _shcode;    //�����ڵ�
    QString _expcode;   //Ȯ���ڵ�
    bool _isETF;        //ETF����
    long _uplmtprice;   //���Ѱ�
    long _dnlmtprice;   //���Ѱ�
    long _jniclose;     //���ϰ�
    QString _memedan;   //�ֹ���������
    long _recprice;     //���ذ�
    bool _isKOSPI;      //����(1:�ڽ���2:�ڽ���)
};

#endif // T8430ITEM_H
