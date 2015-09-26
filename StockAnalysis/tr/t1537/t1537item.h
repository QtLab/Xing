#ifndef T1537ITEM
#define T1537ITEM

#include <QObject>
#include <QString>
#include <QDate>
#include "tr/tritem.h"
class T1537Item : public TrItem
{
	Q_OBJECT
	Q_PROPERTY(QString hname MEMBER _hname READ hname WRITE setHname)		//종목명
	Q_PROPERTY(long price MEMBER _price READ price WRITE setPrice)		//현재가
	Q_PROPERTY(QString sign MEMBER _sign READ sign WRITE setSign)		//전일대비구분
	Q_PROPERTY(long change MEMBER _change READ change WRITE setChange)		//전일대비
	Q_PROPERTY(float diff MEMBER _diff READ diff WRITE setDiff)		//등락율
	Q_PROPERTY(long volume MEMBER _volume READ volume WRITE setVolume)		//누적거래량
	Q_PROPERTY(QTime jniltime MEMBER _jniltime READ jniltime WRITE setJniltime)		//전일동시간
	Q_PROPERTY(QString shcode MEMBER _shcode READ shcode WRITE setShcode)		//종목코드
	Q_PROPERTY(long yeprice MEMBER _yeprice READ yeprice WRITE setYeprice)		//예상체결가
	Q_PROPERTY(long open MEMBER _open READ open WRITE setOpen)		//시가
	Q_PROPERTY(long high MEMBER _high READ high WRITE setHigh)		//고가
	Q_PROPERTY(long low MEMBER _low READ low WRITE setLow)		//저가
	Q_PROPERTY(long value MEMBER _value READ value WRITE setValue)		//누적거래대금(단위:백만)
	Q_PROPERTY(long marketcap MEMBER _marketcap READ marketcap WRITE setMarketcap)		//시가총액(단위:백만)
public:
	explicit T1537Item(QObject *parent=0);
	~T1537Item();
	QString hname() { return _hname; }
	void setHname(QString hname) { _hname = hname; }
	long price() { return _price; }
	void setPrice(long price) { _price = price; }
	QString sign() { return _sign; }
	void setSign(QString sign) { _sign = sign; }
	long change() { return _change; }
	void setChange(long change) { _change = change; }
	float diff() { return _diff; }
	void setDiff(float diff) { _diff = diff; }
	long volume() { return _volume; }
	void setVolume(long volume) { _volume = volume; }
	QTime jniltime() { return _jniltime; }
	void setJniltime(QTime jniltime) { _jniltime = jniltime; }
	QString shcode() { return _shcode; }
	void setShcode(QString shcode) { _shcode = shcode; }
	long yeprice() { return _yeprice; }
	void setYeprice(long yeprice) { _yeprice = yeprice; }
	long open() { return _open; }
	void setOpen(long open) { _open = open; }
	long high() { return _high; }
	void setHigh(long high) { _high = high; }
	long low() { return _low; }
	void setLow(long low) { _low = low; }
	long value() { return _value; }
	void setValue(long value) { _value = value; }
	long marketcap() { return _marketcap; }
	void setMarketcap(long marketcap) { _marketcap = marketcap; }
private:
	QString _hname;		//종목명
	long _price;		//현재가
	QString _sign;		//전일대비구분
	long _change;		//전일대비
	float _diff;		//등락율
	long _volume;		//누적거래량
	QTime _jniltime;		//전일동시간
	QString _shcode;		//종목코드
	long _yeprice;		//예상체결가
	long _open;		//시가
	long _high;		//고가
	long _low;		//저가
	long _value;		//누적거래대금(단위:백만)
	long _marketcap;		//시가총액(단위:백만)
};

#endif //T1537ITEM
