#include "xinglib.h"
#include <QtCore/QMetaType>
#include "service/chart/data/StockPriceData.h"
void initXingContext()
{
	qRegisterMetaType<StockPriceData*>("StockPriceData*");
}