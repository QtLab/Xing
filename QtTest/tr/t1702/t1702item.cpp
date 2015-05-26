#include "t1702item.h"
#include <QDebug>

T1702Item::T1702Item(QObject *parent):TrItem(parent)
{

}

T1702Item::~T1702Item()
{
    qDebug()<<"T1702Item destroyed";
}

QStringList T1702Item::getPropertyList()
{
    QStringList list{"date", "close", "sign", "change", "diff", "volume",
                      "amt0000", "amt0001", "amt0002", "amt0003", "amt0004", "amt0005",
                     "amt0006", "amt0007", "amt0008", "amt0009", "amt0010", "amt0011",
                     "amt0018", "amt0088", "amt0099"};
    return list;
}
