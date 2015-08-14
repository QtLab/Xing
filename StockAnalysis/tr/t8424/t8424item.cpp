#include "t8424item.h"

T8424Item::T8424Item(QObject *parent) : TrItem(parent)
{
    DEFINE_PROPERTY_NAME("업종명","hname");
    DEFINE_PROPERTY_NAME("업종코드", "upcode");
}

T8424Item::~T8424Item()
{

}

