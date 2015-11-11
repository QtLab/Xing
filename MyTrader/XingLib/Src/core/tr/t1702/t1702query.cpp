#include <QTextStream>
#include "logger/log.h"
#include "t1702query.h"

T1702Query::T1702Query(QObject *parent) : CtsTrQuery(tr("t1702"),parent), _cts_idx(0), _cts_date("")
{

}

T1702Item *T1702Query::createItem()
{
    return new T1702Item(_shcode);
}

void T1702Query::onReceiveData(const QString& trCode)
{
	readOutBlock();
	if (this->_cts_date.compare(tr("20050719"))==0){
		qCDebug(trQuery) << "next cts_date is 20050719";
	}
	TrBlockInfo* outBlockInfo1 = trInfo()->getOutBlock1();
	int blockCnt = xaquery()->GetBlockCount(outBlockInfo1->getBlockName());
	for (int i = 0; i<blockCnt; i++) {
		TrItem* item = getTrItemFromReceivedData(outBlockInfo1, i);
		T1702Item* t1702Item = qobject_cast<T1702Item*>(item);
		QString itemDate = t1702Item->date().toString("yyyyMMdd");
		QString fromDate = this->_fromdate.toString("yyyyMMdd");
		if (t1702Item->date()>this->_fromdate) {
			mItemList.append(t1702Item);
		}
		else if (t1702Item->date() == this->_fromdate) {
			mItemList.append(t1702Item);
			emit workDone();
			xaquery()->ClearBlockdata(outBlockInfo1->getBlockName());
			return;
		}
		else {
			emit workDone();
			xaquery()->ClearBlockdata(outBlockInfo1->getBlockName());
			return;
		}
	}
	if (xaquery()->isNext()){
		setNextQuery(true);
		emit scheduleNextQuery();
	}
	else {
		emit workDone();
	}
	xaquery()->ClearBlockdata(outBlockInfo1->getBlockName());
}

T1702Query *T1702Query::createQuery(const QString &shcode, const QDate &fromdate, const QDate &todate, T1702Query::T1702_UNIT unit, T1702Query::T1702_TYPE type, T1702Query::T1702_CUMUL_TYPE cumul, QObject *parent)
{
    T1702Query *query = new T1702Query(parent);
    query->_shcode = shcode;
    query->_todt = todate;
	query->_fromdate = fromdate;
    query->_volvalgb = QString("%1").arg(unit);
    query->_msmdgb = QString("%1").arg(type);
    query->_cumulgb = QString("%1").arg(cumul);
    return query;
}

T1702Query::~T1702Query()
{

}