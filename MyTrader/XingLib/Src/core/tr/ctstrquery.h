#ifndef CTSTRQUERY_H
#define CTSTRQUERY_H

#include "core/tr/trquery.h" 

class CtsTrQuery : public TrQuery
{
	Q_OBJECT

public:
	explicit CtsTrQuery(const QString &trName, QObject *parent);
	~CtsTrQuery();

	virtual QString toString() override;
	QList<TrItem *> getResult();
	void setCompressedBlock(bool isCompressed);
	
public slots:
    virtual void onReceiveData(const QString& trCode) override;
    virtual void onReceiveChartRealData(const QString& trCode) override;
protected:
	virtual void readOutBlock();
	virtual void readOutBlock1();
protected:
	QList<TrItem *> mItemList;
	bool mIsCompressedBlock;
};

#endif // CTSTRQUERY_H
