#ifndef UI_COMMON_UTIL_H
#define UI_COMMON_UTIL_H

#include <QDateTime>

double QDateTimeToChartTime(QDateTime q);
QDateTime ChartTimeToQDateTime(double t);

#endif