#ifndef QUERYMNGR_H
#define QUERYMNGR_H

#include <QObject>
#include <QTimer>
#include <QQueue>
#include "tr/trquery.h"
#include "util/xingthread.h"
#include "function/query/queryhandler.h"
class QueryMngr : public QObject
{
    Q_OBJECT
public:
    explicit QueryMngr(QObject *parent = 0);
    ~QueryMngr();

signals:

public slots:
    void start();
	void requestQuery(TrQuery* query);

private:
    void initRequestTimer();
	void addQueryToQueryHandler(TrQuery* query);
private:
    XingThread mThread;
	QMap<QString, QueryHandler*> mQueryHandlerMap;
};
#endif // QUERYMNGR_H
