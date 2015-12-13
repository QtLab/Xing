#include "chartsettingreader.h"
#include "service/chart/chart_common.h"
#include "common/util/enum_util.h"
#include "indicatorsetting.h"

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
		return true;	
	}
}

bool ChartSettingReader::close()
{
	mFile.close();
	return true;
}

ChartSetting* ChartSettingReader::read()
{
	if (mReader.readNextStartElement())
	{
		QString chartSettingType = mReader.name().toString();
		switch (stringToEnum<CHART_SETTING_TYPE>(chartSettingType))
		{
			case MAIN_CHART:
			{
				MainChartSetting* setting = new MainChartSetting();
				setting->loadSettingFromXml(&mReader);
				return setting;
			}
			break;
		case INDICATOR:
			{
				IndicatorSetting* setting = createIndicatorSetting(&mReader);
				return setting;
			}
			break;
		}
	}
	else {
		return nullptr;
	}
}

QString ChartSettingReader::errorString() const
{
	return mLastErrorString;
}
