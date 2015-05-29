#include "t1702item.h"
#include "util/fieldutil.h"
#include <QDebug>

T1702Item::T1702Item(LPt1702OutBlock1 outblock, QObject *parent):TrItem(parent)
{
    mDate = GET_DATE_FROM_FIELD(outblock->date);
    mClose = GET_LONG_FROM_FIELD(outblock->close);
    mSign = outblock->sign[0]=='2'?SIGN(2):SIGN(5);
    mChange = GET_LONG_FROM_FIELD(outblock->change);
    mDiff = GET_FLOAT_FROM_FIELD(outblock->diff);
    mVolume = GET_LONG_FROM_FIELD(outblock->volume);
    mAmt0000 = GET_LONG_FROM_FIELD(outblock->amt0000);
    mAmt0001 = GET_LONG_FROM_FIELD(outblock->amt0001);
    mAmt0002 = GET_LONG_FROM_FIELD(outblock->amt0002);
    mAmt0003 = GET_LONG_FROM_FIELD(outblock->amt0003);
    mAmt0004 = GET_LONG_FROM_FIELD(outblock->amt0004);
    mAmt0005 = GET_LONG_FROM_FIELD(outblock->amt0005);
    mAmt0006 = GET_LONG_FROM_FIELD(outblock->amt0006);
    mAmt0007 = GET_LONG_FROM_FIELD(outblock->amt0007);
    mAmt0008 = GET_LONG_FROM_FIELD(outblock->amt0008);
    mAmt0009 = GET_LONG_FROM_FIELD(outblock->amt0009);
    mAmt0010 = GET_LONG_FROM_FIELD(outblock->amt0010);
    mAmt0011 = GET_LONG_FROM_FIELD(outblock->amt0011);
    mAmt0018 = GET_LONG_FROM_FIELD(outblock->amt0018);
    mAmt0088 = GET_LONG_FROM_FIELD(outblock->amt0088);
    mAmt0099 = GET_LONG_FROM_FIELD(outblock->amt0099);
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
