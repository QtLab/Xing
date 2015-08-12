#ifndef STOCKINFOUPDATER_H
#define STOCKINFOUPDATER_H

#include <QWidget>
#include <QMap>
#include <QtSql/QSqlQuery>
#include <QDate>
#include "manager/querymngr.h"
#include "tr/t8430/t8430query.h"
#include "tr/t1102/t1102query.h"
#include "data/stockinfo.h"
#include "util/xingthread.h"
class StockInfoUpdater : public QObject
{
    Q_OBJECT
public:
    explicit StockInfoUpdater(QueryMngr *queryMngr,QObject *parent = 0);
    ~StockInfoUpdater();
signals:
    void updateDone();
public slots:
    void update();
    void t8430QueryDone();
    void t1102QueryDone();
private:
    void createTable();
    void saveToDB(StockInfo *info);
    void errorQuery(QSqlQuery *query);
    bool checkCondition(StockInfo *info);
private:
    QueryMngr* mQueryMngr;
    QMap<QString, StockInfo *> mStockInfoUpdatingMap;
    XingThread mThread;
    const QDate ZeroDate;
};

#endif // STOCKINFOUPDATER_H
