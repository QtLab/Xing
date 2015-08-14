#ifndef QUERYMNGR_H
#define QUERYMNGR_H

#include <QObject>
#include <QTimer>
#include <QQueue>
#include "tr/trquery.h"
#include "util/xingthread.h"
class QueryMngr : public QObject
{
    Q_OBJECT
public:
    explicit QueryMngr(QObject *parent = 0);
    ~QueryMngr();

signals:

public slots:
    void start();
    void sendRequest();
    void requestQuery(TrQuery* query);
    void queryDone();
    void onScheduleNextRequest();
    void checkAndRestartTimer();

private:
    void initRequestTimer();
private:
    XingThread mThread;
    QTimer mRequestTimer;
    QList<TrQuery*> mQueryList;
    QQueue<TrQuery*> mSendingQueue;
    int mCurrentInterval;
};
#endif // QUERYMNGR_H
