#ifndef	 STOCKEXCHANGEMNGR_H
#define STOCKEXCHANGEMNGR_H

#include <QObject>
#include "core/util/xingthread.h"
#include "service/sad/warehousehistory.h"
#include "service/sad/stockexchangeinfo.h"


typedef QMap<INVESTORS, WarehouseHistory *> WarehouseInfo;
class StockExchangeMngr : public QObject
{
    Q_OBJECT
public:
    explicit StockExchangeMngr(QObject *parent = 0);
    ~StockExchangeMngr();
    void requestStockExchangeInfo(const QString& shcode);
    void requestWarehouseHistory(const QString& shcode);

private:

signals:
    void responseWarehouseHistory(WarehouseInfo* historyMap);
    void responseStockExchangeInfo(StockExchangeInfo* stockExchangeInfo);

private slots:
    void makeWarehouseHistory(const QString& shcode);
    void makeStockExchangeInfo(const QString& shcode);

private:
    XingThread mThread;
    QMap<QString, WarehouseInfo *> mWarehouseHistoryCache;
    QMap<QString, StockExchangeInfo *>mStockExchangeInfoMap;
};

#endif // MOVEMENTMNGR_H
