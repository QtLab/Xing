#include "core/tr/t1516/t1516item.h"
#include <QDebug>

T1516Item::T1516Item(QObject *parent):TrItem(parent)
{

	DEFINE_PROPERTY_NAME("�����","hname");
	DEFINE_PROPERTY_NAME("���簡","price");
	DEFINE_PROPERTY_NAME("���ϴ�񱸺�","sign");
	DEFINE_PROPERTY_NAME("���ϴ��","change");
	DEFINE_PROPERTY_NAME("�����","diff");
	DEFINE_PROPERTY_NAME("�����ŷ���","volume");
	DEFINE_PROPERTY_NAME("�ð�","open");
	DEFINE_PROPERTY_NAME("��","high");
	DEFINE_PROPERTY_NAME("����","low");
	DEFINE_PROPERTY_NAME("������","sojinrate");
	DEFINE_PROPERTY_NAME("��Ÿ���","beta");
	DEFINE_PROPERTY_NAME("PER","perx");
	DEFINE_PROPERTY_NAME("���μ��ż�","frgsvolume");
	DEFINE_PROPERTY_NAME("������ż�","orgsvolume");
	DEFINE_PROPERTY_NAME("�ŷ�������","diff_vol");
	DEFINE_PROPERTY_NAME("�����ڵ�","shcode");
	DEFINE_PROPERTY_NAME("�ð��Ѿ�","total");
	DEFINE_PROPERTY_NAME("�ŷ����","value");
}
T1516Item::~T1516Item()
{
	//qDebug()<<"T1516Item destroyed";
}
