#ifndef STOCKINFO_H
#define STOCKINFO_H
#include <QString>
#include <QObject>
#include <QDate>
#include <QTime>
#include "tr/tritem.h"
class StockInfo : public TrItem
{
    Q_OBJECT
    Q_PROPERTY(QString hname MEMBER _hname READ hname)
    Q_PROPERTY(QString expcode MEMBER _expcode READ expcode)
    Q_PROPERTY(bool isETF MEMBER _isETF READ isETF)
    Q_PROPERTY(bool isKOSPI MEMBER _isKOSPI READ isKOSPI)

    Q_PROPERTY(long price MEMBER _price READ price WRITE setPrice)		//현재가
    Q_PROPERTY(QString sign MEMBER _sign READ sign WRITE setSign)		//전일대비구분
    Q_PROPERTY(long change MEMBER _change READ change WRITE setChange)		//전일대비
    Q_PROPERTY(float diff MEMBER _diff READ diff WRITE setDiff)		//등락율
    Q_PROPERTY(long volume MEMBER _volume READ volume WRITE setVolume)		//누적거래량
    Q_PROPERTY(long recprice MEMBER _recprice READ recprice WRITE setRecprice)		//기준가
    Q_PROPERTY(long avg MEMBER _avg READ avg WRITE setAvg)		//가중평균
    Q_PROPERTY(long uplmtprice MEMBER _uplmtprice READ uplmtprice WRITE setUplmtprice)		//상한가
    Q_PROPERTY(long dnlmtprice MEMBER _dnlmtprice READ dnlmtprice WRITE setDnlmtprice)		//하한가
    Q_PROPERTY(long jnilvolume MEMBER _jnilvolume READ jnilvolume WRITE setJnilvolume)		//전일거래량
    Q_PROPERTY(long volumediff MEMBER _volumediff READ volumediff WRITE setVolumediff)		//거래량차
    Q_PROPERTY(long open MEMBER _open READ open WRITE setOpen)		//시가
    Q_PROPERTY(QTime opentime MEMBER _opentime READ opentime WRITE setOpentime)		//시가시간
    Q_PROPERTY(long high MEMBER _high READ high WRITE setHigh)		//고가
    Q_PROPERTY(QTime hightime MEMBER _hightime READ hightime WRITE setHightime)		//고가시간
    Q_PROPERTY(long low MEMBER _low READ low WRITE setLow)		//저가
    Q_PROPERTY(QTime lowtime MEMBER _lowtime READ lowtime WRITE setLowtime)		//저가시간
    Q_PROPERTY(long high52w MEMBER _high52w READ high52w WRITE setHigh52W)		//52최고가
    Q_PROPERTY(QDate high52wdate MEMBER _high52wdate READ high52wdate WRITE setHigh52Wdate)		//52최고가일
    Q_PROPERTY(long low52w MEMBER _low52w READ low52w WRITE setLow52W)		//52최저가
    Q_PROPERTY(QDate low52wdate MEMBER _low52wdate READ low52wdate WRITE setLow52Wdate)		//52최저가일
    Q_PROPERTY(float exhratio MEMBER _exhratio READ exhratio WRITE setExhratio)		//소진율
    Q_PROPERTY(float per MEMBER _per READ per WRITE setPer)		//PER
    Q_PROPERTY(float pbrx MEMBER _pbrx READ pbrx WRITE setPbrx)		//PBRX
    Q_PROPERTY(long listing MEMBER _listing READ listing WRITE setListing)		//상장주식수(천)
    Q_PROPERTY(long jkrate MEMBER _jkrate READ jkrate WRITE setJkrate)		//증거금율
    Q_PROPERTY(QString memedan MEMBER _memedan READ memedan WRITE setMemedan)		//수량단위
    Q_PROPERTY(QString offernocd1 MEMBER _offernocd1 READ offernocd1 WRITE setOffernocd1)		//매도증권사코드1
    Q_PROPERTY(QString bidnocd1 MEMBER _bidnocd1 READ bidnocd1 WRITE setBidnocd1)		//매수증권사코드1
    Q_PROPERTY(QString offerno1 MEMBER _offerno1 READ offerno1 WRITE setOfferno1)		//매도증권사명1
    Q_PROPERTY(QString bidno1 MEMBER _bidno1 READ bidno1 WRITE setBidno1)		//매수증권사명1
    Q_PROPERTY(long dvol1 MEMBER _dvol1 READ dvol1 WRITE setDvol1)		//총매도수량1
    Q_PROPERTY(long svol1 MEMBER _svol1 READ svol1 WRITE setSvol1)		//총매수수량1
    Q_PROPERTY(long dcha1 MEMBER _dcha1 READ dcha1 WRITE setDcha1)		//매도증감1
    Q_PROPERTY(long scha1 MEMBER _scha1 READ scha1 WRITE setScha1)		//매수증감1
    Q_PROPERTY(float ddiff1 MEMBER _ddiff1 READ ddiff1 WRITE setDdiff1)		//매도비율1
    Q_PROPERTY(float sdiff1 MEMBER _sdiff1 READ sdiff1 WRITE setSdiff1)		//매수비율1
    Q_PROPERTY(QString offernocd2 MEMBER _offernocd2 READ offernocd2 WRITE setOffernocd2)		//매도증권사코드2
    Q_PROPERTY(QString bidnocd2 MEMBER _bidnocd2 READ bidnocd2 WRITE setBidnocd2)		//매수증권사코드2
    Q_PROPERTY(QString offerno2 MEMBER _offerno2 READ offerno2 WRITE setOfferno2)		//매도증권사명2
    Q_PROPERTY(QString bidno2 MEMBER _bidno2 READ bidno2 WRITE setBidno2)		//매수증권사명2
    Q_PROPERTY(long dvol2 MEMBER _dvol2 READ dvol2 WRITE setDvol2)		//총매도수량2
    Q_PROPERTY(long svol2 MEMBER _svol2 READ svol2 WRITE setSvol2)		//총매수수량2
    Q_PROPERTY(long dcha2 MEMBER _dcha2 READ dcha2 WRITE setDcha2)		//매도증감2
    Q_PROPERTY(long scha2 MEMBER _scha2 READ scha2 WRITE setScha2)		//매수증감2
    Q_PROPERTY(float ddiff2 MEMBER _ddiff2 READ ddiff2 WRITE setDdiff2)		//매도비율2
    Q_PROPERTY(float sdiff2 MEMBER _sdiff2 READ sdiff2 WRITE setSdiff2)		//매수비율2
    Q_PROPERTY(QString offernocd3 MEMBER _offernocd3 READ offernocd3 WRITE setOffernocd3)		//매도증권사코드3
    Q_PROPERTY(QString bidnocd3 MEMBER _bidnocd3 READ bidnocd3 WRITE setBidnocd3)		//매수증권사코드3
    Q_PROPERTY(QString offerno3 MEMBER _offerno3 READ offerno3 WRITE setOfferno3)		//매도증권사명3
    Q_PROPERTY(QString bidno3 MEMBER _bidno3 READ bidno3 WRITE setBidno3)		//매수증권사명3
    Q_PROPERTY(long dvol3 MEMBER _dvol3 READ dvol3 WRITE setDvol3)		//총매도수량3
    Q_PROPERTY(long svol3 MEMBER _svol3 READ svol3 WRITE setSvol3)		//총매수수량3
    Q_PROPERTY(long dcha3 MEMBER _dcha3 READ dcha3 WRITE setDcha3)		//매도증감3
    Q_PROPERTY(long scha3 MEMBER _scha3 READ scha3 WRITE setScha3)		//매수증감3
    Q_PROPERTY(float ddiff3 MEMBER _ddiff3 READ ddiff3 WRITE setDdiff3)		//매도비율3
    Q_PROPERTY(float sdiff3 MEMBER _sdiff3 READ sdiff3 WRITE setSdiff3)		//매수비율3
    Q_PROPERTY(QString offernocd4 MEMBER _offernocd4 READ offernocd4 WRITE setOffernocd4)		//매도증권사코드4
    Q_PROPERTY(QString bidnocd4 MEMBER _bidnocd4 READ bidnocd4 WRITE setBidnocd4)		//매수증권사코드4
    Q_PROPERTY(QString offerno4 MEMBER _offerno4 READ offerno4 WRITE setOfferno4)		//매도증권사명4
    Q_PROPERTY(QString bidno4 MEMBER _bidno4 READ bidno4 WRITE setBidno4)		//매수증권사명4
    Q_PROPERTY(long dvol4 MEMBER _dvol4 READ dvol4 WRITE setDvol4)		//총매도수량4
    Q_PROPERTY(long svol4 MEMBER _svol4 READ svol4 WRITE setSvol4)		//총매수수량4
    Q_PROPERTY(long dcha4 MEMBER _dcha4 READ dcha4 WRITE setDcha4)		//매도증감4
    Q_PROPERTY(long scha4 MEMBER _scha4 READ scha4 WRITE setScha4)		//매수증감4
    Q_PROPERTY(float ddiff4 MEMBER _ddiff4 READ ddiff4 WRITE setDdiff4)		//매도비율4
    Q_PROPERTY(float sdiff4 MEMBER _sdiff4 READ sdiff4 WRITE setSdiff4)		//매수비율4
    Q_PROPERTY(QString offernocd5 MEMBER _offernocd5 READ offernocd5 WRITE setOffernocd5)		//매도증권사코드5
    Q_PROPERTY(QString bidnocd5 MEMBER _bidnocd5 READ bidnocd5 WRITE setBidnocd5)		//매수증권사코드5
    Q_PROPERTY(QString offerno5 MEMBER _offerno5 READ offerno5 WRITE setOfferno5)		//매도증권사명5
    Q_PROPERTY(QString bidno5 MEMBER _bidno5 READ bidno5 WRITE setBidno5)		//매수증권사명5
    Q_PROPERTY(long dvol5 MEMBER _dvol5 READ dvol5 WRITE setDvol5)		//총매도수량5
    Q_PROPERTY(long svol5 MEMBER _svol5 READ svol5 WRITE setSvol5)		//총매수수량5
    Q_PROPERTY(long dcha5 MEMBER _dcha5 READ dcha5 WRITE setDcha5)		//매도증감5
    Q_PROPERTY(long scha5 MEMBER _scha5 READ scha5 WRITE setScha5)		//매수증감5
    Q_PROPERTY(float ddiff5 MEMBER _ddiff5 READ ddiff5 WRITE setDdiff5)		//매도비율5
    Q_PROPERTY(float sdiff5 MEMBER _sdiff5 READ sdiff5 WRITE setSdiff5)		//매수비율5
    Q_PROPERTY(long fwdvl MEMBER _fwdvl READ fwdvl WRITE setFwdvl)		//외국계매도합계수량
    Q_PROPERTY(long ftradmdcha MEMBER _ftradmdcha READ ftradmdcha WRITE setFtradmdcha)		//외국계매도직전대비
    Q_PROPERTY(float ftradmddiff MEMBER _ftradmddiff READ ftradmddiff WRITE setFtradmddiff)		//외국계매도비율
    Q_PROPERTY(long fwsvl MEMBER _fwsvl READ fwsvl WRITE setFwsvl)		//외국계매수합계수량
    Q_PROPERTY(long ftradmscha MEMBER _ftradmscha READ ftradmscha WRITE setFtradmscha)		//외국계매수직전대비
    Q_PROPERTY(float ftradmsdiff MEMBER _ftradmsdiff READ ftradmsdiff WRITE setFtradmsdiff)		//외국계매수비율
    Q_PROPERTY(float vol MEMBER _vol READ vol WRITE setVol)		//회전율
    Q_PROPERTY(QString shcode MEMBER _shcode READ shcode WRITE setShcode)		//단축코드
    Q_PROPERTY(long value MEMBER _value READ value WRITE setValue)		//누적거래대금
    Q_PROPERTY(long jvolume MEMBER _jvolume READ jvolume WRITE setJvolume)		//전일동시간거래량
    Q_PROPERTY(long highyear MEMBER _highyear READ highyear WRITE setHighyear)		//연중최고가
    Q_PROPERTY(QDate highyeardate MEMBER _highyeardate READ highyeardate WRITE setHighyeardate)		//연중최고일자
    Q_PROPERTY(long lowyear MEMBER _lowyear READ lowyear WRITE setLowyear)		//연중최저가
    Q_PROPERTY(QDate lowyeardate MEMBER _lowyeardate READ lowyeardate WRITE setLowyeardate)		//연중최저일자
    Q_PROPERTY(long target MEMBER _target READ target WRITE setTarget)		//목표가
    Q_PROPERTY(long capital MEMBER _capital READ capital WRITE setCapital)		//자본금
    Q_PROPERTY(long abscnt MEMBER _abscnt READ abscnt WRITE setAbscnt)		//유동주식수
    Q_PROPERTY(long parprice MEMBER _parprice READ parprice WRITE setParprice)		//액면가
    Q_PROPERTY(QString gsmm MEMBER _gsmm READ gsmm WRITE setGsmm)		//결산월
    Q_PROPERTY(long subprice MEMBER _subprice READ subprice WRITE setSubprice)		//대용가
    Q_PROPERTY(long total MEMBER _total READ total WRITE setTotal)		//시가총액
    Q_PROPERTY(QDate listdate MEMBER _listdate READ listdate WRITE setListdate)		//상장일
    Q_PROPERTY(QString name MEMBER _name READ name WRITE setName)		//전분기명
    Q_PROPERTY(long bfsales MEMBER _bfsales READ bfsales WRITE setBfsales)		//전분기매출액
    Q_PROPERTY(long bfoperatingincome MEMBER _bfoperatingincome READ bfoperatingincome WRITE setBfoperatingincome)		//전분기영업이익
    Q_PROPERTY(long bfordinaryincome MEMBER _bfordinaryincome READ bfordinaryincome WRITE setBfordinaryincome)		//전분기경상이익
    Q_PROPERTY(long bfnetincome MEMBER _bfnetincome READ bfnetincome WRITE setBfnetincome)		//전분기순이익
    Q_PROPERTY(float bfeps MEMBER _bfeps READ bfeps WRITE setBfeps)		//전분기EPS
    Q_PROPERTY(QString name2 MEMBER _name2 READ name2 WRITE setName2)		//전전분기명
    Q_PROPERTY(long bfsales2 MEMBER _bfsales2 READ bfsales2 WRITE setBfsales2)		//전전분기매출액
    Q_PROPERTY(long bfoperatingincome2 MEMBER _bfoperatingincome2 READ bfoperatingincome2 WRITE setBfoperatingincome2)		//전전분기영업이익
    Q_PROPERTY(long bfordinaryincome2 MEMBER _bfordinaryincome2 READ bfordinaryincome2 WRITE setBfordinaryincome2)		//전전분기경상이익
    Q_PROPERTY(long bfnetincome2 MEMBER _bfnetincome2 READ bfnetincome2 WRITE setBfnetincome2)		//전전분기순이익
    Q_PROPERTY(float bfeps2 MEMBER _bfeps2 READ bfeps2 WRITE setBfeps2)		//전전분기EPS
    Q_PROPERTY(float salert MEMBER _salert READ salert WRITE setSalert)		//전년대비매출액
    Q_PROPERTY(float opert MEMBER _opert READ opert WRITE setOpert)		//전년대비영업이익
    Q_PROPERTY(float ordrt MEMBER _ordrt READ ordrt WRITE setOrdrt)		//전년대비경상이익
    Q_PROPERTY(float netrt MEMBER _netrt READ netrt WRITE setNetrt)		//전년대비순이익
    Q_PROPERTY(float epsrt MEMBER _epsrt READ epsrt WRITE setEpsrt)		//전년대비EPS
    Q_PROPERTY(QString info1 MEMBER _info1 READ info1 WRITE setInfo1)		//락구분
    Q_PROPERTY(QString info2 MEMBER _info2 READ info2 WRITE setInfo2)		//관리/급등구분
    Q_PROPERTY(QString info3 MEMBER _info3 READ info3 WRITE setInfo3)		//정지/연장구분
    Q_PROPERTY(QString info4 MEMBER _info4 READ info4 WRITE setInfo4)		//투자/불성실구분
    Q_PROPERTY(QString janginfo MEMBER _janginfo READ janginfo WRITE setJanginfo)		//장구분
    Q_PROPERTY(float t_per MEMBER _t_per READ t_per WRITE setT_Per)		//T.PER
    Q_PROPERTY(QString tonghwa MEMBER _tonghwa READ tonghwa WRITE setTonghwa)		//통화ISO코드
    Q_PROPERTY(long dval1 MEMBER _dval1 READ dval1 WRITE setDval1)		//총매도대금1
    Q_PROPERTY(long sval1 MEMBER _sval1 READ sval1 WRITE setSval1)		//총매수대금1
    Q_PROPERTY(long dval2 MEMBER _dval2 READ dval2 WRITE setDval2)		//총매도대금2
    Q_PROPERTY(long sval2 MEMBER _sval2 READ sval2 WRITE setSval2)		//총매수대금2
    Q_PROPERTY(long dval3 MEMBER _dval3 READ dval3 WRITE setDval3)		//총매도대금3
    Q_PROPERTY(long sval3 MEMBER _sval3 READ sval3 WRITE setSval3)		//총매수대금3
    Q_PROPERTY(long dval4 MEMBER _dval4 READ dval4 WRITE setDval4)		//총매도대금4
    Q_PROPERTY(long sval4 MEMBER _sval4 READ sval4 WRITE setSval4)		//총매수대금4
    Q_PROPERTY(long dval5 MEMBER _dval5 READ dval5 WRITE setDval5)		//총매도대금5
    Q_PROPERTY(long sval5 MEMBER _sval5 READ sval5 WRITE setSval5)		//총매수대금5
    Q_PROPERTY(long davg1 MEMBER _davg1 READ davg1 WRITE setDavg1)		//총매도평단가1
    Q_PROPERTY(long savg1 MEMBER _savg1 READ savg1 WRITE setSavg1)		//총매수평단가1
    Q_PROPERTY(long davg2 MEMBER _davg2 READ davg2 WRITE setDavg2)		//총매도평단가2
    Q_PROPERTY(long savg2 MEMBER _savg2 READ savg2 WRITE setSavg2)		//총매수평단가2
    Q_PROPERTY(long davg3 MEMBER _davg3 READ davg3 WRITE setDavg3)		//총매도평단가3
    Q_PROPERTY(long savg3 MEMBER _savg3 READ savg3 WRITE setSavg3)		//총매수평단가3
    Q_PROPERTY(long davg4 MEMBER _davg4 READ davg4 WRITE setDavg4)		//총매도평단가4
    Q_PROPERTY(long savg4 MEMBER _savg4 READ savg4 WRITE setSavg4)		//총매수평단가4
    Q_PROPERTY(long davg5 MEMBER _davg5 READ davg5 WRITE setDavg5)		//총매도평단가5
    Q_PROPERTY(long savg5 MEMBER _savg5 READ savg5 WRITE setSavg5)		//총매수평단가5
    Q_PROPERTY(long ftradmdval MEMBER _ftradmdval READ ftradmdval WRITE setFtradmdval)		//외국계매도대금
    Q_PROPERTY(long ftradmsval MEMBER _ftradmsval READ ftradmsval WRITE setFtradmsval)		//외국계매수대금
    Q_PROPERTY(long ftradmdavg MEMBER _ftradmdavg READ ftradmdavg WRITE setFtradmdavg)		//외국계매도평단가
    Q_PROPERTY(long ftradmsavg MEMBER _ftradmsavg READ ftradmsavg WRITE setFtradmsavg)		//외국계매수평단가
    Q_PROPERTY(QString info5 MEMBER _info5 READ info5 WRITE setInfo5)		//투자주의환기
    Q_PROPERTY(QString spac_gubun MEMBER _spac_gubun READ spac_gubun WRITE setSpac_Gubun)		//기업인수목적회사여부
    Q_PROPERTY(long issueprice MEMBER _issueprice READ issueprice WRITE setIssueprice)		//발행가격
    Q_PROPERTY(QString alloc_gubun MEMBER _alloc_gubun READ alloc_gubun WRITE setAlloc_Gubun)		//배분적용구분코드(1:배분발생2:배분해제그외:미발생)
    Q_PROPERTY(QString alloc_text MEMBER _alloc_text READ alloc_text WRITE setAlloc_Text)		//배분적용구분
    Q_PROPERTY(QString shterm_text MEMBER _shterm_text READ shterm_text WRITE setShterm_Text)		//단기과열/VI발동
public:
    explicit StockInfo(QObject *parent=0);
    ~StockInfo();
    QString getSqlInsertStr();
    QString getSqlUpdateStr();
    QString hname() {return _hname;}
    void setHname(QString hname) {_hname = hname; }
    QString expcode() { return _expcode;}
    void setExpcode(QString expcode) {_expcode = expcode; }
    bool isETF() { return _isETF;}
    void setETF(bool etf) { _isETF = etf; }
    bool isKOSPI() { return _isKOSPI;}
    void setKOSPI(bool kospi) { _isKOSPI = kospi; }

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
    long recprice() { return _recprice; }
    void setRecprice(long recprice) { _recprice = recprice; }
    long avg() { return _avg; }
    void setAvg(long avg) { _avg = avg; }
    long uplmtprice() { return _uplmtprice; }
    void setUplmtprice(long uplmtprice) { _uplmtprice = uplmtprice; }
    long dnlmtprice() { return _dnlmtprice; }
    void setDnlmtprice(long dnlmtprice) { _dnlmtprice = dnlmtprice; }
    long jnilvolume() { return _jnilvolume; }
    void setJnilvolume(long jnilvolume) { _jnilvolume = jnilvolume; }
    long volumediff() { return _volumediff; }
    void setVolumediff(long volumediff) { _volumediff = volumediff; }
    long open() { return _open; }
    void setOpen(long open) { _open = open; }
    QTime opentime() { return _opentime; }
    void setOpentime(QTime opentime) { _opentime = opentime; }
    long high() { return _high; }
    void setHigh(long high) { _high = high; }
    QTime hightime() { return _hightime; }
    void setHightime(QTime hightime) { _hightime = hightime; }
    long low() { return _low; }
    void setLow(long low) { _low = low; }
    QTime lowtime() { return _lowtime; }
    void setLowtime(QTime lowtime) { _lowtime = lowtime; }
    long high52w() { return _high52w; }
    void setHigh52W(long high52w) { _high52w = high52w; }
    QDate high52wdate() { return _high52wdate; }
    void setHigh52Wdate(QDate high52wdate) { _high52wdate = high52wdate; }
    long low52w() { return _low52w; }
    void setLow52W(long low52w) { _low52w = low52w; }
    QDate low52wdate() { return _low52wdate; }
    void setLow52Wdate(QDate low52wdate) { _low52wdate = low52wdate; }
    float exhratio() { return _exhratio; }
    void setExhratio(float exhratio) { _exhratio = exhratio; }
    float per() { return _per; }
    void setPer(float per) { _per = per; }
    float pbrx() { return _pbrx; }
    void setPbrx(float pbrx) { _pbrx = pbrx; }
    long listing() { return _listing; }
    void setListing(long listing) { _listing = listing; }
    long jkrate() { return _jkrate; }
    void setJkrate(long jkrate) { _jkrate = jkrate; }
    QString memedan() { return _memedan; }
    void setMemedan(QString memedan) { _memedan = memedan; }
    QString offernocd1() { return _offernocd1; }
    void setOffernocd1(QString offernocd1) { _offernocd1 = offernocd1; }
    QString bidnocd1() { return _bidnocd1; }
    void setBidnocd1(QString bidnocd1) { _bidnocd1 = bidnocd1; }
    QString offerno1() { return _offerno1; }
    void setOfferno1(QString offerno1) { _offerno1 = offerno1; }
    QString bidno1() { return _bidno1; }
    void setBidno1(QString bidno1) { _bidno1 = bidno1; }
    long dvol1() { return _dvol1; }
    void setDvol1(long dvol1) { _dvol1 = dvol1; }
    long svol1() { return _svol1; }
    void setSvol1(long svol1) { _svol1 = svol1; }
    long dcha1() { return _dcha1; }
    void setDcha1(long dcha1) { _dcha1 = dcha1; }
    long scha1() { return _scha1; }
    void setScha1(long scha1) { _scha1 = scha1; }
    float ddiff1() { return _ddiff1; }
    void setDdiff1(float ddiff1) { _ddiff1 = ddiff1; }
    float sdiff1() { return _sdiff1; }
    void setSdiff1(float sdiff1) { _sdiff1 = sdiff1; }
    QString offernocd2() { return _offernocd2; }
    void setOffernocd2(QString offernocd2) { _offernocd2 = offernocd2; }
    QString bidnocd2() { return _bidnocd2; }
    void setBidnocd2(QString bidnocd2) { _bidnocd2 = bidnocd2; }
    QString offerno2() { return _offerno2; }
    void setOfferno2(QString offerno2) { _offerno2 = offerno2; }
    QString bidno2() { return _bidno2; }
    void setBidno2(QString bidno2) { _bidno2 = bidno2; }
    long dvol2() { return _dvol2; }
    void setDvol2(long dvol2) { _dvol2 = dvol2; }
    long svol2() { return _svol2; }
    void setSvol2(long svol2) { _svol2 = svol2; }
    long dcha2() { return _dcha2; }
    void setDcha2(long dcha2) { _dcha2 = dcha2; }
    long scha2() { return _scha2; }
    void setScha2(long scha2) { _scha2 = scha2; }
    float ddiff2() { return _ddiff2; }
    void setDdiff2(float ddiff2) { _ddiff2 = ddiff2; }
    float sdiff2() { return _sdiff2; }
    void setSdiff2(float sdiff2) { _sdiff2 = sdiff2; }
    QString offernocd3() { return _offernocd3; }
    void setOffernocd3(QString offernocd3) { _offernocd3 = offernocd3; }
    QString bidnocd3() { return _bidnocd3; }
    void setBidnocd3(QString bidnocd3) { _bidnocd3 = bidnocd3; }
    QString offerno3() { return _offerno3; }
    void setOfferno3(QString offerno3) { _offerno3 = offerno3; }
    QString bidno3() { return _bidno3; }
    void setBidno3(QString bidno3) { _bidno3 = bidno3; }
    long dvol3() { return _dvol3; }
    void setDvol3(long dvol3) { _dvol3 = dvol3; }
    long svol3() { return _svol3; }
    void setSvol3(long svol3) { _svol3 = svol3; }
    long dcha3() { return _dcha3; }
    void setDcha3(long dcha3) { _dcha3 = dcha3; }
    long scha3() { return _scha3; }
    void setScha3(long scha3) { _scha3 = scha3; }
    float ddiff3() { return _ddiff3; }
    void setDdiff3(float ddiff3) { _ddiff3 = ddiff3; }
    float sdiff3() { return _sdiff3; }
    void setSdiff3(float sdiff3) { _sdiff3 = sdiff3; }
    QString offernocd4() { return _offernocd4; }
    void setOffernocd4(QString offernocd4) { _offernocd4 = offernocd4; }
    QString bidnocd4() { return _bidnocd4; }
    void setBidnocd4(QString bidnocd4) { _bidnocd4 = bidnocd4; }
    QString offerno4() { return _offerno4; }
    void setOfferno4(QString offerno4) { _offerno4 = offerno4; }
    QString bidno4() { return _bidno4; }
    void setBidno4(QString bidno4) { _bidno4 = bidno4; }
    long dvol4() { return _dvol4; }
    void setDvol4(long dvol4) { _dvol4 = dvol4; }
    long svol4() { return _svol4; }
    void setSvol4(long svol4) { _svol4 = svol4; }
    long dcha4() { return _dcha4; }
    void setDcha4(long dcha4) { _dcha4 = dcha4; }
    long scha4() { return _scha4; }
    void setScha4(long scha4) { _scha4 = scha4; }
    float ddiff4() { return _ddiff4; }
    void setDdiff4(float ddiff4) { _ddiff4 = ddiff4; }
    float sdiff4() { return _sdiff4; }
    void setSdiff4(float sdiff4) { _sdiff4 = sdiff4; }
    QString offernocd5() { return _offernocd5; }
    void setOffernocd5(QString offernocd5) { _offernocd5 = offernocd5; }
    QString bidnocd5() { return _bidnocd5; }
    void setBidnocd5(QString bidnocd5) { _bidnocd5 = bidnocd5; }
    QString offerno5() { return _offerno5; }
    void setOfferno5(QString offerno5) { _offerno5 = offerno5; }
    QString bidno5() { return _bidno5; }
    void setBidno5(QString bidno5) { _bidno5 = bidno5; }
    long dvol5() { return _dvol5; }
    void setDvol5(long dvol5) { _dvol5 = dvol5; }
    long svol5() { return _svol5; }
    void setSvol5(long svol5) { _svol5 = svol5; }
    long dcha5() { return _dcha5; }
    void setDcha5(long dcha5) { _dcha5 = dcha5; }
    long scha5() { return _scha5; }
    void setScha5(long scha5) { _scha5 = scha5; }
    float ddiff5() { return _ddiff5; }
    void setDdiff5(float ddiff5) { _ddiff5 = ddiff5; }
    float sdiff5() { return _sdiff5; }
    void setSdiff5(float sdiff5) { _sdiff5 = sdiff5; }
    long fwdvl() { return _fwdvl; }
    void setFwdvl(long fwdvl) { _fwdvl = fwdvl; }
    long ftradmdcha() { return _ftradmdcha; }
    void setFtradmdcha(long ftradmdcha) { _ftradmdcha = ftradmdcha; }
    float ftradmddiff() { return _ftradmddiff; }
    void setFtradmddiff(float ftradmddiff) { _ftradmddiff = ftradmddiff; }
    long fwsvl() { return _fwsvl; }
    void setFwsvl(long fwsvl) { _fwsvl = fwsvl; }
    long ftradmscha() { return _ftradmscha; }
    void setFtradmscha(long ftradmscha) { _ftradmscha = ftradmscha; }
    float ftradmsdiff() { return _ftradmsdiff; }
    void setFtradmsdiff(float ftradmsdiff) { _ftradmsdiff = ftradmsdiff; }
    float vol() { return _vol; }
    void setVol(float vol) { _vol = vol; }
    QString shcode() { return _shcode; }
    void setShcode(QString shcode) { _shcode = shcode; }
    long value() { return _value; }
    void setValue(long value) { _value = value; }
    long jvolume() { return _jvolume; }
    void setJvolume(long jvolume) { _jvolume = jvolume; }
    long highyear() { return _highyear; }
    void setHighyear(long highyear) { _highyear = highyear; }
    QDate highyeardate() { return _highyeardate; }
    void setHighyeardate(QDate highyeardate) { _highyeardate = highyeardate; }
    long lowyear() { return _lowyear; }
    void setLowyear(long lowyear) { _lowyear = lowyear; }
    QDate lowyeardate() { return _lowyeardate; }
    void setLowyeardate(QDate lowyeardate) { _lowyeardate = lowyeardate; }
    long target() { return _target; }
    void setTarget(long target) { _target = target; }
    long capital() { return _capital; }
    void setCapital(long capital) { _capital = capital; }
    long abscnt() { return _abscnt; }
    void setAbscnt(long abscnt) { _abscnt = abscnt; }
    long parprice() { return _parprice; }
    void setParprice(long parprice) { _parprice = parprice; }
    QString gsmm() { return _gsmm; }
    void setGsmm(QString gsmm) { _gsmm = gsmm; }
    long subprice() { return _subprice; }
    void setSubprice(long subprice) { _subprice = subprice; }
    long total() { return _total; }
    void setTotal(long total) { _total = total; }
    QDate listdate() { return _listdate; }
    void setListdate(QDate listdate) { _listdate = listdate; }
    QString name() { return _name; }
    void setName(QString name) { _name = name; }
    long bfsales() { return _bfsales; }
    void setBfsales(long bfsales) { _bfsales = bfsales; }
    long bfoperatingincome() { return _bfoperatingincome; }
    void setBfoperatingincome(long bfoperatingincome) { _bfoperatingincome = bfoperatingincome; }
    long bfordinaryincome() { return _bfordinaryincome; }
    void setBfordinaryincome(long bfordinaryincome) { _bfordinaryincome = bfordinaryincome; }
    long bfnetincome() { return _bfnetincome; }
    void setBfnetincome(long bfnetincome) { _bfnetincome = bfnetincome; }
    float bfeps() { return _bfeps; }
    void setBfeps(float bfeps) { _bfeps = bfeps; }
    QString name2() { return _name2; }
    void setName2(QString name2) { _name2 = name2; }
    long bfsales2() { return _bfsales2; }
    void setBfsales2(long bfsales2) { _bfsales2 = bfsales2; }
    long bfoperatingincome2() { return _bfoperatingincome2; }
    void setBfoperatingincome2(long bfoperatingincome2) { _bfoperatingincome2 = bfoperatingincome2; }
    long bfordinaryincome2() { return _bfordinaryincome2; }
    void setBfordinaryincome2(long bfordinaryincome2) { _bfordinaryincome2 = bfordinaryincome2; }
    long bfnetincome2() { return _bfnetincome2; }
    void setBfnetincome2(long bfnetincome2) { _bfnetincome2 = bfnetincome2; }
    float bfeps2() { return _bfeps2; }
    void setBfeps2(float bfeps2) { _bfeps2 = bfeps2; }
    float salert() { return _salert; }
    void setSalert(float salert) { _salert = salert; }
    float opert() { return _opert; }
    void setOpert(float opert) { _opert = opert; }
    float ordrt() { return _ordrt; }
    void setOrdrt(float ordrt) { _ordrt = ordrt; }
    float netrt() { return _netrt; }
    void setNetrt(float netrt) { _netrt = netrt; }
    float epsrt() { return _epsrt; }
    void setEpsrt(float epsrt) { _epsrt = epsrt; }
    QString info1() { return _info1; }
    void setInfo1(QString info1) { _info1 = info1; }
    QString info2() { return _info2; }
    void setInfo2(QString info2) { _info2 = info2; }
    QString info3() { return _info3; }
    void setInfo3(QString info3) { _info3 = info3; }
    QString info4() { return _info4; }
    void setInfo4(QString info4) { _info4 = info4; }
    QString janginfo() { return _janginfo; }
    void setJanginfo(QString janginfo) { _janginfo = janginfo; }
    float t_per() { return _t_per; }
    void setT_Per(float t_per) { _t_per = t_per; }
    QString tonghwa() { return _tonghwa; }
    void setTonghwa(QString tonghwa) { _tonghwa = tonghwa; }
    long dval1() { return _dval1; }
    void setDval1(long dval1) { _dval1 = dval1; }
    long sval1() { return _sval1; }
    void setSval1(long sval1) { _sval1 = sval1; }
    long dval2() { return _dval2; }
    void setDval2(long dval2) { _dval2 = dval2; }
    long sval2() { return _sval2; }
    void setSval2(long sval2) { _sval2 = sval2; }
    long dval3() { return _dval3; }
    void setDval3(long dval3) { _dval3 = dval3; }
    long sval3() { return _sval3; }
    void setSval3(long sval3) { _sval3 = sval3; }
    long dval4() { return _dval4; }
    void setDval4(long dval4) { _dval4 = dval4; }
    long sval4() { return _sval4; }
    void setSval4(long sval4) { _sval4 = sval4; }
    long dval5() { return _dval5; }
    void setDval5(long dval5) { _dval5 = dval5; }
    long sval5() { return _sval5; }
    void setSval5(long sval5) { _sval5 = sval5; }
    long davg1() { return _davg1; }
    void setDavg1(long davg1) { _davg1 = davg1; }
    long savg1() { return _savg1; }
    void setSavg1(long savg1) { _savg1 = savg1; }
    long davg2() { return _davg2; }
    void setDavg2(long davg2) { _davg2 = davg2; }
    long savg2() { return _savg2; }
    void setSavg2(long savg2) { _savg2 = savg2; }
    long davg3() { return _davg3; }
    void setDavg3(long davg3) { _davg3 = davg3; }
    long savg3() { return _savg3; }
    void setSavg3(long savg3) { _savg3 = savg3; }
    long davg4() { return _davg4; }
    void setDavg4(long davg4) { _davg4 = davg4; }
    long savg4() { return _savg4; }
    void setSavg4(long savg4) { _savg4 = savg4; }
    long davg5() { return _davg5; }
    void setDavg5(long davg5) { _davg5 = davg5; }
    long savg5() { return _savg5; }
    void setSavg5(long savg5) { _savg5 = savg5; }
    long ftradmdval() { return _ftradmdval; }
    void setFtradmdval(long ftradmdval) { _ftradmdval = ftradmdval; }
    long ftradmsval() { return _ftradmsval; }
    void setFtradmsval(long ftradmsval) { _ftradmsval = ftradmsval; }
    long ftradmdavg() { return _ftradmdavg; }
    void setFtradmdavg(long ftradmdavg) { _ftradmdavg = ftradmdavg; }
    long ftradmsavg() { return _ftradmsavg; }
    void setFtradmsavg(long ftradmsavg) { _ftradmsavg = ftradmsavg; }
    QString info5() { return _info5; }
    void setInfo5(QString info5) { _info5 = info5; }
    QString spac_gubun() { return _spac_gubun; }
    void setSpac_Gubun(QString spac_gubun) { _spac_gubun = spac_gubun; }
    long issueprice() { return _issueprice; }
    void setIssueprice(long issueprice) { _issueprice = issueprice; }
    QString alloc_gubun() { return _alloc_gubun; }
    void setAlloc_Gubun(QString alloc_gubun) { _alloc_gubun = alloc_gubun; }
    QString alloc_text() { return _alloc_text; }
    void setAlloc_Text(QString alloc_text) { _alloc_text = alloc_text; }
    QString shterm_text() { return _shterm_text; }
    void setShterm_Text(QString shterm_text) { _shterm_text = shterm_text; }

private:
    QString _hname;     //종목명
    QString _expcode;   //확장코드
    bool _isETF;        //ETF구분
    bool _isKOSPI;      //구분(1:코스피2:코스닥)

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
    long _ftradmdavg;		//외국계매도평단가
    long _ftradmsavg;		//외국계매수평단가
    QString _info5;		//투자주의환기
    QString _spac_gubun;		//기업인수목적회사여부
    long _issueprice;		//발행가격
    QString _alloc_gubun;		//배분적용구분코드(1:배분발생2:배분해제그외:미발생)
    QString _alloc_text;		//배분적용구분
    QString _shterm_text;		//단기과열/VI발동
};

#endif // STOCKINFO_H
