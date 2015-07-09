#include "t8430item.h"
#include "util/fieldutil.h"
#include <QDebug>
T8430Item::T8430Item(LPt8430OutBlock outblock, QObject *parent):TrItem(parent)
{
    _hname = GET_STRING_FROM_FIELD(outblock->hname);
    _shcode = GET_STRING_FROM_FIELD(outblock->shcode);
    _expcode = GET_STRING_FROM_FIELD(outblock->expcode);
    _isETF = outblock->etfgubun[0]=='1';
    _uplmtprice = GET_LONG_FROM_FIELD(outblock->uplmtprice);
    _dnlmtprice = GET_LONG_FROM_FIELD(outblock->dnlmtprice);
    _jniclose = GET_LONG_FROM_FIELD(outblock->jnilclose);
    _memedan = GET_STRING_FROM_FIELD(outblock->memedan);
    _recprice = GET_LONG_FROM_FIELD(outblock->recprice);
    _isKOSPI = outblock->gubun[0]=='1';

    DEFINE_PROPERTY_NAME("종목명", "hname");
    DEFINE_PROPERTY_NAME("단축코드", "shcode");
}

T8430Item::~T8430Item()
{
    //qDebug()<<"T8430Item destroyed";
}
