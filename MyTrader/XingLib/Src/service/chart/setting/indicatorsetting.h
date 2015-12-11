#ifndef INDICATORSETTING_H
#define INDICATORSETTING_H

#include "chartsetting.h"
#include <QColor>

class IndicatorSetting : public ChartSetting
{
	Q_OBJECT
public:
	typedef enum
	{
		AccumDistribution = 0 
		,AroonOscillator
		,Aroon
		,AvgDirectionalIndex
		,AvgTrueRange
		,BollingerBandWidth
		,ChaikinMoneyFlow
		,ChaikinOscillator
		,ChaikinVolatility
		,CloseLocationValue
		,CommondityChannelIndex
		,DetrendedPriceOsc
		,DonchianChannelWidth
		,EaseOfMovement
		,FastStochastic
		,Macd
		,MassIndex
		,Momentum
		,MoneyFlowIndex
		,NegVolumeIndex
		,OnBalanceVolume
		,Performance
		,PercentagePriceOscillator
		,PercentageVolumeOscillator
		,PosVolumeIndex
		,PriceVolumeTrend
		,RateOfChange
		,Rsi
		,SlowStochastic
		,StochRSI
		,Trix
		,UltimateOscillator
		,Volume
		,WilliamsR
		,ParabolicSAR
		,NumOfIndicator
	} IndicatorType;
	Q_ENUM(IndicatorType);
	IndicatorSetting(const QString &name, QObject *parent=0);
	~IndicatorSetting();
	bool saveSettingToXml(QXmlStreamWriter* xml) override;
	bool loadSettingFromXml(QXmlStreamReader* xml) override;

protected:
	virtual void writeSettingToXml(QXmlStreamWriter *xml) = 0;
	virtual void readSettingFromXml(QXmlStreamReader *xml) = 0;
};

#define INDICATOR_TYPE IndicatorSetting::IndicatorType
#define ACCUM_DISTRIBUTION IndicatorSetting::AccumDistribution
#define AROON_OSCILLATOR IndicatorSetting::AroonOscillator
#define AROON IndicatorSetting::Aroon
#define AVG_DIRECTIONAL_INDEX IndicatorSetting::AvgDirectionalIndex
#define AVG_TRUE_RANGE IndicatorSetting::AvgTrueRange
#define BOLLINGER_BAND_WIDTH IndicatorSetting::BollingerBandWidth
#define CHAIKIN_MONEY_FLOW IndicatorSetting::ChaikinMoneyFlow
#define CHAIKIN_OSCILLATOR IndicatorSetting::ChaikinOscillator
#define CHAIKIN_VOLATILITY IndicatorSetting::ChaikinVolatility
#define CLOSE_LOCATION_VALUE IndicatorSetting::CloseLocationValue
#define COMMONDITY_CHANNEL_INDEX IndicatorSetting::CommondityChannelIndex
#define DETRENDED_PRICE_OSC IndicatorSetting::DetrendedPriceOsc
#define DONCHIAN_CHANNEL_WIDTH IndicatorSetting::DonchianChannelWidth
#define EASE_OF_MOVEMENT IndicatorSetting::EaseOfMovement
#define FAST_STOCHASTIC IndicatorSetting::FastStochastic
#define MACD	IndicatorSetting::Macd
#define MASS_INDEX IndicatorSetting::MassIndex
#define MOMENTUM IndicatorSetting::Momentum
#define MONEY_FLOW_INDEX IndicatorSetting::MoneyFlowIndex
#define NEG_VOLUME_INDEX IndicatorSetting::NegVolumeIndex
#define ON_BALANCE_VOLUME IndicatorSetting::OnBalanceVolume
#define PERFORMANCE IndicatorSetting::Performance
#define PERCENTAGE_PRICE_OSCILLATOR IndicatorSetting::PercentagePriceOscillator
#define PERCENTAGE_VOLUME_OSCILLATOR IndicatorSetting::PercentageVolumeOscillator
#define POS_VOLUME_INDEX IndicatorSetting::PosVolumeIndex
#define PRICE_VOLUME_TREND IndicatorSetting::PriceVolumeTrend
#define RATE_OF_CHANGE IndicatorSetting::RateOfChange
#define RSI IndicatorSetting::Rsi
#define SLOW_STOCHASTIC IndicatorSetting::SlowStochastic
#define STOCH_RSI IndicatorSetting::StochRSI
#define TRIX IndicatorSetting::Trix
#define ULTIMATE_OSCILLATOR IndicatorSetting::UltimateOscillator
#define VOLUME IndicatorSetting::Volume
#define WILLIAMS_R IndicatorSetting::WilliamsR
#define PARABOLIC_SAR IndicatorSetting::ParabolicSAR
#define NUM_OF_INDICATOR IndicatorSetting::NumOfIndicator

#endif // INDICATORSETTING_H
