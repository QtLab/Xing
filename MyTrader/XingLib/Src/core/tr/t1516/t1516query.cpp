#include "t1516query.h"
#include <QDebug>
T1516Query::T1516Query(QObject *parent) : CtsTrQuery(tr("t1516"), parent),_upcode(tr("")), _gubun(tr(""))
{

}

T1516Item *T1516Query::createItem()
{
    return new T1516Item();
}

T1516Query::~T1516Query()
{

}

T1516Query *T1516Query::createQuery(const QString &upcode, MARKET_TYPE marketType, QObject *parent)
{
    T1516Query* query = new T1516Query(parent);
    query->setUpcode(upcode);
    if(marketType != MARKET_TYPE_NONE)
        query->setGubun(QString::number(static_cast<int>(marketType)));
    return query;
}
