#ifndef T1516QUERY
#define T1516QUERY

#include <QObject>
#include "tr/ctstrquery"
#include "tr/t1516/t1516item.h"
class T1516Query : public CtsTrQuery
{
	Q_OBJECT
	Q_PROPERTY(QString upcode MEMBER _upcode READ upcode WRITE setUpcode)		//업종코드
	Q_PROPERTY(QString gubun MEMBER _gubun READ gubun WRITE setGubun)		//구분
	Q_PROPERTY(QString shcode MEMBER _shcode READ shcode WRITE setShcode)		//종목코드
	Q_PROPERTY(QString shcode MEMBER _shcode READ shcode WRITE setShcode)		//종목코드
	Q_PROPERTY(float pricejisu MEMBER _pricejisu READ pricejisu WRITE setPricejisu)		//지수
	Q_PROPERTY(QString sign MEMBER _sign READ sign WRITE setSign)		//전일대비구분
	Q_PROPERTY(float change MEMBER _change READ change WRITE setChange)		//전일대비
	Q_PROPERTY(float jdiff MEMBER _jdiff READ jdiff WRITE setJdiff)		//등락율
public:
	~T1516Query();
	QString upcode() { return _upcode; }
	void setUpcode(QString upcode) { _upcode = upcode; }
	QString gubun() { return _gubun; }
	void setGubun(QString gubun) { _gubun = gubun; }
	QString shcode() { return _shcode; }
	void setShcode(QString shcode) { _shcode = shcode; }
	QString shcode() { return _shcode; }
	void setShcode(QString shcode) { _shcode = shcode; }
	float pricejisu() { return _pricejisu; }
	void setPricejisu(float pricejisu) { _pricejisu = pricejisu; }
	QString sign() { return _sign; }
	void setSign(QString sign) { _sign = sign; }
	float change() { return _change; }
	void setChange(float change) { _change = change; }
	float jdiff() { return _jdiff; }
	void setJdiff(float jdiff) { _jdiff = jdiff; }
protected:
	explicit T1516Query(QObject *parent=0);
	virtual T1516Item *createItem() override;
private:
	//InBlock Field [START]
	QString _upcode;		//업종코드
	QString _gubun;		//구분
	QString _shcode;		//종목코드
	//InBlock Field [END]
	//OutBlock Field [START]
	QString _shcode;		//종목코드
	float _pricejisu;		//지수
	QString _sign;		//전일대비구분
	float _change;		//전일대비
	float _jdiff;		//등락율
	//OutBlock Field [END]
};
#endif
