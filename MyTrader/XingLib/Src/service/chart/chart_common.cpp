#include "service/chart/chart_common.h"
#include "service/chart/setting/accdistsetting.h"
IndicatorSetting *createIndicatorSetting(QXmlStreamReader *xml)
{
	QString name = enumToString<CHART_SETTING_TYPE>(INDICATOR);
	Q_ASSERT(xml->name().toString() == name);
	if (xml->readNextStartElement())
	{
		QString indicator_type = xml->name().toString();
		INDICATOR_TYPE type = stringToEnum<IndicatorSetting::IndicatorType>(indicator_type);
		IndicatorSetting *setting = nullptr;
		switch (type)
		{
		case ACCUM_DISTRIBUTION:
			setting = AccDistSetting::createAccDistSetting(xml);
			break;
		case AROON_OSCILLATOR: break;
		case AROON: break;
		case AVG_DIRECTIONAL_INDEX: break;
		case AVG_TRUE_RANGE: break;
		case BOLLINGER_BAND_WIDTH: break;
		case CHAIKIN_MONEY_FLOW: break;
		case CHAIKIN_OSCILLATOR: break;
		case CHAIKIN_VOLATILITY: break;
		case CLOSE_LOCATION_VALUE: break;
		case COMMONDITY_CHANNEL_INDEX: break;
		case DETRENDED_PRICE_OSC: break;
		case DONCHIAN_CHANNEL_WIDTH: break;
		case EASE_OF_MOVEMENT: break;
		case FAST_STOCHASTIC: break;
		case MACD: break;
		case MASS_INDEX: break;
		case MOMENTUM: break;
		case MONEY_FLOW_INDEX: break;
		case NEG_VOLUME_INDEX: break;
		case ON_BALANCE_VOLUME: break;
		case PERFORMANCE: break;
		case PERCENTAGE_PRICE_OSCILLATOR: break;
		case PERCENTAGE_VOLUME_OSCILLATOR: break;
		case POS_VOLUME_INDEX: break;
		case PRICE_VOLUME_TREND: break;
		case RATE_OF_CHANGE: break;
		case RSI: break;
		case SLOW_STOCHASTIC: break;
		case STOCH_RSI: break;
		case TRIX: break;
		case ULTIMATE_OSCILLATOR: break;
		case VOLUME: break;
		case WILLIAMS_R: break;
		case PARABOLIC_SAR: break;
		case NUM_OF_INDICATOR: break;
		default: break;
		}
		return setting;
	}
	else
	{
		return nullptr;
	}
}