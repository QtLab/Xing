#ifndef ACCDISTSETTING_H
#define ACCDISTSETTING_H

#include "basicindicatorsetting.h"

class AccDistSetting : public BasicIndicatorSetting
{
	Q_OBJECT

public:
	bool saveSettingToXml(QXmlStreamWriter* xml) override;
	bool loadSettingFromXml(QXmlStreamReader* xml) override;
	bool apply(FinanceChart* chart, const ChartInfo* chartInfo) override;
	~AccDistSetting();
	static AccDistSetting* createAccDistSetting(const QColor &color, QObject *parent=0);
	static AccDistSetting* createAccDistSetting(long color, QObject *parent=0);

private:
	AccDistSetting(const QString &name, QObject *parent);
	static int sIndex;
};

#endif // ACCDISTSETTING_H
