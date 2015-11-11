#include "ModifiedPrice.h"

ModifiedPrice::ModifiedPrice() : mRate(0.0)
{
}


ModifiedPrice::~ModifiedPrice()
{
}

long ModifiedPrice::operator()(long price)
{
	return price *(1 + mRate / 100.0);
}

long ModifiedPrice::operator()(long price, double rate)
{
	if (rate != 0.0) mRate = rate;
	return price *(1 + mRate / 100.0);
}