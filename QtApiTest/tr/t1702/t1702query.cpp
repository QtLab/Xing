#include "t1702query.h"

T1702Query::T1702Query(QObject *parent) : QObject(parent), _cts_idx(0), _cts_date("")
{

}

T1702Item *T1702Query::createItem()
{
    return new T1702Item();
}

void T1702Query::onReceiveData(const QString &trCode)
{

}

void T1702Query::onReceiveChartRealData(const QString &trCode)
{

}

T1702Query *T1702Query::createQuery(const QString &shcode, const QDate &fromdate, const QDate &todate, T1702Query::T1702_UNIT unit, T1702Query::T1702_TYPE type, T1702Query::T1702_CUMUL_TYPE cumul, QObject *parent)
{
    T1702Query *query = new T1702Query(parent);
    query->_shcode = shcode;
    query->_fromdate = fromdate;
    query->_todt = todate;
    query->_volvaldgb = QString("%d").arg(unit);
    query->_msmdgb = QString("%d").arg(type);
    query->_cumulgb = QString("%d").arg(cumul);
    return query;
}

T1702Query::~T1702Query()
{

}

QString T1702Query::toString()
{
    return tr("T1702Query");
}

