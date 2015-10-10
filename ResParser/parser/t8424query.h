#ifndef T8424QUERY
#define T8424QUERY

#include <QObject>
#include "tr/blocktrquery"
#include "tr/t8424/t8424item.h"
class T8424Query : public BlockTrQuery
{
	Q_OBJECT
	Q_PROPERTY(QString gubun1 MEMBER _gubun1 READ gubun1 WRITE setGubun1)		//구분1
public:
	~T8424Query();
	QString gubun1() { return _gubun1; }
	void setGubun1(QString gubun1) { _gubun1 = gubun1; }
protected:
	explicit T8424Query(QObject *parent=0);
	virtual T8424Item *createItem() override;
private:
	QString _gubun1;		//구분1
};
#endif
