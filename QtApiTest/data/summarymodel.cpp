#include "summarymodel.h"
#include "util/xingutil.h"

SummaryModel::SummaryModel(StockExchangeInfo *stockExchangeInfo, QObject *parent) : QAbstractTableModel(parent), mStockExchangeInfo(stockExchangeInfo)
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
    }else {
        return QVariant::Invalid;
    }

}

QVariant SummaryModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role == Qt::DisplayRole){
        if(orientation == Qt::Horizontal) {
            switch(section) {
            case 0:
                return qkor("����");
            case 1:
                return qkor("������");
            case 2:
                return qkor("�ܱ���");
            case 3:
                return qkor("���");
            case 4:
                return qkor("����ݵ�");
            case 5:
                return qkor("��������");
            case 6:
                return qkor("����");
            case 7:
                return qkor("���ڽ�Ź");
            case 8:
                return qkor("����");
            case 9:
                return qkor("���ձ���");
            case 10:
                return qkor("�����");
            case 11:
                return qkor("��Ÿ����");
            case 12:
                return qkor("���ܱ���");
            case 13:
                return qkor("������");
            default:
                return QVariant::Invalid;
            }
        }else{
            switch(section) {
            case 0:
                return qkor("�ְ�����");
            case 1:
                return qkor("��������");
            case 2:
                return qkor("�л�����");
            default:
                return QVariant::Invalid;
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
        return (int)(getPriceLeadingPercentage(investor)*100.0);
    case 1:
        return (int)(getCurrentWarehousePercentage(investor)*100.0);
    case 2:
        return (int)(getDistributePercentage(investor)*100.0);
    }

    return QVariant::Invalid;
}

float SummaryModel::getPriceLeadingPercentage(INVESTORS investor) const
{
    float percentage = mStockExchangeInfo->getPriceLeadingPercentage(investor);
    return percentage;
}

float SummaryModel::getCurrentWarehousePercentage(INVESTORS investor) const
{
    float percentage =  mStockExchangeInfo->getCurrentWarehousePercentage(investor);
    return percentage;
}

float SummaryModel::getDistributePercentage(INVESTORS investor) const
{
    float percentage =  mStockExchangeInfo->getDistributePercentage(investor);
    return percentage;
}

INVESTORS SummaryModel::getInvestorByColumnIndex(int index) const
{
    return static_cast<INVESTORS>(index);
}

