#include "t8430query.h"

T8430Query *T8430Query::createQuery(const QWidget &requester, T8430Query::MODE mode, QObject *parent)
{
    T8430Query* query = new T8430Query(requester, parent);
    query->mMode = mode;
    return query;
}

T8430Query::T8430Query(const QWidget &requester, QObject *parent) : TrQuery(requester,"t8430", parent)
{

}

T8430Query::~T8430Query()
{

}
