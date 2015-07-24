#ifndef STOCKINFOUPDATER_H
#define STOCKINFOUPDATER_H

#include <QWidget>
#include "manager/querymngr.h"
#include "tr/t8430/t8430query.h"
class StockInfoUpdater : public QWidget
{
    Q_OBJECT
public:
    explicit StockInfoUpdater(QWidget *parent = 0);
    ~StockInfoUpdater();

signals:

public slots:
    void update();
    void t8430QueryDone();
private:
    QueryMngr mQueryMngr;
};

#endif // STOCKINFOUPDATER_H
