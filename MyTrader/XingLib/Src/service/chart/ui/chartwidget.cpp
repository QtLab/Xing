#include "chartwidget.h"
#include "ui_chartwidget.h"
#include <QResizeEvent>
#include <QRadioButton>
#include <QTreeWidget>
#include <QDialog>
#include "common/ui/shcodeselectiondialog.h"
#include "service/chart/stockchartdatamanager.h"
#include "FinanceChart.h"
#include "service/info/stockinfomngr.h"
#include "hotspotdialog.h"
#include "core/util/xingutil.h"
#include "service/chart/setting/MainChartSetting.h"
#include "service/chart/setting/accdistsetting.h"
static Indicator sIndicatorTable[] = {
	{ "AccDist", "Accumulation/Distribution", ACCUM_DISTRIBUTION, MARKET_BREADTH_INDICATOR },
	{ "AroonOsc", "Aroon Oscillator", AROON_OSCILLATOR, TREND_INDICATOR },
	{ "Aroon", "Aroon Up/Down", AROON, TREND_INDICATOR },
	{ "ADX", "Avg Directional Index", AVG_DIRECTIONAL_INDEX, TREND_INDICATOR },
	{ "ATR", "Avg True Range", AVG_TRUE_RANGE, VOLATILITY_INDICATOR },
	{ "BBW", "Bollinger Band Width", BOLLINGER_BAND_WIDTH, VOLATILITY_INDICATOR },
	{ "CMF", "Chaikin Money Flow", CHAIKIN_MONEY_FLOW, MARKET_BREADTH_INDICATOR },
	{ "COscillator", "Chaikin Oscillator", CHAIKIN_OSCILLATOR, MOMENTUM_INDICATOR },
	{ "CVolatility", "Chaikin Volatility", CHAIKIN_VOLATILITY, VOLATILITY_INDICATOR },
	{ "CLV", "Close Location Value", CLOSE_LOCATION_VALUE, ETC },
	{ "CCI", "Commodity Channel Index", COMMONDITY_CHANNEL_INDEX, MOMENTUM_INDICATOR },
	{ "DPO", "Detrended Price Osc", DETRENDED_PRICE_OSC, MOMENTUM_INDICATOR },
	{ "DCW", "Donchian Channel Width", DONCHIAN_CHANNEL_WIDTH, TREND_INDICATOR },
	{ "EMV", "Ease of Movement", EASE_OF_MOVEMENT, MOMENTUM_INDICATOR },
	{ "FStoch", "Fast Stochastic", FAST_STOCHASTIC, MOMENTUM_INDICATOR },
	{ "MACD", "MACD", MACD, MOMENTUM_INDICATOR },
	{ "MDX", "Mass Index", MASS_INDEX, MOMENTUM_INDICATOR },
	{ "Memontum", "Momentum", MOMENTUM, MOMENTUM_INDICATOR },
	{ "MFI", "Money Flow Index", MONEY_FLOW_INDEX, MARKET_BREADTH_INDICATOR },
	{ "NVI", "Neg Volume Index", NEG_VOLUME_INDEX, MARKET_BREADTH_INDICATOR },
	{ "OBV", "On Balance Volume", ON_BALANCE_VOLUME, MARKET_BREADTH_INDICATOR },
	{ "Performance", "Performance", PERFORMANCE, VOLATILITY_INDICATOR },
	{ "PPO", "% Price Oscillator", PERCENTAGE_PRICE_OSCILLATOR, MOMENTUM_INDICATOR },
	{ "PVO", "% Volume Osicillator", PERCENTAGE_VOLUME_OSCILLATOR, MOMENTUM_INDICATOR },
	{ "PVI", "Pos Volume Index", POS_VOLUME_INDEX, MARKET_BREADTH_INDICATOR },
	{ "PVT", "Price Volume Trend", PRICE_VOLUME_TREND, MARKET_BREADTH_INDICATOR },
	{ "ROC", "Rate of Change", RATE_OF_CHANGE, MOMENTUM_INDICATOR },
	{ "RSI", "RSI", RSI, MOMENTUM_INDICATOR },
	{ "SStoch", "Slow Stochastic", SLOW_STOCHASTIC, MOMENTUM_INDICATOR },
	{ "StochRSI", "StochRSI", STOCH_RSI, MOMENTUM_INDICATOR },
	{ "TRIX", "TRIX", TRIX, TREND_INDICATOR },
	{ "UO", "Ultimate Oscillator", ULTIMATE_OSCILLATOR, MOMENTUM_INDICATOR },
	{ "Vol", "Volume", VOLUME, ETC },
	{ "WilliamR", "Willam's %R", WILLIAMS_R, MOMENTUM_INDICATOR }
};

