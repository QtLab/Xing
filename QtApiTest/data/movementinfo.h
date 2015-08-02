#ifndef MOVEMENTINFO_H
#define MOVEMENTINFO_H

#include <QList>
#include <QDate>
typedef struct _MovementItem {
    QDate date;
    long cumulativeSum;				//누적합계
    long minCumulativeSum;			//최고저점
    long currentWareHousing;		//매집수량
    long maxWareHousing;				//
    float distPercent;
} MovementItem;

class MovementInfo
{
public:
    //PEF : 사모펀드 , IC(Invesetment Company) : 금융투자(증권)
    //INSURANCE : 보험, IT(Investment Truest) : 투자신탁(투신)
    //BANK : 은행, ALLFINANZ : 종합금융(종금)
    //NPF : National Pension Fund(연기금) CORP : 기타법인
    //INDIVISUAL : 개인, REGISTERED_FOREIGNER : 등록 외국인
    //NON_REGISTERED_FOREIGNER : 미등록 외국인, NATIONAL : 국가외

    typedef enum {PEF, INVESTMENT_C, INSURANCE, INVESTMENT_T, BANK, ALLFINANZ, NPF, CORP, INDIVISUAL, REGISTERED_FOREIGNER, NON_REGISTERED_FOREIGNER, NATIOANL} TYPE;

    static MovementInfo createMovementInfo(const QString &shcode, TYPE type, const QDate &fromDate , const QDate &toDate = QDate::currentDate());
    ~MovementInfo();
private:
    MovementInfo();
    static QString getFieldNameFromType(TYPE type);

private:
    QList<MovementItem *> mItemList;
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
};

#endif // MOVEMENTINFO_H
