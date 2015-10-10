#include "t1102query.h"

T1102Query::T1102Query(QObject *parent) : SimpleTrQuery(tr("t1102"), parent)
{

}
T1102Query::~T1102Query()
{

}
T1102Item *T1102Query::createItem()
{
	return new T1102Item();
}