ChartWidget::ChartWidget(QueryMngr *queryMngr, QWidget *parent)
	: QWidget(parent), ChartInfo()
	, mNoOfPoints(0)
	, mNumOfIndicators(0)
	, mStartDate(QDateTime::currentDateTime())
	, mEndDate(QDateTime::currentDateTime())
	, mShcodeDlg(new ShcodeSelectionDialog(queryMngr, this))
	, mQueryMngr(queryMngr)
	, mStockManager(new StockChartDataManager(queryMngr))
	, mShcode("005930")
	, mPriceData(nullptr)
	, mStockInfoMngr(StockInfoMngr::getInstance())
{
	mMainChartSetting = new MainChartSetting();
	initUI();
	//updatePeriod();
	mStockManager->start();
	connect(mStockManager, SIGNAL(responseStockData(StockPriceData*)), this, SLOT(onStockPriceDataReceived(StockPriceData*)));
	connect(ui->chartViewer, SIGNAL(clicked(QMouseEvent*)), this, SLOT(onChartClicked(QMouseEvent*)));
	connect(ui->chartViewer, SIGNAL(viewPortChanged()), this, SLOT(onViewPortChanged()));
}

ChartWidget::~ChartWidget()
{
	mStockManager->deleteLater();
	foreach(ChartSetting* setting, mChartSettings.values())
	{
		delete setting;
	}
	delete mMainChartSetting;
	delete mPriceData;
	delete ui->chartViewer->getChart();
	delete ui->viewPortControl->getChart();
	delete ui;
}

void ChartWidget::on_shcodeSearchBtn_clicked()
{
	if (mShcodeDlg->exec() == QDialog::Accepted)
	{
		QString shcode = mShcodeDlg->getSelectedShcode();
		mShcode = shcode;
		mStockManager->requestStockData(mShcode, StockChartDataManager::DAILY, true);
	}
}

void ChartWidget::onStockPriceDataReceived(StockPriceData* stockData)
{
	if (mPriceData != nullptr)
	{
		delete mPriceData;
	}
	mPriceData = stockData;
	setChartRange(mPriceData->getTimeStampDataPtr(), mPriceData->getNumOfData());
	ui->chartViewer->updateViewPort(true, true);
	ui->viewPortControl->setViewer(ui->chartViewer);
}

void ChartWidget::onChartClicked(QMouseEvent*)
{
	QChartViewer *viewer = (QChartViewer *)QObject::sender();
	ImageMapHandler *handler = viewer->getImageMapHandler();
	if (0 != handler)
	{
		// Query the ImageMapHandler to see if the mouse is on a clickable hot spot. We
		// consider the hot spot as clickable if its href ("path") parameter is not empty.
		const char *path = handler->getValue("path");
		if ((0 != path) && (0 != *path))
		{
			// In this sample code, we just show all hot spot parameters.
			HotSpotDialog hs;
			hs.setData(handler);
			hs.exec();
		}
	}
}

void ChartWidget::onMainChartTypeChanged(int id, bool checked) const
{
	if (checked)
	{
		mMainChartSetting->setChartType(static_cast<MAIN_CHART_TYPE>(id));
		ui->chartViewer->updateViewPort(true, true);
	}
}

void ChartWidget::onChannelTypeChanged(int id, bool checked) const
{
	if (checked)
	{
		
		ui->chartViewer->updateViewPort(true, true);
	}
}

void ChartWidget::onIndicatorAdded(QTreeWidgetItem* item, int column)
{
	auto type = item->type() - QTreeWidgetItem::UserType;
	addIndicator(static_cast<INDICATOR_TYPE>(type));
	ui->chartViewer->updateViewPort(true, true);
	mNumOfIndicators++;
}

