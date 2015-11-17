#ifndef STOCKPRICEDATA_H
#define STOCKPRICEDATA_H

#include <QDate>
#include <QtCore/QMap>
#include <QObject>

class StockPriceData
{

public:
	StockPriceData();
	StockPriceData(const StockPriceData& data);
	StockPriceData(const QString& shcode, int size);
	StockPriceData& operator=(const StockPriceData& data);
	~StockPriceData();
	bool addData(const QDateTime& date, double open, double high, double low, double close, double volume);
	bool getDataPtr(double **timeStamp, double **open, double **high, double **low, double **close, double **volume) const;

	double* getTimeStampDataPtr() const { return mTimeStamps; }
	double* getOpenDataPtr() const { return mOpenData; }
	double* getHighDataPtr() const { return mHighData; }
	double* getLowDataPtr() const { return mLowData; }
	double* getCloseDataPtr() const { return mCloseData; }
	double* getVolDataPtr() const { return mVolData; }

	int getDataPtrByPeriod(const QDateTime start, const QDateTime end, int numOfExtraPoints, double **timeStamp, double **open, double **high, double **low, double **close, double **volume) const;
	int getNumOfData() const;
private:
	void init(const StockPriceData& data);
private:
	QString mShcode;
	double *mTimeStamps;
	double *mVolData;
	double *mHighData;
	double *mLowData;
	double *mOpenData;
	double *mCloseData;
	int mSize;
	QDateTime mStartTime;
	QDateTime mEndTime;
	QHash<QDateTime, int> mDateTimeMap;
	int mNumOfPoints;

};
Q_DECLARE_METATYPE(StockPriceData*);
#endif 