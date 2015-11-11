#ifndef T8413ITEM_H
#define T8413ITEM_H

#include "core/tr/tritem.h"
#include <QDate>
class T8413Item : public TrItem
{
Q_OBJECT
	Q_PROPERTY(QDate date MEMBER _date READ date WRITE setDate)		//날짜
	Q_PROPERTY(long open MEMBER _open READ open WRITE setOpen)		//시가
	Q_PROPERTY(long high MEMBER _high READ high WRITE setHigh)		//고가
	Q_PROPERTY(long low MEMBER _low READ low WRITE setLow)		//저가
	Q_PROPERTY(long close MEMBER _close READ close WRITE setClose)		//종가
	Q_PROPERTY(long jdiff_vol MEMBER _jdiff_vol READ jdiff_vol WRITE setJdiff_Vol)		//거래량
	Q_PROPERTY(long value MEMBER _value READ value WRITE setValue)		//거래대금
	Q_PROPERTY(long jongchk MEMBER _jongchk READ jongchk WRITE setJongchk)		//수정구분
	Q_PROPERTY(double rate MEMBER _rate READ rate WRITE setRate)		//수정비율
	Q_PROPERTY(long pricechk MEMBER _pricechk READ pricechk WRITE setPricechk)		//수정주가반영항목
	Q_PROPERTY(long ratevalue MEMBER _ratevalue READ ratevalue WRITE setRatevalue)		//수정비율반영거래대금
	Q_PROPERTY(QString sign MEMBER _sign READ sign WRITE setSign)		//종가등락구분(1:상한2:상승3:보합4:하한5:하락주식일만사용)
public:
	explicit T8413Item(QObject *parent=0);
	~T8413Item();
	QDate date() { return _date; }
	void setDate(QDate date) { _date = date; }
	long open() { return _open; }
	void setOpen(long open) { _open = open; }
	long high() { return _high; }
	void setHigh(long high) { _high = high; }
	long low() { return _low; }
	void setLow(long low) { _low = low; }
	long close() { return _close; }
	void setClose(long close) { _close = close; }
	long jdiff_vol() { return _jdiff_vol; }
	void setJdiff_Vol(long jdiff_vol) { _jdiff_vol = jdiff_vol; }
	long value() { return _value; }
	void setValue(long value) { _value = value; }
	long jongchk() { return _jongchk; }
	void setJongchk(long jongchk) { _jongchk = jongchk; }
	double rate() { return _rate; }
	void setRate(double rate) { _rate = rate; }
	long pricechk() { return _pricechk; }
	void setPricechk(long pricechk) { _pricechk = pricechk; }
	long ratevalue() { return _ratevalue; }
	void setRatevalue(long ratevalue) { _ratevalue = ratevalue; }
	QString sign() { return _sign; }
	void setSign(QString sign) { _sign = sign; }
private:
	QDate _date;		//날짜
	long _open;		//시가
	long _high;		//고가
	long _low;		//저가
	long _close;		//종가
	long _jdiff_vol;		//거래량
	long _value;		//거래대금
	long _jongchk;		//수정구분
	double _rate;		//수정비율
	long _pricechk;		//수정주가반영항목
	long _ratevalue;		//수정비율반영거래대금
	QString _sign;		//종가등락구분(1:상한2:상승3:보합4:하한5:하락주식일만사용)
};

#endif //T8413ITEM_H
