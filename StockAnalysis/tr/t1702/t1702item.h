#ifndef T1702ITEM
#define T1702ITEM

#include <QObject>
#include <QString>
#include <QDate>
#include "tr/tritem.h"
class T1702Item : public TrItem
{
	Q_OBJECT
	Q_PROPERTY(QDate date MEMBER _date READ date WRITE setDate)		//����
	Q_PROPERTY(long close MEMBER _close READ close WRITE setClose)		//����
	Q_PROPERTY(QString sign MEMBER _sign READ sign WRITE setSign)		//���ϴ�񱸺�
	Q_PROPERTY(long change MEMBER _change READ change WRITE setChange)		//���ϴ��
	Q_PROPERTY(float diff MEMBER _diff READ diff WRITE setDiff)		//�����
	Q_PROPERTY(long volume MEMBER _volume READ volume WRITE setVolume)		//�����ŷ���
	Q_PROPERTY(long amt0000 MEMBER _amt0000 READ amt0000 WRITE setAmt0000)		//����ݵ�
	Q_PROPERTY(long amt0001 MEMBER _amt0001 READ amt0001 WRITE setAmt0001)		//����
	Q_PROPERTY(long amt0002 MEMBER _amt0002 READ amt0002 WRITE setAmt0002)		//����
	Q_PROPERTY(long amt0003 MEMBER _amt0003 READ amt0003 WRITE setAmt0003)		//����
	Q_PROPERTY(long amt0004 MEMBER _amt0004 READ amt0004 WRITE setAmt0004)		//����
	Q_PROPERTY(long amt0005 MEMBER _amt0005 READ amt0005 WRITE setAmt0005)		//����
	Q_PROPERTY(long amt0006 MEMBER _amt0006 READ amt0006 WRITE setAmt0006)		//���
	Q_PROPERTY(long amt0007 MEMBER _amt0007 READ amt0007 WRITE setAmt0007)		//��Ÿ����
	Q_PROPERTY(long amt0008 MEMBER _amt0008 READ amt0008 WRITE setAmt0008)		//����
	Q_PROPERTY(long amt0009 MEMBER _amt0009 READ amt0009 WRITE setAmt0009)		//��Ͽܱ���
	Q_PROPERTY(long amt0010 MEMBER _amt0010 READ amt0010 WRITE setAmt0010)		//�̵�Ͽܱ���
	Q_PROPERTY(long amt0011 MEMBER _amt0011 READ amt0011 WRITE setAmt0011)		//������
	Q_PROPERTY(long amt0018 MEMBER _amt0018 READ amt0018 WRITE setAmt0018)		//���
	Q_PROPERTY(long amt0088 MEMBER _amt0088 READ amt0088 WRITE setAmt0088)		//���ΰ�(���+�̵��)
	Q_PROPERTY(long amt0099 MEMBER _amt0099 READ amt0099 WRITE setAmt0099)		//��Ÿ��(��Ÿ+����)
public:
    explicit T1702Item(const QString &shcode, QObject *parent=0);
    ~T1702Item();
    QString getSqlInsertStr();
    QString getSqlUpdateStr();

    QString shcode() { return mShcode; }
	QDate date() { return _date; }
	void setDate(QDate date) { _date = date; }
	long close() { return _close; }
	void setClose(long close) { _close = close; }
	QString sign() { return _sign; }
	void setSign(QString sign) { _sign = sign; }
	long change() { return _change; }
	void setChange(long change) { _change = change; }
	float diff() { return _diff; }
	void setDiff(float diff) { _diff = diff; }
	long volume() { return _volume; }
	void setVolume(long volume) { _volume = volume; }
	long amt0000() { return _amt0000; }
	void setAmt0000(long amt0000) { _amt0000 = amt0000; }
	long amt0001() { return _amt0001; }
	void setAmt0001(long amt0001) { _amt0001 = amt0001; }
	long amt0002() { return _amt0002; }
	void setAmt0002(long amt0002) { _amt0002 = amt0002; }
	long amt0003() { return _amt0003; }
	void setAmt0003(long amt0003) { _amt0003 = amt0003; }
	long amt0004() { return _amt0004; }
	void setAmt0004(long amt0004) { _amt0004 = amt0004; }
	long amt0005() { return _amt0005; }
	void setAmt0005(long amt0005) { _amt0005 = amt0005; }
	long amt0006() { return _amt0006; }
	void setAmt0006(long amt0006) { _amt0006 = amt0006; }
	long amt0007() { return _amt0007; }
	void setAmt0007(long amt0007) { _amt0007 = amt0007; }
	long amt0008() { return _amt0008; }
	void setAmt0008(long amt0008) { _amt0008 = amt0008; }
	long amt0009() { return _amt0009; }
	void setAmt0009(long amt0009) { _amt0009 = amt0009; }
	long amt0010() { return _amt0010; }
	void setAmt0010(long amt0010) { _amt0010 = amt0010; }
	long amt0011() { return _amt0011; }
	void setAmt0011(long amt0011) { _amt0011 = amt0011; }
	long amt0018() { return _amt0018; }
	void setAmt0018(long amt0018) { _amt0018 = amt0018; }
	long amt0088() { return _amt0088; }
	void setAmt0088(long amt0088) { _amt0088 = amt0088; }
	long amt0099() { return _amt0099; }
	void setAmt0099(long amt0099) { _amt0099 = amt0099; }
private:
    QString mShcode;
	QDate _date;		//����
	long _close;		//����
	QString _sign;		//���ϴ�񱸺�
	long _change;		//���ϴ��
	float _diff;		//�����
	long _volume;		//�����ŷ���
	long _amt0000;		//����ݵ�
	long _amt0001;		//����
	long _amt0002;		//����
	long _amt0003;		//����
	long _amt0004;		//����
	long _amt0005;		//����
	long _amt0006;		//���
	long _amt0007;		//��Ÿ����
	long _amt0008;		//����
	long _amt0009;		//��Ͽܱ���
	long _amt0010;		//�̵�Ͽܱ���
	long _amt0011;		//������
	long _amt0018;		//���
	long _amt0088;		//���ΰ�(���+�̵��)
	long _amt0099;		//��Ÿ��(��Ÿ+����)
};

#endif //T1702ITEM
