#ifndef UPJONGCODEUPDATER_H
#define UPJONGCODEUPDATER_H

#include <QObject>
#include <QList>
#include "manager/querymngr.h"
#include "data/commontype.h"
class T1516Query;
class UpjongCodeUpdater : public QObject
{
	Q_OBJECT
public:
	explicit UpjongCodeUpdater(QueryMngr *queryMngr, QObject *parent = 0);
	~UpjongCodeUpdater();
signals:
	void updateUpjongCodeDone();

public slots:
	void updateUpjongCode();
	void t8424QueryDone();
	void t1516QueryDone();
private:
	void requestShcodeListByUpjongCode(const QString &upcode);
	void createUpjongCodeTable();
	void saveUpjongCodeToDB(const QString &upcode, const QString &hname);
	void createUpjongTable(const QString &upcode);
	void saveUpjongInfoToDB(const QString &upcode, const QString &shcode, const QString &hname);
	void errorQuery(QSqlQuery* query);
	UPJONG_TYPE getUpjongType(const QString &upcode);
private:
	QueryMngr* mQueryMngr;
	QList<T1516Query *> mT1516RequestedList;
};

#endif
