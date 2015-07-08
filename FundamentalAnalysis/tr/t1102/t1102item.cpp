#include "t1102item.h"
#include "util/fieldutil.h"
#include <QDebug>

T1102Item::T1102Item(LPt1102OutBlock outblock, QObject *parent):TrItem(parent)
{
	_hname = GET_STRING_FROM_FIELD(outblock->hname);
	_price = GET_LONG_FROM_FIELD(outblock->price);
	_sign = GET_STRING_FROM_FIELD(outblock->sign);
	_change = GET_LONG_FROM_FIELD(outblock->change);
	_diff = GET_FLOAT_FROM_FIELD(outblock->diff);
	_volume = GET_LONG_FROM_FIELD(outblock->volume);
	_recprice = GET_LONG_FROM_FIELD(outblock->recprice);
	_avg = GET_LONG_FROM_FIELD(outblock->avg);
	_uplmtprice = GET_LONG_FROM_FIELD(outblock->uplmtprice);
	_dnlmtprice = GET_LONG_FROM_FIELD(outblock->dnlmtprice);
	_jnilvolume = GET_LONG_FROM_FIELD(outblock->jnilvolume);
	_volumediff = GET_LONG_FROM_FIELD(outblock->volumediff);
	_open = GET_LONG_FROM_FIELD(outblock->open);
	_opentime = GET_TIME_FROM_FIELD(outblock->opentime);
	_high = GET_LONG_FROM_FIELD(outblock->high);
	_hightime = GET_TIME_FROM_FIELD(outblock->hightime);
	_low = GET_LONG_FROM_FIELD(outblock->low);
	_lowtime = GET_TIME_FROM_FIELD(outblock->lowtime);
	_high52w = GET_LONG_FROM_FIELD(outblock->high52w);
	_high52wdate = GET_DATE_FROM_FIELD(outblock->high52wdate);
	_low52w = GET_LONG_FROM_FIELD(outblock->low52w);
	_low52wdate = GET_DATE_FROM_FIELD(outblock->low52wdate);
	_exhratio = GET_FLOAT_FROM_FIELD(outblock->exhratio);
	_per = GET_FLOAT_FROM_FIELD(outblock->per);
	_pbrx = GET_FLOAT_FROM_FIELD(outblock->pbrx);
	_listing = GET_LONG_FROM_FIELD(outblock->listing);
	_jkrate = GET_LONG_FROM_FIELD(outblock->jkrate);
	_memedan = GET_STRING_FROM_FIELD(outblock->memedan);
	_offernocd1 = GET_STRING_FROM_FIELD(outblock->offernocd1);
	_bidnocd1 = GET_STRING_FROM_FIELD(outblock->bidnocd1);
	_offerno1 = GET_STRING_FROM_FIELD(outblock->offerno1);
	_bidno1 = GET_STRING_FROM_FIELD(outblock->bidno1);
	_dvol1 = GET_LONG_FROM_FIELD(outblock->dvol1);
	_svol1 = GET_LONG_FROM_FIELD(outblock->svol1);
	_dcha1 = GET_LONG_FROM_FIELD(outblock->dcha1);
	_scha1 = GET_LONG_FROM_FIELD(outblock->scha1);
	_ddiff1 = GET_FLOAT_FROM_FIELD(outblock->ddiff1);
	_sdiff1 = GET_FLOAT_FROM_FIELD(outblock->sdiff1);
	_offernocd2 = GET_STRING_FROM_FIELD(outblock->offernocd2);
	_bidnocd2 = GET_STRING_FROM_FIELD(outblock->bidnocd2);
	_offerno2 = GET_STRING_FROM_FIELD(outblock->offerno2);
	_bidno2 = GET_STRING_FROM_FIELD(outblock->bidno2);
	_dvol2 = GET_LONG_FROM_FIELD(outblock->dvol2);
	_svol2 = GET_LONG_FROM_FIELD(outblock->svol2);
	_dcha2 = GET_LONG_FROM_FIELD(outblock->dcha2);
	_scha2 = GET_LONG_FROM_FIELD(outblock->scha2);
	_ddiff2 = GET_FLOAT_FROM_FIELD(outblock->ddiff2);
	_sdiff2 = GET_FLOAT_FROM_FIELD(outblock->sdiff2);
	_offernocd3 = GET_STRING_FROM_FIELD(outblock->offernocd3);
	_bidnocd3 = GET_STRING_FROM_FIELD(outblock->bidnocd3);
	_offerno3 = GET_STRING_FROM_FIELD(outblock->offerno3);
	_bidno3 = GET_STRING_FROM_FIELD(outblock->bidno3);
	_dvol3 = GET_LONG_FROM_FIELD(outblock->dvol3);
	_svol3 = GET_LONG_FROM_FIELD(outblock->svol3);
	_dcha3 = GET_LONG_FROM_FIELD(outblock->dcha3);
	_scha3 = GET_LONG_FROM_FIELD(outblock->scha3);
	_ddiff3 = GET_FLOAT_FROM_FIELD(outblock->ddiff3);
	_sdiff3 = GET_FLOAT_FROM_FIELD(outblock->sdiff3);
	_offernocd4 = GET_STRING_FROM_FIELD(outblock->offernocd4);
	_bidnocd4 = GET_STRING_FROM_FIELD(outblock->bidnocd4);
	_offerno4 = GET_STRING_FROM_FIELD(outblock->offerno4);
	_bidno4 = GET_STRING_FROM_FIELD(outblock->bidno4);
	_dvol4 = GET_LONG_FROM_FIELD(outblock->dvol4);
	_svol4 = GET_LONG_FROM_FIELD(outblock->svol4);
	_dcha4 = GET_LONG_FROM_FIELD(outblock->dcha4);
	_scha4 = GET_LONG_FROM_FIELD(outblock->scha4);
	_ddiff4 = GET_FLOAT_FROM_FIELD(outblock->ddiff4);
	_sdiff4 = GET_FLOAT_FROM_FIELD(outblock->sdiff4);
	_offernocd5 = GET_STRING_FROM_FIELD(outblock->offernocd5);
	_bidnocd5 = GET_STRING_FROM_FIELD(outblock->bidnocd5);
	_offerno5 = GET_STRING_FROM_FIELD(outblock->offerno5);
	_bidno5 = GET_STRING_FROM_FIELD(outblock->bidno5);
	_dvol5 = GET_LONG_FROM_FIELD(outblock->dvol5);
	_svol5 = GET_LONG_FROM_FIELD(outblock->svol5);
	_dcha5 = GET_LONG_FROM_FIELD(outblock->dcha5);
	_scha5 = GET_LONG_FROM_FIELD(outblock->scha5);
	_ddiff5 = GET_FLOAT_FROM_FIELD(outblock->ddiff5);
	_sdiff5 = GET_FLOAT_FROM_FIELD(outblock->sdiff5);
	_fwdvl = GET_LONG_FROM_FIELD(outblock->fwdvl);
	_ftradmdcha = GET_LONG_FROM_FIELD(outblock->ftradmdcha);
	_ftradmddiff = GET_FLOAT_FROM_FIELD(outblock->ftradmddiff);
	_fwsvl = GET_LONG_FROM_FIELD(outblock->fwsvl);
	_ftradmscha = GET_LONG_FROM_FIELD(outblock->ftradmscha);
	_ftradmsdiff = GET_FLOAT_FROM_FIELD(outblock->ftradmsdiff);
	_vol = GET_FLOAT_FROM_FIELD(outblock->vol);
	_shcode = GET_STRING_FROM_FIELD(outblock->shcode);
	_value = GET_LONG_FROM_FIELD(outblock->value);
	_jvolume = GET_LONG_FROM_FIELD(outblock->jvolume);
	_highyear = GET_LONG_FROM_FIELD(outblock->highyear);
	_highyeardate = GET_DATE_FROM_FIELD(outblock->highyeardate);
	_lowyear = GET_LONG_FROM_FIELD(outblock->lowyear);
	_lowyeardate = GET_DATE_FROM_FIELD(outblock->lowyeardate);
	_target = GET_LONG_FROM_FIELD(outblock->target);
	_capital = GET_LONG_FROM_FIELD(outblock->capital);
	_abscnt = GET_LONG_FROM_FIELD(outblock->abscnt);
	_parprice = GET_LONG_FROM_FIELD(outblock->parprice);
	_gsmm = GET_STRING_FROM_FIELD(outblock->gsmm);
	_subprice = GET_LONG_FROM_FIELD(outblock->subprice);
	_total = GET_LONG_FROM_FIELD(outblock->total);
	_listdate = GET_DATE_FROM_FIELD(outblock->listdate);
	_name = GET_STRING_FROM_FIELD(outblock->name);
	_bfsales = GET_LONG_FROM_FIELD(outblock->bfsales);
	_bfoperatingincome = GET_LONG_FROM_FIELD(outblock->bfoperatingincome);
	_bfordinaryincome = GET_LONG_FROM_FIELD(outblock->bfordinaryincome);
	_bfnetincome = GET_LONG_FROM_FIELD(outblock->bfnetincome);
	_bfeps = GET_FLOAT_FROM_FIELD(outblock->bfeps);
	_name2 = GET_STRING_FROM_FIELD(outblock->name2);
	_bfsales2 = GET_LONG_FROM_FIELD(outblock->bfsales2);
	_bfoperatingincome2 = GET_LONG_FROM_FIELD(outblock->bfoperatingincome2);
	_bfordinaryincome2 = GET_LONG_FROM_FIELD(outblock->bfordinaryincome2);
	_bfnetincome2 = GET_LONG_FROM_FIELD(outblock->bfnetincome2);
	_bfeps2 = GET_FLOAT_FROM_FIELD(outblock->bfeps2);
	_salert = GET_FLOAT_FROM_FIELD(outblock->salert);
	_opert = GET_FLOAT_FROM_FIELD(outblock->opert);
	_ordrt = GET_FLOAT_FROM_FIELD(outblock->ordrt);
	_netrt = GET_FLOAT_FROM_FIELD(outblock->netrt);
	_epsrt = GET_FLOAT_FROM_FIELD(outblock->epsrt);
	_info1 = GET_STRING_FROM_FIELD(outblock->info1);
	_info2 = GET_STRING_FROM_FIELD(outblock->info2);
	_info3 = GET_STRING_FROM_FIELD(outblock->info3);
	_info4 = GET_STRING_FROM_FIELD(outblock->info4);
	_janginfo = GET_STRING_FROM_FIELD(outblock->janginfo);
	_t_per = GET_FLOAT_FROM_FIELD(outblock->t_per);
	_tonghwa = GET_STRING_FROM_FIELD(outblock->tonghwa);
	_dval1 = GET_LONG_FROM_FIELD(outblock->dval1);
	_sval1 = GET_LONG_FROM_FIELD(outblock->sval1);
	_dval2 = GET_LONG_FROM_FIELD(outblock->dval2);
	_sval2 = GET_LONG_FROM_FIELD(outblock->sval2);
	_dval3 = GET_LONG_FROM_FIELD(outblock->dval3);
	_sval3 = GET_LONG_FROM_FIELD(outblock->sval3);
	_dval4 = GET_LONG_FROM_FIELD(outblock->dval4);
	_sval4 = GET_LONG_FROM_FIELD(outblock->sval4);
	_dval5 = GET_LONG_FROM_FIELD(outblock->dval5);
	_sval5 = GET_LONG_FROM_FIELD(outblock->sval5);
	_davg1 = GET_LONG_FROM_FIELD(outblock->davg1);
	_savg1 = GET_LONG_FROM_FIELD(outblock->savg1);
	_davg2 = GET_LONG_FROM_FIELD(outblock->davg2);
	_savg2 = GET_LONG_FROM_FIELD(outblock->savg2);
	_davg3 = GET_LONG_FROM_FIELD(outblock->davg3);
	_savg3 = GET_LONG_FROM_FIELD(outblock->savg3);
	_davg4 = GET_LONG_FROM_FIELD(outblock->davg4);
	_savg4 = GET_LONG_FROM_FIELD(outblock->savg4);
	_davg5 = GET_LONG_FROM_FIELD(outblock->davg5);
	_savg5 = GET_LONG_FROM_FIELD(outblock->savg5);
	_ftradmdval = GET_LONG_FROM_FIELD(outblock->ftradmdval);
	_ftradmsval = GET_LONG_FROM_FIELD(outblock->ftradmsval);
	_ftradmdvag = GET_LONG_FROM_FIELD(outblock->ftradmdvag);
	_ftradmsvag = GET_LONG_FROM_FIELD(outblock->ftradmsvag);
	_info5 = GET_STRING_FROM_FIELD(outblock->info5);
	_spac_gubun = GET_STRING_FROM_FIELD(outblock->spac_gubun);
	_issueprice = GET_LONG_FROM_FIELD(outblock->issueprice);
	_alloc_gubun = GET_STRING_FROM_FIELD(outblock->alloc_gubun);
	_alloc_text = GET_STRING_FROM_FIELD(outblock->alloc_text);
	_shterm_text = GET_STRING_FROM_FIELD(outblock->shterm_text);

	DEFINE_PROPERTY_NAME("한글명","hname");
	DEFINE_PROPERTY_NAME("현재가","price");
	DEFINE_PROPERTY_NAME("전일대비구분","sign");
	DEFINE_PROPERTY_NAME("전일대비","change");
	DEFINE_PROPERTY_NAME("등락율","diff");
	DEFINE_PROPERTY_NAME("누적거래량","volume");
	DEFINE_PROPERTY_NAME("기준가","recprice");
	DEFINE_PROPERTY_NAME("가중평균","avg");
	DEFINE_PROPERTY_NAME("상한가","uplmtprice");
	DEFINE_PROPERTY_NAME("하한가","dnlmtprice");
	DEFINE_PROPERTY_NAME("전일거래량","jnilvolume");
	DEFINE_PROPERTY_NAME("거래량차","volumediff");
	DEFINE_PROPERTY_NAME("시가","open");
	DEFINE_PROPERTY_NAME("시가시간","opentime");
	DEFINE_PROPERTY_NAME("고가","high");
	DEFINE_PROPERTY_NAME("고가시간","hightime");
	DEFINE_PROPERTY_NAME("저가","low");
	DEFINE_PROPERTY_NAME("저가시간","lowtime");
	DEFINE_PROPERTY_NAME("52최고가","high52w");
	DEFINE_PROPERTY_NAME("52최고가일","high52wdate");
	DEFINE_PROPERTY_NAME("52최저가","low52w");
	DEFINE_PROPERTY_NAME("52최저가일","low52wdate");
	DEFINE_PROPERTY_NAME("소진율","exhratio");
	DEFINE_PROPERTY_NAME("PER","per");
	DEFINE_PROPERTY_NAME("PBRX","pbrx");
	DEFINE_PROPERTY_NAME("상장주식수","listing");
	DEFINE_PROPERTY_NAME("증거금율","jkrate");
	DEFINE_PROPERTY_NAME("수량단위","memedan");
	DEFINE_PROPERTY_NAME("매도증권사코드1","offernocd1");
	DEFINE_PROPERTY_NAME("매수증권사코드1","bidnocd1");
	DEFINE_PROPERTY_NAME("매도증권사명1","offerno1");
	DEFINE_PROPERTY_NAME("매수증권사명1","bidno1");
	DEFINE_PROPERTY_NAME("총매도수량1","dvol1");
	DEFINE_PROPERTY_NAME("총매수수량1","svol1");
	DEFINE_PROPERTY_NAME("매도증감1","dcha1");
	DEFINE_PROPERTY_NAME("매수증감1","scha1");
	DEFINE_PROPERTY_NAME("매도비율1","ddiff1");
	DEFINE_PROPERTY_NAME("매수비율1","sdiff1");
	DEFINE_PROPERTY_NAME("매도증권사코드2","offernocd2");
	DEFINE_PROPERTY_NAME("매수증권사코드2","bidnocd2");
	DEFINE_PROPERTY_NAME("매도증권사명2","offerno2");
	DEFINE_PROPERTY_NAME("매수증권사명2","bidno2");
	DEFINE_PROPERTY_NAME("총매도수량2","dvol2");
	DEFINE_PROPERTY_NAME("총매수수량2","svol2");
	DEFINE_PROPERTY_NAME("매도증감2","dcha2");
	DEFINE_PROPERTY_NAME("매수증감2","scha2");
	DEFINE_PROPERTY_NAME("매도비율2","ddiff2");
	DEFINE_PROPERTY_NAME("매수비율2","sdiff2");
	DEFINE_PROPERTY_NAME("매도증권사코드3","offernocd3");
	DEFINE_PROPERTY_NAME("매수증권사코드3","bidnocd3");
	DEFINE_PROPERTY_NAME("매도증권사명3","offerno3");
	DEFINE_PROPERTY_NAME("매수증권사명3","bidno3");
	DEFINE_PROPERTY_NAME("총매도수량3","dvol3");
	DEFINE_PROPERTY_NAME("총매수수량3","svol3");
	DEFINE_PROPERTY_NAME("매도증감3","dcha3");
	DEFINE_PROPERTY_NAME("매수증감3","scha3");
	DEFINE_PROPERTY_NAME("매도비율3","ddiff3");
	DEFINE_PROPERTY_NAME("매수비율3","sdiff3");
	DEFINE_PROPERTY_NAME("매도증권사코드4","offernocd4");
	DEFINE_PROPERTY_NAME("매수증권사코드4","bidnocd4");
	DEFINE_PROPERTY_NAME("매도증권사명4","offerno4");
	DEFINE_PROPERTY_NAME("매수증권사명4","bidno4");
	DEFINE_PROPERTY_NAME("총매도수량4","dvol4");
	DEFINE_PROPERTY_NAME("총매수수량4","svol4");
	DEFINE_PROPERTY_NAME("매도증감4","dcha4");
	DEFINE_PROPERTY_NAME("매수증감4","scha4");
	DEFINE_PROPERTY_NAME("매도비율4","ddiff4");
	DEFINE_PROPERTY_NAME("매수비율4","sdiff4");
	DEFINE_PROPERTY_NAME("매도증권사코드5","offernocd5");
	DEFINE_PROPERTY_NAME("매수증권사코드5","bidnocd5");
	DEFINE_PROPERTY_NAME("매도증권사명5","offerno5");
	DEFINE_PROPERTY_NAME("매수증권사명5","bidno5");
	DEFINE_PROPERTY_NAME("총매도수량5","dvol5");
	DEFINE_PROPERTY_NAME("총매수수량5","svol5");
	DEFINE_PROPERTY_NAME("매도증감5","dcha5");
	DEFINE_PROPERTY_NAME("매수증감5","scha5");
	DEFINE_PROPERTY_NAME("매도비율5","ddiff5");
	DEFINE_PROPERTY_NAME("매수비율5","sdiff5");
	DEFINE_PROPERTY_NAME("외국계매도합계수량","fwdvl");
	DEFINE_PROPERTY_NAME("외국계매도직전대비","ftradmdcha");
	DEFINE_PROPERTY_NAME("외국계매도비율","ftradmddiff");
	DEFINE_PROPERTY_NAME("외국계매수합계수량","fwsvl");
	DEFINE_PROPERTY_NAME("외국계매수직전대비","ftradmscha");
	DEFINE_PROPERTY_NAME("외국계매수비율","ftradmsdiff");
	DEFINE_PROPERTY_NAME("회전율","vol");
	DEFINE_PROPERTY_NAME("단축코드","shcode");
	DEFINE_PROPERTY_NAME("누적거래대금","value");
	DEFINE_PROPERTY_NAME("전일동시간거래량","jvolume");
	DEFINE_PROPERTY_NAME("연중최고가","highyear");
	DEFINE_PROPERTY_NAME("연중최고일자","highyeardate");
	DEFINE_PROPERTY_NAME("연중최저가","lowyear");
	DEFINE_PROPERTY_NAME("연중최저일자","lowyeardate");
	DEFINE_PROPERTY_NAME("목표가","target");
	DEFINE_PROPERTY_NAME("자본금","capital");
	DEFINE_PROPERTY_NAME("유동주식수","abscnt");
	DEFINE_PROPERTY_NAME("액면가","parprice");
	DEFINE_PROPERTY_NAME("결산월","gsmm");
	DEFINE_PROPERTY_NAME("대용가","subprice");
	DEFINE_PROPERTY_NAME("시가총액","total");
	DEFINE_PROPERTY_NAME("상장일","listdate");
	DEFINE_PROPERTY_NAME("전분기명","name");
	DEFINE_PROPERTY_NAME("전분기매출액","bfsales");
	DEFINE_PROPERTY_NAME("전분기영업이익","bfoperatingincome");
	DEFINE_PROPERTY_NAME("전분기경상이익","bfordinaryincome");
	DEFINE_PROPERTY_NAME("전분기순이익","bfnetincome");
	DEFINE_PROPERTY_NAME("전분기EPS","bfeps");
	DEFINE_PROPERTY_NAME("전전분기명","name2");
	DEFINE_PROPERTY_NAME("전전분기매출액","bfsales2");
	DEFINE_PROPERTY_NAME("전전분기영업이익","bfoperatingincome2");
	DEFINE_PROPERTY_NAME("전전분기경상이익","bfordinaryincome2");
	DEFINE_PROPERTY_NAME("전전분기순이익","bfnetincome2");
	DEFINE_PROPERTY_NAME("전전분기EPS","bfeps2");
	DEFINE_PROPERTY_NAME("전년대비매출액","salert");
	DEFINE_PROPERTY_NAME("전년대비영업이익","opert");
	DEFINE_PROPERTY_NAME("전년대비경상이익","ordrt");
	DEFINE_PROPERTY_NAME("전년대비순이익","netrt");
	DEFINE_PROPERTY_NAME("전년대비EPS","epsrt");
	DEFINE_PROPERTY_NAME("락구분","info1");
	DEFINE_PROPERTY_NAME("관리/급등구분","info2");
	DEFINE_PROPERTY_NAME("정지/연장구분","info3");
	DEFINE_PROPERTY_NAME("투자/불성실구분","info4");
	DEFINE_PROPERTY_NAME("장구분","janginfo");
	DEFINE_PROPERTY_NAME("T.PER","t_per");
	DEFINE_PROPERTY_NAME("통화ISO코드","tonghwa");
	DEFINE_PROPERTY_NAME("총매도대금1","dval1");
	DEFINE_PROPERTY_NAME("총매수대금1","sval1");
	DEFINE_PROPERTY_NAME("총매도대금2","dval2");
	DEFINE_PROPERTY_NAME("총매수대금2","sval2");
	DEFINE_PROPERTY_NAME("총매도대금3","dval3");
	DEFINE_PROPERTY_NAME("총매수대금3","sval3");
	DEFINE_PROPERTY_NAME("총매도대금4","dval4");
	DEFINE_PROPERTY_NAME("총매수대금4","sval4");
	DEFINE_PROPERTY_NAME("총매도대금5","dval5");
	DEFINE_PROPERTY_NAME("총매수대금5","sval5");
	DEFINE_PROPERTY_NAME("총매도평단가1","davg1");
	DEFINE_PROPERTY_NAME("총매수평단가1","savg1");
	DEFINE_PROPERTY_NAME("총매도평단가2","davg2");
	DEFINE_PROPERTY_NAME("총매수평단가2","savg2");
	DEFINE_PROPERTY_NAME("총매도평단가3","davg3");
	DEFINE_PROPERTY_NAME("총매수평단가3","savg3");
	DEFINE_PROPERTY_NAME("총매도평단가4","davg4");
	DEFINE_PROPERTY_NAME("총매수평단가4","savg4");
	DEFINE_PROPERTY_NAME("총매도평단가5","davg5");
	DEFINE_PROPERTY_NAME("총매수평단가5","savg5");
	DEFINE_PROPERTY_NAME("외국계매도대금","ftradmdval");
	DEFINE_PROPERTY_NAME("외국계매수대금","ftradmsval");
	DEFINE_PROPERTY_NAME("외국계매도평단가","ftradmdvag");
	DEFINE_PROPERTY_NAME("외국계매수평단가","ftradmsvag");
	DEFINE_PROPERTY_NAME("투자주의환기","info5");
	DEFINE_PROPERTY_NAME("기업인수목적회사여부","spac_gubun");
	DEFINE_PROPERTY_NAME("발행가격","issueprice");
	DEFINE_PROPERTY_NAME("배분적용구분코드","alloc_gubun");
	DEFINE_PROPERTY_NAME("배분적용구분","alloc_text");
	DEFINE_PROPERTY_NAME("단기과열/VI발동","shterm_text");
}
T1102Item::~T1102Item()
{
	qDebug()<<"T1102Item destroyed";
}
