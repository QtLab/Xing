#ifndef CHARTWIDGET_H
#define CHARTWIDGET_H

#include <QWidget>
#include <QDateTime>
#include "service/chart/data/StockPriceData.h"
#include "service/chart/chart_common.h"
#include "service/chart/setting/chartinfo.h"
#include "service/chart/setting/indicatorsetting.h"

#define MAX_INDICATOR_HEIGHT 100
class MultiChart;
class QTreeWidgetItem;
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
class ChartSetting;
class MainChartSetting;

typedef struct _Indicator {
	QString name;
	QString desc;
	INDICATOR_TYPE index;
	INDICATOR_CATEGORY_TYPE type;
} Indicator;

class ChartWidget : public QWidget, public ChartInfo
{
	Q_OBJECT

public:
	explicit ChartWidget(QueryMngr *queryMngr, QWidget *parent = 0);
	~ChartWidget();
	virtual int getChartWidth() const override;
	virtual int getViewPortWidth() const override;
	virtual int getViewPortHeight() const override;
	virtual int getMainChartHeight() const override;
	virtual int getIndicatorHeight() const override;
public slots:
	void onStockPriceDataReceived(StockPriceData* stockData);
	void onViewPortChanged();
private slots:
	void on_shcodeSearchBtn_clicked();
	void onChartClicked(QMouseEvent *);
	void onMainChartTypeChanged(int id, bool checked) const;
	void onChannelTypeChanged(int id, bool checked) const;
	void onIndicatorAdded(QTreeWidgetItem *item, int column);
	void onMouseMovePlotArea(QMouseEvent *);
protected:
	virtual void resizeEvent(QResizeEvent * event) override;

	void closeEvent(QCloseEvent*) override;
private:
	void initUI();
	void setChartRange(double* timeStamp, int timeStampLen) const;
	void initMainChartSelectionUI();
	void initChannelSelectionUI();
	void initIndicatorSelectionUI() const;
	void drawFullChart(double *timestamp, double *open, double *high, double *low, double *close, double *volume, int numOfData) const;
	void drawChart();
	void loadChartSetting(FinanceChart *chart);
	void updatePeriod();
	int getExtraPoints() const;
		
	void addIndicator(INDICATOR_TYPE type);
	LineLayer *addMovingAvg(FinanceChart *m, QString avgType, int avgPeriod, int color);
	void traceChart(MultiChart *m, int mouseX);
private:
	Ui::ChartWidget *ui;
	QButtonGroup *mMainChartType;
	QButtonGroup *mChannelType;
	int mNoOfPoints;
	int mNumOfIndicators;
	QDateTime mStartDate;
	QDateTime mEndDate;

	ShcodeSelectionDialog *mShcodeDlg;
	QueryMngr *mQueryMngr;
	StockChartDataManager *mStockManager;
	QString mShcode;
	StockPriceData *mPriceData;
	StockInfoMngr *mStockInfoMngr;
	QMap<QString, ChartSetting*> mChartSettings;
	MainChartSetting *mMainChartSetting;
};

#endif // CHARTWIDGET_H
