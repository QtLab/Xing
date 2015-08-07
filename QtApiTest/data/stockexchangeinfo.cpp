#include <QObject>
#include <QtSql/QSqlQuery>
#include "stockexchangeinfo.h"
#include "util/log.h"
StockExchangeInfo::StockExchangeInfo(const QString &shcode):mShcode(shcode)
{
    initDateList();
}

StockExchangeInfo::~StockExchangeInfo()
{

}

MovingVolumeSumInfo *StockExchangeInfo::getTotalMovingVolumeSumInfo(MOVING_TYPE type, const QDate &date) const
{
    QDate toDate = getTargetDate(date);
    QDate fromDate = getFromDate(type, toDate);
    MovingVolumeSumInfo *info = new MovingVolumeSumInfo();
    QSqlQuery query;
    query.prepare(QObject::tr("SELECT SUM(`close`*`volume`) as totalPrice, SUM(`volume`) as totalVolume, SUM(amt0000) as pef, SUM(amt0001) as investment_c, SUM(amt0002) as insurance, SUM(amt0003) as investment_t, SUM(amt0004) as bank, SUM(amt0005) as allfinanz, SUM(amt0006) as npf, SUM(amt0007) as corp, SUM(amt0008) as indivisual, SUM(amt0009) as registered, SUM(amt0010) as non_registered, SUM(amt0011) as national, SUM(amt0018) as institution, SUM(amt0000+amt0001+amt0002+amt0003+amt0004+amt0005+amt0006+amt0007+amt0009+amt0011) as forces FROM Movement_%1 WHERE `date`>='%2' AND `date`<='%3' ").arg(mShcode).arg(fromDate.toString("yyyyMMdd")).arg(toDate.toString("yyyyMMdd")));
    if(query.exec()&query.next()) {
        info->date = toDate;
        qlonglong totalPrice = query.value("totalPrice").toLongLong();
        long totalVolume = query.value("totalVolume").toLongLong();
        info->avgPrice = totalPrice/(qlonglong)totalVolume;
        info->totalVolumeSum = totalVolume;
        info->movingType = type;
        info->volumeSum[static_cast<int>(INDIVISUAL)] = query.value("indivisual").toInt();
        info->volumeSum[static_cast<int>(FORCES)] = query.value("forces").toInt();
        info->volumeSum[static_cast<int>(REGISTERED_FOREIGNER)] = query.value("registered").toInt();
        info->volumeSum[static_cast<int>(INSTITUTION)] = query.value("institution").toInt();
        info->volumeSum[static_cast<int>(PEF)] = query.value("pef").toInt();
        info->volumeSum[static_cast<int>(INVESTMENT_C)] = query.value("investment_c").toInt();
        info->volumeSum[static_cast<int>(INSURANCE)] = query.value("insurance").toInt();
        info->volumeSum[static_cast<int>(INVESTMENT_T)] = query.value("investment_t").toInt();
        info->volumeSum[static_cast<int>(BANK)] = query.value("bank").toInt();
        info->volumeSum[static_cast<int>(ALLFINANZ)] = query.value("allfinanz").toInt();
        info->volumeSum[static_cast<int>(NPF)] = query.value("npf").toInt();
        info->volumeSum[static_cast<int>(CORP)] = query.value("corp").toInt();
        info->volumeSum[static_cast<int>(NON_REGISTERED_FOREIGNER)] = query.value("non_registered").toInt();
        info->volumeSum[static_cast<int>(NATIONAL)] = query.value("NATIONAL").toInt();
        return info;
    }else {
        query_error(stockExchangeInfo, query);
        return info;
    }
}

int StockExchangeInfo::getNumberOfDates()
{
    return mDateList.size();
}

QDate StockExchangeInfo::getDateByIndex(int index) const
{
    return mDateList.at(index);
}

QDate StockExchangeInfo::getFromDate(MOVING_TYPE type, QDate toDate) const
{
    int toIndex = mDateList.indexOf(toDate);
    int fromIndex = toIndex+static_cast<int>(type)-1;
    QDate fromDate(mDateList.at(fromIndex));

    return fromDate;
}

