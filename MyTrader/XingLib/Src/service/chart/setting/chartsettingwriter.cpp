#include "chartsettingwriter.h"
#include <QtWidgets/QMessageBox>
#include "service/chart/setting/chartsetting.h"

ChartSettingWriter::ChartSettingWriter(const QString& fileName) : mFile(fileName), mLastErrorString("")
{
	mWriter.setAutoFormatting(true);
}

ChartSettingWriter::~ChartSettingWriter()
{
}

void ChartSettingWriter::startDocument()
{
	mWriter.setDevice(&mFile);
	mWriter.writeStartDocument();
}

bool ChartSettingWriter::open()
{
	if (mFile.exists())
	{
		mFile.remove();
	}
	if (!mFile.open(QFile::WriteOnly | QFile::Text))
	{
		mLastErrorString = QObject::tr("Save chart setting - cannot write file %1:\n%2.").arg(mFile.fileName()).arg(mFile.errorString());
		return false;
	} else
	{
		startDocument();
		return true;
	}
}

bool ChartSettingWriter::close()
{
	mWriter.writeEndDocument();
	mFile.close();
	return true;
}

bool ChartSettingWriter::write(ChartSetting* setting)
{
	setting->saveSettingToXml(&mWriter);
	return true;
}

QString ChartSettingWriter::errorString() const
{
	return mLastErrorString;
}
