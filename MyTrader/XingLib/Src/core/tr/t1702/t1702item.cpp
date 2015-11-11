#include "core/tr/t1702/t1702item.h"
#include <QDebug>

T1702Item::T1702Item(const QString &shcode, QObject *parent):TrItem(parent), mShcode(shcode)
{

	DEFINE_PROPERTY_NAME("일자","date");
	DEFINE_PROPERTY_NAME("종가","close");
	DEFINE_PROPERTY_NAME("전일대비구분","sign");
	DEFINE_PROPERTY_NAME("전일대비","change");
	DEFINE_PROPERTY_NAME("등락율","diff");
	DEFINE_PROPERTY_NAME("누적거래량","volume");
	DEFINE_PROPERTY_NAME("사모펀드","amt0000");
	DEFINE_PROPERTY_NAME("증권","amt0001");
	DEFINE_PROPERTY_NAME("보험","amt0002");
	DEFINE_PROPERTY_NAME("투신","amt0003");
	DEFINE_PROPERTY_NAME("은행","amt0004");
	DEFINE_PROPERTY_NAME("종금","amt0005");
	DEFINE_PROPERTY_NAME("기금","amt0006");
	DEFINE_PROPERTY_NAME("기타법인","amt0007");
	DEFINE_PROPERTY_NAME("개인","amt0008");
	DEFINE_PROPERTY_NAME("등록외국인","amt0009");
	DEFINE_PROPERTY_NAME("미등록외국인","amt0010");
	DEFINE_PROPERTY_NAME("국가외","amt0011");
	DEFINE_PROPERTY_NAME("기관","amt0018");
	DEFINE_PROPERTY_NAME("외인계","amt0088");
	DEFINE_PROPERTY_NAME("기타계","amt0099");
}
T1702Item::~T1702Item()
{
}

QString T1702Item::getSqlInsertStr()
{
    return makeSqlInsertQuery(tr("Movement_%1").arg(shcode()));
}

QString T1702Item::getSqlUpdateStr()
{
    return makeSqlUpdateQuery(tr("Movement_%1").arg(shcode()), tr(" WHERE date=%1").arg(date().toString(tr("yyyyMMdd"))));
}
