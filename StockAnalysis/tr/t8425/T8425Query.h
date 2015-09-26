#ifndef T8425QUERY_H
#define T8425QUERY_H

#include <QObject>
#include <QString>
#include <QList>
#include "tr\blocktrquery.h"
#include "tr\t8425\T8425Item.h"
class T8425Query : public BlockTrQuery
{
	Q_OBJECT
	Q_PROPERTY(QString dummy READ dummy)
public:
	static T8425Query *createQuery(QObject *parent = 0);
	~T8425Query();

	QString dummy();

protected:
	explicit T8425Query(QObject *parent = 0);
	virtual T8425Item *createItem() override;
};

#endif