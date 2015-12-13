#include "accdistsetting.h"
#include "common/util/enum_util.h"
#include <QtCore/QVariant>
#define NAME_ATTR "name"
#define COLOR_ATTR "color"
#define TO_HEX_STR(X) QString::number(X, 16).toUpper().rightJustified(2, '0')

int AccDistSetting::sIndex = 0;
AccDistSetting::AccDistSetting(const QString &name, QObject *parent)
	: IndicatorSetting(name, parent)
{

}
QColor AccDistSetting::getColor() const
{
	return mColor;
}

bool AccDistSetting::apply(FinanceChart* chart, const ChartInfo* chartInfo)
{
	chart->addAccDist(chartInfo->getIndicatorHeight(), getColor().value());
	return true;
}
void AccDistSetting::setColor(const QColor color)
{
	mColor = color;
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

AccDistSetting* AccDistSetting::createAccDistSetting(QXmlStreamReader* xml)
{
	Q_ASSERT(xml->name()==enumToString<INDICATOR_TYPE>(ACCUM_DISTRIBUTION));
	QXmlStreamAttributes attributes = xml->attributes();
	QString color = attributes.value(COLOR_ATTR).toString();
	return createAccDistSetting(QColor(color.toInt()));
}

void AccDistSetting::writeSettingToXml(QXmlStreamWriter* xml)
{
	xml->writeStartElement(enumToString<INDICATOR_TYPE>(ACCUM_DISTRIBUTION));
	xml->writeAttribute(COLOR_ATTR, QVariant(mColor).toString());
	xml->writeEndElement();
}

void AccDistSetting::readSettingFromXml(QXmlStreamReader* xml)
{
}