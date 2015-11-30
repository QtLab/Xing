#include "chartsettingreader.h"


ChartSettingReader::ChartSettingReader(const QString &fileName) :mFile(fileName), mLastErrorString("")
{
}


ChartSettingReader::~ChartSettingReader()
{
}

bool ChartSettingReader::open()
{
	if (mFile.open(QFile::ReadOnly))
	return true;
}

bool ChartSettingReader::close()
{
	return true;
}

ChartSetting* ChartSettingReader::read()
{
}

QString ChartSettingReader::errorString() const
{
}
