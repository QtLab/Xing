#ifndef CHARTSETTING_H
#define CHARTSETTING_H

#include <QObject>
#include <QXmlStreamWriter>
#include "FinanceChart.h"
#include "service/chart/setting/chartinfo.h"
class FinanceChart;
class ChartInfo;
class ChartSetting : public QObject
{
	Q_OBJECT
	Q_PROPERTY(QString name MEMBER _name READ name)
public:
	typedef enum {MainChart, Indicator} ChartSettingType;
	Q_ENUM(ChartSettingType)
	explicit ChartSetting(const QString &settingName, QObject* parent=0);
	virtual ~ChartSetting();
	virtual bool saveSettingToXml(QXmlStreamWriter *xml) = 0;
	virtual bool loadSettingFromXml(QXmlStreamReader *xml) = 0;
	virtual bool apply(FinanceChart *chart, const ChartInfo* chartInfo) = 0;
	QString name() const;
private:
	QString _name;
};

#define CHART_SETTING_TYPE ChartSetting::ChartSettingType
#define MAIN_CHART ChartSetting::MainChart
#define INDICATOR ChartSetting::Indicator

#endif		//CHARTSETTING_H

