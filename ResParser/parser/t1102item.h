#ifndef T1102ITEM
#define T1102ITEM

#include <QObject>
#include <QString>
#include <QDate>
#include "tr/tritem.h"
#include "tr/t1102/t1102.h
class T1102Item : public TrItem
{
	Q_OBJECT
	Q_PROPERTY(QString hname MEMBER _hname READ hname)		//�ѱ۸�
	Q_PROPERTY(long price MEMBER _price READ price)		//���簡
	Q_PROPERTY(QString sign MEMBER _sign READ sign)		//���ϴ�񱸺�
	Q_PROPERTY(long change MEMBER _change READ change)		//���ϴ��
	Q_PROPERTY(float diff MEMBER _diff READ diff)		//�����
	Q_PROPERTY(long volume MEMBER _volume READ volume)		//�����ŷ���
	Q_PROPERTY(long recprice MEMBER _recprice READ recprice)		//���ذ�
	Q_PROPERTY(long avg MEMBER _avg READ avg)		//�������
	Q_PROPERTY(long uplmtprice MEMBER _uplmtprice READ uplmtprice)		//���Ѱ�
	Q_PROPERTY(long dnlmtprice MEMBER _dnlmtprice READ dnlmtprice)		//���Ѱ�
	Q_PROPERTY(long jnilvolume MEMBER _jnilvolume READ jnilvolume)		//���ϰŷ���
	Q_PROPERTY(long volumediff MEMBER _volumediff READ volumediff)		//�ŷ�����
	Q_PROPERTY(long open MEMBER _open READ open)		//�ð�
	Q_PROPERTY(QTime opentime MEMBER _opentime READ opentime)		//�ð��ð�
	Q_PROPERTY(long high MEMBER _high READ high)		//��
	Q_PROPERTY(QTime hightime MEMBER _hightime READ hightime)		//���ð�
	Q_PROPERTY(long low MEMBER _low READ low)		//����
	Q_PROPERTY(QTime lowtime MEMBER _lowtime READ lowtime)		//�����ð�
	Q_PROPERTY(long high52w MEMBER _high52w READ high52w)		//52�ְ�
	Q_PROPERTY(QDate high52wdate MEMBER _high52wdate READ high52wdate)		//52�ְ���
	Q_PROPERTY(long low52w MEMBER _low52w READ low52w)		//52������
	Q_PROPERTY(QDate low52wdate MEMBER _low52wdate READ low52wdate)		//52��������
	Q_PROPERTY(float exhratio MEMBER _exhratio READ exhratio)		//������
	Q_PROPERTY(float per MEMBER _per READ per)		//PER
	Q_PROPERTY(float pbrx MEMBER _pbrx READ pbrx)		//PBRX
	Q_PROPERTY(long listing MEMBER _listing READ listing)		//�����ֽļ�(õ)
	Q_PROPERTY(long jkrate MEMBER _jkrate READ jkrate)		//���ű���
	Q_PROPERTY(QString memedan MEMBER _memedan READ memedan)		//��������
	Q_PROPERTY(QString offernocd1 MEMBER _offernocd1 READ offernocd1)		//�ŵ����ǻ��ڵ�1
	Q_PROPERTY(QString bidnocd1 MEMBER _bidnocd1 READ bidnocd1)		//�ż����ǻ��ڵ�1
	Q_PROPERTY(QString offerno1 MEMBER _offerno1 READ offerno1)		//�ŵ����ǻ��1
	Q_PROPERTY(QString bidno1 MEMBER _bidno1 READ bidno1)		//�ż����ǻ��1
	Q_PROPERTY(long dvol1 MEMBER _dvol1 READ dvol1)		//�Ѹŵ�����1
	Q_PROPERTY(long svol1 MEMBER _svol1 READ svol1)		//�Ѹż�����1
	Q_PROPERTY(long dcha1 MEMBER _dcha1 READ dcha1)		//�ŵ�����1
	Q_PROPERTY(long scha1 MEMBER _scha1 READ scha1)		//�ż�����1
	Q_PROPERTY(float ddiff1 MEMBER _ddiff1 READ ddiff1)		//�ŵ�����1
	Q_PROPERTY(float sdiff1 MEMBER _sdiff1 READ sdiff1)		//�ż�����1
	Q_PROPERTY(QString offernocd2 MEMBER _offernocd2 READ offernocd2)		//�ŵ����ǻ��ڵ�2
	Q_PROPERTY(QString bidnocd2 MEMBER _bidnocd2 READ bidnocd2)		//�ż����ǻ��ڵ�2
	Q_PROPERTY(QString offerno2 MEMBER _offerno2 READ offerno2)		//�ŵ����ǻ��2
	Q_PROPERTY(QString bidno2 MEMBER _bidno2 READ bidno2)		//�ż����ǻ��2
	Q_PROPERTY(long dvol2 MEMBER _dvol2 READ dvol2)		//�Ѹŵ�����2
	Q_PROPERTY(long svol2 MEMBER _svol2 READ svol2)		//�Ѹż�����2
	Q_PROPERTY(long dcha2 MEMBER _dcha2 READ dcha2)		//�ŵ�����2
	Q_PROPERTY(long scha2 MEMBER _scha2 READ scha2)		//�ż�����2
	Q_PROPERTY(float ddiff2 MEMBER _ddiff2 READ ddiff2)		//�ŵ�����2
	Q_PROPERTY(float sdiff2 MEMBER _sdiff2 READ sdiff2)		//�ż�����2
	Q_PROPERTY(QString offernocd3 MEMBER _offernocd3 READ offernocd3)		//�ŵ����ǻ��ڵ�3
	Q_PROPERTY(QString bidnocd3 MEMBER _bidnocd3 READ bidnocd3)		//�ż����ǻ��ڵ�3
	Q_PROPERTY(QString offerno3 MEMBER _offerno3 READ offerno3)		//�ŵ����ǻ��3
	Q_PROPERTY(QString bidno3 MEMBER _bidno3 READ bidno3)		//�ż����ǻ��3
	Q_PROPERTY(long dvol3 MEMBER _dvol3 READ dvol3)		//�Ѹŵ�����3
	Q_PROPERTY(long svol3 MEMBER _svol3 READ svol3)		//�Ѹż�����3
	Q_PROPERTY(long dcha3 MEMBER _dcha3 READ dcha3)		//�ŵ�����3
	Q_PROPERTY(long scha3 MEMBER _scha3 READ scha3)		//�ż�����3
	Q_PROPERTY(float ddiff3 MEMBER _ddiff3 READ ddiff3)		//�ŵ�����3
	Q_PROPERTY(float sdiff3 MEMBER _sdiff3 READ sdiff3)		//�ż�����3
	Q_PROPERTY(QString offernocd4 MEMBER _offernocd4 READ offernocd4)		//�ŵ����ǻ��ڵ�4
	Q_PROPERTY(QString bidnocd4 MEMBER _bidnocd4 READ bidnocd4)		//�ż����ǻ��ڵ�4
	Q_PROPERTY(QString offerno4 MEMBER _offerno4 READ offerno4)		//�ŵ����ǻ��4
	Q_PROPERTY(QString bidno4 MEMBER _bidno4 READ bidno4)		//�ż����ǻ��4
	Q_PROPERTY(long dvol4 MEMBER _dvol4 READ dvol4)		//�Ѹŵ�����4
	Q_PROPERTY(long svol4 MEMBER _svol4 READ svol4)		//�Ѹż�����4
	Q_PROPERTY(long dcha4 MEMBER _dcha4 READ dcha4)		//�ŵ�����4
	Q_PROPERTY(long scha4 MEMBER _scha4 READ scha4)		//�ż�����4
	Q_PROPERTY(float ddiff4 MEMBER _ddiff4 READ ddiff4)		//�ŵ�����4
	Q_PROPERTY(float sdiff4 MEMBER _sdiff4 READ sdiff4)		//�ż�����4
	Q_PROPERTY(QString offernocd5 MEMBER _offernocd5 READ offernocd5)		//�ŵ����ǻ��ڵ�5
	Q_PROPERTY(QString bidnocd5 MEMBER _bidnocd5 READ bidnocd5)		//�ż����ǻ��ڵ�5
	Q_PROPERTY(QString offerno5 MEMBER _offerno5 READ offerno5)		//�ŵ����ǻ��5
	Q_PROPERTY(QString bidno5 MEMBER _bidno5 READ bidno5)		//�ż����ǻ��5
	Q_PROPERTY(long dvol5 MEMBER _dvol5 READ dvol5)		//�Ѹŵ�����5
	Q_PROPERTY(long svol5 MEMBER _svol5 READ svol5)		//�Ѹż�����5
	Q_PROPERTY(long dcha5 MEMBER _dcha5 READ dcha5)		//�ŵ�����5
	Q_PROPERTY(long scha5 MEMBER _scha5 READ scha5)		//�ż�����5
	Q_PROPERTY(float ddiff5 MEMBER _ddiff5 READ ddiff5)		//�ŵ�����5
	Q_PROPERTY(float sdiff5 MEMBER _sdiff5 READ sdiff5)		//�ż�����5
	Q_PROPERTY(long fwdvl MEMBER _fwdvl READ fwdvl)		//�ܱ���ŵ��հ����
	Q_PROPERTY(long ftradmdcha MEMBER _ftradmdcha READ ftradmdcha)		//�ܱ���ŵ��������
	Q_PROPERTY(float ftradmddiff MEMBER _ftradmddiff READ ftradmddiff)		//�ܱ���ŵ�����
	Q_PROPERTY(long fwsvl MEMBER _fwsvl READ fwsvl)		//�ܱ���ż��հ����
	Q_PROPERTY(long ftradmscha MEMBER _ftradmscha READ ftradmscha)		//�ܱ���ż��������
	Q_PROPERTY(float ftradmsdiff MEMBER _ftradmsdiff READ ftradmsdiff)		//�ܱ���ż�����
	Q_PROPERTY(float vol MEMBER _vol READ vol)		//ȸ����
	Q_PROPERTY(QString shcode MEMBER _shcode READ shcode)		//�����ڵ�
	Q_PROPERTY(long value MEMBER _value READ value)		//�����ŷ����
	Q_PROPERTY(long jvolume MEMBER _jvolume READ jvolume)		//���ϵ��ð��ŷ���
	Q_PROPERTY(long highyear MEMBER _highyear READ highyear)		//�����ְ�
	Q_PROPERTY(QDate highyeardate MEMBER _highyeardate READ highyeardate)		//�����ְ�����
	Q_PROPERTY(long lowyear MEMBER _lowyear READ lowyear)		//����������
	Q_PROPERTY(QDate lowyeardate MEMBER _lowyeardate READ lowyeardate)		//������������
	Q_PROPERTY(long target MEMBER _target READ target)		//��ǥ��
	Q_PROPERTY(long capital MEMBER _capital READ capital)		//�ں���
	Q_PROPERTY(long abscnt MEMBER _abscnt READ abscnt)		//�����ֽļ�
	Q_PROPERTY(long parprice MEMBER _parprice READ parprice)		//�׸鰡
	Q_PROPERTY(QString gsmm MEMBER _gsmm READ gsmm)		//����
	Q_PROPERTY(long subprice MEMBER _subprice READ subprice)		//��밡
	Q_PROPERTY(long total MEMBER _total READ total)		//�ð��Ѿ�
	Q_PROPERTY(QDate listdate MEMBER _listdate READ listdate)		//������
	Q_PROPERTY(QString name MEMBER _name READ name)		//���б��
	Q_PROPERTY(long bfsales MEMBER _bfsales READ bfsales)		//���б�����
	Q_PROPERTY(long bfoperatingincome MEMBER _bfoperatingincome READ bfoperatingincome)		//���б⿵������
	Q_PROPERTY(long bfordinaryincome MEMBER _bfordinaryincome READ bfordinaryincome)		//���б�������
	Q_PROPERTY(long bfnetincome MEMBER _bfnetincome READ bfnetincome)		//���б������
	Q_PROPERTY(float bfeps MEMBER _bfeps READ bfeps)		//���б�EPS
	Q_PROPERTY(QString name2 MEMBER _name2 READ name2)		//�����б��
	Q_PROPERTY(long bfsales2 MEMBER _bfsales2 READ bfsales2)		//�����б�����
	Q_PROPERTY(long bfoperatingincome2 MEMBER _bfoperatingincome2 READ bfoperatingincome2)		//�����б⿵������
	Q_PROPERTY(long bfordinaryincome2 MEMBER _bfordinaryincome2 READ bfordinaryincome2)		//�����б�������
	Q_PROPERTY(long bfnetincome2 MEMBER _bfnetincome2 READ bfnetincome2)		//�����б������
	Q_PROPERTY(float bfeps2 MEMBER _bfeps2 READ bfeps2)		//�����б�EPS
	Q_PROPERTY(float salert MEMBER _salert READ salert)		//����������
	Q_PROPERTY(float opert MEMBER _opert READ opert)		//�����񿵾�����
	Q_PROPERTY(float ordrt MEMBER _ordrt READ ordrt)		//������������
	Q_PROPERTY(float netrt MEMBER _netrt READ netrt)		//�����������
	Q_PROPERTY(float epsrt MEMBER _epsrt READ epsrt)		//������EPS
	Q_PROPERTY(QString info1 MEMBER _info1 READ info1)		//������
	Q_PROPERTY(QString info2 MEMBER _info2 READ info2)		//����/�޵��
	Q_PROPERTY(QString info3 MEMBER _info3 READ info3)		//����/���屸��
	Q_PROPERTY(QString info4 MEMBER _info4 READ info4)		//����/�Ҽ��Ǳ���
	Q_PROPERTY(QString janginfo MEMBER _janginfo READ janginfo)		//�屸��
	Q_PROPERTY(float t_per MEMBER _t_per READ t_per)		//T.PER
	Q_PROPERTY(QString tonghwa MEMBER _tonghwa READ tonghwa)		//��ȭISO�ڵ�
	Q_PROPERTY(long dval1 MEMBER _dval1 READ dval1)		//�Ѹŵ����1
	Q_PROPERTY(long sval1 MEMBER _sval1 READ sval1)		//�Ѹż����1
	Q_PROPERTY(long dval2 MEMBER _dval2 READ dval2)		//�Ѹŵ����2
	Q_PROPERTY(long sval2 MEMBER _sval2 READ sval2)		//�Ѹż����2
	Q_PROPERTY(long dval3 MEMBER _dval3 READ dval3)		//�Ѹŵ����3
	Q_PROPERTY(long sval3 MEMBER _sval3 READ sval3)		//�Ѹż����3
	Q_PROPERTY(long dval4 MEMBER _dval4 READ dval4)		//�Ѹŵ����4
	Q_PROPERTY(long sval4 MEMBER _sval4 READ sval4)		//�Ѹż����4
	Q_PROPERTY(long dval5 MEMBER _dval5 READ dval5)		//�Ѹŵ����5
	Q_PROPERTY(long sval5 MEMBER _sval5 READ sval5)		//�Ѹż����5
	Q_PROPERTY(long davg1 MEMBER _davg1 READ davg1)		//�Ѹŵ���ܰ�1
	Q_PROPERTY(long savg1 MEMBER _savg1 READ savg1)		//�Ѹż���ܰ�1
	Q_PROPERTY(long davg2 MEMBER _davg2 READ davg2)		//�Ѹŵ���ܰ�2
	Q_PROPERTY(long savg2 MEMBER _savg2 READ savg2)		//�Ѹż���ܰ�2
	Q_PROPERTY(long davg3 MEMBER _davg3 READ davg3)		//�Ѹŵ���ܰ�3
	Q_PROPERTY(long savg3 MEMBER _savg3 READ savg3)		//�Ѹż���ܰ�3
	Q_PROPERTY(long davg4 MEMBER _davg4 READ davg4)		//�Ѹŵ���ܰ�4
	Q_PROPERTY(long savg4 MEMBER _savg4 READ savg4)		//�Ѹż���ܰ�4
	Q_PROPERTY(long davg5 MEMBER _davg5 READ davg5)		//�Ѹŵ���ܰ�5
	Q_PROPERTY(long savg5 MEMBER _savg5 READ savg5)		//�Ѹż���ܰ�5
	Q_PROPERTY(long ftradmdval MEMBER _ftradmdval READ ftradmdval)		//�ܱ���ŵ����
	Q_PROPERTY(long ftradmsval MEMBER _ftradmsval READ ftradmsval)		//�ܱ���ż����
	Q_PROPERTY(long ftradmdvag MEMBER _ftradmdvag READ ftradmdvag)		//�ܱ���ŵ���ܰ�
	Q_PROPERTY(long ftradmsvag MEMBER _ftradmsvag READ ftradmsvag)		//�ܱ���ż���ܰ�
	Q_PROPERTY(QString info5 MEMBER _info5 READ info5)		//��������ȯ��
	Q_PROPERTY(QString spac_gubun MEMBER _spac_gubun READ spac_gubun)		//����μ�����ȸ�翩��
	Q_PROPERTY(long issueprice MEMBER _issueprice READ issueprice)		//���డ��
	Q_PROPERTY(QString alloc_gubun MEMBER _alloc_gubun READ alloc_gubun)		//������뱸���ڵ�(1:��й߻�2:��������׿�:�̹߻�)
	Q_PROPERTY(QString alloc_text MEMBER _alloc_text READ alloc_text)		//������뱸��
	Q_PROPERTY(QString shterm_text MEMBER _shterm_text READ shterm_text)		//�ܱ����/VI�ߵ�
public:
	explicit T1102Item(LPt1102OutBlock outblock, QObject *parent=0);
	~T1102Item();
	QString hname() { return _hname; }
	long price() { return _price; }
	QString sign() { return _sign; }
	long change() { return _change; }
	float diff() { return _diff; }
	long volume() { return _volume; }
	long recprice() { return _recprice; }
	long avg() { return _avg; }
	long uplmtprice() { return _uplmtprice; }
	long dnlmtprice() { return _dnlmtprice; }
	long jnilvolume() { return _jnilvolume; }
	long volumediff() { return _volumediff; }
	long open() { return _open; }
	QTime opentime() { return _opentime; }
	long high() { return _high; }
	QTime hightime() { return _hightime; }
	long low() { return _low; }
	QTime lowtime() { return _lowtime; }
	long high52w() { return _high52w; }
	QDate high52wdate() { return _high52wdate; }
	long low52w() { return _low52w; }
	QDate low52wdate() { return _low52wdate; }
	float exhratio() { return _exhratio; }
	float per() { return _per; }
	float pbrx() { return _pbrx; }
	long listing() { return _listing; }
	long jkrate() { return _jkrate; }
	QString memedan() { return _memedan; }
	QString offernocd1() { return _offernocd1; }
	QString bidnocd1() { return _bidnocd1; }
	QString offerno1() { return _offerno1; }
	QString bidno1() { return _bidno1; }
	long dvol1() { return _dvol1; }
	long svol1() { return _svol1; }
	long dcha1() { return _dcha1; }
	long scha1() { return _scha1; }
	float ddiff1() { return _ddiff1; }
	float sdiff1() { return _sdiff1; }
	QString offernocd2() { return _offernocd2; }
	QString bidnocd2() { return _bidnocd2; }
	QString offerno2() { return _offerno2; }
	QString bidno2() { return _bidno2; }
	long dvol2() { return _dvol2; }
	long svol2() { return _svol2; }
	long dcha2() { return _dcha2; }
	long scha2() { return _scha2; }
	float ddiff2() { return _ddiff2; }
	float sdiff2() { return _sdiff2; }
	QString offernocd3() { return _offernocd3; }
	QString bidnocd3() { return _bidnocd3; }
	QString offerno3() { return _offerno3; }
	QString bidno3() { return _bidno3; }
	long dvol3() { return _dvol3; }
	long svol3() { return _svol3; }
	long dcha3() { return _dcha3; }
	long scha3() { return _scha3; }
	float ddiff3() { return _ddiff3; }
	float sdiff3() { return _sdiff3; }
	QString offernocd4() { return _offernocd4; }
	QString bidnocd4() { return _bidnocd4; }
	QString offerno4() { return _offerno4; }
	QString bidno4() { return _bidno4; }
	long dvol4() { return _dvol4; }
	long svol4() { return _svol4; }
	long dcha4() { return _dcha4; }
	long scha4() { return _scha4; }
	float ddiff4() { return _ddiff4; }
	float sdiff4() { return _sdiff4; }
	QString offernocd5() { return _offernocd5; }
	QString bidnocd5() { return _bidnocd5; }
	QString offerno5() { return _offerno5; }
	QString bidno5() { return _bidno5; }
	long dvol5() { return _dvol5; }
	long svol5() { return _svol5; }
	long dcha5() { return _dcha5; }
	long scha5() { return _scha5; }
	float ddiff5() { return _ddiff5; }
	float sdiff5() { return _sdiff5; }
	long fwdvl() { return _fwdvl; }
	long ftradmdcha() { return _ftradmdcha; }
	float ftradmddiff() { return _ftradmddiff; }
	long fwsvl() { return _fwsvl; }
	long ftradmscha() { return _ftradmscha; }
	float ftradmsdiff() { return _ftradmsdiff; }
	float vol() { return _vol; }
	QString shcode() { return _shcode; }
	long value() { return _value; }
	long jvolume() { return _jvolume; }
	long highyear() { return _highyear; }
	QDate highyeardate() { return _highyeardate; }
	long lowyear() { return _lowyear; }
	QDate lowyeardate() { return _lowyeardate; }
	long target() { return _target; }
	long capital() { return _capital; }
	long abscnt() { return _abscnt; }
	long parprice() { return _parprice; }
	QString gsmm() { return _gsmm; }
	long subprice() { return _subprice; }
	long total() { return _total; }
	QDate listdate() { return _listdate; }
	QString name() { return _name; }
	long bfsales() { return _bfsales; }
	long bfoperatingincome() { return _bfoperatingincome; }
	long bfordinaryincome() { return _bfordinaryincome; }
	long bfnetincome() { return _bfnetincome; }
	float bfeps() { return _bfeps; }
	QString name2() { return _name2; }
	long bfsales2() { return _bfsales2; }
	long bfoperatingincome2() { return _bfoperatingincome2; }
	long bfordinaryincome2() { return _bfordinaryincome2; }
	long bfnetincome2() { return _bfnetincome2; }
	float bfeps2() { return _bfeps2; }
	float salert() { return _salert; }
	float opert() { return _opert; }
	float ordrt() { return _ordrt; }
	float netrt() { return _netrt; }
	float epsrt() { return _epsrt; }
	QString info1() { return _info1; }
	QString info2() { return _info2; }
	QString info3() { return _info3; }
	QString info4() { return _info4; }
	QString janginfo() { return _janginfo; }
	float t_per() { return _t_per; }
	QString tonghwa() { return _tonghwa; }
	long dval1() { return _dval1; }
	long sval1() { return _sval1; }
	long dval2() { return _dval2; }
	long sval2() { return _sval2; }
	long dval3() { return _dval3; }
	long sval3() { return _sval3; }
	long dval4() { return _dval4; }
	long sval4() { return _sval4; }
	long dval5() { return _dval5; }
	long sval5() { return _sval5; }
	long davg1() { return _davg1; }
	long savg1() { return _savg1; }
	long davg2() { return _davg2; }
	long savg2() { return _savg2; }
	long davg3() { return _davg3; }
	long savg3() { return _savg3; }
	long davg4() { return _davg4; }
	long savg4() { return _savg4; }
	long davg5() { return _davg5; }
	long savg5() { return _savg5; }
	long ftradmdval() { return _ftradmdval; }
	long ftradmsval() { return _ftradmsval; }
	long ftradmdvag() { return _ftradmdvag; }
	long ftradmsvag() { return _ftradmsvag; }
	QString info5() { return _info5; }
	QString spac_gubun() { return _spac_gubun; }
	long issueprice() { return _issueprice; }
	QString alloc_gubun() { return _alloc_gubun; }
	QString alloc_text() { return _alloc_text; }
	QString shterm_text() { return _shterm_text; }
	QString _hname;		//�ѱ۸�
	long _price;		//���簡
	QString _sign;		//���ϴ�񱸺�
	long _change;		//���ϴ��
	float _diff;		//�����
	long _volume;		//�����ŷ���
	long _recprice;		//���ذ�
	long _avg;		//�������
	long _uplmtprice;		//���Ѱ�
	long _dnlmtprice;		//���Ѱ�
	long _jnilvolume;		//���ϰŷ���
	long _volumediff;		//�ŷ�����
	long _open;		//�ð�
	QTime _opentime;		//�ð��ð�
	long _high;		//��
	QTime _hightime;		//���ð�
	long _low;		//����
	QTime _lowtime;		//�����ð�
	long _high52w;		//52�ְ�
	QDate _high52wdate;		//52�ְ���
	long _low52w;		//52������
	QDate _low52wdate;		//52��������
	float _exhratio;		//������
	float _per;		//PER
	float _pbrx;		//PBRX
	long _listing;		//�����ֽļ�(õ)
	long _jkrate;		//���ű���
	QString _memedan;		//��������
	QString _offernocd1;		//�ŵ����ǻ��ڵ�1
	QString _bidnocd1;		//�ż����ǻ��ڵ�1
	QString _offerno1;		//�ŵ����ǻ��1
	QString _bidno1;		//�ż����ǻ��1
	long _dvol1;		//�Ѹŵ�����1
	long _svol1;		//�Ѹż�����1
	long _dcha1;		//�ŵ�����1
	long _scha1;		//�ż�����1
	float _ddiff1;		//�ŵ�����1
	float _sdiff1;		//�ż�����1
	QString _offernocd2;		//�ŵ����ǻ��ڵ�2
	QString _bidnocd2;		//�ż����ǻ��ڵ�2
	QString _offerno2;		//�ŵ����ǻ��2
	QString _bidno2;		//�ż����ǻ��2
	long _dvol2;		//�Ѹŵ�����2
	long _svol2;		//�Ѹż�����2
	long _dcha2;		//�ŵ�����2
	long _scha2;		//�ż�����2
	float _ddiff2;		//�ŵ�����2
	float _sdiff2;		//�ż�����2
	QString _offernocd3;		//�ŵ����ǻ��ڵ�3
	QString _bidnocd3;		//�ż����ǻ��ڵ�3
	QString _offerno3;		//�ŵ����ǻ��3
	QString _bidno3;		//�ż����ǻ��3
	long _dvol3;		//�Ѹŵ�����3
	long _svol3;		//�Ѹż�����3
	long _dcha3;		//�ŵ�����3
	long _scha3;		//�ż�����3
	float _ddiff3;		//�ŵ�����3
	float _sdiff3;		//�ż�����3
	QString _offernocd4;		//�ŵ����ǻ��ڵ�4
	QString _bidnocd4;		//�ż����ǻ��ڵ�4
	QString _offerno4;		//�ŵ����ǻ��4
	QString _bidno4;		//�ż����ǻ��4
	long _dvol4;		//�Ѹŵ�����4
	long _svol4;		//�Ѹż�����4
	long _dcha4;		//�ŵ�����4
	long _scha4;		//�ż�����4
	float _ddiff4;		//�ŵ�����4
	float _sdiff4;		//�ż�����4
	QString _offernocd5;		//�ŵ����ǻ��ڵ�5
	QString _bidnocd5;		//�ż����ǻ��ڵ�5
	QString _offerno5;		//�ŵ����ǻ��5
	QString _bidno5;		//�ż����ǻ��5
	long _dvol5;		//�Ѹŵ�����5
	long _svol5;		//�Ѹż�����5
	long _dcha5;		//�ŵ�����5
	long _scha5;		//�ż�����5
	float _ddiff5;		//�ŵ�����5
	float _sdiff5;		//�ż�����5
	long _fwdvl;		//�ܱ���ŵ��հ����
	long _ftradmdcha;		//�ܱ���ŵ��������
	float _ftradmddiff;		//�ܱ���ŵ�����
	long _fwsvl;		//�ܱ���ż��հ����
	long _ftradmscha;		//�ܱ���ż��������
	float _ftradmsdiff;		//�ܱ���ż�����
	float _vol;		//ȸ����
	QString _shcode;		//�����ڵ�
	long _value;		//�����ŷ����
	long _jvolume;		//���ϵ��ð��ŷ���
	long _highyear;		//�����ְ�
	QDate _highyeardate;		//�����ְ�����
	long _lowyear;		//����������
	QDate _lowyeardate;		//������������
	long _target;		//��ǥ��
	long _capital;		//�ں���
	long _abscnt;		//�����ֽļ�
	long _parprice;		//�׸鰡
	QString _gsmm;		//����
	long _subprice;		//��밡
	long _total;		//�ð��Ѿ�
	QDate _listdate;		//������
	QString _name;		//���б��
	long _bfsales;		//���б�����
	long _bfoperatingincome;		//���б⿵������
	long _bfordinaryincome;		//���б�������
	long _bfnetincome;		//���б������
	float _bfeps;		//���б�EPS
	QString _name2;		//�����б��
	long _bfsales2;		//�����б�����
	long _bfoperatingincome2;		//�����б⿵������
	long _bfordinaryincome2;		//�����б�������
	long _bfnetincome2;		//�����б������
	float _bfeps2;		//�����б�EPS
	float _salert;		//����������
	float _opert;		//�����񿵾�����
	float _ordrt;		//������������
	float _netrt;		//�����������
	float _epsrt;		//������EPS
	QString _info1;		//������
	QString _info2;		//����/�޵��
	QString _info3;		//����/���屸��
	QString _info4;		//����/�Ҽ��Ǳ���
	QString _janginfo;		//�屸��
	float _t_per;		//T.PER
	QString _tonghwa;		//��ȭISO�ڵ�
	long _dval1;		//�Ѹŵ����1
	long _sval1;		//�Ѹż����1
	long _dval2;		//�Ѹŵ����2
	long _sval2;		//�Ѹż����2
	long _dval3;		//�Ѹŵ����3
	long _sval3;		//�Ѹż����3
	long _dval4;		//�Ѹŵ����4
	long _sval4;		//�Ѹż����4
	long _dval5;		//�Ѹŵ����5
	long _sval5;		//�Ѹż����5
	long _davg1;		//�Ѹŵ���ܰ�1
	long _savg1;		//�Ѹż���ܰ�1
	long _davg2;		//�Ѹŵ���ܰ�2
	long _savg2;		//�Ѹż���ܰ�2
	long _davg3;		//�Ѹŵ���ܰ�3
	long _savg3;		//�Ѹż���ܰ�3
	long _davg4;		//�Ѹŵ���ܰ�4
	long _savg4;		//�Ѹż���ܰ�4
	long _davg5;		//�Ѹŵ���ܰ�5
	long _savg5;		//�Ѹż���ܰ�5
	long _ftradmdval;		//�ܱ���ŵ����
	long _ftradmsval;		//�ܱ���ż����
	long _ftradmdvag;		//�ܱ���ŵ���ܰ�
	long _ftradmsvag;		//�ܱ���ż���ܰ�
	QString _info5;		//��������ȯ��
	QString _spac_gubun;		//����μ�����ȸ�翩��
	long _issueprice;		//���డ��
	QString _alloc_gubun;		//������뱸���ڵ�(1:��й߻�2:��������׿�:�̹߻�)
	QString _alloc_text;		//������뱸��
	QString _shterm_text;		//�ܱ����/VI�ߵ�
};

#endif //T1102ITEM
