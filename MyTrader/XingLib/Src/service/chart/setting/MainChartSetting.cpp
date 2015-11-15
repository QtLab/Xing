#include "MainChartSetting.h"
#include "service/chart/setting/chartinfo.h"
#include "FinanceChart.h"
#include <QtCore/qglobal.h>

MainChartSetting::MainChartSetting(QObject *parent) : ChartSetting("MainChart", parent), _logScale(false), mChartType(CANDLE_STICK), _percentageScale(false), _candleUpColor(0xff0000), _candleDnColor(0x0000ff), _lineColor(0x000040)
{
}


bool MainChartSetting::apply(FinanceChart* chart, const ChartInfo* chartInfo)
{
	Q_ASSERT(chart!=nullptr);
	chart->addMainChart(chartInfo->getMainChartHeight());
	chart->setLogScale(_logScale);
	if (_percentageScale)
		chart->setPercentageAxis();
	switch (mChartType)
	{
	case CLOSING_PRICE:
		chart->addCloseLine(_lineColor);
		break;
	case MEDIAN_PRICE:
		chart->addMedianPrice(_lineColor);
		break;
	case OHLC:
		chart->addHLOC(0x33ff33, 0xff3333);
		break;
	case TYPICAL_PRICE:
		chart->addTypicalPrice(_lineColor);
		break;
	case WEIGHTED_CLOSE: 
		chart->addWeightedClose(_lineColor);
		break;
	case CANDLE_STICK:
		chart->addCandleStick(_candleUpColor, _candleDnColor);
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