void ChartWidget::resizeEvent(QResizeEvent* event)
{
	QWidget::resizeEvent(event);

	QSize old = event->oldSize();
	QSize current = event->size();

	if (mPriceData != nullptr)
	{
		ui->chartViewer->updateViewPort(true, true);

	}
}

void ChartWidget::initUI()
{
	ui = new Ui::ChartWidget();
	ui->setupUi(this);

	initMainChartSelectionUI();
	initChannelSelectionUI();
	initIndicatorSelectionUI();
}

void ChartWidget::setChartRange(double* timeStamp, int timeStampLen) const
{
	ui->chartViewer->setFullRange("x", *timeStamp, *(timeStamp + timeStampLen - 1));
	ui->chartViewer->setViewPortWidth(0.05);
	ui->chartViewer->setViewPortLeft(1 - ui->chartViewer->getViewPortWidth());
	ui->chartViewer->setZoomInWidthLimit(10.0 / timeStampLen);
	ui->chartViewer->setMouseWheelZoomRatio(1.1);
}

void ChartWidget::initMainChartSelectionUI()
{
	QVBoxLayout *layout = new QVBoxLayout(ui->mChartType);
	QRadioButton *candleStick = new QRadioButton(tr("CandleStick"));
	QRadioButton *closePrice = new QRadioButton(tr("Closing Price"));
	QRadioButton *medianPrice = new QRadioButton(tr("Median Price"));
	QRadioButton *ohlc = new QRadioButton(tr("OHLC"));
	QRadioButton *typicalPrice = new QRadioButton(tr("Typical Price"));
	QRadioButton *weightedClose = new QRadioButton(tr("Weighted Close"));
	layout->addWidget(candleStick);
	layout->addWidget(closePrice);
	layout->addWidget(medianPrice);
	layout->addWidget(ohlc);
	layout->addWidget(typicalPrice);
	layout->addWidget(weightedClose);

	mMainChartType = new QButtonGroup(layout);
	mMainChartType->addButton(candleStick, CANDLE_STICK);
	mMainChartType->addButton(closePrice, CLOSING_PRICE);
	mMainChartType->addButton(medianPrice, MEDIAN_PRICE);
	mMainChartType->addButton(ohlc, OHLC);
	mMainChartType->addButton(typicalPrice, TYPICAL_PRICE);
	mMainChartType->addButton(weightedClose, WEIGHTED_CLOSE);
	
	switch (mMainChartSetting->getChartType())
	{
	case CANDLE_STICK:	
		candleStick->setChecked(true);
		break;
	case CLOSING_PRICE: 
		closePrice->setChecked(true);
		break;
	case MEDIAN_PRICE: 
		medianPrice->setChecked(true);
		break;
	case OHLC:
		ohlc->setChecked(true);
		break;
	case TYPICAL_PRICE:
		typicalPrice->setChecked(true);
		break;
	case WEIGHTED_CLOSE: 
		weightedClose->setChecked(true);
		break;
	default: break;
	}
	connect(mMainChartType, SIGNAL(buttonToggled(int, bool)), SLOT(onMainChartTypeChanged(int, bool)));
}

void ChartWidget::initChannelSelectionUI()
{
	QVBoxLayout *layout = new QVBoxLayout(ui->mChannelType);
	QRadioButton *none = new QRadioButton(tr("None"));
	QRadioButton *bb = new QRadioButton(tr("Bollinger Band"));
	QRadioButton *dc = new QRadioButton(tr("Donchain Channel"));
	QRadioButton *env = new QRadioButton(tr("Envelop"));
	layout->addWidget(none);
	layout->addWidget(bb);
	layout->addWidget(dc);
	layout->addWidget(env);

	mChannelType = new QButtonGroup(layout);
	mChannelType->addButton(none, NONE);
	mChannelType->addButton(bb, BOLLINGER_BAND);
	mChannelType->addButton(dc, DONCHAIN_CHANNEL);
	mChannelType->addButton(env, ENVELOP);

	connect(mChannelType, SIGNAL(buttonToggled(int, bool)), SLOT(onChannelTypeChanged(int, bool)));
}

