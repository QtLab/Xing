#ifndef T1537ITEM
#define T1537ITEM

#include <QObject>
#include <QString>
#include <QDate>
#include "tr/tritem.h"
class T1537Item : public TrItem
{
	Q_OBJECT
	Q_PROPERTY(QString hname MEMBER _hname READ hname WRITE setHname)		//�����
	Q_PROPERTY(long price MEMBER _price READ price WRITE setPrice)		//���簡
	Q_PROPERTY(QString sign MEMBER _sign READ sign WRITE setSign)		//���ϴ�񱸺�
	Q_PROPERTY(long change MEMBER _change READ change WRITE setChange)		//���ϴ��
	Q_PROPERTY(float diff MEMBER _diff READ diff WRITE setDiff)		//�����
	Q_PROPERTY(long volume MEMBER _volume READ volume WRITE setVolume)		//�����ŷ���
	Q_PROPERTY(QTime jniltime MEMBER _jniltime READ jniltime WRITE setJniltime)		//���ϵ��ð�
	Q_PROPERTY(QString shcode MEMBER _shcode READ shcode WRITE setShcode)		//�����ڵ�
	Q_PROPERTY(long yeprice MEMBER _yeprice READ yeprice WRITE setYeprice)		//����ü�ᰡ
	Q_PROPERTY(long open MEMBER _open READ open WRITE setOpen)		//�ð�
	Q_PROPERTY(long high MEMBER _high READ high WRITE setHigh)		//��
	Q_PROPERTY(long low MEMBER _low READ low WRITE setLow)		//����
	Q_PROPERTY(long value MEMBER _value READ value WRITE setValue)		//�����ŷ����(����:�鸸)
	Q_PROPERTY(long marketcap MEMBER _marketcap READ marketcap WRITE setMarketcap)		//�ð��Ѿ�(����:�鸸)
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
	QString _hname;		//�����
	long _price;		//���簡
	QString _sign;		//���ϴ�񱸺�
	long _change;		//���ϴ��
	float _diff;		//�����
	long _volume;		//�����ŷ���
	QTime _jniltime;		//���ϵ��ð�
	QString _shcode;		//�����ڵ�
	long _yeprice;		//����ü�ᰡ
	long _open;		//�ð�
	long _high;		//��
	long _low;		//����
	long _value;		//�����ŷ����(����:�鸸)
	long _marketcap;		//�ð��Ѿ�(����:�鸸)
};

#endif //T1537ITEM
