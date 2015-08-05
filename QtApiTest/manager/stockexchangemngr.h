#ifndef	 STOCKEXCHANGEMNGR_H
#define STOCKEXCHANGEMNGR_H

#include <QObject>
#include "util/xingthread.h"
#include "data/warehousehistory.h"

typedef QMap<INVESTORS, WarehouseHistory *> WarehouseHistoryMap;
class StockExchangeMngr : public QObject
{
    Q_OBJECT
public:
    explicit StockExchangeMngr(QObject *parent = 0);
    ~StockExchangeMngr();
    void requestWarehouseHistory(const QString& shcode);
signals:
    void responseWarehouseHistory(WarehouseHistoryMap historyMap);
private slots:
    void makeWarehouseHistory(const QString& shcode);
private:
    XingThread mThread;
};

#endif // MOVEMENTMNGR_H
