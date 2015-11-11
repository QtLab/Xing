#include <QDebug>
#include <QMetaObject>
#include <QThread>
#include "logger/log.h"
#include "querymngr.h"
QueryMngr::QueryMngr(QObject *parent) : QObject(parent)
{

}

QueryMngr::~QueryMngr()
{
	QMap<QString, QueryHandler*>::const_iterator it;
	for (it = mQueryHandlerMap.constBegin(); it != mQueryHandlerMap.constEnd(); it++)
	{
		QueryHandler* handler = it.value();
		handler->deleteLater();
	}
}

void QueryMngr::start()
{
    moveToThread(&mThread);
    mThread.start();
}

void QueryMngr::addQueryToQueryHandler(TrQuery* query)
{
	QueryHandler *queryHandler;
	QString trName = query->getTrName();
	if (!mQueryHandlerMap.contains(trName))
	{
		QTimer *timer = new QTimer();
		timer->moveToThread(&mThread);
		queryHandler = new QueryHandler(trName, timer);
		queryHandler->moveToThread(&mThread);
		queryHandler->start();
		mQueryHandlerMap.insert(trName, queryHandler);
	} 
	else
	{
		queryHandler = mQueryHandlerMap.value(query->getTrName());
	}
	query->moveToThread(&mThread);
	queryHandler->requestQuery(query);
}

void QueryMngr::requestQuery(TrQuery *query)
{
    qCDebug(queryMngr)<<query->getTrName()<<" is requested"<<endl;
	addQueryToQueryHandler(query);
}

