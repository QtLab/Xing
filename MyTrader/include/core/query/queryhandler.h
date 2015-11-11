#ifndef QUERYHANDLER_H
#define QUERYHANDLER_H

#include <QObject>
#include <QtCore/QTimer>
#include "core/tr/t8425/T8425Query.h"
#include <QtCore/QQueue>
#include <QElapsedTimer>

class QueryHandler : public QObject
{
	Q_OBJECT

public:
	explicit QueryHandler(const QString trName, QTimer *requestTimer, QObject *parent = 0);
	~QueryHandler();

public slots:
	void start();
	void sendRequest();
	void requestQuery(TrQuery *query);
	void queryDone();
	void onScheduleNextRequest();
	void checkAndRestartTimer();

private:
	void initRequestTimer();

private:
	QTimer *mRequestTimer;
	QElapsedTimer mElapsedTimer;
	QList<TrQuery *> mQueryList;
	QQueue<TrQuery *> mSendingQueue;
	int mCurrentInterval;
	QString mTrName;
};

#endif // QUERYHANDLER_H
