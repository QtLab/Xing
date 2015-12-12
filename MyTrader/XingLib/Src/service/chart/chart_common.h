#ifndef CHART_COMMON_H
#define CHART_COMMON_H
#include <QXmlStreamReader>
#include "service/chart/setting/indicatorsetting.h"
#include "service/chart/setting/MainChartSetting.h"
#include "common/util/enum_util.h"
typedef enum { NONE, BOLLINGER_BAND, DONCHAIN_CHANNEL, ENVELOP } CHANNEL_TYPE;
	

typedef enum {
	MARKET_BREADTH_INDICATOR,
	TREND_INDICATOR,
	VOLATILITY_INDICATOR,
	MOMENTUM_INDICATOR,
	ETC
} INDICATOR_CATEGORY_TYPE;

IndicatorSetting *createIndicatorSetting(QXmlStreamReader *xml);
#endif