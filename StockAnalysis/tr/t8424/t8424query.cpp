#include "t8424query.h"

T8424Query::T8424Query(QObject *parent) : BlockTrQuery(tr("t8424"), parent)
{

}

T8424Item *T8424Query::createItem()
{
    return new T8424Item();
}

T8424Query::~T8424Query()
{

}

T8424Query *T8424Query::createQuery(MARKET_TYPE upType, QObject *parent)
{
    T8424Query *query = new T8424Query(parent);
    query->setGubun(QString::number(static_cast<int>(upType)));
    return query;
}