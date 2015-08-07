#ifndef SUMMARYMODEL_H
#define SUMMARYMODEL_H

#include <QObject>
#include <QAbstractTableModel>
#include "manager/stockexchangemngr.h"
class SummaryModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit SummaryModel(const QString &shcode, const WarehouseInfo *historyMap, QObject *parent = 0);
    ~SummaryModel();

    virtual int rowCount(const QModelIndex &parent = QModelIndex()) const;
    virtual int columnCount(const QModelIndex &parent=QModelIndex()) const;
    virtual QVariant data(const QModelIndex &index, int role=Qt::DisplayRole) const;
    virtual QVariant headerData(int section, Qt::Orientation orientation, int role=Qt::DisplayRole) const;

signals:

public slots:
private:
    QVariant getDisplayRoleData(const QModelIndex &index) const;
    QVariant getPriceLeadingPercentage(INVESTORS investor) const;
    INVESTORS getInvestorByColumnIndex(int index) const;
private:
    QString mShcode;
    WarehouseInfo *mWarehouseMap;
};

#endif // SUMMARYMODEL_H
