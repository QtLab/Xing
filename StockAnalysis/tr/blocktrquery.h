#ifndef BLOCKTRQUERY_H
#define BLOCKTRQUERY_H

#include <QObject>
#include "tr/trquery.h"

class BlockTrQuery : public TrQuery
{
	Q_OBJECT

public:
	explicit BlockTrQuery(const QString &trName, QObject *parent);
	~BlockTrQuery();

	virtual QString toString() override;
	QList<TrItem *> getResult();

public slots:
    virtual void onReceiveData(const QString& trCode);
    virtual void onReceiveChartRealData(const QString& trCode);

private:
	QList<TrItem *> mItemList;
};

#endif // BLOCKTRQUERY_H
