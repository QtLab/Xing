#ifndef STOCKINFOMNGR_H
#define STOCKINFOMNGR_H

#include <QObject>
#include <QThread>
#include <QList>
#include "data/stockinfo.h"
#include "tr/trquery.h"
class StockInfoMngr : public QThread
{
    Q_OBJECT
public:
    explicit StockInfoMngr(QObject *parent = 0);
    ~StockInfoMngr();
    QList<StockInfo *> getStockInfoList();
public slots:
    void update();
    void onReceiveMsg(const QString& msg);
signals:
    void onUpdated();
    void notifyMsg(const QString& msg);
private:
    void trRequest(TrQuery* query);

    QList<TrQuery*> mQueryList;
};

#endif // STOCKINFOMNGR_H
