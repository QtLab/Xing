#include "T8425Item.h"

T8425Item::T8425Item(QObject *parent/*=0*/) :TrItem(parent)
{
	DEFINE_PROPERTY_NAME("테마명", "tmname");
	DEFINE_PROPERTY_NAME("테마코드", "tmcode");
}

T8425Item::~T8425Item()
{

}
