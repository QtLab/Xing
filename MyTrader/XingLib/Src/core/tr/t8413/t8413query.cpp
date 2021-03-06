#include "t8413query.h"

T8413Query::T8413Query(QObject *parent) : CtsTrQuery(tr("t8413"), parent)
{

}


T8413Query* T8413Query::createQuery(const QString& shcode, const QString& gubun, long qrycnt, const QDate& sDate, const QDate& eDate, bool comp_yn, QObject* parent)
{
	T8413Query *query = new T8413Query(parent);
	query->setShcode(shcode);
	query->setGubun(gubun);
	query->setQrycnt(qrycnt);
	query->setSdate(sDate);
	query->setEdate(eDate);
	query->setComp_Yn(comp_yn ? "Y" : "N");
	query->setCompressedBlock(comp_yn);
	return query;
}

T8413Query::~T8413Query()
{

}
T8413Item *T8413Query::createItem()
{
	return new T8413Item();
}

void T8413Query::readOutBlock1()
{
	TrBlockInfo* outBlockInfo1 = trInfo()->getOutBlock1();
	if (mIsCompressedBlock)
	{
		long decompressedSize = xaquery()->Decompress(outBlockInfo1->getBlockName());
		if (decompressedSize <= 0) return;
	}
	int blockCnt = xaquery()->GetBlockCount(outBlockInfo1->getBlockName());
	for (int i = 0; i<blockCnt; i++) {
		TrItem *item = getTrItemFromReceivedData(outBlockInfo1, i);
		mItemList.insert(i, item);
	}
	
	xaquery()->ClearBlockdata(outBlockInfo1->getBlockName());
}