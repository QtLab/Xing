#include "core/tr/t1702/t1702item.h"
#include <QDebug>

T1702Item::T1702Item(const QString &shcode, QObject *parent):TrItem(parent), mShcode(shcode)
{

	DEFINE_PROPERTY_NAME("����","date");
	DEFINE_PROPERTY_NAME("����","close");
	DEFINE_PROPERTY_NAME("���ϴ�񱸺�","sign");
	DEFINE_PROPERTY_NAME("���ϴ��","change");
	DEFINE_PROPERTY_NAME("�����","diff");
	DEFINE_PROPERTY_NAME("�����ŷ���","volume");
	DEFINE_PROPERTY_NAME("����ݵ�","amt0000");
	DEFINE_PROPERTY_NAME("����","amt0001");
	DEFINE_PROPERTY_NAME("����","amt0002");
	DEFINE_PROPERTY_NAME("����","amt0003");
	DEFINE_PROPERTY_NAME("����","amt0004");
	DEFINE_PROPERTY_NAME("����","amt0005");
	DEFINE_PROPERTY_NAME("���","amt0006");
	DEFINE_PROPERTY_NAME("��Ÿ����","amt0007");
	DEFINE_PROPERTY_NAME("����","amt0008");
	DEFINE_PROPERTY_NAME("��Ͽܱ���","amt0009");
	DEFINE_PROPERTY_NAME("�̵�Ͽܱ���","amt0010");
	DEFINE_PROPERTY_NAME("������","amt0011");
	DEFINE_PROPERTY_NAME("���","amt0018");
	DEFINE_PROPERTY_NAME("���ΰ�","amt0088");
	DEFINE_PROPERTY_NAME("��Ÿ��","amt0099");
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
