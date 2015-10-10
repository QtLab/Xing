#include "StockPriceHistory.h"

StockPriceHistory::StockPriceHistory(const QString& shcode) : mShcode(shcode)
{
}

StockPriceHistory::~StockPriceHistory()
{
	foreach(StockPrice * price, mStockPriceList)
	{
		delete price;
	}
}

void StockPriceHistory::appendPrice(StockPrice* price)
{
	mStockPriceList.append(price);
}

void StockPriceHistory::prependPrice(StockPrice* price)
{
	mStockPriceList.prepend(price);
}

StockPriceHistory::const_iterator StockPriceHistory::cbegin() const
{
	return mStockPriceList.cbegin();
}

StockPriceHistory::const_iterator StockPriceHistory::cend() const
{
	return mStockPriceList.cend();
}