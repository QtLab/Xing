#include "indicatorsetting.h"
#include "common/util/enum_util.h"
IndicatorSetting::IndicatorSetting(const QString &name, QObject *parent)
	: ChartSetting(name, parent)
{

}

IndicatorSetting::~IndicatorSetting()
{

}

bool IndicatorSetting::saveSettingToXml(QXmlStreamWriter* xml)
{
	xml->writeStartElement(enumToString<CHART_SETTING_TYPE>(INDICATOR));
	writeSettingToXml(xml);
	xml->writeEndElement();
	return true;
}

bool IndicatorSetting::loadSettingFromXml(QXmlStreamReader* xml)
{
	return true;
}
