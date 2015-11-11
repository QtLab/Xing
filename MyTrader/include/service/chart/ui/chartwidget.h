#ifndef CHARTWIDGET_H
#define CHARTWIDGET_H

#include <QWidget>
#include <QDateTime>
#include "service/chart/data/StockPriceData.h"

#define MAX_INDICATOR_HEIGHT 100
class QButtonGroup;
class LineLayer;
class XYChart;
class FinanceChart;
class StockInfoMngr;
namespace Ui { class ChartWidget; };

class QComboBox;
class QCheckBox;
class QLineEdit;
class QChartViewer;
class ShcodeSelectionDialog;
class QueryMngr;
class StockChartDataManager;
typedef enum { CANDLE_STICK, CLOSING_PRICE, MEDIAN_PRICE, OHLC, TYPICAL_PRICE, WEIGHTED_CLOSE } MAIN_CHART_TYPE;
typedef enum { NONE, BOLLINGER_BAND, DONCHAIN_CHANNEL, ENVELOP } CHANNEL_TYPE;
typedef enum
{
	ACCUM_DISTRIBUTION = 0
	, AROON_OSCILLATOR
	, AROON
	, AVG_DIRECTIONAL_INDEX
	, AVG_TRUE_RANGE
	, BOLLINGER_BAND_WIDTH
	, CHAIKIN_MONEY_FLOW
	, CHAIKIN_OSCILLATOR
	, CHAIKIN_VOLATILITY
	, CLOSE_LOCATION_VALUE
	, COMMONDITY_CHANNEL_INDEX
	, DETRENDED_PRICE_OSC
	, DONCHIAN_CHANNEL_WIDTH
	, EASE_OF_MOVEMENT
	, FAST_STOCHASTIC
	, MACD
	, MASS_INDEX
	, MOMENTUM
	, MONEY_FLOW_INDEX
	, NEG_VOLUME_INDEX
	, ON_BALANCE_VOLUME
	, PERFORMANCE
	, PERCENTAGE_PRICE_OSCILLATOR
	, PERCENTAGE_VOLUME_OSCILLATOR
	, POS_VOLUME_INDEX
	, PRICE_VOLUME_TREND
	, RATE_OF_CHANGE
	, RSI
	, SLOW_STOCHASTIC
	, STOCH_RSI
	, TRIX
	, ULTIMATE_OSCILLATOR
	, VOLUME
	, WILLIAMS_R
	, PARABOLIC_SAR
	, NUM_OF_INDICATOR
} INDICATOR_INDEX;

typedef enum {
	MARKET_BREADTH_INDICATOR,
	TREND_INDICATOR,
	VOLATILITY_INDICATOR,
	MOMENTUM_INDICATOR, 
	ETC
} INDICATOR_TYPE;
typedef struct _Indicator {
	QString name;
	QString desc;
	INDICATOR_INDEX index;
	INDICATOR_TYPE type;
} Indicator;

class ChartWidget : public QWidget
{
	Q_OBJECT

public:
	ChartWidget(QueryMngr *queryMngr, QWidget *parent = 0);
	~ChartWidget();
	public slots:
	void onStockPriceDataReceived(StockPriceData* stockData);
	void onViewPortChanged() const;
	private slots:
	void on_shcodeSearchBtn_clicked();
	void onChartClicked(QMouseEvent *);
	void onChartSettingChanged();
	void onMainChartTypeChanged(int id, bool checked);
	void onChannelTypeChanged(int id, bool checked);
protected:
	virtual void resizeEvent(QResizeEvent * event) override;
private:
	void initUI();
	void setChartRange(double* timeStamp, int timeStampLen) const;
	void initMainChartSelectionUI();
	void initChannelSelectionUI();
	void initIndicatorSelectionUI();
	void drawFullChart(double *timestamp, double *open, double *high, double *low, double *close, double *volume, int numOfData) const;
	void drawChart() const;
	void updatePeriod();
	int getChartWidth() const;
	int getViewPortWidth() const;
	int getViewPortHeight() const;
	int getMainChartHeight() const;
	int getIndicatorHeight() const;
	int getExtraPoints() const;
	static XYChart* addIndicator(FinanceChart *m, QString indicator, int height);
	LineLayer *addMovingAvg(FinanceChart *m, QString avgType, int avgPeriod, int color);
private:
	Ui::ChartWidget *ui;
	QButtonGroup *mMainChartType;
	QButtonGroup *mChannelType;
	int mNoOfPoints;
	int mNumOfIndicators;
	int mResizeOffset;
	QDateTime mStartDate;
	QDateTime mEndDate;

	ShcodeSelectionDialog *mShcodeDlg;
	QueryMngr *mQueryMngr;
	StockChartDataManager *mStockManager;
	QString mShcode;
	StockPriceData *mPriceData;
	StockInfoMngr *mStockInfoMngr;

};

#endif // CHARTWIDGET_H
