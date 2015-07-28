#include <QFile>
#include <QMetaObject>
#include <QMetaProperty>
#include "trteststockinfoupdater.h"
TrTestStockInfoUpdater::TrTestStockInfoUpdater(QueryMngr *queryMngr, QObject *parent) : QObject(parent),mUpdater(new StockInfoUpdater(queryMngr,this))
{

}

TrTestStockInfoUpdater::~TrTestStockInfoUpdater()
{

}

void TrTestStockInfoUpdater::start()
{
    connect(mUpdater, SIGNAL(updateDone()), this, SLOT(onTestDone()));
    mUpdater->update();
}

void TrTestStockInfoUpdater::onTestDone()
{
//    QString filename = "stockupdate.txt";
//    QFile file(filename);
//    if (file.open(QIODevice::WriteOnly)) {
//        QTextStream stream(&file);
//        const QMap<QString, StockInfo*> infoMap = mUpdater->getStockInfoMap();
//        foreach(StockInfo *info , infoMap.values()) {
//            stream<<info->toString();
//        }
//    }
//    file.close();
    emit testDone();
}

