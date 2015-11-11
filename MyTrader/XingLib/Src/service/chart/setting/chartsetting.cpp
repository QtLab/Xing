#include "chartsetting.h"

ChartSetting::ChartSetting(const QString& settingName) :mSettingName(settingName)
{
}

ChartSetting::~ChartSetting()
{
}

QString ChartSetting::settingName() const
{
	return mSettingName;
}