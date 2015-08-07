#include "summarymodel.h"

SummaryModel::SummaryModel(const QString &shcode,const WarehouseInfo* historyMap, QObject *parent) : QAbstractTableModel(parent), mShcode(shcode)
{

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
    return QVariant::Invalid;
}

QVariant SummaryModel::getPriceLeadingPercentage(INVESTORS investor) const
{
    WarehouseHistory *history = mWarehouseMap->value(investor);
    return QVariant::Invalid;
}

INVESTORS SummaryModel::getInvestorByColumnIndex(int index) const
{
    return static_cast<INVESTORS>(index);
}

