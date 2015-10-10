#include "t8424query.h"

T8424Query::T8424Query(QObject *parent) : BlockTrQuery(tr("t8424"), parent)
{

}
T8424Query::~T8424Query()
{

}
T8424Item *T8424Query::createItem()
{
	return new T8424Item();
}
