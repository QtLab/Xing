#ifndef BASICINDICATORSETTING_H
#define BASICINDICATORSETTING_H

#include "chartsetting.h"
#include <QColor>
class BasicIndicatorSetting : public ChartSetting
{
	Q_OBJECT
	Q_PROPERTY(QColor color MEMBER _color READ color WRITE setColor)
public:
	BasicIndicatorSetting(const QString &name, QObject *parent=0);
	~BasicIndicatorSetting();
	QColor color() const { return _color; }
	void setColor(const QColor &color) { _color = color; }
private:
	QColor _color;
};

#endif // BASICINDICATORSETTING_H
