#include "t1702query.h"

T1702Query::T1702Query(const QWidget &requester, const QString &shcode
                       , const QDate &todt, REQUEST_UNIT unit, REQUEST_TYPE type
                       , REQUEST_OPTION option, QObject* parent)
    : TrQuery(requester, "t1702", parent), mShcode(shcode),mToDate(todt)
    ,mUnit(unit),mType(type), mOption(option)
{

}

QString T1702Query::getShcode()
{
    return mShcode;
}

QDate T1702Query::getDate()
{
    return mToDate;
}

T1702Query::REQUEST_UNIT T1702Query::getUnit()
{
    return mUnit;
}

T1702Query::REQUEST_TYPE T1702Query::getType()
{
    return mType;
}

T1702Query::REQUEST_OPTION T1702Query::getOption()
{
    return mOption;
}

T1702Query::~T1702Query()
{

}

