#ifndef ACCDISTSETTING_H
#define ACCDISTSETTING_H

#include "indicatorsetting.h"

class AccDistSetting : public IndicatorSetting
{
	Q_OBJECT

public:
	QColor getColor() const;
	bool apply(FinanceChart* chart, const ChartInfo* chartInfo) override;
	void setColor(const QColor color);
	~AccDistSetting();
	static AccDistSetting* createAccDistSetting(const QColor &color, QObject *parent=0);
	static AccDistSetting* createAccDistSetting(long color, QObject *parent=0);
	static AccDistSetting* createAccDistSetting(QXmlStreamReader *xml);
protected:

	void writeSettingToXml(QXmlStreamWriter* xml) override;
	void readSettingFromXml(QXmlStreamReader* xml) override;
private:
	AccDistSetting(const QString &name, QObject *parent);
	QColor mColor;
	static int sIndex;
};

#endif // ACCDISTSETTING_H
