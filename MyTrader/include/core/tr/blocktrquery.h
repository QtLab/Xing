#ifndef BLOCKTRQUERY_H
#define BLOCKTRQUERY_H

#include <QObject>
#include "core/tr/trquery.h"

class BlockTrQuery : public TrQuery
{
	Q_OBJECT

public:
	explicit BlockTrQuery(const QString &trName, QObject *parent);
	~BlockTrQuery();

	virtual QString toString() override;
	QList<TrItem *> getResult();

public slots:
    virtual void onReceiveData(const QString& trCode) override;
    virtual void onReceiveChartRealData(const QString& trCode) override;

private:
	QList<TrItem *> mItemList;
};

#endif // BLOCKTRQUERY_H
