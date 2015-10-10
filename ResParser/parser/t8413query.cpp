#include "t8413query.h"

T8413Query::T8413Query(QObject *parent) : CtsTrQuery(tr("t8413"), parent)
{

}
T8413Query::~T8413Query()
{

}
T8413Item *T8413Query::createItem()
{
	return new T8413Item();
}
