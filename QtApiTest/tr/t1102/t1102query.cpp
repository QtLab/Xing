#include <QDebug>
#include "t1102query.h"


T1102Query::T1102Query(QObject *parent) : TrQuery(tr("t1102"), parent)
{

}

T1102Item *T1102Query::createItem()
{
    return new T1102Item();
}

void T1102Query::onReceiveData(const QString &trCode)
{
    TrItem* item = getTrItemFromReceivedData(0);
    emit queryDone(qobject_cast<T1102Item*>(item));
}

void T1102Query::onReceiveChartRealData(const QString &trCode)
{

}

T1102Query *T1102Query::createQuery(const QString &shcode, QObject *parent)
{
    T1102Query *query = new T1102Query(parent);
    query->setShcode(shcode);
    return query;
}

T1102Query::~T1102Query()
{
}

void T1102Query::setShcode(const QString &shcode)
{
    _shcode = shcode;
}

QString T1102Query::shcode()
{
    return _shcode;
}

QString T1102Query::toString()
{
    return tr("T1102Query");
}

