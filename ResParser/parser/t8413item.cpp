#include "tr/t8413/t8413item.h"
#include <QDebug>

T8413Item::T8413Item(QObject *parent):TrItem(parent)
{
	DEFINE_PROPERTY_NAME("날짜","date");
	DEFINE_PROPERTY_NAME("시가","open");
	DEFINE_PROPERTY_NAME("고가","high");
	DEFINE_PROPERTY_NAME("저가","low");
	DEFINE_PROPERTY_NAME("종가","close");
	DEFINE_PROPERTY_NAME("거래량","jdiff_vol");
	DEFINE_PROPERTY_NAME("거래대금","value");
	DEFINE_PROPERTY_NAME("수정구분","jongchk");
	DEFINE_PROPERTY_NAME("수정비율","rate");
	DEFINE_PROPERTY_NAME("수정주가반영항목","pricechk");
	DEFINE_PROPERTY_NAME("수정비율반영거래대금","ratevalue");
	DEFINE_PROPERTY_NAME("종가등락구분","sign");
}
T8413Item::~T8413Item()
{

}