long StockExchangeInfo::getMovingVolumeSum(INVESTORS investor, MOVING_TYPE type, const QDate &date) const
{
    QDate toDate = getTargetDate(date);
    QDate fromDate = getFromDate(type, toDate);

    QSqlQuery query;
    query.prepare(QObject::tr("SELECT SUM(%1) as volumeSum FROM Movement_%2 WHERE `date` >= %3 AND `date`<=%4").arg(getColumnNameByInvestor(investor)).arg(mShcode).arg(fromDate.toString("yyyyMMdd")).arg(toDate.toString("yyyyMMdd")));

    if(query.exec()&& query.next()) {
        return query.value("volumeSum").toInt();
    } else {
        query_error(stockExchangeInfo, query);
        return -1;
    }
}

long StockExchangeInfo::getMovingAvgPrice(MOVING_TYPE type, const QDate &date) const
{
    long totalVolume = 0;
    qlonglong totalPrice = 0;
    QDate toDate = getTargetDate(date);
    QDate fromDate = getFromDate(type, date);
    QSqlQuery query;
    query.prepare(QObject::tr("SELECT `close`, `volume` FROM Movement_%1 WHERE `date`>=%2 AND `date`<=%3").arg(mShcode).arg(fromDate.toString("yyyyMMdd")).arg(toDate.toString("yyyyMMdd")));
    if(query.exec()) {
        while(query.next()) {
            long price = query.value("close").toInt();
            long volume = query.value("volume").toInt();
            totalVolume += volume;
            totalPrice += (qlonglong)volume*(qlonglong)price;
        }
        return totalPrice/totalVolume;
    } else {
        query_error(stockExchangeInfo, query);
        return -1;
    }
}

long StockExchangeInfo::getMovingTotalVolumeSum(MOVING_TYPE type, const QDate &date) const
{
    QDate toDate = getTargetDate(date);
    QDate fromDate = getFromDate(type, date);
    QSqlQuery query;
    query.prepare(QObject::tr("SELECT SUM(`volume`) as totalVolume FROM Movement_%1 WHERE `date`>=%2 AND `date`<=%3").arg(mShcode).arg(fromDate.toString("yyyyMMdd")).arg(toDate.toString("yyyyMMdd")));
    if(query.exec()&&query.next()) {
        return query.value("totalVolume").toInt();
    } else {
        query_error(stockExchangeInfo, query);
        return -1;
    }
}

void StockExchangeInfo::initDateList()
{
    QSqlQuery query;
    query.prepare(QObject::tr("SELECT `date` FROM Movement_%1 ORDER BY `date` DESC").arg(mShcode));
    if(query.exec()) {
        while(query.next()) {
            mDateList.push_back(query.value("date").toDate());
        }
    }
}

QDate StockExchangeInfo::getTargetDate(const QDate &date) const
{
    QSqlQuery query;
    query.prepare(QObject::tr("SELECT max(`date`) FROM Movement_%1 WHERE `date`<='%2'").arg(mShcode).arg(date.toString("yyyyMMdd")));
    if(query.exec()&&query.next()) {
        QDate lessDate = query.value(0).toDate();
        return lessDate;
    } else {
        query_error(stockExchangeInfo,query);
        return date;
    }
}

QString StockExchangeInfo::getColumnNameByInvestor(INVESTORS investor) const
{
    switch(investor) {
    case INDIVISUAL:
        return INDIVISUAL_COLUMN;
    case FORCES:
        return FORCES_COLUMN;
    case REGISTERED_FOREIGNER:
        return REGISTERED_FOREIGNER_COLUMN;
    case INSTITUTION:
        return INSTITUTION_COLUMN;
    case PEF:
        return PEF_COLUMN;
    case INVESTMENT_C:
        return INVESTMENT_C_COLUMN;
    case INSURANCE:
        return INSURANCE_COLUMN;
    case INVESTMENT_T:
        return INVESTMENT_T_COLUMN;
    case BANK:
        return BANK_COLUMN;
    case ALLFINANZ:
        return ALLFINANZ_COLUMN;
    case NPF:
        return NPF_COLUMN;
    case CORP:
        return CORP_COLUMN;
    case NON_REGISTERED_FOREIGNER:
        return NON_REGISTERED_FOREIGNER_COLUMN;
    case NATIONAL:
        return NATIONAL_COLUMN;
    default :
        qCCritical(stockExchangeInfo)<<"Can not find column name for "<<investor;
        break;
    }
}

