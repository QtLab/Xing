#include "t8430item.h"
#include "util/fieldutil.h"
#include <QDebug>
T8430Item::T8430Item(LPt8430OutBlock outblock, QObject *parent):TrItem(parent)
{
    mHname = GET_STRING_FROM_FIELD(outblock->hname);
    mShcode = GET_STRING_FROM_FIELD(outblock->shcode);
    mExpcode = GET_STRING_FROM_FIELD(outblock->expcode);
    bIsETF = outblock->etfgubun[0]=='1';
    mUplmtprice = GET_LONG_FROM_FIELD(outblock->uplmtprice);
    mDnlmtprice = GET_LONG_FROM_FIELD(outblock->dnlmtprice);
    mJniclose = GET_LONG_FROM_FIELD(outblock->jnilclose);
    mMemedan = GET_STRING_FROM_FIELD(outblock->memedan);
    mRecprice = GET_LONG_FROM_FIELD(outblock->recprice);
    bIsKOSPI = outblock->gubun[0]=='1';

    DEFINE_PROPERTY_NAME("종목명", "hname");
    DEFINE_PROPERTY_NAME("단축코드", "shcode");
}

T8430Item::~T8430Item()
{

}
