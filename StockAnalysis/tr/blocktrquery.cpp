#include "blocktrquery.h"

BlockTrQuery::BlockTrQuery(const QString &trName, QObject *parent)
	: TrQuery(trName, parent)
{

}

BlockTrQuery::~BlockTrQuery()
{
	foreach(TrItem* item, getResult()) {
		item->deleteLater();
	}
}

QString BlockTrQuery::toString()
{
    QString desc;
    QTextStream stream(&desc);
    stream<<getTrName()<<" Query Result[START]"<<endl;
    foreach(TrItem* item, getResult()) {
        stream<<item->toString()<<endl;
    }
	stream<<getTrName()<<" Query Result[END]"<<endl;
    return desc;
}

QList<TrItem *> BlockTrQuery::getResult()
{
	return mItemList;
}

void BlockTrQuery::onReceiveData(const QString& trCode)
{
    TrBlockInfo* outBlockInfo = trInfo()->getOutBlock();
    int blockCnt = xaquery()->GetBlockCount(outBlockInfo->getBlockName());
    for(int i = 0; i<blockCnt; i++) {
        TrItem* item = getTrItemFromReceivedData(outBlockInfo, i);
        mItemList.append(item);
    }
    workDone();
    xaquery()->ClearBlockdata(outBlockInfo->getBlockName());
}

void BlockTrQuery::onReceiveChartRealData(const QString& trCode)
{

}
