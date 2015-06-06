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

    DEFINE_PROPERTY_NAME("일자","date");
    DEFINE_PROPERTY_NAME("종가","close");
    DEFINE_PROPERTY_NAME("전일대비구분","sign");
    DEFINE_PROPERTY_NAME("전일대비", "change");
    DEFINE_PROPERTY_NAME("등락율", "diff");
    DEFINE_PROPERTY_NAME("누적거래량", "volume");
    DEFINE_PROPERTY_NAME("개인", "amt0008");
    DEFINE_PROPERTY_NAME("등록외국인", "amt0009");
    DEFINE_PROPERTY_NAME("미등록외국인", "amt0010");
    DEFINE_PROPERTY_NAME("외인계", "amt0088");
    DEFINE_PROPERTY_NAME("기관", "amt0018");
    DEFINE_PROPERTY_NAME("투신", "amt0003");
    DEFINE_PROPERTY_NAME("보험", "amt0002");
    DEFINE_PROPERTY_NAME("은행", "amt0004");
    DEFINE_PROPERTY_NAME("종금", "amt0005");
    DEFINE_PROPERTY_NAME("기금", "amt0006");
    DEFINE_PROPERTY_NAME("사모펀드", "amt0000");
    DEFINE_PROPERTY_NAME("증권", "amt0001");
    DEFINE_PROPERTY_NAME("기타법인", "amt0007");
    DEFINE_PROPERTY_NAME("국가외", "amt0011");
    DEFINE_PROPERTY_NAME("기타계", "amt0099");
}

T1702Item::~T1702Item()
{
    qDebug()<<"T1702Item destroyed";
}
