#ifndef CHARTSETTINGWRITER_H
#define CHARTSETTINGWRITER_H
#include <QtCore/QString>
#include <QFile>
#include <QXmlStreamWriter>
class ChartSetting;

class ChartSettingWriter
{
public:
	explicit ChartSettingWriter(const QString &fileName);
	~ChartSettingWriter();
	bool open();
	bool close();
	bool write(ChartSetting* setting);
	QString errorString() const;

private:
	void startDocument();

private:
	QFile mFile;
	QString mLastErrorString;
	QXmlStreamWriter mWriter;
};

#endif