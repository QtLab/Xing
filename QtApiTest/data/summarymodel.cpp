#include "summarymodel.h"

SummaryModel::SummaryModel(const QString &shcode,const WarehouseInfo* historyMap, QObject *parent) : QAbstractTableModel(parent), mShcode(shcode)
{
    initWarehouseData();
}

SummaryModel::~SummaryModel()
{

}

int SummaryModel::rowCount(const QModelIndex &parent) const
{
    return 3; 	//�ְ�����, ��������, �л�����
}

int SummaryModel::columnCount(const QModelIndex &parent) const
{
    return 14; 	//����, ������, �ܱ���, ���, ����ݵ�, ��������, ����, ���ڽ�Ź, ����, ���ձ���, �����, ��Ÿ����, ���ܱ���, ������
}

QVariant SummaryModel::data(const QModelIndex &index, int role) const
{
    if(role == Qt::DisplayRole) {
        return getDisplayRoleData(index);
    }
}

QVariant SummaryModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    return QVariant::Invalid;

}

QVariant SummaryModel::getDisplayRoleData(const QModelIndex &index) const
{
    INVESTORS investor = static_cast<INVESTORS>(index.column());
    switch(index.row()) {
    case 0 :
        return getPriceLeadingPercentage(investor);
    case 1:
        return getCurrentWarehousePercentage(investor);
    case 2:
        return getDistributePercentage(investor);
    }

    return QVariant::Invalid;
}

QVariant SummaryModel::getPriceLeadingPercentage(INVESTORS investor) const
{
    WarehouseHistory *history = mWarehouseMap->value(investor);
    return QVariant::Invalid;
}

QVariant SummaryModel::getCurrentWarehousePercentage(INVESTORS investor) const
{

}

QVariant SummaryModel::getDistributePercentage(INVESTORS investor) const
{

}

INVESTORS SummaryModel::getInvestorByColumnIndex(int index) const
{
    return static_cast<INVESTORS>(index);
}

void SummaryModel::initWarehouseData()
{
    for(int i = 0; i<NUM_OF_INVESTORS; i++) {
        INVESTORS investor = static_cast<INVESTORS>(i);
        WarehouseHistory *history = WarehouseHistory::createWarehouseHistory(mShcode, investor);
        mWarehouseMap.insert(investor, history);
    }

}

