#include "t8430item.h"

T8430Item::T8430Item()
{

}

T8430Item::~T8430Item()
{

}

QStringList T8430Item::getPropertyList()
{
    QStringList list{"mHname", "mShcode", "mExpcode", "bIsETF", "mUplmtprice", "bIsETF", "mUplmtprice", "mDnlmtprice", "mJniclose", "mMemedan", "mRecprice", "bIsKOSPI"};
    return list;
}

