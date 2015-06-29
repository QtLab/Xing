#include "t1702query.h"

T1702Query::T1702Query(const QWidget *requester, const QString &shcode
                       , const QDate &fromdt, const QDate &todt, REQUEST_UNIT unit, REQUEST_TYPE type
                       , REQUEST_OPTION option, QObject* parent)
    : TrQuery(requester, "t1702", parent), mShcode(shcode),mFromDate(fromdt),mToDate(todt)
    ,mUnit(unit),mType(type), mOption(option)
{

}

QString T1702Query::getShcode()
{
    return mShcode;
}

QDate T1702Query::getToDate()
{
    return mToDate;
}

QDate T1702Query::getFromDate()
{
    return mFromDate;
}

T1702Query::REQUEST_UNIT T1702Query::getVolvalgb()
{
    return mUnit;
}

T1702Query::REQUEST_TYPE T1702Query::getMsmdgb()
{
    return mType;
}

T1702Query::REQUEST_OPTION T1702Query::getCumulgb()
{
    return mOption;
}

void T1702Query::addT1702Item(T1702Item *item)
{
    mResultList.append(item);
}

void T1702Query::setCtsIdx(const QString &cts_idx)
{
    m_cts_idx = cts_idx;
}

QString T1702Query::getCtsIdx()
{
    return m_cts_idx;
}

void T1702Query::setCtsDate(const QDate &cts_date)
{
    m_cts_date = cts_date;
}

QDate T1702Query::getCtsDate()
{
    return m_cts_date;
}

QList<T1702Item *> T1702Query::getResultList()
{
    return mResultList;
}

T1702Query::~T1702Query()
{

}

T1702Query *T1702Query::createQuery(const QWidget *requester, const QString &shcode, const QDate &fromdt, const QDate &todt, T1702Query::REQUEST_UNIT unit, T1702Query::REQUEST_TYPE type, T1702Query::REQUEST_OPTION option, QObject *parent)
{
    T1702Query* query = new T1702Query(requester, shcode, fromdt, todt, unit, type, option, parent);
    return query;
}

