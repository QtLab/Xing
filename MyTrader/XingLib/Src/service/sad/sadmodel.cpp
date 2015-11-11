#include <QColor>
#include <QLocale>
#include "sadmodel.h"
#include "core/util/xingutil.h"
SADModel::SADModel(StockExchangeInfo *stockExchangeInfo, QObject *parent) : QAbstractTableModel(parent), mStockExchangeInfo(stockExchangeInfo)
{
    initRowCnt();
    initData();
}

SADModel::~SADModel()
{
}

int SADModel::rowCount(const QModelIndex &parent) const
{
    return mRowCnt;
}

int SADModel::columnCount(const QModelIndex &parent) const
{
    return 17;
}

QVariant SADModel::data(const QModelIndex &index, int role) const
{
    if(role==Qt::DisplayRole) {
        return getDisplayRoleData(index);
    } else if(role == Qt::ForegroundRole) {
        return getForegroundRoleData(index);
    } else if(role == Qt::TextAlignmentRole) {
        return getTextAlignmentRole(index);
    }
    return QVariant::Invalid;
}
QVariant SADModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role == Qt::DisplayRole) {
        if(orientation==Qt::Horizontal) {
            switch(section) {
            case 0:
                return qkor("����");
            case 1:
                return qkor("��մܰ�");
            case 2:
                return qkor("�ŷ���");
            case 3:
                return qkor("����");
            case 4:
                return qkor("������");
            case 5:
                return qkor("�ܱ���");
            case 6:
                return qkor("���");
            case 7:
                return qkor("����ݵ�");
            case 8:
                return qkor("��������");
            case 9:
                return qkor("����");
            case 10:
                return qkor("���ڽ�Ź");
            case 11:
                return qkor("����");
            case 12:
                return qkor("���ձ���");
            case 13:
                return qkor("�����");
            case 14:
                return qkor("��Ÿ����");
            case 15:
                return qkor("���ܱ���");
            case 16:
                return qkor("������");
            default:
                return QVariant::Invalid;
            }
        } else {
            return section;
        }
    } else {
        return QVariant::Invalid;
    }
}

void SADModel::initRowCnt()
{
    int days = mStockExchangeInfo->getNumberOfDates();
    if(days<MOVING_5_DAYS) {
        mRowCnt = days==6?5:days;
    } else if(days<MOVING_20_DAYS) {
        mRowCnt = DAILY_ROW_SIZE+days/MOVING_5_DAYS;
    } else if(days<MOVING_60_DAYS) {
        mRowCnt = DAILY_ROW_SIZE + WEEKLY_ROW_SIZE + days/MOVING_20_DAYS;
    } else if(days<MOVING_240_DAYS) {
        mRowCnt = DAILY_ROW_SIZE + WEEKLY_ROW_SIZE + MONTHLY_ROW_SIZE+days/MOVING_60_DAYS;
    } else {
        mRowCnt = DAILY_ROW_SIZE + WEEKLY_ROW_SIZE + MONTHLY_ROW_SIZE + QUARTERLY_ROW_SIZE+days/MOVING_240_DAYS;
    }
}
void SADModel::initData()
{
    for(int i = 0; i<mRowCnt; ++i) {
        if(i<DAILY_ROW_SIZE) {
            QDate date = mStockExchangeInfo->getDateByIndex(i);
            MovingVolumeSumInfo* info = mStockExchangeInfo->getTotalMovingVolumeSumInfo(DAILY,date);
            mValues.push_back(info);
        } else if(i<DAILY_ROW_SIZE+WEEKLY_ROW_SIZE) {
            int index = (i-DAILY_ROW_SIZE)*MOVING_5_DAYS;
            QDate date = mStockExchangeInfo->getDateByIndex(index);
            MovingVolumeSumInfo* info = mStockExchangeInfo->getTotalMovingVolumeSumInfo(MOVING_5_DAYS,date);
            mValues.push_back(info);
        } else if(i<DAILY_ROW_SIZE+WEEKLY_ROW_SIZE+MONTHLY_ROW_SIZE) {
            int index = (i-DAILY_ROW_SIZE-WEEKLY_ROW_SIZE)*MOVING_20_DAYS;
            QDate date = mStockExchangeInfo->getDateByIndex(index);
            MovingVolumeSumInfo* info = mStockExchangeInfo->getTotalMovingVolumeSumInfo(MOVING_20_DAYS,date);
            mValues.push_back(info);
        } else if(i<DAILY_ROW_SIZE+WEEKLY_ROW_SIZE+MONTHLY_ROW_SIZE+QUARTERLY_ROW_SIZE) {
            int index = (i-DAILY_ROW_SIZE-WEEKLY_ROW_SIZE-MONTHLY_ROW_SIZE)*MOVING_60_DAYS;
            QDate date = mStockExchangeInfo->getDateByIndex(index);
            MovingVolumeSumInfo* info = mStockExchangeInfo->getTotalMovingVolumeSumInfo(MOVING_60_DAYS,date);
            mValues.push_back(info);
        } else {
            int index = (i-DAILY_ROW_SIZE-WEEKLY_ROW_SIZE-MONTHLY_ROW_SIZE-QUARTERLY_ROW_SIZE)*MOVING_240_DAYS;
            QDate date = mStockExchangeInfo->getDateByIndex(index);
            MovingVolumeSumInfo* info = mStockExchangeInfo->getTotalMovingVolumeSumInfo(MOVING_240_DAYS,date);
            mValues.push_back(info);
        }
    }
}

