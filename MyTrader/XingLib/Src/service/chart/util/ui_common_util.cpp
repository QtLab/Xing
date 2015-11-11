#include "ui_common_util.h"
#include "chartdir.h"
double QDateTimeToChartTime(QDateTime q)
{
	QDate d = q.date();
	QTime t = q.time();
	return Chart::chartTime(d.year(), d.month(), d.day(), t.hour(), t.minute(),
		t.second()) + t.msec() / 1000.0;
}// Convert from chartTime to QDateTime
QDateTime ChartTimeToQDateTime(double t)
{
	double ymdhms = floor(t);
	int ms = (int)(floor((t - ymdhms) * 1000));
	int ymd = Chart::getChartYMD(ymdhms);
	int hms = (int)fmod(ymdhms, 86400);

	return QDateTime(QDate(ymd / 10000, (ymd % 10000) / 100, ymd % 100),
		QTime(hms / 3600, (hms % 3600) / 60, hms % 60, ms));
}