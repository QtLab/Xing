#ifndef SHCODEMANAGER_H
#define SHCODEMANAGER_H

#include <QObject>
#include <QWidget>

#include "xing/xaquery.h"
#include "tr/t8430/t8430query.h"
#include "tr/t8430/t8430item.h"
#include "tr/t1102/t1102query.h"
#include "tr/t1102/t1102item.h"
#include "data/stockinfo.h"
#define USE_THREAD 0
class StockInfoMngr : public QObject
{
    Q_OBJECT
public:
    explicit StockInfoMngr(QObject *parent = 0);
    ~StockInfoMngr();
    void requestUpdate(QWidget* requester);

    QStringList getShcodeList();
    QString getStockName(const QString& shcode);
signals:
    void updateDone();

public slots:
    void init();
private slots:
    void onT8430ItemReceived(QList<T8430Item*> list);

private:
    void insertShcodeListToDB(T8430Item *item);
    void updateSt5ockInfo();
    bool connectDB();
    bool createTable();

private:
    QMap<QString, QString> mShcodeMap;
    QMap<QString, StockInfo*> mStockInfoMap;
    QList<QString> mShcodeList;
    QWidget* mRequester;
};

#endif // SHCODEMANAGER_H
