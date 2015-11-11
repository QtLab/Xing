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
    long cumulativeSum = 0;				//�����հ�
    long minCumulativeSum = 0;			//�ְ�����
    long currentWareHousing = 0;		//��������
    long maxWareHousing = 0;			//��������
    float distPercent = 0;				//�л����
} WarehouseHistoryData;

class WarehouseHistory
{
public:
    //PEF : ����ݵ� , IC(Invesetment Company) : ��������(����)
    //INSURANCE : ����, IT(Investment Trust) : ���ڽ�Ź(����)
    //BANK : ����, ALLFINANZ : ���ձ���(����)
    //NPF : National Pension Fund(�����) CORP : ��Ÿ����
    //INDIVISUAL : ����, REGISTERED_FOREIGNER : ��� �ܱ���
    //NON_REGISTERED_FOREIGNER : �̵�� �ܱ���, NATIONAL : ������

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
