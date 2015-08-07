#include "summarymodel.h"

SummaryModel::SummaryModel(const QString &shcode,const WarehouseInfo* historyMap, QObject *parent) : QAbstractTableModel(parent), mShcode(shcode)
{

}

SummaryModel::~SummaryModel()
{

}

int SummaryModel::rowCount(const QModelIndex &parent) const
{
    return 3; 	//주가선도, 보유비중, 분산추이
}

int SummaryModel::columnCount(const QModelIndex &parent) const
{
    return 14; 	//개인, 세력합, 외국인, 기관, 사모펀드, 금융투자, 보험, 투자신탁, 은행, 종합금융, 연기금, 기타법인, 내외국인, 국가외
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

