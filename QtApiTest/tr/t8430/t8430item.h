#ifndef T8430ITEM
#define T8430ITEM

#include <QObject>
#include <QString>
#include <QDate>
#include "tr/tritem.h"
class T8430Item : public TrItem
{
	Q_OBJECT
	Q_PROPERTY(QString hname MEMBER _hname READ hname WRITE setHname)		//종목명
	Q_PROPERTY(QString shcode MEMBER _shcode READ shcode WRITE setShcode)		//단축코드
	Q_PROPERTY(QString expcode MEMBER _expcode READ expcode WRITE setExpcode)		//확장코드
	Q_PROPERTY(QString etfgubun MEMBER _etfgubun READ etfgubun WRITE setEtfgubun)		//ETF구분(1:ETF)
	Q_PROPERTY(long uplmtprice MEMBER _uplmtprice READ uplmtprice WRITE setUplmtprice)		//상한가
	Q_PROPERTY(long dnlmtprice MEMBER _dnlmtprice READ dnlmtprice WRITE setDnlmtprice)		//하한가
	Q_PROPERTY(long jnilclose MEMBER _jnilclose READ jnilclose WRITE setJnilclose)		//전일가
	Q_PROPERTY(QString memedan MEMBER _memedan READ memedan WRITE setMemedan)		//주문수량단위
	Q_PROPERTY(long recprice MEMBER _recprice READ recprice WRITE setRecprice)		//기준가
	Q_PROPERTY(QString gubun MEMBER _gubun READ gubun WRITE setGubun)		//구분(1:코스피2:코스닥)
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
	QString _hname;		//종목명
	QString _shcode;		//단축코드
	QString _expcode;		//확장코드
	QString _etfgubun;		//ETF구분(1:ETF)
	long _uplmtprice;		//상한가
	long _dnlmtprice;		//하한가
	long _jnilclose;		//전일가
	QString _memedan;		//주문수량단위
	long _recprice;		//기준가
	QString _gubun;		//구분(1:코스피2:코스닥)
};

#endif //T8430ITEM
