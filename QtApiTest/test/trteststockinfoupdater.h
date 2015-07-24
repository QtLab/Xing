#ifndef TRTESTSTOCKINFOUPDATER_H
#define TRTESTSTOCKINFOUPDATER_H

#include <QObject>
#include <QTextStream>
#include "manager/querymngr.h"
#include "manager/stockinfoupdater.h"
class TrTestStockInfoUpdater : public QObject
{
    Q_OBJECT
public:
    explicit TrTestStockInfoUpdater(QueryMngr* queryMngr, QObject *parent = 0);
    ~TrTestStockInfoUpdater();
    void start();
signals:
    void testDone(int code);
public slots:
    void onTestDone();
private:
private:
    StockInfoUpdater* mUpdater;

};

#endif // TRTESTSTOCKINFOUPDATER_H
