#include <QDebug>
#include <QTextStream>
#include "t8430query.h"

T8430Query::T8430Query(QObject *parent) : BlockTrQuery(tr("t8430"),parent)
{

}

T8430Item *T8430Query::createItem()
{
   return new T8430Item();
}

T8430Query *T8430Query::createQuery(const QString &gubun, QObject *parent)
{
   T8430Query *query = new T8430Query(parent);
   query->setGubun(gubun);
   return query;
}

T8430Query::~T8430Query()
{

}