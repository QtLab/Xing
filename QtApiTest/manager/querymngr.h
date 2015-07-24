#ifndef QUERYMNGR_H
#define QUERYMNGR_H

#include <QObject>
#include <QThread>
#include <QTimer>
#include <QQueue>
#include "tr/trquery.h"
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
private:
    void initRequestTimer();
    void checkAndRestartTimer();
private:
    QThread mThread;
    QTimer mRequestTimer;
    QList<TrQuery*> mQueryList;
    QQueue<TrQuery*> mSendingQueue;
};
#endif // QUERYMNGR_H
