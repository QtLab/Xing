#ifndef CHARTSETTINGREADER_H
#define CHARTSETTINGREADER_H
#include "MainChartSetting.h"
#include <QtCore/QFile>
class QString;

class ChartSettingReader
{
public:
	explicit ChartSettingReader(const QString &fileName);
	~ChartSettingReader();
	bool open();
	bool close();
	ChartSetting* read();
	QString errorString() const;
private:
	QFile mFile;
	QString mLastErrorString;
	QXmlStreamReader mReader;
};

#endif