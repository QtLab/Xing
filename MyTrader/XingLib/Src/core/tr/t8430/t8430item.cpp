#include "core/tr/t8430/t8430item.h"
#include <QDebug>

T8430Item::T8430Item(QObject *parent):TrItem(parent)
{

	DEFINE_PROPERTY_NAME("종목명","hname");
	DEFINE_PROPERTY_NAME("단축코드","shcode");
	DEFINE_PROPERTY_NAME("확장코드","expcode");
	DEFINE_PROPERTY_NAME("ETF구분","etfgubun");
	DEFINE_PROPERTY_NAME("상한가","uplmtprice");
	DEFINE_PROPERTY_NAME("하한가","dnlmtprice");
	DEFINE_PROPERTY_NAME("전일가","jnilclose");
	DEFINE_PROPERTY_NAME("주문수량단위","memedan");
	DEFINE_PROPERTY_NAME("기준가","recprice");
	DEFINE_PROPERTY_NAME("구분","gubun");
}
T8430Item::~T8430Item()
{
}
