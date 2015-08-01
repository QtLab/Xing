#ifndef MOVEMENTUPDATER_H
#define MOVEMENTUPDATER_H

#include <QObject>
#include <QtSql/QSqlQuery>
#include <QDate>
#include "util/xingthread.h"
#include "manager/querymngr.h"
#include "manager/stockinfomngr.h"
#include "tr/t1702/t1702Item.h"
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
    void t1702QueryDone();
private:
    void saveToDB(T1702Item* item);
    void createStockMovementTable(const QString &shcode);
    void errorQuery(QSqlQuery *query);
    void requestMovementData(const QString &shcode);
    QDate getLastUpdatedDateFromDatabase(const QString & shcode);
private:
    QueryMngr* mQueryMngr;
    XingThread mThread;
    QDate sStockStartDate;
};

#endif // MOVEMENTUPDATER_H
