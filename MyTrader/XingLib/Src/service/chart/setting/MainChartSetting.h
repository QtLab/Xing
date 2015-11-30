#ifndef MAINCHARTSETTING_H
#define MAINCHARTSETTING_H
#include <QObject>
#include "service\chart\setting\chartsetting.h"
#include "service\chart\chart_common.h"


class Financechart;
class ChartInfo;

class MainChartSetting :
	public ChartSetting
{
	Q_OBJECT
	Q_PROPERTY(bool logScale MEMBER _logScale READ logScale WRITE setLogScale)
	Q_PROPERTY(bool percentageScale MEMBER _percentageScale READ percentageScale WRITE setPercentageScale)
	Q_PROPERTY(long candleUpColor MEMBER _candleUpColor READ candleUpColor WRITE setCandleUpColor)
	Q_PROPERTY(long candleDnColor MEMBER _candleDnColor READ candleDnColor WRITE setCandleDnColor)
	Q_PROPERTY(long lineColor MEMBER _lineColor READ lineColor WRITE setLineColor)
public:
	explicit MainChartSetting(QObject *parent=0);
	~MainChartSetting();

	bool saveSettingToXml(QXmlStreamWriter* xml) override;
	bool loadSettingFromXml(QXmlStreamReader* xml) override;
	bool apply(FinanceChart* chart, const ChartInfo* chartInfo) override;

	void setLogScale(bool enable) { _logScale = enable; }
	bool logScale() const
	{ return _logScale; }
	
	void setPercentageScale(bool enable) { _percentageScale = enable; }
	bool percentageScale() const { return _percentageScale; }

	void setCandleUpColor(long color) { _candleUpColor = color; }
	long candleUpColor() const { return _candleUpColor; }

	void setCandleDnColor(long color) { _candleDnColor = color; }
	long candleDnColor() const { return _candleDnColor; }

	void setLineColor(long color) { _lineColor = color; }
	long lineColor() const { return _lineColor; }

	void setChartType(MAIN_CHART_TYPE type) { mChartType = type;}
	MAIN_CHART_TYPE getChartType() const
	{ return mChartType; }
	
private:
	bool _logScale;
	MAIN_CHART_TYPE mChartType;
	bool _percentageScale;
	long _candleUpColor;
	long _candleDnColor;
	long _lineColor;
};
#endif
