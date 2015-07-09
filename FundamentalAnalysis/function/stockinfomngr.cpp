#include "stockinfomngr.h"
#include <QFuture>
#include <QFutureWatcher>
#include <QtConcurrent/QtConcurrent>
#include <QThread>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlRecord>
#include <QtSql/QSqlError>

StockInfoMngr::StockInfoMngr(QObject *parent) : QObject(parent)
{

}

StockInfoMngr::~StockInfoMngr()
{

}

void StockInfoMngr::requestUpdate(QWidget *requester)
{
    T8430Query* query = T8430Query::createQuery(requester, T8430Query::ALL);
    connect(query, &T8430Query::workDone,this,&StockInfoMngr::onT8430ItemReceived);
    XAQueryMngr::getInstance()->requestQuery(query);
    mRequester = requester;
}

void StockInfoMngr::init()
{

    qDebug()<<"ShcodeManager::init executed in "<<QThread::currentThreadId();
    if(connectDB()){
        QSqlQuery query;
        query.prepare("SELECT shcode, hname FROM shcodeTable");
        if(query.exec()){
            while(query.next()){
                mShcodeMap.insert(query.value("shcode").toString(), query.value("hname").toString());
            }
        } else {
            qDebug() << query.executedQuery();
            qDebug()<<query.lastError();
        }
    }
}

QStringList StockInfoMngr::getShcodeList()
{
    return mShcodeMap.keys();
}

QString StockInfoMngr::getStockName(const QString &shcode)
{
    if(!mShcodeMap.contains(shcode))
    {
        qDebug()<<"getStockName - not found : "<<shcode;
        return "Not Found";
    }
    return mShcodeMap.value(shcode);
}

void StockInfoMngr::onT8430ItemReceived(QList<T8430Item *> list)
{
    if(createTable()) {
#if USE_THREAD 1
        QFutureWatcher<void> watcher;
        QFuture<void> future;
        connect(&watcher, SIGNAL(finished()), this, SLOT(shcodelistUpdateFinished()));
        future = QtConcurrent::map(list, insertShcodeListToDB);
        watcher.setFuture(future);
        watcher.waitForFinished();
#else
        qDebug()<<"onT8430ItemReceived - "<<QThread::currentThreadId();
        foreach(T8430Item* item, list) {
            //insertShcodeListToDB(item);
            StockInfo* info = new StockInfo();
            info->setHname(item->hname());
            info->setShcode(item->shcode());
            info->setExpcode(item->expcode());
            info->setETF(item->isETF());
            info->setKOSPI(item->isKOSPI());
            mStockInfoMap.insert(info->shcode(), info);
            mShcodeList.push_back(info->shcode());
        }

        //emit updateDone();
        qDebug()<<"insertShcodeListToDB finished";
#endif
    }
}
void StockInfoMngr::insertShcodeListToDB(T8430Item *item){
    QSqlQuery qry;
    QString qryString = QString("SELECT COUNT(*) FROM shcodeTable WHERE shcode = '%1'").arg(item->shcode());

    qry.prepare(qryString);
    if(qry.exec()){
        if(qry.next()){
            if(qry.value(0).toInt()==0) {
                QString insertString = QString("INSERT INTO shcodeTable (shcode, hname, market) VALUES ('%1', '%2', '%3')").arg(item->shcode()).arg(item->hname()).arg(item->isKOSPI()?"KOSPI":"KOSDAQ");
                qry.prepare(insertString);
                qry.exec();
            }
        }
    }else {
        qDebug()<<"hname="<<item->hname()<<", shcode="<<item->shcode();
        qDebug() << qry.executedQuery();
        qDebug()<<qry.lastError();
    }
    mShcodeMap.insert(item->shcode(), item->hname());
    item->deleteLater();
    return;
}

void StockInfoMngr::updateStockInfo()
{

}

bool StockInfoMngr::connectDB()
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

bool StockInfoMngr::createTable()
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

