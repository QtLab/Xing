#include "t8430item.h"

#include <QDebug>
T8430Item::T8430Item(QObject *parent):TrItem(parent)
{
    DEFINE_PROPERTY_NAME("�����", "hname");
    DEFINE_PROPERTY_NAME("�����ڵ�", "shcode");
}

T8430Item::~T8430Item()
{
    //qDebug()<<"T8430Item destroyed";
}