QVariant SADModel::getDisplayRoleData(const QModelIndex &index) const
{
    switch(index.column()) {
    case 0:
        if(index.row()<DAILY_ROW_SIZE) {
            return mStockExchangeInfo->getDateByIndex(index.row());
        } else if(index.row()< DAILY_ROW_SIZE + WEEKLY_ROW_SIZE) {
            return tr("%1 week").arg(index.row()-DAILY_ROW_SIZE+1);
        } else if(index.row()< DAILY_ROW_SIZE + WEEKLY_ROW_SIZE + MONTHLY_ROW_SIZE) {
            return tr("%1 month").arg(index.row()-DAILY_ROW_SIZE- WEEKLY_ROW_SIZE+1);
        } else if(index.row()< DAILY_ROW_SIZE + WEEKLY_ROW_SIZE + MONTHLY_ROW_SIZE + QUARTERLY_ROW_SIZE) {
            return tr("%1 quarter").arg(index.row()-DAILY_ROW_SIZE-WEEKLY_ROW_SIZE - MONTHLY_ROW_SIZE + 1);
        } else {
            return tr("%1 year").arg(index.row()-DAILY_ROW_SIZE-WEEKLY_ROW_SIZE - MONTHLY_ROW_SIZE - QUARTERLY_ROW_SIZE + 1) ;
        }
        break;
    case 1:
        return tr("%L1").arg(mValues.at(index.row())->avgPrice);
    case 2:
        return tr("%L1").arg(mValues.at(index.row())->totalVolumeSum);
    default:
        return tr("%L1").arg(mValues.at(index.row())->volumeSum[index.column()-3]);
    }
}

QVariant SADModel::getForegroundRoleData(const QModelIndex &index) const
{
    if((index.column()==0)||(index.column()==1)||(index.column()==2)) {
        return QVariant(QColor(Qt::black));
    } else {
        if(getInvestorColumnValue(index)>=0) {
            return QVariant(QColor(Qt::red));
        } else {
            return QVariant(QColor(Qt::blue));
        }
    }
    return QVariant::Invalid;
}

QVariant SADModel::getTextAlignmentRole(const QModelIndex &index) const
{
    if(index.column()==0)
        return Qt::AlignCenter;
    return QVariant((Qt::AlignRight | Qt::AlignVCenter));
}

long SADModel::getInvestorColumnValue(const QModelIndex &index) const
{
    return mValues.at(index.row())->volumeSum[index.column()-3];
}

