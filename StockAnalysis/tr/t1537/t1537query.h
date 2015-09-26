#ifndef T1537QUERY_H
#define T1537QUERY_H

#include <QObject>
#include <QList>
#include "tr/ctstrquery.h"
#include "tr/t1537/t1537item.h"
class T1537Query : public CtsTrQuery
{
	Q_OBJECT
	Q_PROPERTY(QString tmcode MEMBER _tmcode READ tmcode WRITE setTmcode)
	Q_PROPERTY(long upcnt MEMBER _upcnt READ upcnt WRITE setUpCnt)
	Q_PROPERTY(long tmcnt MEMBER _tmcnt READ tmcnt WRITE setTmCnt)
	Q_PROPERTY(long uprate MEMBER _uprate READ uprate WRITE setUpRate)
	Q_PROPERTY(QString tmname MEMBER _tmname READ tmname WRITE setTmName)

public:
	~T1537Query();
	static T1537Query *createQuery(const QString &tmcode, QObject *parent = 0);

	void setTmcode(const QString &tmcode) { _tmcode = tmcode; }
	QString tmcode() { return _tmcode; }

	void setUpCnt(long upcnt) { _upcnt = upcnt; }
	long upcnt() { return _upcnt; }

	void setTmCnt(long tmcnt) { _tmcnt = tmcnt; }
	long tmcnt() { return _tmcnt; }

	void setUpRate(long uprate) { _uprate = uprate; }
	long uprate() { return _uprate; }

	void setTmName(const QString &tmname) { _tmname = tmname; }
	QString tmname() { return _tmname; }

protected:
	explicit T1537Query(QObject *parent = 0);
	virtual T1537Item *createItem() override;

private:
	//InBlockField
	QString _tmcode;

	//OutBlockField [START]
	long _upcnt;
	long _tmcnt;
	long _uprate;
	QString _tmname;
	//OutBlockField [END]
};

#endif // T1537QUERY_H
