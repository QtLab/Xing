#include "StockPriceData.h"
#include "service/chart/util/ui_common_util.h"
#include "logger/log.h"

StockPriceData::StockPriceData() :
mShcode(""),
mTimeStamps(nullptr),
mVolData(nullptr),
mHighData(nullptr),
mLowData(nullptr),
mOpenData(nullptr),
mCloseData(nullptr),
mSize(0),
mNumOfPoints(0)

{
}

StockPriceData::StockPriceData(const StockPriceData& data)
{
	init(data);
}

StockPriceData::StockPriceData(const QString& shcode, int size) : mShcode(shcode)
, mTimeStamps(new double[size])
, mVolData(new double[size])
, mHighData(new double[size])
, mLowData(new double[size])
, mOpenData(new double[size])
, mCloseData(new double[size])
, mSize(size)
, mNumOfPoints(size-1)
{
}

StockPriceData& StockPriceData::operator=(const StockPriceData& data)
{
	if (mTimeStamps != nullptr)
	{
		delete mTimeStamps;
		delete mVolData;
		delete mHighData;
		delete mLowData;
		delete mOpenData;
		delete mCloseData;
	}
	init(data);
	return *this;
}

StockPriceData::~StockPriceData()
{
	delete mTimeStamps;
	delete mVolData;
	delete mHighData;
	delete mLowData;
	delete mOpenData;
	delete mCloseData;
}

bool StockPriceData::addData(const QDateTime& dateTime, double open, double high, double low, double close, double volume)
{
	if (mNumOfPoints <0)
	{
		qCWarning(stockChart) << "add more data than size";
		return false;
	}
	if (mNumOfPoints == mSize-1)
	{
		mStartTime= dateTime;
	}
	else if (mNumOfPoints == 0)
	{
		mEndTime= dateTime;
	}
	auto timeStamp = QDateTimeToChartTime(dateTime);
	memcpy((mTimeStamps + mNumOfPoints), &timeStamp, sizeof(double));
	memcpy((mOpenData + mNumOfPoints), &open, sizeof(double));
	memcpy((mHighData + mNumOfPoints), &high, sizeof(double));
	memcpy((mLowData + mNumOfPoints), &low, sizeof(double));
	memcpy((mCloseData + mNumOfPoints), &close, sizeof(double));
	memcpy((mVolData + mNumOfPoints), &volume, sizeof(double));
	mDateTimeMap.insert(dateTime, mNumOfPoints);
	mNumOfPoints--;
	return true;
}

bool StockPriceData::getDataPtr(double** timeStamp, double** open, double** high, double** low, double** close, double** volume) const
{
	if (mDateTimeMap.size() != mSize)
	{
		qCWarning(stockChart) << "data size is less than allocated size, " << mDateTimeMap.size() << "/" << mSize;
		return false;
	}
	if (timeStamp != nullptr)
		*timeStamp = mTimeStamps;
	if (open != nullptr)
		*open = mOpenData;
	if (high != nullptr)
		*high = mHighData;
	if (low != nullptr)
		*low = mLowData;
	if (close != nullptr)
		*close = mCloseData;
	if (volume != nullptr)
		*volume = mVolData;
	return true;
}

int StockPriceData::getDataPtrByPeriod(const QDateTime start, const QDateTime end, int numOfExtraPoints, double** timeStamp, double** open, double** high, double** low, double** close, double** volume) const
{
	QDateTime startTime = start;
	QDateTime endTime = end;
	if (startTime < mStartTime)
	{
		qCWarning(stockChart) << "requested start date is invalid - " << startTime.toString(Qt::ISODate) << ", start date of data is " << mStartTime.toString(Qt::ISODate);
		return -1;
	}
	else if (startTime >= endTime)
	{
		qCWarning(stockChart) << "start date is bigger than end date - start(" << startTime.toString(Qt::ISODate) << "), end(" << endTime.toString(Qt::ISODate) << ")";
		return -1;
	}
	while (!mDateTimeMap.contains(startTime) && (startTime < mEndTime))
	{
		startTime = startTime.addDays(1);
	}
	if (startTime >= mEndTime)
	{
		qCWarning(stockChart) << "requested start date is invalid - " << start.toString(Qt::ISODate) << ", start date of data is " << mStartTime.toString(Qt::ISODate);
		return -1;
	}
	while (!mDateTimeMap.contains(endTime) && (endTime > mStartTime))
	{
		endTime = endTime.addDays(-1);
	}
	if (endTime <= mStartTime)
	{
		qCWarning(stockChart) << "requested end date is invalid - " << end.toString(Qt::ISODate) << ", end date of data is " << mEndTime.toString(Qt::ISODate);
		return -1;
	}
	auto startIndex = mDateTimeMap.value(startTime);
	auto endIndex = mDateTimeMap.value(endTime);
	if (startIndex - numOfExtraPoints < 0)
	{
		qCWarning(stockChart) << "requested extra points " << numOfExtraPoints << " is out of range";
		return -1;
	}
	startIndex = startIndex - numOfExtraPoints;
	auto numOfPoints = endIndex - startIndex + 1;
	*timeStamp = (mTimeStamps + startIndex);
	*open = (mOpenData + startIndex);
	*high = (mHighData + startIndex);
	*low = (mLowData + startIndex);
	*close = (mCloseData + startIndex);
	*volume = (mVolData + startIndex);
	return numOfPoints;
}

int StockPriceData::getNumOfData() const
{
	return mSize;
}

void StockPriceData::init(const StockPriceData& data)
{
	mShcode = data.mShcode;
	mSize = data.mSize;
	mTimeStamps = new double[mSize];
	memcpy(mTimeStamps, data.mTimeStamps, sizeof(double) * mSize);
	mVolData = new double[mSize];
	memcpy(mVolData, data.mVolData, sizeof(double) * mSize);
	mHighData = new double[mSize];
	memcpy(mHighData, data.mHighData, sizeof(double) * mSize);
	mLowData = new double[mSize];
	memcpy(mLowData, data.mLowData, sizeof(double) * mSize);
	mOpenData = new double[mSize];
	memcpy(mOpenData, data.mOpenData, sizeof(double) * mSize);
	mCloseData = new double[mSize];
	memcpy(mCloseData, data.mCloseData, sizeof(double) * mSize);
}

