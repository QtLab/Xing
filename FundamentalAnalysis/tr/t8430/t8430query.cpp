#include "t8430query.h"

T8430Query *T8430Query::createQuery(const QWidget *requester, T8430Query::MODE mode, QObject *parent)
{
    HWND winId = (HWND)requester->winId();
    T8430Query* query = new T8430Query(winId, parent);
    query->mMode = mode;
    return query;
}

T8430Query::T8430Query(HWND winId, QObject *parent) : TrQuery("t8430", winId, parent)
{

}

T8430Query::~T8430Query()
{

}
