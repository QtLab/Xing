#ifndef STOCKINFOUPDATER_H
#define STOCKINFOUPDATER_H

#include <QWidget>
#include <QMap>
#include <QtSql/QSqlQuery>
#include <QDate>
#include "manager/querymngr.h"
#include "tr/t8430/t8430query.h"
#include "tr/t1102/t1102query.h"
#include "tr/t1516/t1516query.h"
#include "data/stockinfo.h"
#include "util/xingthread.h"
class StockInfoUpdater : public QObject
{
    Q_OBJECT
public:
    explicit StockInfoUpdater(QueryMngr *queryMngr,QObject *parent = 0);
    ~StockInfoUpdater();
signals:
    void updateStockInfoDone();
    void updateUpjongCodeDone();
public slots:
    void updateStockInfo();
    void updateUpjongCode();
    void t8424QueryDone();
    void t8430QueryDone();
    void t1102QueryDone();
    void t1516QueryDone();
private:
    void createStockInfoTable();
    void createUpjongCodeTable();
    void createUpjongTable(const QString &upcode);
    void requestShcodeListByUpjongCode(const QString &upcode);
    void saveStockInfoToDB(StockInfo *info);
    void saveUpjongCodeToDB(const QString &upcode, const QString &hname);
    void saveUpjongInfoToDB(const QString &upcode, const QString &shcode, const QString &hname);
    void errorQuery(QSqlQuery *query);
    bool checkCondition(StockInfo *info);
private:
    QueryMngr* mQueryMngr;
    QMap<QString, StockInfo *> mStockInfoUpdatingMap;
    XingThread mThread;
    QList<T1516Query *> mT1516RequestedList;
    const QDate ZeroDate;
};

#endif // STOCKINFOUPDATER_H
