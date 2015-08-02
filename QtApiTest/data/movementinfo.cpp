#include <QtSql/QSqlQuery>
#include <QVariant>
#include <math.h>
#include "movementinfo.h"
QString MovementInfo::PEF_COLUMN_NAME = QString("amt0000");
QString MovementInfo::INVESTMENT_C_COLUMN_NAME = QString("amt0001");
QString MovementInfo::INSURANCE_COLUMN_NAME = QString("amt0002");
QString MovementInfo::INVESTMENT_T_COLUMN_NAME = QString("amt0003");
QString MovementInfo::BANK_COLUMN_NAME = QString("amt0004");
QString MovementInfo::ALLFINANZ_COLUMN_NAME = QString("amt0005");
QString MovementInfo::NPF_COLUMN_NAME = QString("amt0006");
QString MovementInfo::CORP_COLUMN_NAME = QString("amt0007");
QString MovementInfo::INDIVISUAL_COLUMN_NAME = QString("amt0008");
QString MovementInfo::REGISTERED_FOREIGNER_COLUMN_NAME = QString("amt0009");
QString MovementInfo::NON_REGISTERED_FOREIGNER_COLUMN_NAME = QString("amt0010");
QString MovementInfo::NATIONAL_COLUMN_NAME = QString("amt0011");

MovementInfo::MovementInfo()
{

}

QString MovementInfo::getFieldNameFromType(MovementInfo::TYPE type)
{
    switch(type) {
    case PEF :
        return PEF_COLUMN_NAME;
    case INVESTMENT_C :
        return INVESTMENT_C_COLUMN_NAME;
    case INSURANCE :
        return INSURANCE_COLUMN_NAME;
    case INVESTMENT_T:
        return INVESTMENT_T_COLUMN_NAME;
    case BANK :
        return BANK_COLUMN_NAME;
    case ALLFINANZ :
        return ALLFINANZ_COLUMN_NAME;
    case NPF :
        return NPF_COLUMN_NAME;
    case CORP:
        return CORP_COLUMN_NAME;
    case INDIVISUAL:
        return INDIVISUAL_COLUMN_NAME;
    case REGISTERED_FOREIGNER:
        return REGISTERED_FOREIGNER_COLUMN_NAME;
    case NON_REGISTERED_FOREIGNER:
        return NON_REGISTERED_FOREIGNER_COLUMN_NAME;
    case NATIONAL:
        return NATIONAL_COLUMN_NAME;
    default:
        return NONE;
    }
}

MovementInfo *MovementInfo::createMovementInfo(const QString &shcode, MovementInfo::TYPE type)
{
    MovementInfo *info = new MovementInfo();
    QSqlQuery query;
    long cumulativeSum = 0;
    long minCumulativeSum = 0;
    long maxWareHousing = 0;
    query.prepare(QObject::tr("SELECT `date`, `close`, `%1` FROM Movement_%2 ORDER BY `date` DESC").arg(getFieldNameFromType(type)).arg(shcode));
    if(query.exec()) {
        while(query.next()) {
            MovementItem *item = new MovementItem();
            item->date = query.value(0).toDate();
            item->cumulativeSum = cumulativeSum += query.value(2).toInt();
            item->minCumulativeSum = minCumulativeSum = fmin(cumulativeSum, minCumulativeSum);
            item->currentWareHousing = cumulativeSum-minCumulativeSum;
            maxWareHousing = fmax(maxWareHousing, item->currentWareHousing);
            item->distPercent = (float) (item->currentWareHousing/item->maxWareHousing);
            info->mItemList.append(item);
        }
    }
    return info;
}

int MovementInfo::getCount()
{
   return mItemList.size();
}

MovementInfo::~MovementInfo()
{
    foreach(MovementItem * item , mItemList) {
        delete item;
    }
    mItemList.clear();
}

QDate MovementInfo::date(int index)
{
    return mItemList.at(index)->date;
}

long MovementInfo::cumulativeSum(int index)
{
    return mItemList.at(index)->cumulativeSum;
}

long MovementInfo::minCumulativeSum(int index)
{
    return mItemList.at(index)->minCumulativeSum;
}

long MovementInfo::currentWareHousing(int index)
{
    return mItemList.at(index)->currentWareHousing;
}

long MovementInfo::maxWareHousing(int index)
{
    return mItemList.at(index)->maxWareHousing;
}

float MovementInfo::distPercent(int index)
{
    return mItemList.at(index)->distPercent;
}

