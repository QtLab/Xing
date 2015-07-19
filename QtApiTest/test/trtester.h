#ifndef TRTESTER_H
#define TRTESTER_H

#include <QObject>
#include <QThread>
#include <QList>
#include <QTimer>
#include "XingLib/xasession.h"
#include "tr/trquery.h"

class TrTester : public QThread
{
    Q_OBJECT
public:
    explicit TrTester(QObject *parent = 0);
    ~TrTester();
    void addQuery(TrQuery* query);
    void startTest();

protected:
    virtual void run();

signals:
    void testOver();
public slots:
    void testDone();
    void runTest();
    void sendQuery();
    void onScheduleNextQuery();
private:
    QList<TrQuery*> mQueryList;
    QList<TrQuery*> mWaitingQueryList;
    XASession mSession;
    QTimer *mSendingTimer;
};

#endif // TRTESTER_H