void ChartWidget::initIndicatorSelectionUI() const
{
	QTreeWidget *treeWidget = new QTreeWidget(ui->mIndicatorType);
	QTreeWidgetItem *marketBreadthIndicator = new QTreeWidgetItem(treeWidget);
	marketBreadthIndicator->setText(0, qkor("시장강도"));
	QTreeWidgetItem *trendIndicator = new QTreeWidgetItem(treeWidget);
	trendIndicator->setText(0, qkor("추세"));
	QTreeWidgetItem *momentumIndicator = new QTreeWidgetItem(treeWidget);
	momentumIndicator->setText(0, qkor("모멘텀"));
	QTreeWidgetItem *volatilityIndicator = new QTreeWidgetItem(treeWidget);
	volatilityIndicator->setText(0, qkor("변동성"));
	QTreeWidgetItem *etcIndicator = new QTreeWidgetItem(treeWidget);
	etcIndicator->setText(0, qkor("변동성"));
	treeWidget->header()->hide();
	for (int i = 0; i < NUM_OF_INDICATOR; ++i)
	{
		switch (sIndicatorTable[i].type)
		{
		case MARKET_BREADTH_INDICATOR:
		{
			QTreeWidgetItem *item = new QTreeWidgetItem(marketBreadthIndicator, QTreeWidgetItem::UserType+static_cast<int>(sIndicatorTable[i].index));
			item->setText(0, sIndicatorTable[i].desc);
		}
		break;
		case TREND_INDICATOR:
		{
			QTreeWidgetItem *item = new QTreeWidgetItem(trendIndicator, QTreeWidgetItem::UserType+static_cast<int>(sIndicatorTable[i].index));
			item->setText(0, sIndicatorTable[i].desc);
		}
		break;
		case VOLATILITY_INDICATOR:
		{
			QTreeWidgetItem *item = new QTreeWidgetItem(volatilityIndicator, QTreeWidgetItem::UserType+static_cast<int>(sIndicatorTable[i].index));
			item->setText(0, sIndicatorTable[i].desc);
		}
		break;
		case MOMENTUM_INDICATOR:
		{
			QTreeWidgetItem *item = new QTreeWidgetItem(momentumIndicator, QTreeWidgetItem::UserType+static_cast<int>(sIndicatorTable[i].index));
			item->setText(0, sIndicatorTable[i].desc);
		}
		break;
		case ETC:
		{
			QTreeWidgetItem *item = new QTreeWidgetItem(etcIndicator, QTreeWidgetItem::UserType+static_cast<int>(sIndicatorTable[i].index));
			item->setText(0, sIndicatorTable[i].desc);
		}break;
		default: break;
		}
	}
	connect(treeWidget, SIGNAL(itemDoubleClicked(QTreeWidgetItem*, int)), this, SLOT(onIndicatorAdded(QTreeWidgetItem*, int)));
}

void ChartWidget::drawFullChart(double* timestamp, double* open, double* high, double* low, double* close, double* volume, int numOfData) const
{
	XYChart *chart = new XYChart(getViewPortWidth(), getViewPortHeight());
	chart->setPlotArea(60, 10,getViewPortWidth()-120, getViewPortHeight()-30 );
	CandleStickLayer *layer = chart->addCandleStickLayer(DoubleArray(high, numOfData), DoubleArray(low, numOfData), DoubleArray(open, numOfData), DoubleArray(close, numOfData), 0xff0000, 0x0000ff);
	layer->setXData(DoubleArray(timestamp, numOfData));
	layer->setLineWidth(2);
	chart->xAxis()->setDateScale(ui->chartViewer->getValueAtViewPort("x", 0), ui->chartViewer->getValueAtViewPort("x", 1));

	// For the auto-scaled y-axis, as we hide the labels, we can disable axis rounding. This can
	// make the axis scale fit the data tighter.
	chart->yAxis()->setRounding(false, false);
	delete ui->viewPortControl->getChart();
	ui->viewPortControl->setChart(chart);
}

