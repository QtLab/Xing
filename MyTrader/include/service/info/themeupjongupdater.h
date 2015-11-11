#ifndef THEMEUPJONGUPDATER_H
#define THEMEUPJONGUPDATER_H

#include <QObject>
#include "core/query/querymngr.h"
class T1537Query;
class ThemeUpjongUpdater : public QObject
{
	Q_OBJECT

public:
	explicit ThemeUpjongUpdater(QueryMngr *queryMngr, QObject *parent = 0);
	~ThemeUpjongUpdater();
	bool isUpdating();
signals:
	void updateThemeUpjongDone();

public slots:
	void updateThemeUpjong();

private:
	void createThemeCodeTable();
	void saveToThemeCodeTable(const QString &tmcode, const QString &tmname);
	void requestShcodeListByThemeCode(const QString &tmcode);
	void createThemeUpjongDB(const QString &tmcode);
	void saveToThemeUpjongDB(const QString &tmcode, const QString &shcode, const QString &hname);
	void errorQuery(QSqlQuery *query);

private:
	QueryMngr *mQueryMngr;
	QList<T1537Query *> mRequestedQuery;
};

#endif // THEMEUPJONGUPDATER_H
