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
	Q_PROPERTY(QString hname MEMBER _hname READ hname)		//한글명
	Q_PROPERTY(long price MEMBER _price READ price)		//현재가
	Q_PROPERTY(QString sign MEMBER _sign READ sign)		//전일대비구분
	Q_PROPERTY(long change MEMBER _change READ change)		//전일대비
	Q_PROPERTY(float diff MEMBER _diff READ diff)		//등락율
	Q_PROPERTY(long volume MEMBER _volume READ volume)		//누적거래량
	Q_PROPERTY(long recprice MEMBER _recprice READ recprice)		//기준가
	Q_PROPERTY(long avg MEMBER _avg READ avg)		//가중평균
	Q_PROPERTY(long uplmtprice MEMBER _uplmtprice READ uplmtprice)		//상한가
	Q_PROPERTY(long dnlmtprice MEMBER _dnlmtprice READ dnlmtprice)		//하한가
	Q_PROPERTY(long jnilvolume MEMBER _jnilvolume READ jnilvolume)		//전일거래량
	Q_PROPERTY(long volumediff MEMBER _volumediff READ volumediff)		//거래량차
	Q_PROPERTY(long open MEMBER _open READ open)		//시가
	Q_PROPERTY(QTime opentime MEMBER _opentime READ opentime)		//시가시간
	Q_PROPERTY(long high MEMBER _high READ high)		//고가
	Q_PROPERTY(QTime hightime MEMBER _hightime READ hightime)		//고가시간
	Q_PROPERTY(long low MEMBER _low READ low)		//저가
	Q_PROPERTY(QTime lowtime MEMBER _lowtime READ lowtime)		//저가시간
	Q_PROPERTY(long high52w MEMBER _high52w READ high52w)		//52최고가
	Q_PROPERTY(QDate high52wdate MEMBER _high52wdate READ high52wdate)		//52최고가일
	Q_PROPERTY(long low52w MEMBER _low52w READ low52w)		//52최저가
	Q_PROPERTY(QDate low52wdate MEMBER _low52wdate READ low52wdate)		//52최저가일
	Q_PROPERTY(float exhratio MEMBER _exhratio READ exhratio)		//소진율
	Q_PROPERTY(float per MEMBER _per READ per)		//PER
	Q_PROPERTY(float pbrx MEMBER _pbrx READ pbrx)		//PBRX
	Q_PROPERTY(long listing MEMBER _listing READ listing)		//상장주식수(천)
	Q_PROPERTY(long jkrate MEMBER _jkrate READ jkrate)		//증거금율
	Q_PROPERTY(QString memedan MEMBER _memedan READ memedan)		//수량단위
	Q_PROPERTY(QString offernocd1 MEMBER _offernocd1 READ offernocd1)		//매도증권사코드1
	Q_PROPERTY(QString bidnocd1 MEMBER _bidnocd1 READ bidnocd1)		//매수증권사코드1
	Q_PROPERTY(QString offerno1 MEMBER _offerno1 READ offerno1)		//매도증권사명1
	Q_PROPERTY(QString bidno1 MEMBER _bidno1 READ bidno1)		//매수증권사명1
	Q_PROPERTY(long dvol1 MEMBER _dvol1 READ dvol1)		//총매도수량1
	Q_PROPERTY(long svol1 MEMBER _svol1 READ svol1)		//총매수수량1
	Q_PROPERTY(long dcha1 MEMBER _dcha1 READ dcha1)		//매도증감1
	Q_PROPERTY(long scha1 MEMBER _scha1 READ scha1)		//매수증감1
	Q_PROPERTY(float ddiff1 MEMBER _ddiff1 READ ddiff1)		//매도비율1
	Q_PROPERTY(float sdiff1 MEMBER _sdiff1 READ sdiff1)		//매수비율1
	Q_PROPERTY(QString offernocd2 MEMBER _offernocd2 READ offernocd2)		//매도증권사코드2
	Q_PROPERTY(QString bidnocd2 MEMBER _bidnocd2 READ bidnocd2)		//매수증권사코드2
	Q_PROPERTY(QString offerno2 MEMBER _offerno2 READ offerno2)		//매도증권사명2
	Q_PROPERTY(QString bidno2 MEMBER _bidno2 READ bidno2)		//매수증권사명2
	Q_PROPERTY(long dvol2 MEMBER _dvol2 READ dvol2)		//총매도수량2
	Q_PROPERTY(long svol2 MEMBER _svol2 READ svol2)		//총매수수량2
	Q_PROPERTY(long dcha2 MEMBER _dcha2 READ dcha2)		//매도증감2
	Q_PROPERTY(long scha2 MEMBER _scha2 READ scha2)		//매수증감2
	Q_PROPERTY(float ddiff2 MEMBER _ddiff2 READ ddiff2)		//매도비율2
	Q_PROPERTY(float sdiff2 MEMBER _sdiff2 READ sdiff2)		//매수비율2
	Q_PROPERTY(QString offernocd3 MEMBER _offernocd3 READ offernocd3)		//매도증권사코드3
	Q_PROPERTY(QString bidnocd3 MEMBER _bidnocd3 READ bidnocd3)		//매수증권사코드3
	Q_PROPERTY(QString offerno3 MEMBER _offerno3 READ offerno3)		//매도증권사명3
	Q_PROPERTY(QString bidno3 MEMBER _bidno3 READ bidno3)		//매수증권사명3
	Q_PROPERTY(long dvol3 MEMBER _dvol3 READ dvol3)		//총매도수량3
	Q_PROPERTY(long svol3 MEMBER _svol3 READ svol3)		//총매수수량3
	Q_PROPERTY(long dcha3 MEMBER _dcha3 READ dcha3)		//매도증감3
	Q_PROPERTY(long scha3 MEMBER _scha3 READ scha3)		//매수증감3
	Q_PROPERTY(float ddiff3 MEMBER _ddiff3 READ ddiff3)		//매도비율3
	Q_PROPERTY(float sdiff3 MEMBER _sdiff3 READ sdiff3)		//매수비율3
	Q_PROPERTY(QString offernocd4 MEMBER _offernocd4 READ offernocd4)		//매도증권사코드4
	Q_PROPERTY(QString bidnocd4 MEMBER _bidnocd4 READ bidnocd4)		//매수증권사코드4
	Q_PROPERTY(QString offerno4 MEMBER _offerno4 READ offerno4)		//매도증권사명4
	Q_PROPERTY(QString bidno4 MEMBER _bidno4 READ bidno4)		//매수증권사명4
	Q_PROPERTY(long dvol4 MEMBER _dvol4 READ dvol4)		//총매도수량4
	Q_PROPERTY(long svol4 MEMBER _svol4 READ svol4)		//총매수수량4
	Q_PROPERTY(long dcha4 MEMBER _dcha4 READ dcha4)		//매도증감4
	Q_PROPERTY(long scha4 MEMBER _scha4 READ scha4)		//매수증감4
	Q_PROPERTY(float ddiff4 MEMBER _ddiff4 READ ddiff4)		//매도비율4
	Q_PROPERTY(float sdiff4 MEMBER _sdiff4 READ sdiff4)		//매수비율4
	Q_PROPERTY(QString offernocd5 MEMBER _offernocd5 READ offernocd5)		//매도증권사코드5
	Q_PROPERTY(QString bidnocd5 MEMBER _bidnocd5 READ bidnocd5)		//매수증권사코드5
	Q_PROPERTY(QString offerno5 MEMBER _offerno5 READ offerno5)		//매도증권사명5
	Q_PROPERTY(QString bidno5 MEMBER _bidno5 READ bidno5)		//매수증권사명5
	Q_PROPERTY(long dvol5 MEMBER _dvol5 READ dvol5)		//총매도수량5
	Q_PROPERTY(long svol5 MEMBER _svol5 READ svol5)		//총매수수량5
	Q_PROPERTY(long dcha5 MEMBER _dcha5 READ dcha5)		//매도증감5
	Q_PROPERTY(long scha5 MEMBER _scha5 READ scha5)		//매수증감5
	Q_PROPERTY(float ddiff5 MEMBER _ddiff5 READ ddiff5)		//매도비율5
	Q_PROPERTY(float sdiff5 MEMBER _sdiff5 READ sdiff5)		//매수비율5
	Q_PROPERTY(long fwdvl MEMBER _fwdvl READ fwdvl)		//외국계매도합계수량
	Q_PROPERTY(long ftradmdcha MEMBER _ftradmdcha READ ftradmdcha)		//외국계매도직전대비
	Q_PROPERTY(float ftradmddiff MEMBER _ftradmddiff READ ftradmddiff)		//외국계매도비율
	Q_PROPERTY(long fwsvl MEMBER _fwsvl READ fwsvl)		//외국계매수합계수량
	Q_PROPERTY(long ftradmscha MEMBER _ftradmscha READ ftradmscha)		//외국계매수직전대비
	Q_PROPERTY(float ftradmsdiff MEMBER _ftradmsdiff READ ftradmsdiff)		//외국계매수비율
	Q_PROPERTY(float vol MEMBER _vol READ vol)		//회전율
	Q_PROPERTY(QString shcode MEMBER _shcode READ shcode)		//단축코드
	Q_PROPERTY(long value MEMBER _value READ value)		//누적거래대금
	Q_PROPERTY(long jvolume MEMBER _jvolume READ jvolume)		//전일동시간거래량
	Q_PROPERTY(long highyear MEMBER _highyear READ highyear)		//연중최고가
	Q_PROPERTY(QDate highyeardate MEMBER _highyeardate READ highyeardate)		//연중최고일자
	Q_PROPERTY(long lowyear MEMBER _lowyear READ lowyear)		//연중최저가
	Q_PROPERTY(QDate lowyeardate MEMBER _lowyeardate READ lowyeardate)		//연중최저일자
	Q_PROPERTY(long target MEMBER _target READ target)		//목표가
	Q_PROPERTY(long capital MEMBER _capital READ capital)		//자본금
	Q_PROPERTY(long abscnt MEMBER _abscnt READ abscnt)		//유동주식수
	Q_PROPERTY(long parprice MEMBER _parprice READ parprice)		//액면가
	Q_PROPERTY(QString gsmm MEMBER _gsmm READ gsmm)		//결산월
	Q_PROPERTY(long subprice MEMBER _subprice READ subprice)		//대용가
	Q_PROPERTY(long total MEMBER _total READ total)		//시가총액
	Q_PROPERTY(QDate listdate MEMBER _listdate READ listdate)		//상장일
	Q_PROPERTY(QString name MEMBER _name READ name)		//전분기명
	Q_PROPERTY(long bfsales MEMBER _bfsales READ bfsales)		//전분기매출액
	Q_PROPERTY(long bfoperatingincome MEMBER _bfoperatingincome READ bfoperatingincome)		//전분기영업이익
	Q_PROPERTY(long bfordinaryincome MEMBER _bfordinaryincome READ bfordinaryincome)		//전분기경상이익
	Q_PROPERTY(long bfnetincome MEMBER _bfnetincome READ bfnetincome)		//전분기순이익
	Q_PROPERTY(float bfeps MEMBER _bfeps READ bfeps)		//전분기EPS
	Q_PROPERTY(QString name2 MEMBER _name2 READ name2)		//전전분기명
	Q_PROPERTY(long bfsales2 MEMBER _bfsales2 READ bfsales2)		//전전분기매출액
	Q_PROPERTY(long bfoperatingincome2 MEMBER _bfoperatingincome2 READ bfoperatingincome2)		//전전분기영업이익
	Q_PROPERTY(long bfordinaryincome2 MEMBER _bfordinaryincome2 READ bfordinaryincome2)		//전전분기경상이익
	Q_PROPERTY(long bfnetincome2 MEMBER _bfnetincome2 READ bfnetincome2)		//전전분기순이익
	Q_PROPERTY(float bfeps2 MEMBER _bfeps2 READ bfeps2)		//전전분기EPS
	Q_PROPERTY(float salert MEMBER _salert READ salert)		//전년대비매출액
	Q_PROPERTY(float opert MEMBER _opert READ opert)		//전년대비영업이익
	Q_PROPERTY(float ordrt MEMBER _ordrt READ ordrt)		//전년대비경상이익
	Q_PROPERTY(float netrt MEMBER _netrt READ netrt)		//전년대비순이익
	Q_PROPERTY(float epsrt MEMBER _epsrt READ epsrt)		//전년대비EPS
	Q_PROPERTY(QString info1 MEMBER _info1 READ info1)		//락구분
	Q_PROPERTY(QString info2 MEMBER _info2 READ info2)		//관리/급등구분
	Q_PROPERTY(QString info3 MEMBER _info3 READ info3)		//정지/연장구분
	Q_PROPERTY(QString info4 MEMBER _info4 READ info4)		//투자/불성실구분
	Q_PROPERTY(QString janginfo MEMBER _janginfo READ janginfo)		//장구분
	Q_PROPERTY(float t_per MEMBER _t_per READ t_per)		//T.PER
	Q_PROPERTY(QString tonghwa MEMBER _tonghwa READ tonghwa)		//통화ISO코드
	Q_PROPERTY(long dval1 MEMBER _dval1 READ dval1)		//총매도대금1
	Q_PROPERTY(long sval1 MEMBER _sval1 READ sval1)		//총매수대금1
	Q_PROPERTY(long dval2 MEMBER _dval2 READ dval2)		//총매도대금2
	Q_PROPERTY(long sval2 MEMBER _sval2 READ sval2)		//총매수대금2
	Q_PROPERTY(long dval3 MEMBER _dval3 READ dval3)		//총매도대금3
	Q_PROPERTY(long sval3 MEMBER _sval3 READ sval3)		//총매수대금3
	Q_PROPERTY(long dval4 MEMBER _dval4 READ dval4)		//총매도대금4
	Q_PROPERTY(long sval4 MEMBER _sval4 READ sval4)		//총매수대금4
	Q_PROPERTY(long dval5 MEMBER _dval5 READ dval5)		//총매도대금5
	Q_PROPERTY(long sval5 MEMBER _sval5 READ sval5)		//총매수대금5
	Q_PROPERTY(long davg1 MEMBER _davg1 READ davg1)		//총매도평단가1
	Q_PROPERTY(long savg1 MEMBER _savg1 READ savg1)		//총매수평단가1
	Q_PROPERTY(long davg2 MEMBER _davg2 READ davg2)		//총매도평단가2
	Q_PROPERTY(long savg2 MEMBER _savg2 READ savg2)		//총매수평단가2
	Q_PROPERTY(long davg3 MEMBER _davg3 READ davg3)		//총매도평단가3
	Q_PROPERTY(long savg3 MEMBER _savg3 READ savg3)		//총매수평단가3
	Q_PROPERTY(long davg4 MEMBER _davg4 READ davg4)		//총매도평단가4
	Q_PROPERTY(long savg4 MEMBER _savg4 READ savg4)		//총매수평단가4
	Q_PROPERTY(long davg5 MEMBER _davg5 READ davg5)		//총매도평단가5
	Q_PROPERTY(long savg5 MEMBER _savg5 READ savg5)		//총매수평단가5
	Q_PROPERTY(long ftradmdval MEMBER _ftradmdval READ ftradmdval)		//외국계매도대금
	Q_PROPERTY(long ftradmsval MEMBER _ftradmsval READ ftradmsval)		//외국계매수대금
	Q_PROPERTY(long ftradmdvag MEMBER _ftradmdvag READ ftradmdvag)		//외국계매도평단가
	Q_PROPERTY(long ftradmsvag MEMBER _ftradmsvag READ ftradmsvag)		//외국계매수평단가
	Q_PROPERTY(QString info5 MEMBER _info5 READ info5)		//투자주의환기
	Q_PROPERTY(QString spac_gubun MEMBER _spac_gubun READ spac_gubun)		//기업인수목적회사여부
	Q_PROPERTY(long issueprice MEMBER _issueprice READ issueprice)		//발행가격
	Q_PROPERTY(QString alloc_gubun MEMBER _alloc_gubun READ alloc_gubun)		//배분적용구분코드(1:배분발생2:배분해제그외:미발생)
	Q_PROPERTY(QString alloc_text MEMBER _alloc_text READ alloc_text)		//배분적용구분
	Q_PROPERTY(QString shterm_text MEMBER _shterm_text READ shterm_text)		//단기과열/VI발동
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
	QString _hname;		//한글명
	long _price;		//현재가
	QString _sign;		//전일대비구분
	long _change;		//전일대비
	float _diff;		//등락율
	long _volume;		//누적거래량
	long _recprice;		//기준가
	long _avg;		//가중평균
	long _uplmtprice;		//상한가
	long _dnlmtprice;		//하한가
	long _jnilvolume;		//전일거래량
	long _volumediff;		//거래량차
	long _open;		//시가
	QTime _opentime;		//시가시간
	long _high;		//고가
	QTime _hightime;		//고가시간
	long _low;		//저가
	QTime _lowtime;		//저가시간
	long _high52w;		//52최고가
	QDate _high52wdate;		//52최고가일
	long _low52w;		//52최저가
	QDate _low52wdate;		//52최저가일
	float _exhratio;		//소진율
	float _per;		//PER
	float _pbrx;		//PBRX
	long _listing;		//상장주식수(천)
	long _jkrate;		//증거금율
	QString _memedan;		//수량단위
	QString _offernocd1;		//매도증권사코드1
	QString _bidnocd1;		//매수증권사코드1
	QString _offerno1;		//매도증권사명1
	QString _bidno1;		//매수증권사명1
	long _dvol1;		//총매도수량1
	long _svol1;		//총매수수량1
	long _dcha1;		//매도증감1
	long _scha1;		//매수증감1
	float _ddiff1;		//매도비율1
	float _sdiff1;		//매수비율1
	QString _offernocd2;		//매도증권사코드2
	QString _bidnocd2;		//매수증권사코드2
	QString _offerno2;		//매도증권사명2
	QString _bidno2;		//매수증권사명2
	long _dvol2;		//총매도수량2
	long _svol2;		//총매수수량2
	long _dcha2;		//매도증감2
	long _scha2;		//매수증감2
	float _ddiff2;		//매도비율2
	float _sdiff2;		//매수비율2
	QString _offernocd3;		//매도증권사코드3
	QString _bidnocd3;		//매수증권사코드3
	QString _offerno3;		//매도증권사명3
	QString _bidno3;		//매수증권사명3
	long _dvol3;		//총매도수량3
	long _svol3;		//총매수수량3
	long _dcha3;		//매도증감3
	long _scha3;		//매수증감3
	float _ddiff3;		//매도비율3
	float _sdiff3;		//매수비율3
	QString _offernocd4;		//매도증권사코드4
	QString _bidnocd4;		//매수증권사코드4
	QString _offerno4;		//매도증권사명4
	QString _bidno4;		//매수증권사명4
	long _dvol4;		//총매도수량4
	long _svol4;		//총매수수량4
	long _dcha4;		//매도증감4
	long _scha4;		//매수증감4
	float _ddiff4;		//매도비율4
	float _sdiff4;		//매수비율4
	QString _offernocd5;		//매도증권사코드5
	QString _bidnocd5;		//매수증권사코드5
	QString _offerno5;		//매도증권사명5
	QString _bidno5;		//매수증권사명5
	long _dvol5;		//총매도수량5
	long _svol5;		//총매수수량5
	long _dcha5;		//매도증감5
	long _scha5;		//매수증감5
	float _ddiff5;		//매도비율5
	float _sdiff5;		//매수비율5
	long _fwdvl;		//외국계매도합계수량
	long _ftradmdcha;		//외국계매도직전대비
	float _ftradmddiff;		//외국계매도비율
	long _fwsvl;		//외국계매수합계수량
	long _ftradmscha;		//외국계매수직전대비
	float _ftradmsdiff;		//외국계매수비율
	float _vol;		//회전율
	QString _shcode;		//단축코드
	long _value;		//누적거래대금
	long _jvolume;		//전일동시간거래량
	long _highyear;		//연중최고가
	QDate _highyeardate;		//연중최고일자
	long _lowyear;		//연중최저가
	QDate _lowyeardate;		//연중최저일자
	long _target;		//목표가
	long _capital;		//자본금
	long _abscnt;		//유동주식수
	long _parprice;		//액면가
	QString _gsmm;		//결산월
	long _subprice;		//대용가
	long _total;		//시가총액
	QDate _listdate;		//상장일
	QString _name;		//전분기명
	long _bfsales;		//전분기매출액
	long _bfoperatingincome;		//전분기영업이익
	long _bfordinaryincome;		//전분기경상이익
	long _bfnetincome;		//전분기순이익
	float _bfeps;		//전분기EPS
	QString _name2;		//전전분기명
	long _bfsales2;		//전전분기매출액
	long _bfoperatingincome2;		//전전분기영업이익
	long _bfordinaryincome2;		//전전분기경상이익
	long _bfnetincome2;		//전전분기순이익
	float _bfeps2;		//전전분기EPS
	float _salert;		//전년대비매출액
	float _opert;		//전년대비영업이익
	float _ordrt;		//전년대비경상이익
	float _netrt;		//전년대비순이익
	float _epsrt;		//전년대비EPS
	QString _info1;		//락구분
	QString _info2;		//관리/급등구분
	QString _info3;		//정지/연장구분
	QString _info4;		//투자/불성실구분
	QString _janginfo;		//장구분
	float _t_per;		//T.PER
	QString _tonghwa;		//통화ISO코드
	long _dval1;		//총매도대금1
	long _sval1;		//총매수대금1
	long _dval2;		//총매도대금2
	long _sval2;		//총매수대금2
	long _dval3;		//총매도대금3
	long _sval3;		//총매수대금3
	long _dval4;		//총매도대금4
	long _sval4;		//총매수대금4
	long _dval5;		//총매도대금5
	long _sval5;		//총매수대금5
	long _davg1;		//총매도평단가1
	long _savg1;		//총매수평단가1
	long _davg2;		//총매도평단가2
	long _savg2;		//총매수평단가2
	long _davg3;		//총매도평단가3
	long _savg3;		//총매수평단가3
	long _davg4;		//총매도평단가4
	long _savg4;		//총매수평단가4
	long _davg5;		//총매도평단가5
	long _savg5;		//총매수평단가5
	long _ftradmdval;		//외국계매도대금
	long _ftradmsval;		//외국계매수대금
	long _ftradmdvag;		//외국계매도평단가
	long _ftradmsvag;		//외국계매수평단가
	QString _info5;		//투자주의환기
	QString _spac_gubun;		//기업인수목적회사여부
	long _issueprice;		//발행가격
	QString _alloc_gubun;		//배분적용구분코드(1:배분발생2:배분해제그외:미발생)
	QString _alloc_text;		//배분적용구분
	QString _shterm_text;		//단기과열/VI발동
};

#endif //T1102ITEM
