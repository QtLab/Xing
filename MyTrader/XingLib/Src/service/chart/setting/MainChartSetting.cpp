#include "MainChartSetting.h"
#include "service/chart/setting/chartinfo.h"
#include "FinanceChart.h"

MainChartSetting::MainChartSetting() : ChartSetting("MainChart"), mIsLogScale(false), mChartType(CANDLE_STICK), mIsPercentageSale(false), mCandleUpColor(0xff0000), mCandleDownColor(0x0000ff), mLineColor(0x000040)
{
}


bool MainChartSetting::apply(FinanceChart* chart, const ChartInfo* chartInfo)
{
	Q_ASSERT(chart!=nullptr);
	chart->addMainChart(chartInfo->getMainChartHeight());
	chart->setLogScale(mIsLogScale);
	if (mIsPercentageSale)
		chart->setPercentageAxis();
	switch (mChartType)
	{
	case CLOSING_PRICE:
		chart->addCloseLine(mLineColor);
		break;
	case MEDIAN_PRICE:
		chart->addMedianPrice(mLineColor);
		break;
	case OHLC:
		chart->addHLOC(0x33ff33, 0xff3333);
		break;
	case TYPICAL_PRICE:
		chart->addTypicalPrice(mLineColor);
		break;
	case WEIGHTED_CLOSE: 
		chart->addWeightedClose(mLineColor);
		break;
	case CANDLE_STICK:
		chart->addCandleStick(mCandleUpColor, mCandleDownColor);
	default: break;
	}
	return true;
}

MainChartSetting::~MainChartSetting()
{
}

bool MainChartSetting::saveSettingToXml(XmlStreamWriter* xml)
{
	return true;
}

bool MainChartSetting::loadSettingFromXml(XmlStreamReader* xml)
{
	return true;
}
