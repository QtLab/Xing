#ifndef SADMODEL_H
#define SADMODEL_H

#include <QObject>
#include <QAbstractTableModel>
#include "service/sad/stockexchangemngr.h"

#define DAILY_ROW_SIZE 5
#define WEEKLY_ROW_SIZE 4
#define MONTHLY_ROW_SIZE 3
#define QUARTERLY_ROW_SIZE 4

//Supply and Demand Model
class SADModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit SADModel(StockExchangeInfo *stockExchangeInfo, QObject *parent = 0);
    ~SADModel();
    virtual int rowCount(const QModelIndex &parent = QModelIndex()) const;
    virtual int columnCount(const QModelIndex &parent=QModelIndex()) const;
    virtual QVariant data(const QModelIndex &index, int role=Qt::DisplayRole) const;
    virtual QVariant headerData(int section, Qt::Orientation orientation, int role=Qt::DisplayRole) const;

signals:

public slots:

private:
    void initRowCnt();
    void initData();
    QVariant getDisplayRoleData(const QModelIndex &index) const;
    QVariant getForegroundRoleData(const QModelIndex &index) const;
    QVariant getTextAlignmentRole(const QModelIndex &index) const;
    long getInvestorColumnValue(const QModelIndex &index) const;

private:
    int mRowCnt;
    StockExchangeInfo *mStockExchangeInfo;
    QList<MovingVolumeSumInfo *> mValues;
};

#endif // SADMODEL_H
