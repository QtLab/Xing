#ifndef T1102ITEM_H
#define T1102ITEM_H

#include <QObject>
#include <QString>
#include <Qtime>
#include <Qdate>
#include "tr/tritem.h"
class T1102Item : public TrItem
{
    Q_OBJECT
    Q_PROPERTY(QString hname MEMBER _hname READ date)
    Q_PROPERTY(long price MEMBER _price READ price)
    Q_PROPERTY(bool sign MEMBER _sign READ sign)
    Q_PROPERTY(long change MEMBER _change READ change)
    Q_PROPERTY(float diff MEMBER _diff READ diff)
    Q_PROPERTY(long volume MEMBER _volume READ volume)
    Q_PROPERTY(long recprice MEMBER _recprice READ recprice)
    Q_PROPERTY(long avg MEMBER _avg READ avg)
    Q_PROPERTY(long uplmtprice MEMBER _uplmtprice READ uplmtprice)
    Q_PROPERTY(long dnlmtprice MEMBER _dnlmtprice READ dnlmtprice)
    Q_PROPERTY(long jnilvolume MEMBER _jnilvolume READ jnilvolume)
    Q_PROPERTY(long volumediff MEMBER _volumediff READ volumediff)
    Q_PROPERTY(long open MEMBER _open READ open)
    Q_PROPERTY(QString opentime MEMBER _opentime READ opentime)
    Q_PROPERTY(long high MEMBER _high READ high)
    Q_PROPERTY(QString hightime MEMBER _hightime READ hightime)
    Q_PROPERTY(long low MEMBER _low READ low)
    Q_PROPERTY(QString lowtime MEMBER _lowtime READ lowtime)
    Q_PROPERTY(long high52w MEMBER _high52w READ high52w)
    Q_PROPERTY(QString high52wdate MEMBER _high52wdate READ high52wdate)
    Q_PROPERTY(long low52w MEMBER _low52w READ low52w)
    Q_PROPERTY(QString low52wdate MEMBER _low52wdate READ low52wdate)
    Q_PROPERTY(float exhratio MEMBER _exhratio READ exhratio)
    Q_PROPERTY(float per MEMBER _per READ per)
    Q_PROPERTY(float pbrs MEMBER _pbrx READ pbrx)
    Q_PROPERTY(long listing MEMBER _listing READ listing)
    Q_PROPERTY(long jkrate MEMBER _jkrate READ jkrate)
    Q_PROPERTY(QString memedan MEMBER _memedan READ memedan)
    Q_PROPERTY(QString offernocd1 MEMBER _offernocd1 READ offernocd1)
    Q_PROPERTY(QString bidnocd1 MEMBER _bidnocd1 READ bidnocd1)
    Q_PROPERTY(QString offerno1 MEMBER _offerno1 READ offerno1)
    Q_PROPERTY(QString bidno1 MEMBER _bidno1 READ bidno1)
    Q_PROPERTY(long dvol1 MEMBER _dvol1 READ dvol1)
    Q_PROPERTY(long svol1 MEMBER _svol1 READ svol1)
    Q_PROPERTY(long dcha1 MEMBER _dcha1 READ dcha1)
    Q_PROPERTY(long scha1 MEMBER _scha1 READ scha1)
    Q_PROPERTY(float ddiff1 MEMBER _ddiff1 READ ddiff1)
    Q_PROPERTY(float sdiff1 MEMBER _sdiff1 READ sdiff1)
    Q_PROPERTY(QString offernocd2 MEMBER _offernocd2 READ offernocd2)
    Q_PROPERTY(QString bidnocd2 MEMBER _bidnocd2 READ bidnocd2)
    Q_PROPERTY(QString offerno2 MEMBER _offerno2 READ offerno2)
    Q_PROPERTY(QString bidno2 MEMBER _bidno2 READ bidno2)
    Q_PROPERTY(long dvol2 MEMBER _dvol2 READ dvol2)
    Q_PROPERTY(long svol2 MEMBER _svol2 READ svol2)
    Q_PROPERTY(long dcha2 MEMBER _dcha2 READ dcha2)
    Q_PROPERTY(long scha2 MEMBER _scha2 READ scha2)
    Q_PROPERTY(float ddiff2 MEMBER _ddiff2 READ ddiff2)
    Q_PROPERTY(float sdiff2 MEMBER _sdiff2 READ sdiff2)
    Q_PROPERTY(QString offernocd3 MEMBER _offernocd3 READ offernocd3)
    Q_PROPERTY(QString bidnocd3 MEMBER _bidnocd3 READ bidnocd3)
    Q_PROPERTY(QString offerno3 MEMBER _offerno3 READ offerno3)
    Q_PROPERTY(QString bidno3 MEMBER _bidno3 READ bidno3)
    Q_PROPERTY(long dvol3 MEMBER _dvol3 READ dvol3)
    Q_PROPERTY(long svol3 MEMBER _svol3 READ svol3)
    Q_PROPERTY(long dcha3 MEMBER _dcha3 READ dcha3)
    Q_PROPERTY(long scha3 MEMBER _scha3 READ scha3)
    Q_PROPERTY(float ddiff3 MEMBER _ddiff3 READ ddiff3)
    Q_PROPERTY(float sdiff3 MEMBER _sdiff3 READ sdiff3)
    Q_PROPERTY(QString offernocd4 MEMBER _offernocd4 READ offernocd4)
    Q_PROPERTY(QString bidnocd4 MEMBER _bidnocd4 READ bidnocd4)
    Q_PROPERTY(QString offerno4 MEMBER _offerno4 READ offerno4)
    Q_PROPERTY(QString bidno4 MEMBER _bidno4 READ bidno4)
    Q_PROPERTY(long dvol4 MEMBER _dvol4 READ dvol4)
    Q_PROPERTY(long svol4 MEMBER _svol4 READ svol4)
    Q_PROPERTY(long dcha4 MEMBER _dcha4 READ dcha4)
    Q_PROPERTY(long scha4 MEMBER _scha4 READ scha4)
    Q_PROPERTY(float ddiff4 MEMBER _ddiff4 READ ddiff4)
    Q_PROPERTY(float sdiff4 MEMBER _sdiff4 READ sdiff4)
    Q_PROPERTY(QString offernocd5 MEMBER _offernocd5 READ offernocd5)
    Q_PROPERTY(QString bidnocd5 MEMBER _bidnocd5 READ bidnocd5)
    Q_PROPERTY(QString offerno5 MEMBER _offerno5 READ offerno5)
    Q_PROPERTY(QString bidno5 MEMBER _bidno5 READ bidno5)
    Q_PROPERTY(long dvol5 MEMBER _dvol5 READ dvol5)
    Q_PROPERTY(long svol5 MEMBER _svol5 READ svol5)
    Q_PROPERTY(long dcha5 MEMBER _dcha5 READ dcha5)
    Q_PROPERTY(long scha5 MEMBER _dcha5 READ dcha5)
    Q_PROPERTY(float ddiff5 MEMBER _ddiff5 READ ddiff5)
    Q_PROPERTY(float sdiff5 MEMBER _sdiff5 READ sdiff5)
    Q_PROPERTY(long fwdvl MEMBER _fwdvl READ fwdvl)
    Q_PROPERTY(long ftradmdcha MEMBER _ftradmdcha READ ftradmdcha)
    Q_PROPERTY(float ftradmddiff MEMBER _ftradmddiff READ ftradmddiff)
    Q_PROPERTY(long fwsvl MEMBER _fwsvl READ fwsvl)
    Q_PROPERTY(long ftradmscha MEMBER _ftradmscha READ ftradmscha)
    Q_PROPERTY(float ftradmsdiff MEMBER _ftradmsdiff READ ftradmsdiff)
    Q_PROPERTY(float vol MEMBER _vol READ vol)
    Q_PROPERTY(QString shcode MEMBER _shcode READ shcode)
    Q_PROPERTY(long value MEMBER _value READ value)
    Q_PROPERTY(long jvolume MEMBER _jvolume READ jvolume)
    Q_PROPERTY(long highyear MEMBER _highyear READ highyear)
    Q_PROPERTY(QString highyeardate MEMBER _highyeardate READ highyeardate)
    Q_PROPERTY(long lowyear MEMBER _lowyear READ lowyear)
    Q_PROPERTY(QString lowyeardate MEMBER _lowyeardate READ lowyeardate)
    Q_PROPERTY(long target MEMBER _target READ target)
    Q_PROPERTY(long capital MEMBER _capital READ capital)
    Q_PROPERTY(long abscnt MEMBER _abscnt READ abscnt)
    Q_PROPERTY(long parprice MEMBER _parprice READ parprice)
    Q_PROPERTY(QString gsmm MEMBER _gsmm READ gsmm)
    Q_PROPERTY(long subprice MEMBER _subprice READ subprice)
    Q_PROPERTY(long total MEMBER _total READ total)
    Q_PROPERTY(QString listdate MEMBER _listdate READ listdate)
    Q_PROPERTY(QString name MEMBER _name READ name)
    Q_PROPERTY(long bfsales MEMBER _bfsales READ bfsales)
    Q_PROPERTY(long bfoperatingincome MEMBER _bfoperatingincome READ bfoperatingincome)
    Q_PROPERTY(long bfordinaryincome MEMBER _bfordinaryincome READ bfordinaryincome)
    Q_PROPERTY(long bfnetincome MEMBER _bfnetincome READ bfnetincome)
    Q_PROPERTY(float bfeps MEMBER _bfeps READ bfeps)
    Q_PROPERTY(QString name2 MEMBER _name2 READ name2)
    Q_PROPERTY(long bfsales2 MEMBER _bfsales2 READ bfsales2)
    Q_PROPERTY(long bfoperatingincome2 MEMBER _bfoperatingincome2 READ bfoperatingincome2)
    Q_PROPERTY(long bfordinaryincome2 MEMBER _bfordinaryincome2 READ bfordinaryincome2)
    Q_PROPERTY(long bfnetincome2 MEMBER _bfnetincome2 READ bfnetincome2)
    Q_PROPERTY(float bfeps2 MEMBER _bfeps2 READ bfeps2)
    Q_PROPERTY(float salert MEMBER _salert READ salert)
    Q_PROPERTY(float opert MEMBER _opert READ opert)
    Q_PROPERTY(float ordrt MEMBER _ordrt READ ordrt)
    Q_PROPERTY(float netrt MEMBER _netrt READ netrt)
    Q_PROPERTY(float epsrt MEMBER _epsrt READ epsrt)
    Q_PROPERTY(QString info1 MEMBER _info1 READ info1)
    Q_PROPERTY(QString info2 MEMBER _info2 READ info2)
    Q_PROPERTY(QString info3 MEMBER _info3 READ info3)
    Q_PROPERTY(QString info4 MEMBER _info4 READ info4)
    Q_PROPERTY(QString janginfo MEMBER _janginfo READ janginfo)
    Q_PROPERTY(QString t_per MEMBER _t_per READ t_per)
    Q_PROPERTY(QString tonghwa MEMBER _tonghwa READ tonghwa)
    Q_PROPERTY(long dval1 MEMBER _dval1 READ dval1)
    Q_PROPERTY(long sval1 MEMBER _sval1 READ sval1)
    Q_PROPERTY(long dval2 MEMBER _dval2 READ dval2)
    Q_PROPERTY(long sval2 MEMBER _sval2 READ sval2)
    Q_PROPERTY(long dval3 MEMBER _dval3 READ dval3)
    Q_PROPERTY(long sval3 MEMBER _sval3 READ sval3)
    Q_PROPERTY(long dval4 MEMBER _dval4 READ dval4)
    Q_PROPERTY(long sval4 MEMBER _sval4 READ sval4)
    Q_PROPERTY(long dval5 MEMBER _dval5 READ dval5)
    Q_PROPERTY(long sval5 MEMBER _sval5 READ sval5)
    Q_PROPERTY(long davg1 MEMBER _davg1 READ davg1)
    Q_PROPERTY(long savg1 MEMBER _savg1 READ savg1)
    Q_PROPERTY(long davg2 MEMBER _davg2 READ davg2)
    Q_PROPERTY(long savg2 MEMBER _savg2 READ savg2)
    Q_PROPERTY(long davg3 MEMBER _davg3 READ davg3)
    Q_PROPERTY(long savg3 MEMBER _savg3 READ savg3)
    Q_PROPERTY(long davg4 MEMBER _davg4 READ davg4)
    Q_PROPERTY(long savg4 MEMBER _savg4 READ savg4)
    Q_PROPERTY(long davg5 MEMBER _davg5 READ davg5)
    Q_PROPERTY(long savg5 MEMBER _savg5 READ savg5)
    Q_PROPERTY(long ftradmdval MEMBER _ftradmdval READ ftradmdval)
    Q_PROPERTY(long ftradmsval MEMBER _ftradmsval READ ftradmsval)
    Q_PROPERTY(long ftradmdavg MEMBER _ftradmdavg READ ftradmdavg)
    Q_PROPERTY(long ftradmsavg MEMBER _ftradmsavg READ ftradmsavg)
    Q_PROPERTY(QString info5 MEMBER _info5 READ info5)
    Q_PROPERTY(QString spac_gubun MEMBER _spac_gubun READ spac_gubun)
    Q_PROPERTY(long issueprice MEMBER _issueprice READ issueprice)
    Q_PROPERTY(QString alloc_gubun MEMBER _alloc_gubun READ alloc_gubun)
    Q_PROPERTY(QString alloc_text MEMBER _alloc_text READ alloc_text)
    Q_PROPERTY(QString shterm_text MEMBER _shterm_text READ shterm_text)
public:
    T1102Item();
    ~T1102Item();



private:
    QString    _hname               ;    // [string,   20] 한글명
    long    _price               ;    // [long  ,    8] 현재가
    bool    _sign                ;    // [string,    1] 전일대비구분
    long    _change              ;    // [long  ,    8] 전일대비
    float    _diff                ;    // [float ,  6.2] 등락율
    long    _volume              ;    // [long  ,   12] 누적거래량
    long    _recprice            ;    // [long  ,    8] 기준가
    long    _avg                 ;    // [long  ,    8] 가중평균
    long    _uplmtprice          ;    // [long  ,    8] 상한가
    long    _dnlmtprice          ;    // [long  ,    8] 하한가
    long    _jnilvolume          ;    // [long  ,   12] 전일거래량
    long    _volumediff          ;    // [long  ,   12] 거래량차
    long    _open                ;    // [long  ,    8] 시가
    QString    _opentime            ;    // [string,    6] 시가시간
    long    _high                ;    // [long  ,    8] 고가
    QString    _hightime            ;    // [string,    6] 고가시간
    long    _low                 ;    // [long  ,    8] 저가
    QString    _lowtime             ;    // [string,    6] 저가시간
    long    _high52w             ;    // [long  ,    8] 52최고가
    QString    _high52wdate         ;    // [string,    8] 52최고가일
    long    _low52w              ;    // [long  ,    8] 52최저가
    QString    _low52wdate          ;    // [string,    8] 52최저가일
    float    _exhratio            ;    // [float ,  6.2] 소진율
    float    _per                 ;    // [float ,  6.2] PER
    float    _pbrx                ;    // [float ,  6.2] PBRX
    long    _listing             ;    // [long  ,   12] 상장주식수(천)
    long    _jkrate              ;    // [long  ,    8] 증거금율
    QString    _memedan             ;    // [string,    5] 수량단위
    QString    _offernocd1          ;    // [string,    3] 매도증권사코드1
    QString    _bidnocd1            ;    // [string,    3] 매수증권사코드1
    QString    _offerno1            ;    // [string,    6] 매도증권사명1
    QString    _bidno1              ;    // [string,    6] 매수증권사명1
    long    _dvol1               ;    // [long  ,    8] 총매도수량1
    long    _svol1               ;    // [long  ,    8] 총매수수량1
    long    _dcha1               ;    // [long  ,    8] 매도증감1
    long    _scha1               ;    // [long  ,    8] 매수증감1
    float    _ddiff1              ;    // [float ,  6.2] 매도비율1
    float    _sdiff1              ;    // [float ,  6.2] 매수비율1
    QString    _offernocd2          ;    // [string,    3] 매도증권사코드2
    QString    _bidnocd2            ;    // [string,    3] 매수증권사코드2
    QString    _offerno2            ;    // [string,    6] 매도증권사명2
    QString    _bidno2              ;    // [string,    6] 매수증권사명2
    long    _dvol2               ;    // [long  ,    8] 총매도수량2
    long    _svol2               ;    // [long  ,    8] 총매수수량2
    long    _dcha2               ;    // [long  ,    8] 매도증감2
    long    _scha2               ;    // [long  ,    8] 매수증감2
    float    _ddiff2              ;    // [float ,  6.2] 매도비율2
    float    _sdiff2              ;    // [float ,  6.2] 매수비율2
    QString    _offernocd3          ;    // [string,    3] 매도증권사코드3
    QString    _bidnocd3            ;    // [string,    3] 매수증권사코드3
    QString    _offerno3            ;    // [string,    6] 매도증권사명3
    QString    _bidno3              ;    // [string,    6] 매수증권사명3
    long    _dvol3               ;    // [long  ,    8] 총매도수량3
    long    _svol3               ;    // [long  ,    8] 총매수수량3
    long    _dcha3               ;    // [long  ,    8] 매도증감3
    long    _scha3               ;    // [long  ,    8] 매수증감3
    float    _ddiff3              ;    // [float ,  6.2] 매도비율3
    float    _sdiff3              ;    // [float ,  6.2] 매수비율3
    QString    _offernocd4          ;    // [string,    3] 매도증권사코드4
    QString    _bidnocd4            ;    // [string,    3] 매수증권사코드4
    QString    _offerno4            ;    // [string,    6] 매도증권사명4
    QString    _bidno4              ;    // [string,    6] 매수증권사명4
    long    _dvol4               ;    // [long  ,    8] 총매도수량4
    long    _svol4               ;    // [long  ,    8] 총매수수량4
    long    _dcha4               ;    // [long  ,    8] 매도증감4
    long    _scha4               ;    // [long  ,    8] 매수증감4
    float    _ddiff4              ;    // [float ,  6.2] 매도비율4
    float    _sdiff4              ;    // [float ,  6.2] 매수비율4
    QString    _offernocd5          ;    // [string,    3] 매도증권사코드5
    QString    _bidnocd5            ;    // [string,    3] 매수증권사코드5
    QString    _offerno5            ;    // [string,    6] 매도증권사명5
    QString    _bidno5              ;    // [string,    6] 매수증권사명5
    long    _dvol5               ;    // [long  ,    8] 총매도수량5
    long    _svol5               ;    // [long  ,    8] 총매수수량5
    long    _dcha5               ;    // [long  ,    8] 매도증감5
    long    _scha5               ;    // [long  ,    8] 매수증감5
    float    _ddiff5              ;    // [float ,  6.2] 매도비율5
    float    _sdiff5              ;    // [float ,  6.2] 매수비율5
    long    _fwdvl               ;    // [long  ,   12] 외국계매도합계수량
    long    _ftradmdcha          ;    // [long  ,   12] 외국계매도직전대비
    float    _ftradmddiff         ;    // [float ,  6.2] 외국계매도비율
    long    _fwsvl               ;    // [long  ,   12] 외국계매수합계수량
    long    _ftradmscha          ;    // [long  ,   12] 외국계매수직전대비
    float    _ftradmsdiff         ;    // [float ,  6.2] 외국계매수비율
    float    _vol                 ;    // [float ,  6.2] 회전율
    QString    _shcode              ;    // [string,    6] 단축코드
    long    _value               ;    // [long  ,   12] 누적거래대금
    long    _jvolume             ;    // [long  ,   12] 전일동시간거래량
    long    _highyear            ;    // [long  ,    8] 연중최고가
    QString    _highyeardate        ;    // [string,    8] 연중최고일자
    long    _lowyear             ;    // [long  ,    8] 연중최저가
    QString    _lowyeardate         ;    // [string,    8] 연중최저일자
    long    _target              ;    // [long  ,    8] 목표가
    long    _capital             ;    // [long  ,   12] 자본금
    long    _abscnt              ;    // [long  ,   12] 유동주식수
    long    _parprice            ;    // [long  ,    8] 액면가
    QString    _gsmm                ;    // [string,    2] 결산월
    long    _subprice            ;    // [long  ,    8] 대용가
    long    _total               ;    // [long  ,   12] 시가총액
    QString    _listdate            ;    // [string,    8] 상장일
    QString    _name                ;    // [string,   10] 전분기명
    long    _bfsales             ;    // [long  ,   12] 전분기매출액
    long    _bfoperatingincome   ;    // [long  ,   12] 전분기영업이익
    long    _bfordinaryincome    ;    // [long  ,   12] 전분기경상이익
    long    _bfnetincome         ;    // [long  ,   12] 전분기순이익
    float    _bfeps               ;    // [float , 13.2] 전분기EPS
    QString    _name2               ;    // [string,   10] 전전분기명
    long    _bfsales2            ;    // [long  ,   12] 전전분기매출액
    long    _bfoperatingincome2  ;    // [long  ,   12] 전전분기영업이익
    long    _bfordinaryincome2   ;    // [long  ,   12] 전전분기경상이익
    long    _bfnetincome2        ;    // [long  ,   12] 전전분기순이익
    float    _bfeps2              ;    // [float , 13.2] 전전분기EPS
    float    _salert              ;    // [float ,  7.2] 전년대비매출액
    float    _opert               ;    // [float ,  7.2] 전년대비영업이익
    float    _ordrt               ;    // [float ,  7.2] 전년대비경상이익
    float    _netrt               ;    // [float ,  7.2] 전년대비순이익
    float    _epsrt               ;    // [float ,  7.2] 전년대비EPS
    QString    _info1               ;    // [string,   10] 락구분
    QString    _info2               ;    // [string,   10] 관리/급등구분
    QString    _info3               ;    // [string,   10] 정지/연장구분
    QString    _info4               ;    // [string,   12] 투자/불성실구분
    QString    _janginfo            ;    // [string,   10] 장구분
    QString    _t_per               ;    // [float ,  6.2] T.PER
    QString    _tonghwa             ;    // [string,    3] 통화ISO코드
    long    _dval1               ;    // [long  ,   18] 총매도대금1
    long    _sval1               ;    // [long  ,   18] 총매수대금1
    long    _dval2               ;    // [long  ,   18] 총매도대금2
    long    _sval2               ;    // [long  ,   18] 총매수대금2
    long    _dval3               ;    // [long  ,   18] 총매도대금3
    long    _sval3               ;    // [long  ,   18] 총매수대금3
    long    _dval4               ;    // [long  ,   18] 총매도대금4
    long    _sval4               ;    // [long  ,   18] 총매수대금4
    long    _dval5               ;    // [long  ,   18] 총매도대금5
    long    _sval5               ;    // [long  ,   18] 총매수대금5
    long    _davg1               ;    // [long  ,    8] 총매도평단가1
    long    _savg1               ;    // [long  ,    8] 총매수평단가1
    long    _davg2               ;    // [long  ,    8] 총매도평단가2
    long    _savg2               ;    // [long  ,    8] 총매수평단가2
    long    _davg3               ;    // [long  ,    8] 총매도평단가3
    long    _savg3               ;    // [long  ,    8] 총매수평단가3
    long    _davg4               ;    // [long  ,    8] 총매도평단가4
    long    _savg4               ;    // [long  ,    8] 총매수평단가4
    long    _davg5               ;    // [long  ,    8] 총매도평단가5
    long    _savg5               ;    // [long  ,    8] 총매수평단가5
    long    _ftradmdval          ;    // [long  ,   18] 외국계매도대금
    long    _ftradmsval          ;    // [long  ,   18] 외국계매수대금
    long    _ftradmdavg          ;    // [long  ,    8] 외국계매도평단가
    long    _ftradmsavg          ;    // [long  ,    8] 외국계매수평단가
    QString    _info5               ;    // [string,    8] 투자주의환기
    QString    _spac_gubun          ;    // [string,    1] 기업인수목적회사여부
    long    _issueprice          ;    // [long  ,    8] 발행가격
    QString    _alloc_gubun         ;    // [string,    1] 배분적용구분코드(1:배분발생2:배
    QString    _alloc_text          ;    // [string,    8] 배분적용구분
    QString    _shterm_text         ;    // [string,   10] 단기과열/VI발동

};

#endif // T1102ITEM_H
