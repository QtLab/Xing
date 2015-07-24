#ifndef STOCKINFOUPDATER_H
#define STOCKINFOUPDATER_H

#include <QWidget>
#include <QMap>
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
    QueryMngr* mQueryMngr;
    QMap<QString, StockInfo *> mStockInfoMap;
    QMap<QString, StockInfo *> mStockInfoUpdatingMap;
};

#endif // STOCKINFOUPDATER_H
