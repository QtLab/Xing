#include <QtSql/QSqlQuery>
#include <QtSql/QSqlRecord>
#include <QtSql/QSqlError>
#include <QDateTime>
#include "util/log.h"
#include "movementupdater.h"
#include "tr/t1702/t1702Query.h"

MovementUpdater::MovementUpdater(QueryMngr *queryMngr, QObject *parent) : QObject(parent), mQueryMngr(queryMngr), mDb(QSqlDatabase::addDatabase("QMYSQL"))

{

}

MovementUpdater::~MovementUpdater()
{

}

void MovementUpdater::update()
{
    moveToThread(&mThread);
    mThread.start();
    qCDebug(movementUpdater)<<"Update Start time"<<QDateTime::currentDateTime().toString(Qt::ISODate);
    connectDB();
    T1702Query *query = T1702Query::createQuery(tr("005930"));
    connect(query, SIGNAL(workDone()), this,SLOT(t1702QueryDone()));
    mQueryMngr->requestQuery(query);
}

void MovementUpdater::t1702QueryDone()
{
   QObject* sender = QObject::sender();
   if(sender != NULL) {
       T1702Query *query = qobject_cast<T1702Query *>(sender);
       if(query != NULL) {
          QList<T1702Item *> list = query->getResult();
          foreach(T1702Item *item, list) {
              saveToDB(item);
              item->deleteLater();
          }
          query->deleteLater();
          emit updateDone();
       }
   }
}

void MovementUpdater::connectDB()
{
    mDb.setHostName("192.168.219.250");
    mDb.setDatabaseName("XingDB");
    mDb.setUserName("seuki77");
    mDb.setPassword("folken77");
    if(mDb.isOpen())
        return;

    if(!mDb.open()) {
        qCDebug(movementUpdater)<<mDb.lastError();
        qCDebug(movementUpdater)<<"Failed to connect";
    } else {
        qCDebug(movementUpdater)<<"Connected!";
    }
}

void MovementUpdater::saveToDB(T1702Item *item)
{
    QSqlQuery qry;
    QString qryString = QString("SELECT COUNT(*) FROM Movement_%1 WHERE `date`='%2'").arg(item->shcode()).arg(item->date().toString(tr("yyyyMMdd")));
    qry.prepare(qryString);
    if(qry.exec()) {
        if(qry.next()) {
            if(qry.value(0).toInt()==0) {	//Row is not existed, So insert
                QString insertString = item->getSqlInsertStr();
                qry.prepare(insertString);
            }else {	//Row is existed, So update
                QString updateString = item->getSqlUpdateStr();
                qry.prepare(updateString);
            }
            if(!qry.exec()){
                errorQuery(&qry);
            }
        }
    }else {
        errorQuery(&qry);
    }

}

void MovementUpdater::createStockMovementTable(const QString &shcode)
{
    QSqlQuery query;
    query.prepare(tr("CREATE TABLE IF NOT EXIST Movement_%1 ( `Date` DATE UNIQUE PRIMARY KEY, `close` INTEGER(8), `sign` CHAR(1), `change` INTEGER(8), `diff` FLOAT(8), `volume` BIGINT(12), `amt0001` BIGINT(12), `amt0002` BIGINT(12), `amt0003` BIGINT(12), `amt0004` BIGINT(12), `amt0005` BIGINT(12), `amt0006` BIGINT(12), `amt0007` BIGINT(12), `amt0008` BIGINT(12), `amt0009` BIGINT(12), `amt0010` BIGINT(12), `amt0011` BIGINT(12), `amt0018` BIGINT(12), `amt0088` BIGINT(12), `amt0099` BIGINT(12)").arg(shcode));
    if(!query.exec()) {
        errorQuery(&query);
    } else {
        qCDebug(movementUpdater)<<tr("Movement_%1 table created").arg(shcode);
    }
}

void MovementUpdater::errorQuery(QSqlQuery *query)
{
    qCWarning(movementUpdater)<<"QueryError : "<<query->lastError()<<endl<<query->executedQuery();
}


