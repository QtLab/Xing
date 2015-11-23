#include <QTime>
#include "logger/log.h"
#include "ctstrquery.h"

CtsTrQuery::CtsTrQuery(const QString &trName, QObject *parent)
	: TrQuery(trName, parent), mIsCompressedBlock(false)
{

}

CtsTrQuery::~CtsTrQuery()
{
	foreach(TrItem * item, getResult()) {
		item->deleteLater();
	}
}

QString CtsTrQuery::toString()
{
	QString desc;
	QTextStream stream(&desc);
	stream << getTrName() << " Query Result[START]" << endl;
	foreach(TrItem* item, getResult()){
		stream << item->toString() << endl;
	}
	stream << getTrName() << " Query Result[END]" << endl;
	return desc;
}

QList<TrItem *> CtsTrQuery::getResult()
{
	return mItemList;
}

void CtsTrQuery::setCompressedBlock(bool isCompressed)
{
	mIsCompressedBlock = isCompressed;
}

void CtsTrQuery::readOutBlock()
{
	TrBlockInfo* outBlockInfo = trInfo()->getOutBlock();

	foreach(QString fieldName, outBlockInfo->getFieldNameList()) {
		QString value = xaquery()->GetFieldData(outBlockInfo->getBlockName(), fieldName, 0);
		TrFieldInfo* fieldInfo = outBlockInfo->getField(fieldName);
		bool result;
		switch (fieldInfo->getDataType()) {
		case TrFieldInfo::CHAR:
			result = this->setProperty(fieldName.toLocal8Bit(), value);
			break;
		case TrFieldInfo::LONG:
			result = this->setProperty(fieldName.toLocal8Bit(), value.toLong());
			break;
		case TrFieldInfo::LONGLONG:
			result = this->setProperty(fieldName.toLocal8Bit(), value.toLongLong());
			break;
		case TrFieldInfo::FLOAT:
			result = this->setProperty(fieldName.toLocal8Bit(), value.toFloat());
			break;
		case TrFieldInfo::DATE:
			result = this->setProperty(fieldName.toLocal8Bit(), QDate::fromString(value, "yyyyMMdd"));
			break;
		case TrFieldInfo::TIME:
			result = this->setProperty(fieldName.toLocal8Bit(), QTime::fromString(value, "hhmmss"));
			break;
		default:
			result = this->setProperty(fieldName.toLocal8Bit(), value);
		}
		if (!result) {
			qCWarning(trQuery) << "setProperty for " << fieldName << " failed" << endl;
		}
	}
	xaquery()->ClearBlockdata(outBlockInfo->getBlockName());
}

void CtsTrQuery::readOutBlock1()
{
	TrBlockInfo* outBlockInfo1 = trInfo()->getOutBlock1();
	if (mIsCompressedBlock)
	{
		long decompressedSize = xaquery()->Decompress(outBlockInfo1->getBlockName());
		if (decompressedSize <= 0) return;
	}
	int blockCnt = xaquery()->GetBlockCount(outBlockInfo1->getBlockName());
	for (int i = 0; i < blockCnt; i++) {
		TrItem *item = getTrItemFromReceivedData(outBlockInfo1, i);
		mItemList.append(item);
	}
	xaquery()->ClearBlockdata(outBlockInfo1->getBlockName());
}

void CtsTrQuery::onReceiveData(const QString& trCode)
{

	if (xaquery()->isNext()) {
		setNextQuery(true);
		emit scheduleNextQuery();
		readOutBlock();
		readOutBlock1();
	}
	else{
		readOutBlock();
		readOutBlock1();
		emit workDone();
	}
}

void CtsTrQuery::onReceiveChartRealData(const QString& trCode)
{

}
