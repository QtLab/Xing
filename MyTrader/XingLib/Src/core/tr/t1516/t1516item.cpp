#include "core/tr/t1516/t1516item.h"
#include <QDebug>

T1516Item::T1516Item(QObject *parent):TrItem(parent)
{

	DEFINE_PROPERTY_NAME("종목명","hname");
	DEFINE_PROPERTY_NAME("현재가","price");
	DEFINE_PROPERTY_NAME("전일대비구분","sign");
	DEFINE_PROPERTY_NAME("전일대비","change");
	DEFINE_PROPERTY_NAME("등락율","diff");
	DEFINE_PROPERTY_NAME("누적거래량","volume");
	DEFINE_PROPERTY_NAME("시가","open");
	DEFINE_PROPERTY_NAME("고가","high");
	DEFINE_PROPERTY_NAME("저가","low");
	DEFINE_PROPERTY_NAME("소진율","sojinrate");
	DEFINE_PROPERTY_NAME("베타계수","beta");
	DEFINE_PROPERTY_NAME("PER","perx");
	DEFINE_PROPERTY_NAME("외인순매수","frgsvolume");
	DEFINE_PROPERTY_NAME("기관순매수","orgsvolume");
	DEFINE_PROPERTY_NAME("거래증가율","diff_vol");
	DEFINE_PROPERTY_NAME("종목코드","shcode");
	DEFINE_PROPERTY_NAME("시가총액","total");
	DEFINE_PROPERTY_NAME("거래대금","value");
}
T1516Item::~T1516Item()
{
	//qDebug()<<"T1516Item destroyed";
}
