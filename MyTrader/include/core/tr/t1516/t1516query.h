#ifndef T1516QUERY_H
#define T1516QUERY_H

#include <QObject>
#include "core/tr/ctstrquery.h"
#include "common/type/commontype.h"
#include "core/tr/t1516/t1516item.h"
class T1516Query : public CtsTrQuery
{
    Q_OBJECT
    Q_PROPERTY(QString upcode MEMBER _upcode READ upcode WRITE setUpcode)
    Q_PROPERTY(QString gubun MEMBER _gubun READ gubun WRITE setGubun)
    Q_PROPERTY(QString shcode MEMBER _shcode READ shcode WRITE setShcode)

	Q_PROPERTY(float pricejisu MEMBER _pricejisu READ pricejisu WRITE setPricejisu)
	Q_PROPERTY(QString sign MEMBER _sign READ sign WRITE setSign)
	Q_PROPERTY(float change MEMBER _change READ change WRITE setChange)
	Q_PROPERTY(float jdiff MEMBER _jdiff READ jdiff WRITE setJdiff)
public:
    ~T1516Query();
    static T1516Query *createQuery(const QString& upcode, MARKET_TYPE marketType, QObject *parent=0);

    void setUpcode(const QString &upcode) { _upcode = upcode; }
    QString upcode() { return _upcode; }

    void setGubun(const QString &gubun) { _gubun = gubun; }
    QString gubun() { return _gubun; }

    void setShcode(const QString &shcode) { _shcode = shcode; }
    QString shcode() { return _shcode; }

	void setPricejisu(float priceJisu) { _pricejisu = priceJisu; }
	float pricejisu() { return _pricejisu; }

	void setSign(const QString &sign) { _sign = sign; }
	QString sign() { return _sign; }

	void setChange(float change) { _change = change; }
	float change() { return _change; }

	void setJdiff(float jdiff) { _jdiff = jdiff; }
	float jdiff() { return _jdiff; }
protected:
    explicit T1516Query(QObject *parent = 0);
    virtual T1516Item *createItem() override;

private:

	//InBlockField [START]
    QString _upcode;
    QString _gubun;
    QString _shcode;
	//InBlockField [END]

	//OutBlockField [START]
	float _pricejisu;
	QString _sign;
	float _change;
	float _jdiff;
	//OutBlockField [END]
};

#endif // T1516QUERY_H
