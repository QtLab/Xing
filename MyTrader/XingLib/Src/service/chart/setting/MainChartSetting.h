#pragma once
#include "service\chart\setting\chartsetting.h"
#include "service/chart/chart_common.h"

class Financechart;
class ChartInfo;

class MainChartSetting :
	public ChartSetting
{
public:
	MainChartSetting();
	~MainChartSetting();

	bool saveSettingToXml(XmlStreamWriter* xml) override;
	bool loadSettingFromXml(XmlStreamReader* xml) override;
	bool apply(FinanceChart* chart, const ChartInfo* chartInfo) override;
	void setLogScale(bool enable) { mIsLogScale = enable; }
	void setPercentageScale(bool enable) { mIsPercentageSale = enable; }
	void setChartType(MAIN_CHART_TYPE type) { mChartType = type;}
	MAIN_CHART_TYPE getChartType() const
	{ return mChartType; }
	
private:
	bool mIsLogScale;
	MAIN_CHART_TYPE mChartType;
	bool mIsPercentageSale;
	long mCandleUpColor;
	long mCandleDownColor;
	long mLineColor;
};

