#ifndef T8430ITEM
#define T8430ITEM

#include <QObject>
#include <QString>
#include <QDate>
#include "tr/tritem.h"
class T8430Item : public TrItem
{
	Q_OBJECT
	Q_PROPERTY(QString hname MEMBER _hname READ hname WRITE setHname)		//�����
	Q_PROPERTY(QString shcode MEMBER _shcode READ shcode WRITE setShcode)		//�����ڵ�
	Q_PROPERTY(QString expcode MEMBER _expcode READ expcode WRITE setExpcode)		//Ȯ���ڵ�
	Q_PROPERTY(QString etfgubun MEMBER _etfgubun READ etfgubun WRITE setEtfgubun)		//ETF����(1:ETF)
	Q_PROPERTY(long uplmtprice MEMBER _uplmtprice READ uplmtprice WRITE setUplmtprice)		//���Ѱ�
	Q_PROPERTY(long dnlmtprice MEMBER _dnlmtprice READ dnlmtprice WRITE setDnlmtprice)		//���Ѱ�
	Q_PROPERTY(long jnilclose MEMBER _jnilclose READ jnilclose WRITE setJnilclose)		//���ϰ�
	Q_PROPERTY(QString memedan MEMBER _memedan READ memedan WRITE setMemedan)		//�ֹ���������
	Q_PROPERTY(long recprice MEMBER _recprice READ recprice WRITE setRecprice)		//���ذ�
	Q_PROPERTY(QString gubun MEMBER _gubun READ gubun WRITE setGubun)		//����(1:�ڽ���2:�ڽ���)
public:
	explicit T8430Item(QObject *parent=0);
	~T8430Item();
	virtual QString toString();
	QString hname() { return _hname; }
	void setHname(QString hname) { _hname = hname; }
	QString shcode() { return _shcode; }
	void setShcode(QString shcode) { _shcode = shcode; }
	QString expcode() { return _expcode; }
	void setExpcode(QString expcode) { _expcode = expcode; }
	QString etfgubun() { return _etfgubun; }
	void setEtfgubun(QString etfgubun) { _etfgubun = etfgubun; }
	long uplmtprice() { return _uplmtprice; }
	void setUplmtprice(long uplmtprice) { _uplmtprice = uplmtprice; }
	long dnlmtprice() { return _dnlmtprice; }
	void setDnlmtprice(long dnlmtprice) { _dnlmtprice = dnlmtprice; }
	long jnilclose() { return _jnilclose; }
	void setJnilclose(long jnilclose) { _jnilclose = jnilclose; }
	QString memedan() { return _memedan; }
	void setMemedan(QString memedan) { _memedan = memedan; }
	long recprice() { return _recprice; }
	void setRecprice(long recprice) { _recprice = recprice; }
	QString gubun() { return _gubun; }
	void setGubun(QString gubun) { _gubun = gubun; }
private:
	QString _hname;		//�����
	QString _shcode;		//�����ڵ�
	QString _expcode;		//Ȯ���ڵ�
	QString _etfgubun;		//ETF����(1:ETF)
	long _uplmtprice;		//���Ѱ�
	long _dnlmtprice;		//���Ѱ�
	long _jnilclose;		//���ϰ�
	QString _memedan;		//�ֹ���������
	long _recprice;		//���ذ�
	QString _gubun;		//����(1:�ڽ���2:�ڽ���)
};

#endif //T8430ITEM
