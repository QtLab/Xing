#include "core/tr/t1537/t1537item.h"
#include <QDebug>

T1537Item::T1537Item(QObject *parent):TrItem(parent)
{
	DEFINE_PROPERTY_NAME("�����","hname");
	DEFINE_PROPERTY_NAME("���簡","price");
	DEFINE_PROPERTY_NAME("���ϴ�񱸺�","sign");
	DEFINE_PROPERTY_NAME("���ϴ��","change");
	DEFINE_PROPERTY_NAME("�����","diff");
	DEFINE_PROPERTY_NAME("�����ŷ���","volume");
	DEFINE_PROPERTY_NAME("���ϵ��ð�","jniltime");
	DEFINE_PROPERTY_NAME("�����ڵ�","shcode");
	DEFINE_PROPERTY_NAME("����ü�ᰡ","yeprice");
	DEFINE_PROPERTY_NAME("�ð�","open");
	DEFINE_PROPERTY_NAME("��","high");
	DEFINE_PROPERTY_NAME("����","low");
	DEFINE_PROPERTY_NAME("�����ŷ����","value");
	DEFINE_PROPERTY_NAME("�ð��Ѿ�","marketcap");
}
T1537Item::~T1537Item()
{
}
