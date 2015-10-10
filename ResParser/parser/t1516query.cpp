#include "t1516query.h"

T1516Query::T1516Query(QObject *parent) : CtsTrQuery(tr("t1516"), parent)
{

}
T1516Query::~T1516Query()
{

}
T1516Item *T1516Query::createItem()
{
	return new T1516Item();
}
