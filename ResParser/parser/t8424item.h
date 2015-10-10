#ifndef T8424ITEM
#define T8424ITEM

#include <QObject>
#include <QString>
#include <QDate>
#include "tr/tritem.h"
class T8424Item : public TrItem
{
	Q_OBJECT
	Q_PROPERTY(QString hname MEMBER _hname READ hname WRITE setHname)		//업종명
	Q_PROPERTY(QString upcode MEMBER _upcode READ upcode WRITE setUpcode)		//업종코드
public:
	explicit T8424Item(QObject *parent=0);
	~T8424Item();
	QString hname() { return _hname; }
	void setHname(QString hname) { _hname = hname; }
	QString upcode() { return _upcode; }
	void setUpcode(QString upcode) { _upcode = upcode; }
private:
	QString _hname;		//업종명
	QString _upcode;		//업종코드
};

#endif //T8424ITEM
