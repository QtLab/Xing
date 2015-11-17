#include "basicindicatorsetting.h"

BasicIndicatorSetting::BasicIndicatorSetting(const QString &name, QObject *parent)
	: ChartSetting(name, parent), _color(Qt::darkRed)
{

}

BasicIndicatorSetting::~BasicIndicatorSetting()
{

}
