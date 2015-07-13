#include "t8430item.h"

#include <QDebug>
T8430Item::T8430Item(QObject *parent):TrItem(parent)
{
    DEFINE_PROPERTY_NAME("종목명", "hname");
    DEFINE_PROPERTY_NAME("단축코드", "shcode");
}

T8430Item::~T8430Item()
{
    //qDebug()<<"T8430Item destroyed";
}
