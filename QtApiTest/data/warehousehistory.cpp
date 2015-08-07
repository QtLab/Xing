#include <QtSql/QSqlQuery>
#include <QObject>
#include <QVariant>
#include "warehousehistory.h"

QString WarehouseHistory::PEF_COLUMN_NAME = QString("`amt0000`");
QString WarehouseHistory::INVESTMENT_C_COLUMN_NAME = QString("`amt0001`");
QString WarehouseHistory::INSURANCE_COLUMN_NAME = QString("`amt0002`");
QString WarehouseHistory::INVESTMENT_T_COLUMN_NAME = QString("`amt0003`");
QString WarehouseHistory::BANK_COLUMN_NAME = QString("`amt0004`");
QString WarehouseHistory::ALLFINANZ_COLUMN_NAME = QString("`amt0005`");
QString WarehouseHistory::NPF_COLUMN_NAME = QString("`amt0006`");
QString WarehouseHistory::CORP_COLUMN_NAME = QString("`amt0007`");
QString WarehouseHistory::INDIVISUAL_COLUMN_NAME = QString("`amt0008`");
QString WarehouseHistory::REGISTERED_FOREIGNER_COLUMN_NAME = QString("`amt0009`");
QString WarehouseHistory::NON_REGISTERED_FOREIGNER_COLUMN_NAME = QString("`amt0010`");
QString WarehouseHistory::NATIONAL_COLUMN_NAME = QString("`amt0011`");
QString WarehouseHistory::INSTITUTION_COLUMN_NAME = QString("`amt0018`");

WarehouseHistory::WarehouseHistory()
{

}

QString WarehouseHistory::getFieldNameFromType(INVESTORS type)
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
    case INSTITUTION:
        return INSTITUTION_COLUMN_NAME;
    case FORCES:
        return "(amt0000+amt0001+amt0002+amt0003+amt0004+amt0005+amt0006+amt0007+amt0009+amt0011) as forces";
    default:

        return "default";
    }
}

void WarehouseHistory::calculateAvgPrice(long prevWareHousing, WarehouseHistoryData *item, long prevAvgPrice)
{
    if(item->currentWareHousing>0) {
        if(prevAvgPrice!=0) {
            long incrementedWareHousing = item->currentWareHousing-prevWareHousing;
            incrementedWareHousing=incrementedWareHousing<0?0:incrementedWareHousing;
           item->avgPrice = ((qlonglong)prevAvgPrice*(qlonglong)prevWareHousing+(qlonglong)incrementedWareHousing*(qlonglong) item->price)/(prevWareHousing+incrementedWareHousing);
        } else {
            item->avgPrice = item->price;
        }
    }else {
        item->avgPrice = item->price;
    }
}

void WarehouseHistory::calculateDistPercent(WarehouseHistoryData *item)
{
    if(item->maxWareHousing==0) {
        item->distPercent = 0;
    } else {
        item->distPercent = (float) ((double)item->currentWareHousing/(double)item->maxWareHousing);
    }
}

WarehouseHistory *WarehouseHistory::createWarehouseHistory(const QString &shcode, INVESTORS type)
{
    WarehouseHistory *info = new WarehouseHistory();
    QSqlQuery query;
    long cumulativeSum = 0;
    long minCumulativeSum = 0;
    long prevWareHousing = 0;
    long prevAvgPrice = 0;
    long maxWarehousing = 0;
    query.prepare(QObject::tr("SELECT `date`, %1,`close` FROM Movement_%2 ORDER BY `date` ASC").arg(getFieldNameFromType(type)).arg(shcode));
    if(query.exec()) {
        while(query.next()) {
            WarehouseHistoryData *item = new WarehouseHistoryData();
            item->price = query.value(2).toInt();
            item->volume = query.value(1).toInt();
            cumulativeSum+= item->volume;
            item->cumulativeSum = cumulativeSum;
            minCumulativeSum = fmin(minCumulativeSum, cumulativeSum);
            item->minCumulativeSum = minCumulativeSum;
            item->currentWareHousing = cumulativeSum-minCumulativeSum;
            calculateAvgPrice(prevWareHousing, item, prevAvgPrice);
            maxWarehousing = fmax(maxWarehousing, item->currentWareHousing);
            item->maxWareHousing = maxWarehousing;
            calculateDistPercent(item);
            item->date = query.value(0).toDate();
            info->mItemMap.insert(item->date, item);
            info->mDateList.push_front(item->date);
            prevWareHousing = item->currentWareHousing;
            prevAvgPrice = item->avgPrice;
        }
    }
    return info;
}

int WarehouseHistory::getCount()
{
    return mItemMap.size();
}

WarehouseHistory::~WarehouseHistory()
{
    foreach(WarehouseHistoryData * item , mItemMap) {
        delete item;
    }
    mItemMap.clear();
}

const WarehouseHistoryData *WarehouseHistory::operator[](const QDate &date) const
{
    WarehouseHistoryData *data = mItemMap.value(date);
    return mItemMap.value(date);
}

const WarehouseHistoryData *WarehouseHistory::last() const
{
    return mItemMap.value(mDateList.first());
}

const WarehouseHistoryData *WarehouseHistory::operator[](int index) const
{
    return mItemMap.value(mDateList.at(index));
}
