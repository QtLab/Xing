#ifndef STOCKDATAMANAGER_H
#define STOCKDATAMANAGER_H

#include <QObject>
#include "xing/xaquery.h"
#include "tr/t1702/t1702query.h"
#include "tr/t1702/t1702item.h"
class StockDatamanager : public QObject
{
    Q_OBJECT
public:
    explicit StockDatamanager(QObject *parent=0);
    ~StockDatamanager();

    void requestUpdate(QWidget* requester);
};

#endif // STOCKDATAMANAGER_H
