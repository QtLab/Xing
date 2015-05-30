#include "t8430item.h"
#include "util/fieldutil.h"
#include <QDebug>
T8430Item::T8430Item(LPt8430OutBlock outblock, QObject *parent):TrItem(parent)
{
    mHname = GET_STRING_FROM_FIELD(outblock->hname);
    mShcode = GET_STRING_FROM_FIELD(outblock->shcode);
    mExpcode = GET_STRING_FROM_FIELD(outblock->expcode);,./
}

T8430Item::~T8430Item()
{
    qDebug()<<"T8430Item destroyed";
}

QStringList T8430Item::getPropertyList()
{
    QStringList list{"mHname", "mShcode", "mExpcode", "bIsETF", "mUplmtprice", "bIsETF", "mUplmtprice", "mDnlmtprice", "mJniclose", "mMemedan", "mRecprice", "bIsKOSPI"};
    return list;
}
