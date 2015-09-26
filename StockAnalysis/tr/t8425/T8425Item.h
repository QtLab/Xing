#ifndef T8425ITEM_H
#define T8425ITEM_H

#include <QObject>
#include <QString>
#include "tr\tritem.h"
class T8425Item : public TrItem
{
	Q_OBJECT
	Q_PROPERTY(QString tmname MEMBER _tmname READ tmname WRITE setTmName)
	Q_PROPERTY(QString tmcode MEMBER _tmcode READ tmcode WRITE setTmCode)
public:
	explicit T8425Item(QObject *parent=0);
	~T8425Item();
	QString tmname() { return _tmname; }
	void setTmName(const QString &tmname) { _tmname = tmname; }
	QString tmcode() { return _tmcode;  }
	void setTmCode(const QString &tmcode) { _tmcode = tmcode; }

private:
	QString _tmname;		//테마명
	QString _tmcode;			//테마코드
};

#endif