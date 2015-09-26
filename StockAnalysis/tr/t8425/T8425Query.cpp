#include <QTextStream>
#include "T8425Query.h"


T8425Query::T8425Query(QObject *parent) : BlockTrQuery(tr("t8425"), parent)
{

}

T8425Item * T8425Query::createItem()
{
	return new T8425Item();
}

T8425Query * T8425Query::createQuery(QObject *parent /*= 0*/)
{
	T8425Query *query = new T8425Query(parent);
	return query;
}

T8425Query::~T8425Query()
{
}

QString T8425Query::dummy()
{
	return tr("");
}