#ifndef MOVEMENTINFO_H
#define MOVEMENTINFO_H

#include <QList>
#include <QDate>
typedef struct _MovementItem {
    QDate date;
    long cumulativeSum;				//�����հ�
    long minCumulativeSum;			//�ְ�����
    long currentWareHousing;		//��������
    long maxWareHousing;				//
    float distPercent;
} MovementItem;

class MovementInfo
{
public:
    //PEF : ����ݵ� , IC(Invesetment Company) : ��������(����)
    //INSURANCE : ����, IT(Investment Truest) : ���ڽ�Ź(����)
    //BANK : ����, ALLFINANZ : ���ձ���(����)
    //NPF : National Pension Fund(�����) CORP : ��Ÿ����
    //INDIVISUAL : ����, REGISTERED_FOREIGNER : ��� �ܱ���
    //NON_REGISTERED_FOREIGNER : �̵�� �ܱ���, NATIONAL : ������

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
