#ifndef CTSTRQUERY_H
#define CTSTRQUERY_H

#include "tr/trquery.h" 

class CtsTrQuery : public TrQuery
{
	Q_OBJECT

public:
	explicit CtsTrQuery(const QString &trName, QObject *parent);
	~CtsTrQuery();

	virtual QString toString() override;
	QList<TrItem *> getResult();
	
public slots:
	virtual void readOutBlock();
	virtual void readOutBlock1();
    virtual void onReceiveData(const QString& trCode);
    virtual void onReceiveChartRealData(const QString& trCode);

protected:
	QList<TrItem *> mItemList;
	
};

#endif // CTSTRQUERY_H
