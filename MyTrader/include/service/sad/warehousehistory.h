#ifndef WAREHOUSEHISTORY_H
#define WAREHOUSEHISTORY_H

#include <QString>
#include <QDate>
#include <QMap>
#include "common/type/commontype.h"
typedef struct _WarehouseHistoryData {
    QDate date;
    long volume = 0;
    long price = 0;
    long avgPrice = 0;
    long cumulativeSum = 0;				//누적합계
    long minCumulativeSum = 0;			//최고저점
    long currentWareHousing = 0;		//매집수량
    long maxWareHousing = 0;			//매집고점
    float distPercent = 0;				//분산비율
} WarehouseHistoryData;

class WarehouseHistory
{
public:
    //PEF : 사모펀드 , IC(Invesetment Company) : 금융투자(증권)
    //INSURANCE : 보험, IT(Investment Trust) : 투자신탁(투신)
    //BANK : 은행, ALLFINANZ : 종합금융(종금)
    //NPF : National Pension Fund(연기금) CORP : 기타법인
    //INDIVISUAL : 개인, REGISTERED_FOREIGNER : 등록 외국인
    //NON_REGISTERED_FOREIGNER : 미등록 외국인, NATIONAL : 국가외

    static WarehouseHistory *createWarehouseHistory(const QString &shcode, INVESTORS type);
    int getCount();
    ~WarehouseHistory();

    const WarehouseHistoryData *operator[](const QDate &date) const;
    const WarehouseHistoryData *operator[](int index) const;
    const WarehouseHistoryData *last() const;
private:
    WarehouseHistory();
    static QString getFieldNameFromType(INVESTORS type);
    static void calculateAvgPrice(long prevWareHousing, WarehouseHistoryData *item, long prevAvgPrice);
    static void calculateDistPercent(WarehouseHistoryData *item);
private:
    QMap<QDate, WarehouseHistoryData *> mItemMap;
    QList<QDate> mDateList;
    static QString PEF_COLUMN_NAME;
    static QString INVESTMENT_C_COLUMN_NAME;
    static QString INSURANCE_COLUMN_NAME;
    static QString INVESTMENT_T_COLUMN_NAME;
    static QString BANK_COLUMN_NAME;
    static QString ALLFINANZ_COLUMN_NAME;
    static QString NPF_COLUMN_NAME;
    static QString CORP_COLUMN_NAME;
    static QString INDIVISUAL_COLUMN_NAME;
    static QString REGISTERED_FOREIGNER_COLUMN_NAME;
    static QString NON_REGISTERED_FOREIGNER_COLUMN_NAME;
    static QString NATIONAL_COLUMN_NAME;
    static QString INSTITUTION_COLUMN_NAME;
};

#endif // WAREHOUSEHISTORY_H
