#include "accdistsetting.h"

int AccDistSetting::sIndex = 0;
AccDistSetting::AccDistSetting(const QString &name, QObject *parent)
	: BasicIndicatorSetting(name, parent)
{

}

bool AccDistSetting::saveSettingToXml(XmlStreamWriter* xml)
{
	return true;
}

bool AccDistSetting::loadSettingFromXml(XmlStreamReader* xml)
{
	return true;
}

bool AccDistSetting::apply(FinanceChart* chart, const ChartInfo* chartInfo)
{
	chart->addAccDist(chartInfo->getIndicatorHeight(), 0xff);
	return true;
}

AccDistSetting::~AccDistSetting()
{

}

AccDistSetting* AccDistSetting::createAccDistSetting(const QColor &color, QObject *parent)
{
	QString name = tr("AccDist-%1").arg(sIndex++);
	AccDistSetting *setting = new AccDistSetting(name, parent);
	setting->setColor(color);
	return setting;
}

AccDistSetting* AccDistSetting::createAccDistSetting(long color, QObject *parent)
{
	return createAccDistSetting(QColor(color & 0xff0000, color & 0x00ff00, color & 0x0000ff), parent);
}
