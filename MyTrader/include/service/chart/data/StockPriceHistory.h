#pragma once
#include <QList>
#include <QDate>
#include <QtCore/QMap>

class StockPriceData
{
public:
	typedef enum _DATA_TYPE {TIMESTAMP, OPEN, HIGH, LOW, CLOSE, VOLUME, NONE} DATA_TYPE;
	explicit StockPriceData(const QString& shcode, int size);
	~StockPriceData();
	bool addData(const QDateTime& date, double open, double high, double low, double close, double volume);
	bool getDataArray(double *timeStamp, double *open, double *high, double *low, double *close, double *volume) const;
	bool getDataArrayByPeriod(const QDateTime start, const QDateTime end, int numOfExtraPoints, double *timeStamp, double *open, double *high, double *low, double *close, double *volume) const;
	double* getDataArray(DATA_TYPE type) const;
	int getNumOfData();
private:
	QString mShcode;
	double *mTimeStamps;
	double *mVolData;
	double *mHighData;
	double *mLowData;
	double *mOpenData;
	double *mCloseData;
	int mNoOfPoints;
	QMap<QDateTime, int> mDateTimeMap;
};
