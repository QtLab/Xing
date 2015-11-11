#ifndef SIMPLETRQUERY_H
#define SIMPLETRQUERY_H

#include <QObject>
#include "core/tr/trquery.h"

class SimpleTrQuery : public TrQuery
{
	Q_OBJECT

public:
	explicit SimpleTrQuery(const QString &trName, QObject *parent = 0);
	~SimpleTrQuery();
	TrItem *getResult();
	virtual QString toString() override;
public slots:
	virtual void onReceiveData(const QString& trCode) override;
    virtual void onReceiveChartRealData(const QString& trCode) override;
private:
	TrItem *mResult;
};

#endif // SIMPLETRQUERY_H
