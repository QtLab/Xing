#include "simpletrquery.h"

SimpleTrQuery::SimpleTrQuery(const QString &trName, QObject *parent)
	: TrQuery(trName, parent)
{

}

SimpleTrQuery::~SimpleTrQuery()
{
	mResult->deleteLater();
}

TrItem * SimpleTrQuery::getResult()
{
	return mResult;
}

QString SimpleTrQuery::toString()
{
	QString desc;
    QTextStream stream(&desc);
    stream<<getTrName()<<" Query Result[START]"<<endl;
    stream<<mResult->toString()<<endl;
	stream<<getTrName()<<" Query Result[END]"<<endl;
	return desc;
}

void SimpleTrQuery::onReceiveData(const QString& trCode)
{
	TrBlockInfo* outblockInfo = trInfo()->getOutBlock();
    mResult = getTrItemFromReceivedData(outblockInfo, 0);
    emit workDone();
    xaquery()->ClearBlockdata(outblockInfo->getBlockName());
}

void SimpleTrQuery::onReceiveChartRealData(const QString& trCode)
{

}