void ChartWidget::drawChart() const
{
	auto viewPortStartDate = ui->chartViewer->getValueAtViewPort("x", ui->chartViewer->getViewPortLeft());
	auto viewPortEndDate = ui->chartViewer->getValueAtViewPort("x", ui->chartViewer->getViewPortLeft() + ui->chartViewer->getViewPortWidth());

	auto numOfData = mPriceData->getNumOfData();

	int extraPoints = getExtraPoints();
	auto startIndex = static_cast<int>(floor(Chart::bSearch(DoubleArray(mPriceData->getTimeStampDataPtr(), numOfData), viewPortStartDate))) - extraPoints;
	auto endIndex = static_cast<int>(ceil(Chart::bSearch(DoubleArray(mPriceData->getTimeStampDataPtr(), numOfData), viewPortEndDate)));

	auto numOfPoints = endIndex - startIndex - 1;

	auto viewPortTimeStamps = DoubleArray((mPriceData->getTimeStampDataPtr() + startIndex), numOfPoints);
	auto viewPortHigh = DoubleArray((mPriceData->getHighDataPtr() + startIndex), numOfPoints);
	auto viewPortLow = DoubleArray((mPriceData->getLowDataPtr()+ startIndex), numOfPoints);
	auto viewPortOpen = DoubleArray((mPriceData->getOpenDataPtr() + startIndex), numOfPoints);
	auto viewPortClose = DoubleArray((mPriceData->getCloseDataPtr() + startIndex), numOfPoints);
	auto viewPortVolume = DoubleArray((mPriceData->getVolDataPtr() + startIndex), numOfPoints);
	auto mainHeight = getMainChartHeight();
	auto width = getChartWidth();

	FinanceChart *chart = new FinanceChart(width);

	if (numOfData < 0)
	{
		return;
	}

	chart->setData(viewPortTimeStamps,
		viewPortHigh,
		viewPortLow,
		viewPortOpen,
		viewPortClose,
		viewPortVolume,
		extraPoints);

	chart->addPlotAreaTitle(Chart::Top, mShcode.toUtf8().data());
	//	auto indicator = addIndicator(chart, ui->mIndicator1->itemData(ui->mIndicator1->currentIndex()).toString(), indicatorHeight);
	//	auto plotArea = indicator->getPlotArea();
	//	auto dynamicLayer = indicator->initDynamicLayer();
	//	auto topLeftX = plotArea->getRightX() - 20;
	//	auto topLeftY = plotArea->getTopY() + 10;
	//	auto bottomRightX = plotArea->getRightX() - 10;
	//	auto bottomRightY = plotArea->getTopY() + 20;
	//	dynamicLayer->rect(topLeftX, topLeftY, bottomRightX, bottomRightY, 0xff0000, 0x0000ff); 
	//d->text("<*img=@Triangle,color=00CC00,width=7,height=10*>", "normal", 8, 50, 50, 0);

	mMainChartSetting->apply(chart, this);

	foreach(ChartSetting *setting, mChartSettings)
	{
		setting->apply(chart, this);
	}
	delete ui->chartViewer->getChart();
	ui->chartViewer->setChart(chart);

	char buffer[1024];
	sprintf(buffer, "title='%s {value|P}'", chart->getToolTipDateFormat());
	//	QString url = tr("<area shape='rect' coords='%1,%2,%3,%4', title='%5' %6").arg(topLeftX).arg(topLeftY).arg(bottomRightX).arg(bottomRightY).arg("test").arg(chart->getHTMLImageMap("clickable", "", buffer));
	//	ui->chartViewer->setImageMap(url.toLocal8Bit().data());
	ui->chartViewer->setImageMap(chart->getHTMLImageMap("clickable", "", buffer));

}

void ChartWidget::loadChartSetting(FinanceChart* chart)
{
}

