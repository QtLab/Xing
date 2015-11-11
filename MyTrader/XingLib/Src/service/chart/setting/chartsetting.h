#pragma once
#include <QString>
class FinanceChart;
class XmlStreamWriter;
class XmlStreamReader;
class ChartSetting
{
public:
	ChartSetting(const QString &settingName);
	virtual ~ChartSetting();
	virtual bool saveSettingToXml(XmlStreamWriter *xml) = 0;
	virtual bool loadSettingFromXml(XmlStreamReader *xml) = 0;
	virtual bool apply(FinanceChart *chart) = 0;

	QString settingName() const;
private:
	QString mSettingName;
};

