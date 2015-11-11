#include "queryhandler.h"
#include "logger/log.h"
QueryHandler::QueryHandler(const QString trName, QTimer* requestTimer, QObject* parent) :mRequestTimer(requestTimer), mCurrentInterval(1000), mTrName(trName), QObject(parent)
{
}

QueryHandler::~QueryHandler()
{
	mRequestTimer->deleteLater();
}

void QueryHandler::start()
{
	initRequestTimer();
}

void QueryHandler::sendRequest()
{
	if (!mSendingQueue.isEmpty()) {
		if (mCurrentInterval<3000){
			mCurrentInterval += 300;
		}
		mRequestTimer->setInterval(mCurrentInterval);
		TrQuery *query = mSendingQueue.dequeue();
		query->request();
		mElapsedTimer.restart();
	}
	else if (mRequestTimer->isActive()) {
		mRequestTimer->stop();
		mCurrentInterval = 1000;
		qCDebug(queryMngr) << "Sending Queue for "<<mTrName<<" is empty, so stop Request Timer";
	}
}

void QueryHandler::requestQuery(TrQuery* query)
{
	qCDebug(queryMngr) << query->getTrName() << " is requested" << endl;
	mQueryList.append(query);
	mSendingQueue.append(query);
	connect(query, SIGNAL(workDone()), this, SLOT(queryDone()));
	connect(query, SIGNAL(scheduleNextQuery()), this, SLOT(onScheduleNextRequest()));
	QMetaObject::invokeMethod(this, "checkAndRestartTimer", Qt::QueuedConnection);
}

void QueryHandler::queryDone()
{
	QObject* sender = QObject::sender();
	if (sender != NULL) {
		TrQuery* query = qobject_cast<TrQuery *>(sender);
		qCDebug(queryMngr) << "query for " << query->getTrName() << " is done" << endl;
		if (mQueryList.contains(query)) {
			mQueryList.removeOne(query);
		}
		else {
			qCWarning(queryMngr) << "mQueryList doesn't contain sender - " << qPrintable(sender->objectName());
		}
	}
	else {
		qCWarning(queryMngr) << "sender is NULL";
	}
}

void QueryHandler::onScheduleNextRequest()
{
	QObject* sender = QObject::sender();
	if (sender != NULL) {
		TrQuery* query = qobject_cast<TrQuery*>(sender);
		if (mQueryList.contains(query)) {
			mSendingQueue.enqueue(query);
			checkAndRestartTimer();
		}
		else {
			qCDebug(queryMngr) << "sender is not contained in mQueryList";
		}
	}
	else {
		qCDebug(queryMngr) << "sender is NULL";
	}
}

void QueryHandler::checkAndRestartTimer()
{
	if (!mRequestTimer->isActive()) {
		qint64 elapsedTime = mElapsedTimer.elapsed();
		if (elapsedTime>=1000)
		{
			mRequestTimer->start();
		}
		else {
			mRequestTimer->start(1000-elapsedTime);
		}
		qCDebug(queryMngr) << "mRequestTimer for "<<mTrName<<" is restarted";
	}
}

void QueryHandler::initRequestTimer()
{
	connect(mRequestTimer, SIGNAL(timeout()), this, SLOT(sendRequest()));
	QMetaObject::invokeMethod(mRequestTimer, "start", Qt::QueuedConnection, Q_ARG(int, mCurrentInterval));
	mElapsedTimer.start();
}