#include <QtSql/QSqlQuery>
#include <QtSql/QSqlRecord>
#include <QtSql/QSqlError>
#include "UpjongCodeUpdater.h"
#include "core/tr/t8424/t8424query.h"
#include "core/tr/t1516/t1516query.h"
#include "logger/log.h"
#include "core/util/xingutil.h"
UpjongCodeUpdater::UpjongCodeUpdater(QueryMngr *queryMngr, QObject *parent /*= 0*/) : QObject(parent), mQueryMngr(queryMngr)
{

}

UpjongCodeUpdater::~UpjongCodeUpdater()
{
}

bool UpjongCodeUpdater::isUpdating()
{
	return mT1516RequestedList.size() != 0;
}

void UpjongCodeUpdater::updateUpjongCode()
{
	createUpjongCodeTable();
	T8424Query *query = T8424Query::createQuery();
	connect(query, SIGNAL(workDone()), this, SLOT(t8424QueryDone()));
	mQueryMngr->requestQuery(query);
}

void UpjongCodeUpdater::t8424QueryDone()
{
	QObject *sender = QObject::sender();
	if (sender != NULL) {
		T8424Query *query = qobject_cast<T8424Query *>(sender);
		if (query != NULL) {
			QList<TrItem *> itemList = query->getResult();
			foreach(TrItem *trItem, itemList) {
				T8424Item *item = qobject_cast<T8424Item *>(trItem);
				saveUpjongCodeToDB(item->upcode(), item->hname());
				requestShcodeListByUpjongCode(item->upcode());
			}
			query->deleteLater();
		}
	}
}

void UpjongCodeUpdater::requestShcodeListByUpjongCode(const QString &upcode)
{
	T1516Query *query = T1516Query::createQuery(upcode, MARKET_TYPE_NONE);
	connect(query, SIGNAL(workDone()), this, SLOT(t1516QueryDone()));
	mQueryMngr->requestQuery(query);
	mT1516RequestedList.append(query);
}

void UpjongCodeUpdater::t1516QueryDone()
{
	QObject* sender = QObject::sender();
	if (sender != NULL) {
		T1516Query* query = qobject_cast<T1516Query*>(sender);
		if (query != NULL) {
			QList<TrItem*> itemList = query->getResult();
			createUpjongTable(query->upcode());
			foreach(TrItem *trItem, itemList) {
				T1516Item *item = qobject_cast<T1516Item *>(trItem);
				saveUpjongInfoToDB(query->upcode(), item->shcode(), item->hname());
			}
			mT1516RequestedList.removeOne(query);
			qCDebug(stockInfoUpdater)  << " t1516 - "<< mT1516RequestedList.size() <<" queries are left";
			if (mT1516RequestedList.size() == 0) {
				emit updateUpjongCodeDone();
			}
			query->deleteLater();
		}
	}
}

void UpjongCodeUpdater::createUpjongCodeTable()
{
	QSqlQuery query;
	query.prepare("CREATE TABLE IF NOT EXISTS UpjongCodeTable (upcode CHAR(3) UNIQUE PRIMARY KEY, hname VARCHAR(20), upjong_type INTEGER(1))");
	if (!query.exec()) {
		errorQuery(&query);
		return;
	}
	else {
		qCDebug(upjongCodeUpdater) << "UpjongCodeTable is created";
		return;
	}
}

void UpjongCodeUpdater::saveUpjongCodeToDB(const QString &upcode, const QString &hname)
{
	QSqlQuery qry;
	QString qryString = tr("SELECT COUNT(*) FROM UpjongCodeTable WHERE upcode='%1'").arg(upcode);
	qry.prepare(qryString);
	if (qry.exec()) {
		if (qry.next()) {
			if (qry.value(0).toInt() == 0) {
				UPJONG_TYPE upjongType = getUpjongType(upcode);
				qryString = tr("INSERT INTO UpjongCodeTable (upcode, hname, upjong_type) VALUES ('%1', '%2', %3)").arg(upcode).arg(hname).arg(static_cast<int>(upjongType));
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

void UpjongCodeUpdater::createUpjongTable(const QString &upcode)
{
	QSqlQuery query;
	query.prepare(tr("CREATE TABLE IF NOT EXISTS UpjongTable_%1 (shcode CHAR(6) UNIQUE PRIMARY KEY, hname VARCHAR(20))").arg(upcode));
	if (!query.exec()) {
		errorQuery(&query);
		return;
	}
	else {
		qCDebug(stockInfoUpdater) << "UpjongTable_" << upcode << " is created";
		return;
	}
}

void UpjongCodeUpdater::saveUpjongInfoToDB(const QString &upcode, const QString &shcode, const QString &hname)
{
	QSqlQuery qry;
	QString qryString = tr("SELECT COUNT(*) FROM UpjongTable_%1 WHERE shcode='%2'").arg(upcode).arg(shcode);
	qry.prepare(qryString);
	if (qry.exec()){
		if (qry.next()) {
			if (qry.value(0).toInt() == 0) {
				qryString = tr("INSERT INTO UpjongTable_%1 ( shcode, hname ) VALUES ( '%2', '%3')").arg(upcode).arg(shcode).arg(hname);
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

void UpjongCodeUpdater::errorQuery(QSqlQuery* query)
{
	qCWarning(upjongCodeUpdater) << "QueryError : " << query->lastError() << endl << query->executedQuery();
}

UPJONG_TYPE UpjongCodeUpdater::getUpjongType(const QString &upcode)
{
	int upcodeValue = upcode.toInt();
	if ((upcodeValue != 42) && (upcodeValue < 300)) {
		return KOSPI_UPJONG;
	} else if ((upcodeValue >= 300) && (upcodeValue<500)) {
		return KOSDAQ_UPJONG;
	} else if ((upcodeValue==42)||((upcodeValue >= 500) && (upcodeValue < 600))) {
		return SECTOR_UPJONG;
	} else {
		return SPECIAL_UPJONG;
	}
}

