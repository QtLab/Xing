#include <QDebug>
#include <QThread>
#include "t8430query.h"

T8430Query::T8430Query(QObject *parent) : TrQuery(tr(TR_NAME), parent)
{

}

void T8430Query::setMode(T8430Query::MODE mode)
{
    mMode = mode;
}

T8430Query::~T8430Query()
{

}

T8430Query *T8430Query::createQuery(T8430Query::MODE mode, QObject *parent)
{
    T8430Query* query = new T8430Query(parent);
    query->setMode(mode);
    return query;
}

void T8430Query::request()
{
    qDebug()<<"request thread id = "<<QThread::currentThreadId();
    xaquery()->setFieldData(IN_BLOCK_NAME, "gubun", 0,QString::number(mMode));
    xaquery()->Request(false);
}

void T8430Query::onReceiveData(const QString &trCode)
{
    QList<T8430Item*> itemList;
    int nCount = xaquery()->GetBlockCount(OUT_BLOCK_NAME);
    for( int index = 0; index<nCount; index++){
        T8430Item *item = new T8430Item();
        foreach(QString property , item->getPropertyList()) {
            QString fieldValue = xaquery()->GetFieldData(OUT_BLOCK_NAME, property, index);
            item->setProperty(property.toLocal8Bit(), fieldValue);
        }
    }
    foreach(T8430Item* item, itemList) {

    }
}

void T8430Query::onReceiveChartRealData(const QString &trCode)
{

}

T8430Query *T8430Query::getQuery()
{
    return this;
}

