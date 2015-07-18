#ifndef TRTESTER_H
#define TRTESTER_H

#include <QObject>
#include <QThread>
#include <QList>
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

signals:
    void testOver();
public slots:
    void testDone();
    void runTest();
private:
    QList<TrQuery*> mQueryList;
    XASession mSession;
};

#endif // TRTESTER_H