void ChartWidget::updatePeriod()
{
	mEndDate = QDateTime::currentDateTime();
	// If the trading day has not yet started (before 9:00am), or if the end date is on
	// on Sat or Sun, we set the end date to 3:00pm of the last trading day
	while ((mEndDate.time() < QTime(9, 0, 0)) || (mEndDate.date().dayOfWeek() > 6))
	{
		mEndDate = QDateTime(mEndDate.date().addDays(-1), QTime(15, 0, 0));
	}
	int durationInDays = 30;
	// Compute the start date by subtracting the duration from the end date.
	mStartDate = mEndDate;
	if (durationInDays > 30)
	{
		// More or equal to 30 days - so we use months as the unit
		mStartDate = QDateTime(QDate(mEndDate.date().year(), mEndDate.date().month(), 1).addMonths(-durationInDays / 30));
	}
	else
	{
		// Less than 30 days - use day as the unit. The starting point of the axis is
		// always at the start of the day (9:00am). Note that we use trading days, so
		// we skip Sat and Sun in counting the days.
		mStartDate = QDateTime(mEndDate.date());
		for (int i = 1; i < durationInDays; ++i) {
			if (mStartDate.date().dayOfWeek() == 1) {
				mStartDate = mStartDate.addDays(-3);
			}
			else {
				mStartDate = mStartDate.addDays(-1);
			}
		}
	}
	mStartDate.setTime(QTime(15, 0, 0));
	mEndDate.setTime(QTime(15, 0, 0));
}

int ChartWidget::getChartWidth() const
{
	return ui->chartViewerFrame->width() - 100;
}

int ChartWidget::getViewPortWidth() const
{
	return ui->viewPortFrame->width()-100;
}

int ChartWidget::getViewPortHeight() const 
{
	return 100;
}

int ChartWidget::getMainChartHeight() const
{
	auto totalHeight = ui->chartViewerFrame->height()-140;

	if (mNumOfIndicators == 0)
		return totalHeight;
	else if ((totalHeight - mNumOfIndicators*MAX_INDICATOR_HEIGHT) > MAX_INDICATOR_HEIGHT)
	{
		return totalHeight - mNumOfIndicators*MAX_INDICATOR_HEIGHT;
	}
	else
	{
		return totalHeight / (mNumOfIndicators + 1);
	}
}

int ChartWidget::getIndicatorHeight() const
{
	auto totalHeight = ui->chartViewerFrame->height()-140;
	if (mNumOfIndicators == 0)
		return 0;
	else if ((totalHeight - mNumOfIndicators*MAX_INDICATOR_HEIGHT) > MAX_INDICATOR_HEIGHT)
	{
		return MAX_INDICATOR_HEIGHT;
	}
	else
	{
		return totalHeight / (mNumOfIndicators + 1);
	}

	return 0;
}

int ChartWidget::getExtraPoints() const
{
	return 25;
}

void ChartWidget::onViewPortChanged() const
{
	double *timestamp(nullptr), *high(nullptr), *low(nullptr), *open(nullptr), *close(nullptr), *volume(nullptr);
	mPriceData->getDataPtr(&timestamp, &open, &high, &low, &close, &volume);
	auto numOfData = mPriceData->getNumOfData();
	drawChart();
	drawFullChart(timestamp, open, high, low, close, volume, numOfData);
}

