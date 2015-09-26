#ifndef MOVEMENTUPDATER_H
#define MOVEMENTUPDATER_H

#include <QObject>
#include <QtSql/QSqlQuery>
#include <QDate>
#include <QMap>
#include <QQueue>
#include <QTime>
#include "manager/querymngr.h"
#include "manager/stockinfomngr.h"
#include "tr/t1702/t1702query.h"
#include "tr/t1516/t1516query.h"
class MovementUpdater : public QObject
{
    Q_OBJECT
public:
    explicit MovementUpdater(QueryMngr* queryMngr, QObject *parent = 0);
    ~MovementUpdater();

signals:
    void updateDone();
public slots:
	void updateByShcode(const QString &shcode);
    void updateByShcodeList(QList<QString> shcodeList);
    void updateByUpcode(const QString &upcode);
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
    QDate getLastUpdatedDateFromDatabase(const QString &shcode);
    QDate getFirstUpdatedDateFromDatabase(const QString &shcode);
private:
    QueryMngr* mQueryMngr;
    QDate sStockStartDate;
    QList<QString> mUpdatingShcodeList;
    QList<T1516Query *> mRequestedUpcodeList;
    QTime mMarketEndTime;
    int totalNumOfShcode;
};

#endif // MOVEMENTUPDATER_H
