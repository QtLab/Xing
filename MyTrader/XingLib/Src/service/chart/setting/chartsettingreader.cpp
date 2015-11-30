#include "chartsettingreader.h"


ChartSettingReader::ChartSettingReader(const QString& fileName) :mFile(fileName), mLastErrorString("")
{
}


ChartSettingReader::~ChartSettingReader()
{
}

bool ChartSettingReader::open()
{
	if (!mFile.open(QFile::ReadOnly | QFile::Text))
	{
		mLastErrorString = QObject::tr("load chart setting - cannot read file %1:\n%2.").arg(mFile.fileName()).arg(mFile.errorString());
		return false;
	} else
	{
		mReader.setDevice(&mFile);
		if (mReader.readNextStartElement())
		{
			
		}
		return true;	
	}
	
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