void ChartWidget::addIndicator(INDICATOR_TYPE type)
{
	switch (type)
	{
	case ACCUM_DISTRIBUTION:
	{
		AccDistSetting *setting = AccDistSetting::createAccDistSetting(0xff, this);
		mChartSettings.insert(setting->name(), setting);
		ui->chartViewer->updateViewPort(true, true);
	}
		break;
	case AROON_OSCILLATOR:
//		m->addAroonOsc(height, 14, 0xff);
		break;
	case AROON:
//		m->addAroon(height, 14, 0x339933, 0x333399);
		break;
	case AVG_DIRECTIONAL_INDEX:
//		m->addADX(height, 14, 0x8000, 0x800000, 0x80);
		break;
	case AVG_TRUE_RANGE:
//		m->addATR(height, 14, 0x808080, 0xff);
		break;
	case BOLLINGER_BAND_WIDTH:
//		m->addBollingerWidth(height, 20, 2, 0xff);
		break;
	case CHAIKIN_MONEY_FLOW: 
//		m->addChaikinMoneyFlow(height, 21, 0x8000);
		break;
	case CHAIKIN_OSCILLATOR:
//		m->addChaikinOscillator(height, 0xff);
		break;
	case CHAIKIN_VOLATILITY:
//		m->addChaikinVolatility(height, 10, 10, 0xff);
		break;
	case CLOSE_LOCATION_VALUE:
//		m->addCLV(height, 0xff);
		break;
	case COMMONDITY_CHANNEL_INDEX:
//		m->addCCI(height, 20, 0x800080, 100, 0xff6666, 0x6666ff);
		break;
	case DETRENDED_PRICE_OSC:
//		m->addDPO(height, 20, 0xff);
		break;
	case DONCHIAN_CHANNEL_WIDTH: 
//		m->addDonchianWidth(height, 20, 0xff);
		break;
	case EASE_OF_MOVEMENT:
//		m->addEaseOfMovement(height, 9, 0x6060, 0x606000);
		break;
	case FAST_STOCHASTIC:
//		m->addFastStochastic(height, 14, 3, 0x6060, 0x606000);
		break;
	case MACD: 
//		m->addMACD(height, 26, 12, 9, 0xff, 0xff00ff, 0x8000);
		break;
	case MASS_INDEX:
//		m->addMassIndex(height, 0x800080, 0xff6666, 0x6666ff);
		break;
	case MOMENTUM:
//		m->addMomentum(height, 12, 0xff);
		break;
	case MONEY_FLOW_INDEX:
//		m->addMFI(height, 14, 0x800080, 30, 0xff6666, 0x6666ff);
		break;
	case NEG_VOLUME_INDEX:
//		m->addNVI(height, 255, 0xff, 0x883333);
		break;
	case ON_BALANCE_VOLUME:
//		m->addOBV(height, 0xff);
		break;
	case PERFORMANCE:
//		m->addPerformance(height, 0xff);
		break;
	case PERCENTAGE_PRICE_OSCILLATOR:
//		m->addPPO(height, 26, 12, 9, 0xff, 0xff00ff, 0x8000);
		break;
	case PERCENTAGE_VOLUME_OSCILLATOR:
//		m->addPVO(height, 26, 12, 9, 0xff, 0xff00ff, 0x8000);
		break;
	case POS_VOLUME_INDEX:
//		m->addPVI(height, 255, 0xff, 0x883333);
		break;
	case PRICE_VOLUME_TREND:
//		m->addPVT(height, 0xff);
		break;
	case RATE_OF_CHANGE:
//		m->addROC(height, 12, 0xff);
		break;
	case RSI: 
//		m->addRSI(height, 14, 0x800080, 20, 0xff6666, 0x6666ff);
		break;
	case SLOW_STOCHASTIC:
//		m->addSlowStochastic(height, 14, 3, 0x6060, 0x606000);
		break;
	case STOCH_RSI: 
//		m->addStochRSI(height, 14, 0x800080, 30, 0xff6666, 0x6666ff);
		break;
	case TRIX:
//		m->addTRIX(height, 12, 0xff);
		break;
	case ULTIMATE_OSCILLATOR:
//		m->addUltimateOscillator(height, 7, 14, 28, 0x800080, 20, 0xff6666, 0x6666ff);
		break;
	case VOLUME:
//		m->addVolIndicator(height, 0x99ff99, 0xff9999, 0xc0c0c0);
		break;
	case WILLIAMS_R:
//		m->addWilliamR(height, 14, 0x800080, 30, 0xff6666, 0x6666ff);
		break;
	case PARABOLIC_SAR:
//		m ->addParabolicSAR(0.02, 0.02, 0.2, Chart::DiamondShape, 5, 0x008800, 0x000000);
		break;
	case NUM_OF_INDICATOR: break;
	default: 
		break;
	}
}

LineLayer* ChartWidget::addMovingAvg(FinanceChart* m, QString avgType, int avgPeriod, int color)
{
	if (avgPeriod > 1)
	{
		if (avgType == "SMA")
			return m->addSimpleMovingAvg(avgPeriod, color);
		else if (avgType == "EMA")
			return m->addExpMovingAvg(avgPeriod, color);
		else if (avgType == "TMA")
			return m->addTriMovingAvg(avgPeriod, color);
		else if (avgType == "WMA")
			return m->addWeightedMovingAvg(avgPeriod, color);
	}

	return nullptr;
}