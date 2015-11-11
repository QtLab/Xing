#include "core/tr/t1537/t1537item.h"
#include <QDebug>

T1537Item::T1537Item(QObject *parent):TrItem(parent)
{
	DEFINE_PROPERTY_NAME("종목명","hname");
	DEFINE_PROPERTY_NAME("현재가","price");
	DEFINE_PROPERTY_NAME("전일대비구분","sign");
	DEFINE_PROPERTY_NAME("전일대비","change");
	DEFINE_PROPERTY_NAME("등락율","diff");
	DEFINE_PROPERTY_NAME("누적거래량","volume");
	DEFINE_PROPERTY_NAME("전일동시간","jniltime");
	DEFINE_PROPERTY_NAME("종목코드","shcode");
	DEFINE_PROPERTY_NAME("예상체결가","yeprice");
	DEFINE_PROPERTY_NAME("시가","open");
	DEFINE_PROPERTY_NAME("고가","high");
	DEFINE_PROPERTY_NAME("저가","low");
	DEFINE_PROPERTY_NAME("누적거래대금","value");
	DEFINE_PROPERTY_NAME("시가총액","marketcap");
}
T1537Item::~T1537Item()
{
}
