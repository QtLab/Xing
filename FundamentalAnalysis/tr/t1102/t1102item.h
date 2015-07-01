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
    char    _open                ;    // [long  ,    8] 시가
    char    _opentime            ;    // [string,    6] 시가시간
    char    _high                ;    // [long  ,    8] 고가
    char    _hightime            ;    // [string,    6] 고가시간
    char    _low                 ;    // [long  ,    8] 저가
    char    _lowtime             ;    // [string,    6] 저가시간
    char    _high52w             ;    // [long  ,    8] 52최고가
    char    _high52wdate         ;    // [string,    8] 52최고가일
    char    _low52w              ;    // [long  ,    8] 52최저가
    char    _low52wdate          ;    // [string,    8] 52최저가일
    char    _exhratio            ;    // [float ,  6.2] 소진율
    char    _per                 ;    // [float ,  6.2] PER
    char    _pbrx                ;    // [float ,  6.2] PBRX
    char    _listing             ;    // [long  ,   12] 상장주식수(천)
    char    _jkrate              ;    // [long  ,    8] 증거금율
    char    _memedan             ;    // [string,    5] 수량단위
    char    _offernocd1          ;    // [string,    3] 매도증권사코드1
    char    _bidnocd1            ;    // [string,    3] 매수증권사코드1
    char    _offerno1            ;    // [string,    6] 매도증권사명1
    char    _bidno1              ;    // [string,    6] 매수증권사명1
    char    _dvol1               ;    // [long  ,    8] 총매도수량1
    char    _svol1               ;    // [long  ,    8] 총매수수량1
    char    _dcha1               ;    // [long  ,    8] 매도증감1
    char    _scha1               ;    // [long  ,    8] 매수증감1
    char    _ddiff1              ;    // [float ,  6.2] 매도비율1
    char    _sdiff1              ;    // [float ,  6.2] 매수비율1
    char    _offernocd2          ;    // [string,    3] 매도증권사코드2
    char    _bidnocd2            ;    // [string,    3] 매수증권사코드2
    char    _offerno2            ;    // [string,    6] 매도증권사명2
    char    _bidno2              ;    // [string,    6] 매수증권사명2
    char    _dvol2               ;    // [long  ,    8] 총매도수량2
    char    _svol2               ;    // [long  ,    8] 총매수수량2
    char    _dcha2               ;    // [long  ,    8] 매도증감2
    char    _scha2               ;    // [long  ,    8] 매수증감2
    char    _ddiff2              ;    // [float ,  6.2] 매도비율2
    char    _sdiff2              ;    // [float ,  6.2] 매수비율2
    char    _offernocd3          ;    // [string,    3] 매도증권사코드3
    char    _bidnocd3            ;    // [string,    3] 매수증권사코드3
    char    _offerno3            ;    // [string,    6] 매도증권사명3
    char    _bidno3              ;    // [string,    6] 매수증권사명3
    char    _dvol3               ;    // [long  ,    8] 총매도수량3
    char    _svol3               ;    // [long  ,    8] 총매수수량3
    char    _dcha3               ;    // [long  ,    8] 매도증감3
    char    _scha3               ;    // [long  ,    8] 매수증감3
    char    _ddiff3              ;    // [float ,  6.2] 매도비율3
    char    _sdiff3              ;    // [float ,  6.2] 매수비율3
    char    _offernocd4          ;    // [string,    3] 매도증권사코드4
    char    _bidnocd4            ;    // [string,    3] 매수증권사코드4
    char    _offerno4            ;    // [string,    6] 매도증권사명4
    char    _bidno4              ;    // [string,    6] 매수증권사명4
    char    _dvol4               ;    // [long  ,    8] 총매도수량4
    char    _svol4               ;    // [long  ,    8] 총매수수량4
    char    _dcha4               ;    // [long  ,    8] 매도증감4
    char    _scha4               ;    // [long  ,    8] 매수증감4
    char    _ddiff4              ;    // [float ,  6.2] 매도비율4
    char    _sdiff4              ;    // [float ,  6.2] 매수비율4
    char    _offernocd5          ;    // [string,    3] 매도증권사코드5
    char    _bidnocd5            ;    // [string,    3] 매수증권사코드5
    char    _offerno5            ;    // [string,    6] 매도증권사명5
    char    _bidno5              ;    // [string,    6] 매수증권사명5
    char    _dvol5               ;    // [long  ,    8] 총매도수량5
    char    _svol5               ;    // [long  ,    8] 총매수수량5
    char    _dcha5               ;    // [long  ,    8] 매도증감5
    char    _scha5               ;    // [long  ,    8] 매수증감5
    char    _ddiff5              ;    // [float ,  6.2] 매도비율5
    char    _sdiff5              ;    // [float ,  6.2] 매수비율5
    char    _fwdvl               ;    // [long  ,   12] 외국계매도합계수량
    char    _ftradmdcha          ;    // [long  ,   12] 외국계매도직전대비
    char    _ftradmddiff         ;    // [float ,  6.2] 외국계매도비율
    char    _fwsvl               ;    // [long  ,   12] 외국계매수합계수량
    char    _ftradmscha          ;    // [long  ,   12] 외국계매수직전대비
    char    _ftradmsdiff         ;    // [float ,  6.2] 외국계매수비율
    char    _vol                 ;    // [float ,  6.2] 회전율
    char    _shcode              ;    // [string,    6] 단축코드
    char    _value               ;    // [long  ,   12] 누적거래대금
    char    _jvolume             ;    // [long  ,   12] 전일동시간거래량
    char    _highyear            ;    // [long  ,    8] 연중최고가
    char    _highyeardate        ;    // [string,    8] 연중최고일자
    char    _lowyear             ;    // [long  ,    8] 연중최저가
    char    _lowyeardate         ;    // [string,    8] 연중최저일자
    char    _target              ;    // [long  ,    8] 목표가
    char    _capital             ;    // [long  ,   12] 자본금
    char    _abscnt              ;    // [long  ,   12] 유동주식수
    char    _parprice            ;    // [long  ,    8] 액면가
    char    _gsmm                ;    // [string,    2] 결산월
    char    _subprice            ;    // [long  ,    8] 대용가
    char    _total               ;    // [long  ,   12] 시가총액
    char    _listdate            ;    // [string,    8] 상장일
    char    _name                ;    // [string,   10] 전분기명
    char    _bfsales             ;    // [long  ,   12] 전분기매출액
    char    _bfoperatingincome   ;    // [long  ,   12] 전분기영업이익
    char    _bfordinaryincome    ;    // [long  ,   12] 전분기경상이익
    char    _bfnetincome         ;    // [long  ,   12] 전분기순이익
    char    _bfeps               ;    // [float , 13.2] 전분기EPS
    char    _name2               ;    // [string,   10] 전전분기명
    char    _bfsales2            ;    // [long  ,   12] 전전분기매출액
    char    _bfoperatingincome2  ;    // [long  ,   12] 전전분기영업이익
    char    _bfordinaryincome2   ;    // [long  ,   12] 전전분기경상이익
    char    _bfnetincome2        ;    // [long  ,   12] 전전분기순이익
    char    _bfeps2              ;    // [float , 13.2] 전전분기EPS
    char    _salert              ;    // [float ,  7.2] 전년대비매출액
    char    _opert               ;    // [float ,  7.2] 전년대비영업이익
    char    _ordrt               ;    // [float ,  7.2] 전년대비경상이익
    char    _netrt               ;    // [float ,  7.2] 전년대비순이익
    char    _epsrt               ;    // [float ,  7.2] 전년대비EPS
    char    _info1               ;    // [string,   10] 락구분
    char    _info2               ;    // [string,   10] 관리/급등구분
    char    _info3               ;    // [string,   10] 정지/연장구분
    char    _info4               ;    // [string,   12] 투자/불성실구분
    char    _janginfo            ;    // [string,   10] 장구분
    char    _t_per               ;    // [float ,  6.2] T.PER
    char    _tonghwa             ;    // [string,    3] 통화ISO코드
    char    _dval1               ;    // [long  ,   18] 총매도대금1
    char    _sval1               ;    // [long  ,   18] 총매수대금1
    char    _dval2               ;    // [long  ,   18] 총매도대금2
    char    _sval2               ;    // [long  ,   18] 총매수대금2
    char    _dval3               ;    // [long  ,   18] 총매도대금3
    char    _sval3               ;    // [long  ,   18] 총매수대금3
    char    _dval4               ;    // [long  ,   18] 총매도대금4
    char    _sval4               ;    // [long  ,   18] 총매수대금4
    char    _dval5               ;    // [long  ,   18] 총매도대금5
    char    _sval5               ;    // [long  ,   18] 총매수대금5
    char    _davg1               ;    // [long  ,    8] 총매도평단가1
    char    _savg1               ;    // [long  ,    8] 총매수평단가1
    char    _davg2               ;    // [long  ,    8] 총매도평단가2
    char    _savg2               ;    // [long  ,    8] 총매수평단가2
    char    _davg3               ;    // [long  ,    8] 총매도평단가3
    char    _savg3               ;    // [long  ,    8] 총매수평단가3
    char    _davg4               ;    // [long  ,    8] 총매도평단가4
    char    _savg4               ;    // [long  ,    8] 총매수평단가4
    char    _davg5               ;    // [long  ,    8] 총매도평단가5
    char    _savg5               ;    // [long  ,    8] 총매수평단가5
    char    _ftradmdval          ;    // [long  ,   18] 외국계매도대금
    char    _ftradmsval          ;    // [long  ,   18] 외국계매수대금
    char    _ftradmdavg          ;    // [long  ,    8] 외국계매도평단가
    char    _ftradmsavg          ;    // [long  ,    8] 외국계매수평단가
    char    _info5               ;    // [string,    8] 투자주의환기
    char    _spac_gubun          ;    // [string,    1] 기업인수목적회사여부
    char    _issueprice          ;    // [long  ,    8] 발행가격
    char    _alloc_gubun         ;    // [string,    1] 배분적용구분코드(1:배분발생2:배
    char    _alloc_text          ;    // [string,    8] 배분적용구분
    char    _shterm_text         ;    // [string,   10] 단기과열/VI발동

};

#endif // T1102ITEM_H
