#include "core/tr/t8430/t8430item.h"
#include <QDebug>

T8430Item::T8430Item(QObject *parent):TrItem(parent)
{

	DEFINE_PROPERTY_NAME("�����","hname");
	DEFINE_PROPERTY_NAME("�����ڵ�","shcode");
	DEFINE_PROPERTY_NAME("Ȯ���ڵ�","expcode");
	DEFINE_PROPERTY_NAME("ETF����","etfgubun");
	DEFINE_PROPERTY_NAME("���Ѱ�","uplmtprice");
	DEFINE_PROPERTY_NAME("���Ѱ�","dnlmtprice");
	DEFINE_PROPERTY_NAME("���ϰ�","jnilclose");
	DEFINE_PROPERTY_NAME("�ֹ���������","memedan");
	DEFINE_PROPERTY_NAME("���ذ�","recprice");
	DEFINE_PROPERTY_NAME("����","gubun");
}
T8430Item::~T8430Item()
{
}
