#ifndef T1516ITEM
#define T1516ITEM

#include <QObject>
#include <QString>
#include <QDate>
#include "tr/tritem.h"
class T1516Item : public TrItem
{
	Q_OBJECT
	Q_PROPERTY(QString hname MEMBER _hname READ hname WRITE setHname)		//�����
	Q_PROPERTY(long price MEMBER _price READ price WRITE setPrice)		//���簡
	Q_PROPERTY(QString sign MEMBER _sign READ sign WRITE setSign)		//���ϴ�񱸺�
	Q_PROPERTY(long change MEMBER _change READ change WRITE setChange)		//���ϴ��
	Q_PROPERTY(float diff MEMBER _diff READ diff WRITE setDiff)		//�����
	Q_PROPERTY(long volume MEMBER _volume READ volume WRITE setVolume)		//�����ŷ���
	Q_PROPERTY(long open MEMBER _open READ open WRITE setOpen)		//�ð�
	Q_PROPERTY(long high MEMBER _high READ high WRITE setHigh)		//��
	Q_PROPERTY(long low MEMBER _low READ low WRITE setLow)		//����
	Q_PROPERTY(float sojinrate MEMBER _sojinrate READ sojinrate WRITE setSojinrate)		//������
	Q_PROPERTY(float beta MEMBER _beta READ beta WRITE setBeta)		//��Ÿ���
	Q_PROPERTY(float perx MEMBER _perx READ perx WRITE setPerx)		//PER
	Q_PROPERTY(long frgsvolume MEMBER _frgsvolume READ frgsvolume WRITE setFrgsvolume)		//���μ��ż�
	Q_PROPERTY(long orgsvolume MEMBER _orgsvolume READ orgsvolume WRITE setOrgsvolume)		//������ż�
	Q_PROPERTY(float diff_vol MEMBER _diff_vol READ diff_vol WRITE setDiff_Vol)		//�ŷ�������
	Q_PROPERTY(QString shcode MEMBER _shcode READ shcode WRITE setShcode)		//�����ڵ�
	Q_PROPERTY(long total MEMBER _total READ total WRITE setTotal)		//�ð��Ѿ�
	Q_PROPERTY(long value MEMBER _value READ value WRITE setValue)		//�ŷ����
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
	QString _hname;		//�����
	long _price;		//���簡
	QString _sign;		//���ϴ�񱸺�
	long _change;		//���ϴ��
	float _diff;		//�����
	long _volume;		//�����ŷ���
	long _open;		//�ð�
	long _high;		//��
	long _low;		//����
	float _sojinrate;		//������
	float _beta;		//��Ÿ���
	float _perx;		//PER
	long _frgsvolume;		//���μ��ż�
	long _orgsvolume;		//������ż�
	float _diff_vol;		//�ŷ�������
	QString _shcode;		//�����ڵ�
	long _total;		//�ð��Ѿ�
	long _value;		//�ŷ����
};

#endif //T1516ITEM
