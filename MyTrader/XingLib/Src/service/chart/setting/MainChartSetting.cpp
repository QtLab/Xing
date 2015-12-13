#include "MainChartSetting.h"
#include "service/chart/setting/chartinfo.h"
#include "FinanceChart.h"
#include "common/util/enum_util.h"
#include <QtCore/qglobal.h>
#include <QtCore/QVariant>

#define LOG_SCALE_ATTRIBUTE "logScale"
#define PERCENTAGE_ATTRIBUTE "percentageScale"
#define UP_COLOR_ATTRIBUTE "upColor"
#define DN_COLOR_ATTRIBUTE "downColor"
#define LINE_COLOR_ATTRIBUTE "lineColor"

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

bool MainChartSetting::saveSettingToXml(QXmlStreamWriter* xml)
{
	xml->writeStartElement(enumToString<CHART_SETTING_TYPE>(MAIN_CHART));
	xml->writeAttribute(LOG_SCALE_ATTRIBUTE, QVariant(_logScale).toString());
	xml->writeAttribute(PERCENTAGE_ATTRIBUTE, QVariant(_percentageScale).toString());
	xml->writeStartElement(enumToString<MAIN_CHART_TYPE>(mChartType));
	switch (mChartType)
	{
	case CANDLE_STICK:
		xml->writeAttribute(UP_COLOR_ATTRIBUTE, QVariant(_candleUpColor).toString());
		xml->writeAttribute(DN_COLOR_ATTRIBUTE, QVariant(_candleDnColor).toString());
		xml->writeEndElement();
			break;
	case CLOSING_PRICE:	
	case MEDIAN_PRICE: 
	case OHLC:
	case TYPICAL_PRICE:
	case WEIGHTED_CLOSE: 
		xml->writeAttribute(LINE_COLOR_ATTRIBUTE, QVariant(_lineColor).toString());
		xml->writeEndElement();
		break;
	default: break;
	}
	xml->writeEndElement();
	return true;
}

bool MainChartSetting::loadSettingFromXml(QXmlStreamReader* xml)
{
	Q_ASSERT(xml->name() == enumToString<CHART_SETTING_TYPE>(MAIN_CHART));
	auto attributes = xml->attributes();
	_logScale = QVariant(attributes.value(LOG_SCALE_ATTRIBUTE).toString()).toBool();
	_percentageScale = QVariant(attributes.value(PERCENTAGE_ATTRIBUTE).toString()).toBool();
	QString chartType = xml->readNextStartElement();
	switch (stringToEnum<MAIN_CHART_TYPE>(chartType))
	{
	case CANDLE_STICK:
		auto candleAttributes = xml->attributes();
		_candleUpColor = candleAttributes.value(UP_COLOR_ATTRIBUTE).toString().toInt();
		_candleDnColor = candleAttributes.value(DN_COLOR_ATTRIBUTE).toString().toInt();
		break;
	case CLOSING_PRICE:
		case 
	}
	return true;
}
