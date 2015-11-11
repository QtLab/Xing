#include <QtSql/QSqlQuery>
#include <QtSql/QSqlRecord>
#include <QtSql/QSqlError>
#include "themeupjongupdater.h"
#include "core/tr/t8425/T8425Query.h"
#include "core/tr/t1537/T1537Query.h"
#include "logger/log.h"

ThemeUpjongUpdater::ThemeUpjongUpdater(QueryMngr *queryMngr, QObject *parent)
	: QObject(parent), mQueryMngr(queryMngr)
{

}

ThemeUpjongUpdater::~ThemeUpjongUpdater()
{

}

bool ThemeUpjongUpdater::isUpdating()
{
	return mRequestedQuery.size() != 0;
}

void ThemeUpjongUpdater::updateThemeUpjong()
{
	createThemeCodeTable();
	T8425Query *query = T8425Query::createQuery();
	connect(query, &T8425Query::workDone, this, [&](){
		QObject *sender = QObject::sender();
		if (sender != NULL) {
			T8425Query *query = qobject_cast<T8425Query *>(sender);
			if (query != NULL) {
				QList<TrItem *> itemList = query->getResult();
				foreach(TrItem * trItem, itemList) {
					T8425Item *item = qobject_cast<T8425Item *>(trItem);
					saveToThemeCodeTable(item->tmcode(), item->tmname());
					requestShcodeListByThemeCode(item->tmcode());
				}
				query->deleteLater();
			}
		}
	});
	mQueryMngr->requestQuery(query);
}

void ThemeUpjongUpdater::createThemeCodeTable()
{
	QSqlQuery query;
	query.prepare("CREATE TABLE IF NOT EXISTS ThemeCodeTable (tmcode CHAR(4) UNIQUE PRIMARY KEY, tmname VARCHAR(36))");
	if (!query.exec()) {
		errorQuery(&query);
		return;
	}
	else {
		qCDebug(themeUpjongUpdater) << "ThemeUpjongCodeTable is create";
	}
}

void ThemeUpjongUpdater::saveToThemeCodeTable(const QString &tmcode, const QString &tmname)
{
	QSqlQuery qry;
	QString qryString = tr("SELECT COUNT(*) FROM ThemeCodeTable WHERE tmcode='%1'").arg(tmcode);
	qry.prepare(qryString);
	if (qry.exec()) {
		if (qry.next()) {
			if (qry.value(0).toInt() == 0) {
				qryString = tr("INSERT INTO ThemeCodeTable (tmcode, tmname) VALUES ('%1', '%2')").arg(tmcode).arg(tmname);
				qry.prepare(qryString);
				if (!qry.exec()) {
					errorQuery(&qry);
				}
			}
		}
	}
	else {
		errorQuery(&qry);
	}
}

void ThemeUpjongUpdater::requestShcodeListByThemeCode(const QString &tmcode)
{
	createThemeUpjongDB(tmcode);
	T1537Query *query = T1537Query::createQuery(tmcode);
	connect(query, &T1537Query::workDone, this, [&]() {
		QObject *sender = QObject::sender();
		if (sender != NULL) {
			T1537Query *query = qobject_cast<T1537Query *>(sender);
			if (query != NULL) {
				QList<TrItem*> itemList = query->getResult();
				foreach(TrItem *item, itemList) {
					T1537Item *t1537Item = qobject_cast<T1537Item *>(item);
					saveToThemeUpjongDB(query->tmcode(), t1537Item->shcode(), t1537Item->hname());
				}
				mRequestedQuery.removeOne(query);
				query->deleteLater();
				if (mRequestedQuery.size() == 0) {
					emit updateThemeUpjongDone();
				}
			}
		}
	});
	mQueryMngr->requestQuery(query);
	mRequestedQuery.append(query);
}

void ThemeUpjongUpdater::createThemeUpjongDB(const QString &tmcode)
{
	QSqlQuery query;
	query.prepare(tr("CREATE TABLE IF NOT EXISTS ThemeUpjongTable_%1 (shcode CHAR(6) UNIQUE PRIMARY KEY, hname VARCHAR(20))").arg(tmcode));
	if (!query.exec()) {
		errorQuery(&query);
		return;
	}
	else {
		return;
	}
}

void ThemeUpjongUpdater::saveToThemeUpjongDB(const QString &tmcode, const QString &shcode, const QString &hname)
{
	QSqlQuery qry;
	QString qryString = tr("SELECT COUNT(*) FROM ThemeUpjongTable_%1 WHERE shcode='%2'").arg(tmcode).arg(shcode);
	qry.prepare(qryString);
	if (qry.exec()){
		if (qry.next()) {
			if (qry.value(0).toInt() == 0) {
				qryString = tr("INSERT INTO ThemeUpjongTable_%1 ( shcode, hname ) VALUES ( '%2', '%3')").arg(tmcode).arg(shcode).arg(hname);
				qry.prepare(qryString);
				if (!qry.exec()) {
					errorQuery(&qry);
				}
			}
		}
	}
	else {
		errorQuery(&qry);
	}
}

void ThemeUpjongUpdater::errorQuery(QSqlQuery *query)
{
	qCWarning(themeUpjongUpdater) << "QueryError : " << query->lastError() << endl << query->executedQuery();
}
