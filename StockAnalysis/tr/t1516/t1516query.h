#ifndef T1516QUERY_H
#define T1516QUERY_H

#include <QObject>
#include "tr/trquery.h"
#include "tr/t1516/t1516item.h"
#include "data/commontype.h"
class T1516Query : public TrQuery
{
    Q_OBJECT
    Q_PROPERTY(QString upcode MEMBER _upcode READ upcode WRITE setUpcode)
    Q_PROPERTY(QString gubun MEMBER _gubun READ gubun WRITE setGubun)
    Q_PROPERTY(QString shcode MEMBER _shcode READ shcode WRITE setShcode)
public:
    ~T1516Query();
    static T1516Query *createQuery(const QString& upcode, MARKET_TYPE marketType, QObject *parent=0);

    void setUpcode(const QString &upcode) { _upcode = upcode; }
    QString upcode() { return _upcode; }

    void setGubun(const QString &gubun) { _gubun = gubun; }
    QString gubun() { return _gubun; }

    void setShcode(const QString &shcode) { _shcode = shcode; }
    QString shcode() { return _shcode; }

    virtual QString toString() override;
    QMap<QString, T1516Item *> getResult();
protected:
    explicit T1516Query(QObject *parent = 0);
    virtual T1516Item *createItem() override;
signals:
private:
    bool hasNextData();
public slots:
    virtual void onReceiveData(const QString& trCode);
    virtual void onReceiveChartRealData(const QString& trCode);

private:
    QString _upcode;
    QString _gubun;
    QString _shcode;
    QMap<QString, T1516Item*> mItemMap;
};

#endif // T1516QUERY_H
