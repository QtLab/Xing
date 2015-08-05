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

long WarehouseHistory::calculateMinCumulativeSum(long minCumulativeSum, long cumulativeSum, bool isFirstRecord)
{
//    if(isFirstRecord) {
//        return cumulativeSum;
//    }
//    else
        return fmin(cumulativeSum, minCumulativeSum);
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

long WarehouseHistory::calculateMaxWarehousing(bool &isFirstRecord, WarehouseHistoryData *item, long maxWarehousing)
{
//    if(isFirstRecord) {
//        isFirstRecord = false;
//        return item->currentWareHousing;
//    } else
//        return fmax(maxWarehousing, item->currentWareHousing);
//    return item->maxWareHousing;
    return fmax(maxWarehousing, item->currentWareHousing);

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
    bool isFirstRecord= true;
    if(query.exec()) {
        while(query.next()) {
            WarehouseHistoryData *item = new WarehouseHistoryData();
            item->price = query.value(2).toInt();
            item->volume = query.value(1).toInt();
            cumulativeSum+= item->volume;
            item->cumulativeSum = cumulativeSum;
            minCumulativeSum = calculateMinCumulativeSum(minCumulativeSum, cumulativeSum, isFirstRecord);
            item->minCumulativeSum = minCumulativeSum;
            item->currentWareHousing = cumulativeSum-minCumulativeSum;
            calculateAvgPrice(prevWareHousing, item, prevAvgPrice);
            maxWarehousing = calculateMaxWarehousing(isFirstRecord, item, maxWarehousing);
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

VolumeHistoryData *WarehouseHistory::getVolumeHistory(const QString &shcode, const QDate &from, const QDate &to)
{
    QSqlQuery query;
    query.prepare(QObject::tr("SELECT AVG(`close`) AS avgPrice, SUM(`volume`) AS volume, SUM(`amt0000`) AS pef, SUM(`amt0001`) AS investment_c, SUM(`amt0002`) AS insurance, SUM(`amt0003`) AS investment_t, SUM(`amt0004`) AS bank, SUM(`amt0005`) AS allfinanz, SUM(`amt0006`) AS npf, SUM(`amt0007`) AS corp, SUM(`amt0008`) AS indivisual, SUM(`amt0009`) AS registered_foreigner, SUM(`amt0010`) AS non_registered_foreigner, SUM(`amt0011`) AS national FROM Movement_%1 WHERE `date`>='%2' AND `date`<='%3' ORDER BY `Date` ASC").arg(shcode).arg(from.toString("yyyyMMdd")).arg(to.toString("yyyyMMdd")));
    if(query.exec()) {
        if(query.next()){
            VolumeHistoryData *data = new VolumeHistoryData();
            data->avgPrice = query.value("avgPrice").toInt();
            data->volume = query.value("volume").toInt();
            data->pefVolume = query.value("pef").toInt();
            data->investmentCompanyVolume = query.value("investment_c").toInt();
            data->insuranceVolume = query.value("insurance").toInt();
            data->investmentTrustVolume = query.value("investment_t").toInt();
            data->bankVolume = query.value("bank").toInt();
            data->allFinanzVolume = query.value("allfinanz").toInt();
            data->npfVolume = query.value("npf").toInt();
            data->corpVolume = query.value("corp").toInt();
            data->indivisualVolume = query.value("indivisual").toInt();
            data->registeredForeignerVolume = query.value("registered_foreigner").toInt();
            data->nonRegisteredForeignerVolume = query.value("non_registered_foreigner").toInt();
            data->nationalVolume = query.value("national").toInt();
            return data;
        }
    }
    return nullptr;
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

const WarehouseHistoryData *WarehouseHistory::operator[](const QDate &date)
{
    WarehouseHistoryData *data = mItemMap.value(date);
    return mItemMap.value(date);
}

const WarehouseHistoryData *WarehouseHistory::operator[](int index)
{
    return mItemMap.value(mDateList.at(index));
}
