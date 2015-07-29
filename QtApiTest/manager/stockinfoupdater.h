#ifndef STOCKINFOUPDATER_H
#define STOCKINFOUPDATER_H

#include <QWidget>
#include <QMap>
#include <QThread>
#include <QtSql/QSqlQuery>
#include "manager/querymngr.h"
#include "tr/t8430/t8430query.h"
#include "tr/t1102/t1102query.h"
#include "data/stockinfo.h"
class StockInfoUpdater : public QObject
{
    Q_OBJECT
public:
    explicit StockInfoUpdater(QueryMngr *queryMngr,QObject *parent = 0);
    ~StockInfoUpdater();
    const QMap<QString, StockInfo *> getStockInfoMap();
signals:
    void updateDone();
public slots:
    void update();
    void t8430QueryDone();
    void t1102QueryDone();
private:
    void createTable();
    void saveToDB(StockInfo* info);
    void errorQuery(QSqlQuery* query);
private:
    QueryMngr* mQueryMngr;
    QMap<QString, StockInfo *> mStockInfoUpdatingMap;
    QMap<QString, StockInfo *> mStockInfoMap;
    QThread mThread;
};

#endif // STOCKINFOUPDATER_H
