#ifndef TRTESTER_H
#define TRTESTER_H

#include <QObject>
#include <QThread>
#include <QList>
#include "XingLib/xasession.h"
#include "tr/trquery.h"

class Worker : public QObject
{
    Q_OBJECT
public:
    explicit Worker(QObject * parent = 0);
    ~Worker();
private slots:
    void onTimeout();
};

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
private:
    QList<TrQuery*> mQueryList;
    QList<TrQuery*> mWaitingQueryList;
    XASession mSession;
    friend class Worker;
};

#endif // TRTESTER_H
