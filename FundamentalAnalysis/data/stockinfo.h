#ifndef STOCKINFO_H
#define STOCKINFO_H
#include <QString>
#include <QDate>
#include <QTime>
class StockInfo
{
public:
    StockInfo();
    ~StockInfo();

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
    long ftradmdvag() { return _ftradmdvag; }
    void setFtradmdvag(long ftradmdvag) { _ftradmdvag = ftradmdvag; }
    long ftradmsvag() { return _ftradmsvag; }
    void setFtradmsvag(long ftradmsvag) { _ftradmsvag = ftradmsvag; }
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
    QString _hname;     //�����
    QString _expcode;   //Ȯ���ڵ�
    bool _isETF;        //ETF����
    bool _isKOSPI;      //����(1:�ڽ���2:�ڽ���)

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

#endif // STOCKINFO_H
