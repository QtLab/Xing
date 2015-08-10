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
                return qkor("개인");
            case 1:
                return qkor("세력합");
            case 2:
                return qkor("외국인");
            case 3:
                return qkor("기관");
            case 4:
                return qkor("사모펀드");
            case 5:
                return qkor("금융투자");
            case 6:
                return qkor("보험");
            case 7:
                return qkor("투자신탁");
            case 8:
                return qkor("은행");
            case 9:
                return qkor("종합금융");
            case 10:
                return qkor("연기금");
            case 11:
                return qkor("기타법인");
            case 12:
                return qkor("내외국인");
            case 13:
                return qkor("국가외");
            default:
                return QVariant::Invalid;
            }
        }else{
            switch(section) {
            case 0:
                return qkor("주가선도");
            case 1:
                return qkor("보유비중");
            case 2:
                return qkor("분산추이");
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

