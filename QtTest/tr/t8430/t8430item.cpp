#include "t8430item.h"
#include <QDebug>
T8430Item::T8430Item(QObject *parent):TrItem(parent)
{

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

