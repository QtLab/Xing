#ifndef STOCKCHARTDATAMANAGER_H
#define STOCKCHARTDATAMANAGER_H

#include <QObject>
#include <QMap>
#include "core/tr/t8413/t8413query.h"
#include "service/chart/data/StockPriceData.h"
#include "core/query/querymngr.h"
class XingThread;
class StockChartDataManager : public QObject
{
	Q_OBJECT

public:
	typedef enum {DAILY, WEEKLY, MONTHLY} TIME_UNIT;
	explicit StockChartDataManager(QueryMngr* queryMngr, QObject *parent =0);
	~StockChartDataManager();
	void start();
signals:
	void responseStockData(StockPriceData *history);
public slots:
	void requestStockData(const QString &shcode, TIME_UNIT timeUnit, const QDate &startDate, const QDate &endDate, bool modified_price);
	void requestStockData(const QString &shcode, TIME_UNIT timeUnit, bool modified_price);
	void onReceivedStockData();
private:
	XingThread* mWorkThread;
	QueryMngr* mQueryMngr;
	QMap<T8413Query *, bool> mQueryMap;
	QMap<QString, StockPriceData *> mStockPriceDataCacheMap;
};

#endif // STOCKCHARTDATAMANAGER_H
