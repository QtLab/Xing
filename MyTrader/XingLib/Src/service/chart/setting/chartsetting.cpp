#include "chartsetting.h"
ChartSetting::ChartSetting(const QString& settingName, QObject* parent) :QObject(parent), _name(settingName)
{
}

ChartSetting::~ChartSetting()
{
}

QString ChartSetting::name() const
{
	return _name;
}