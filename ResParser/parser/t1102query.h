#ifndef T1102QUERY
#define T1102QUERY

#include <QObject>
#include "tr/simpletrquery"
#include "tr/t1102/t1102item.h"
class T1102QueryQuery : public SimpleTrQuery
{
	Q_OBJECT
	Q_PROPERTY(QString shcode MEMBER _shcode READ shcode WRITE setShcode)		//단축코드
public:
	~T1102Query();
	QString shcode() { return _shcode; }
	void setShcode(QString shcode) { _shcode = shcode; }
protected:
	explicit T1102Query(QObject *parent=0);
	virtual T1102Item *createItem() override;
private:
	QString _shcode;		//단축코드
};
#endif
