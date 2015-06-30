#include "shcodelistupdater.h"
#include <QFuture>
#include <QFutureWatcher>
#include <QtConcurrent/QtConcurrent>
#include <QThread>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlRecord>
#include <QtSql/QSqlError>

void insertShcodeListToDB(T8430Item *item){
    QSqlQuery qry;
    QString qryString = QString("SELECT COUNT(*) FROM shcodeTable WHERE shcode = '%1'").arg(item->shcode());

    qry.prepare(qryString);
    if(qry.exec()){
        if(qry.next()){
            if(qry.value(0).toInt()==0) {
                QString insertString = QString("INSERT INTO shcodeTable (shcode, hname, market) VALUES ('%1', '%2', '%3')").arg(item->shcode()).arg(item->hname()).arg(item->isKOSPI()?"KOSPI":"KOSDAQ");
                qry.prepare(insertString);
                qry.exec();
                qDebug()<<"success";
            }
        }
    }else {
        qDebug()<<"hname="<<item->hname()<<", shcode="<<item->shcode();
        qDebug() << qry.executedQuery();
        qDebug()<<qry.lastError();
    }
    return;
}
ShcodeListUpdater::ShcodeListUpdater(QObject *parent) : QObject(parent)
{

}

ShcodeListUpdater::~ShcodeListUpdater()
{

}

void ShcodeListUpdater::updateShcodeList(QWidget *requester, XAQueryMngr* queryMngr)
{
    T8430Query* query = T8430Query::createQuery(requester, T8430Query::ALL);
    connect(query, &T8430Query::workDone,this,&ShcodeListUpdater::onT8430ItemReceived);
    queryMngr->requestQuery(query);
}

void ShcodeListUpdater::onT8430ItemReceived(QList<T8430Item *> list)
{
    if(connectDB()&&createTable()) {
#if USE_THREAD 1
        QFutureWatcher<void> watcher;
        QFuture<void> future;
        connect(&watcher, SIGNAL(finished()), this, SLOT(shcodelistUpdateFinished()));
        future = QtConcurrent::map(list, insertShcodeListToDB);
        watcher.setFuture(future);
        watcher.waitForFinished();
#else
        foreach(T8430Item* item, list) {
            insertShcodeListToDB(item);
        }
#endif
    }
}

void ShcodeListUpdater::shcodelistUpdateFinished()
{
    emit shcodeListUpdated();
}

bool ShcodeListUpdater::connectDB()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");

    db.setHostName("192.168.219.250");
    db.setDatabaseName("XingDB");
    db.setUserName("seuki77");
    db.setPassword("folken77");

    if(!db.open()){
        qDebug()<<db.lastError();
        qFatal("Failed to connect");
        return false;
    } else {
        qDebug("Connected!");
        return true;
    }
}

bool ShcodeListUpdater::createTable()
{
    QSqlQuery query;
    query.prepare("CREATE TABLE IF NOT EXISTS shcodeTable (shcode CHAR(6) UNIQUE PRIMARY KEY, hname VARCHAR(30), market VARCHAR(6))");
    if(!query.exec()) {
        qDebug()<< query.lastError();
        return false;
    } else {
        qDebug()<< "shcodeTable is created";
        return true;
    }
}

