#include "summarymodel.h"
#include "util/xingutil.h"

SummaryModel::SummaryModel(const QString &shcode , StockExchangeInfo *stockExchangeInfo, QObject *parent) : QAbstractTableModel(parent), mShcode(shcode),mStockExchangeInfo(stockExchangeInfo)
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
    if(role == Qt::DisplayRole){
        if(orientation = Qt::Horizontal) {
            switch(section) {
            case 0:
                qkor()
            }
        }
    }
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
    return mStockExchangeInfo->getPriceLeadingPercentage(investor);
}

QVariant SummaryModel::getCurrentWarehousePercentage(INVESTORS investor) const
{
    return mStockExchangeInfo->getCurrentWarehousePercentage(investor);
}

QVariant SummaryModel::getDistributePercentage(INVESTORS investor) const
{
    return mStockExchangeInfo->getDistributePercentage(investor);
}

INVESTORS SummaryModel::getInvestorByColumnIndex(int index) const
{
    return static_cast<INVESTORS>(index);
}

