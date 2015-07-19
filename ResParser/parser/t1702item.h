#ifndef T1702ITEM
#define T1702ITEM

#include <QObject>
#include <QString>
#include <QDate>
#include "tr/tritem.h"
class T1702Item : public TrItem
{
	Q_OBJECT
	Q_PROPERTY(long cts_idx MEMBER _cts_idx READ cts_idx WRITE setCts_Idx)		//CTSIDX
	Q_PROPERTY(QString cts_date MEMBER _cts_date READ cts_date WRITE setCts_Date)		//CTSDATE
public:
	explicit T1702Item(QObject *parent=0);
	~T1702Item();
	virtual QString toString();
	long cts_idx() { return _cts_idx; }
	void setCts_Idx(long cts_idx) { _cts_idx = cts_idx; }
	QString cts_date() { return _cts_date; }
	void setCts_Date(QString cts_date) { _cts_date = cts_date; }
private:
	long _cts_idx;		//CTSIDX
	QString _cts_date;		//CTSDATE
};

#endif //T1702ITEM
