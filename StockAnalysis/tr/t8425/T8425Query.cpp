#include <QTextStream>
#include "T8425Query.h"


T8425Query::T8425Query(QObject *parent) : TrQuery(TrQuery::T8425, tr("t8425"), parent)
{

}

T8425Item * T8425Query::createItem()
{
	return new T8425Item();
}

void T8425Query::onReceiveData(const QString& trCode)
{
	TrBlockInfo* outBlockInfo = trInfo()->getOutBlock();
	int blockCnt = xaquery()->GetBlockCount(outBlockInfo->getBlockName());
	for (int i = 0; i < blockCnt; i++) {
		TrItem *item = getTrItemFromReceivedData(outBlockInfo, i);
		mResult.append(qobject_cast<T8425Item*>(item));
	}
	workDone();
	xaquery()->ClearBlockdata(outBlockInfo->getBlockName());
}

void T8425Query::onReceiveChartRealData(const QString& trCode)
{

}

T8425Query * T8425Query::createQuery(QObject *parent /*= 0*/)
{
	T8425Query *query = new T8425Query(parent);
	return query;
}

T8425Query::~T8425Query()
{
}

QString T8425Query::dummy()
{
	return tr("");
}

QString T8425Query::toString()
{
	QString desc;
	QTextStream stream(&desc);
	stream << "T8425 Result[START]" << endl;
	foreach(T8425Item* item, getResult()) {
		stream << item->toString() << endl;
	}
	stream << "T8425 Result[END]" << endl;
	return desc;
}

QList<T8425Item *> T8425Query::getResult()
{
	return mResult;
}
