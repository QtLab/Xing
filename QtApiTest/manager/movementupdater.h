#ifndef MOVEMENTUPDATER_H
#define MOVEMENTUPDATER_H

#include <QObject>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QThread>
#include "manager/querymngr.h"
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
    void connectDB();
    void saveToDB(T1702Item* item);
    void createStockMovementTable(const QString &shcode);
    void errorQuery(QSqlQuery *query);
private:
    QueryMngr* mQueryMngr;
    QSqlDatabase mDb;
};

#endif // MOVEMENTUPDATER_H
