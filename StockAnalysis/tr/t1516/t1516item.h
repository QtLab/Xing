#ifndef T1516ITEM
#define T1516ITEM

#include <QObject>
#include <QString>
#include <QDate>
#include "tr/tritem.h"
class T1516Item : public TrItem
{
	Q_OBJECT
	Q_PROPERTY(QString hname MEMBER _hname READ hname WRITE setHname)		//종목명
	Q_PROPERTY(long price MEMBER _price READ price WRITE setPrice)		//현재가
	Q_PROPERTY(QString sign MEMBER _sign READ sign WRITE setSign)		//전일대비구분
	Q_PROPERTY(long change MEMBER _change READ change WRITE setChange)		//전일대비
	Q_PROPERTY(float diff MEMBER _diff READ diff WRITE setDiff)		//등락율
	Q_PROPERTY(long volume MEMBER _volume READ volume WRITE setVolume)		//누적거래량
	Q_PROPERTY(long open MEMBER _open READ open WRITE setOpen)		//시가
	Q_PROPERTY(long high MEMBER _high READ high WRITE setHigh)		//고가
	Q_PROPERTY(long low MEMBER _low READ low WRITE setLow)		//저가
	Q_PROPERTY(float sojinrate MEMBER _sojinrate READ sojinrate WRITE setSojinrate)		//소진율
	Q_PROPERTY(float beta MEMBER _beta READ beta WRITE setBeta)		//베타계수
	Q_PROPERTY(float perx MEMBER _perx READ perx WRITE setPerx)		//PER
	Q_PROPERTY(long frgsvolume MEMBER _frgsvolume READ frgsvolume WRITE setFrgsvolume)		//외인순매수
	Q_PROPERTY(long orgsvolume MEMBER _orgsvolume READ orgsvolume WRITE setOrgsvolume)		//기관순매수
	Q_PROPERTY(float diff_vol MEMBER _diff_vol READ diff_vol WRITE setDiff_Vol)		//거래증가율
	Q_PROPERTY(QString shcode MEMBER _shcode READ shcode WRITE setShcode)		//종목코드
	Q_PROPERTY(long total MEMBER _total READ total WRITE setTotal)		//시가총액
	Q_PROPERTY(long value MEMBER _value READ value WRITE setValue)		//거래대금
public:
	explicit T1516Item(QObject *parent=0);
	~T1516Item();
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
	long open() { return _open; }
	void setOpen(long open) { _open = open; }
	long high() { return _high; }
	void setHigh(long high) { _high = high; }
	long low() { return _low; }
	void setLow(long low) { _low = low; }
	float sojinrate() { return _sojinrate; }
	void setSojinrate(float sojinrate) { _sojinrate = sojinrate; }
	float beta() { return _beta; }
	void setBeta(float beta) { _beta = beta; }
	float perx() { return _perx; }
	void setPerx(float perx) { _perx = perx; }
	long frgsvolume() { return _frgsvolume; }
	void setFrgsvolume(long frgsvolume) { _frgsvolume = frgsvolume; }
	long orgsvolume() { return _orgsvolume; }
	void setOrgsvolume(long orgsvolume) { _orgsvolume = orgsvolume; }
	float diff_vol() { return _diff_vol; }
	void setDiff_Vol(float diff_vol) { _diff_vol = diff_vol; }
	QString shcode() { return _shcode; }
	void setShcode(QString shcode) { _shcode = shcode; }
	long total() { return _total; }
	void setTotal(long total) { _total = total; }
	long value() { return _value; }
	void setValue(long value) { _value = value; }
private:
	QString _hname;		//종목명
	long _price;		//현재가
	QString _sign;		//전일대비구분
	long _change;		//전일대비
	float _diff;		//등락율
	long _volume;		//누적거래량
	long _open;		//시가
	long _high;		//고가
	long _low;		//저가
	float _sojinrate;		//소진율
	float _beta;		//베타계수
	float _perx;		//PER
	long _frgsvolume;		//외인순매수
	long _orgsvolume;		//기관순매수
	float _diff_vol;		//거래증가율
	QString _shcode;		//종목코드
	long _total;		//시가총액
	long _value;		//거래대금
};

#endif //T1516ITEM
