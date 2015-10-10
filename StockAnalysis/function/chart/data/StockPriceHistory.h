#pragma once
#include <QList>
#include <QDate>
typedef struct _StockPrice{
	QDate date;
	int open;					//시가
	int high;						//고가
	int low;						//저가
	int close;					//종가
	long volume;				//거래량
}StockPrice;
class StockPriceHistory
{
public:
	typedef QList<StockPrice*>::const_iterator const_iterator;
	StockPriceHistory(const QString &shcode);
	~StockPriceHistory();
	void appendPrice(StockPrice* price);
	void prependPrice(StockPrice* price);
	const_iterator cbegin() const;
	const_iterator cend() const;
	QString getShcode() { return mShcode; }
private:
	QList<StockPrice*> mStockPriceList;
	QString mShcode;
};

