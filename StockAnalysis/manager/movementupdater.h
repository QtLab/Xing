#ifndef MOVEMENTUPDATER_H
#define MOVEMENTUPDATER_H

#include <QObject>
#include <QtSql/QSqlQuery>
#include <QDate>
#include <QMap>
#include <QQueue>
#include <QTime>
#include "util/xingthread.h"
#include "manager/querymngr.h"
#include "manager/stockinfomngr.h"
#include "tr/t1702/t1702query.h"
class MovementUpdater : public QObject
{
    Q_OBJECT
public:
    explicit MovementUpdater(QueryMngr* queryMngr, QObject *parent = 0);
    ~MovementUpdater();

signals:
    void updateDone();
public slots:
    void update();
    void update(QList<QString> upcodeList);
    void t1702QueryDone();
    void t1516QueryDone();
private slots:
    void updateStart();
private:
    void saveToDB(T1702Item* item);
    void createStockMovementTable(const QString &shcode);
    void errorQuery(QSqlQuery *query);
    void nextRequest();
    bool requestMovementData(const QString &shcode);
    QDate getLastUpdatedDateFromDatabase(const QString & shcode);
private:
    QueryMngr* mQueryMngr;
    XingThread mThread;
    QDate sStockStartDate;
    QList<QString> mUpdatingShcodeList;
    QList<T1516Query *> mRequestedUpcodeLl
    QTime mMarketEndTime;
};

#endif // MOVEMENTUPDATER_H
