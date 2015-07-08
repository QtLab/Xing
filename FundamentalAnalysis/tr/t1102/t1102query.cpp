#include "t1102query.h"

T1102Query::T1102Query()
{

}

T1102Query::~T1102Query()
{

}

T1102Query *T1102Query::createQuery(const QWidget *requester, const QString &shcode, QObject *parent)
{
    HWND winId = (HWND)requester->winId();
    T1102Query* query = new T1102Query(winId, shcode, parent);
    return query;
}

T1102Query::T1102Query(HWND winId, const QString &shcode, QObject *parent):TrQuery("t1102", winId, parent), mShcode(shcode)
{

}

QString T1102Query::getShcode()
{
    return mShcode;
}


