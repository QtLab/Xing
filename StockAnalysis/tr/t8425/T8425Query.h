#pragma once
#include <QObject>
#include <QString>
#include <QList>
#include "tr\trquery.h"
#include "tr\t8425\T8425Item.h"
class T8425Query : public TrQuery
{
	Q_OBJECT
	Q_PROPERTY(QString dummy READ dummy)
public:
	static T8425Query *createQuery(QObject *parent = 0);
	~T8425Query();

	QString dummy();

	virtual QString toString() override;
	QList<T8425Item *> getResult();
protected:
	explicit T8425Query(QObject *parent = 0);
	virtual T8425Item *createItem() override;

public slots:
	virtual void onReceiveData(const QString& trCode);
	virtual void onReceiveChartRealData(const QString& trCode);

private:
	QList<T8425Item *> mResult;
};

