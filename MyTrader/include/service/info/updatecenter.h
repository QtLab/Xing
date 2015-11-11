#ifndef UPDATECENTER_H
#define UPDATECENTER_H

#include <QObject>

class XingThread;
class StockInfoUpdater;
class QueryMngr;
class ThemeUpjongUpdater;
class UpjongCodeUpdater;
class MovementUpdater;
class UpdateCenter : public QObject
{
	Q_OBJECT

public:
	explicit UpdateCenter(QueryMngr *queryMngr, QObject *parent = 0);
	~UpdateCenter();
	void updateMovementTable();
signals:
	void updateStockInfoDone();
	void updateCodeTableDone();
	void updateMovementTableDone();	

public slots:
	void updateStockInfo();
	void updateCodeTable();
	void updateMovementTable(const QString &upcode);
private:
	QueryMngr *mQueryMngr;
	XingThread *mWorkThread;
	StockInfoUpdater *mStockInfoUpdater;
	ThemeUpjongUpdater *mThemeUpjongUpdater;
	UpjongCodeUpdater *mUpjongCodeUpdater;
	MovementUpdater *mMovementUpdater;
};

#endif // UPDATECENTER_H
