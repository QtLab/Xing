#include <QTextStream>
#include "t1537query.h"

T1537Query::T1537Query(QObject *parent)
	: CtsTrQuery(tr("t1537"), parent), _tmcode(tr(""))
{

}

T1537Item * T1537Query::createItem()
{
	return new T1537Item();
}

T1537Query::~T1537Query()
{

}

T1537Query * T1537Query::createQuery(const QString &tmcode, QObject *parent /*= 0*/)
{
	T1537Query *query = new T1537Query(parent);
	query->setTmcode(tmcode);
	return query;
}