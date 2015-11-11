#include <QDebug>
#include <QTextStream>
#include "t1102query.h"

T1102Query::T1102Query(QObject *parent) : SimpleTrQuery(tr("t1102"), parent)
{

}

T1102Item *T1102Query::createItem()
{
    return new T1102Item();
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
