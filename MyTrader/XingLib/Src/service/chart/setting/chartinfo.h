#pragma once
class ChartInfo
{
public:
	ChartInfo();
	virtual ~ChartInfo();
	virtual int getChartWidth() const = 0;
	virtual int getViewPortWidth() const = 0;
	virtual int getViewPortHeight() const = 0;
	virtual int getMainChartHeight() const = 0;
	virtual int getIndicatorHeight() const = 0;
};

