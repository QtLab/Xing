#include "MainChartSetting.h"
#include "service/chart/setting/chartinfo.h"
#include "FinanceChart.h"
#include <QtCore/qglobal.h>
#include <QtCore/QVariant>

#define START_ELEMENT "MainChart"
#define LOG_SCALE_ATTRIBUTE "logScale"
#define PERCENTAGE_ATTRIBUTE "percentageScale"
#define UP_COLOR_ATTRIBUTE "upColor"
#define DN_COLOR_ATTRIBUTE "downColor"
#define LINE_COLOR_ATTRIBUTE "lineColor"
#define CANDLE_ELEMENT "Candle"
#define CLOSING_PRICE_ELEMENT "ClosingPrice"
#define MEDIAN_PRICE_ELEMENT "MedianPrice"
#define OHLC_ELEMENT "OHLC"
#define TYPICAL_PRICE_ELEMENT "TypicalPrice" 
#define WEIGHTED_CLOSE_ELEMENT "WeightedClose"

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
	xml->writeStartElement(START_ELEMENT);
	xml->writeAttribute(LOG_SCALE_ATTRIBUTE, QVariant(_logScale).toString());
	xml->writeAttribute(PERCENTAGE_ATTRIBUTE, QVariant(_percentageScale).toString());
	switch (mChartType)
	{
	case CANDLE_STICK:
		xml->writeStartElement(CANDLE_ELEMENT);
		xml->writeAttribute(UP_COLOR_ATTRIBUTE, QVariant(_candleUpColor).toString());
		xml->writeAttribute(DN_COLOR_ATTRIBUTE, QVariant(_candleDnColor).toString());
		xml->writeEndElement();
			break;
	case CLOSING_PRICE:
		xml->writeStartElement(CLOSING_PRICE_ELEMENT);
		xml->writeAttribute(LINE_COLOR_ATTRIBUTE, QVariant(_lineColor).toString());
		xml->writeEndElement();
		break;
	case MEDIAN_PRICE: 
		xml->writeStartElement(MEDIAN_PRICE_ELEMENT);
		xml->writeAttribute(LINE_COLOR_ATTRIBUTE, QVariant(_lineColor).toString());
		xml->writeEndElement();
		break;
	case OHLC:
		xml->writeStartElement(OHLC_ELEMENT);
		xml->writeAttribute(LINE_COLOR_ATTRIBUTE, QVariant(_lineColor).toString());
		xml->writeEndElement();
	case TYPICAL_PRICE:
		xml->writeStartElement(TYPICAL_PRICE_ELEMENT);
		xml->writeAttribute(LINE_COLOR_ATTRIBUTE, QVariant(_lineColor).toString());
		xml->writeEndElement();
		break;
	case WEIGHTED_CLOSE: 
		xml->writeStartElement(WEIGHTED_CLOSE_ELEMENT);
		xml->writeAttribute(LINE_COLOR_ATTRIBUTE, QVariant(_lineColor).toString());
		xml->writeEndElement();
		break;
	default: break;
	}
	return true;
}

bool MainChartSetting::loadSettingFromXml(QXmlStreamReader* xml)
{
	return true;
}
