#ifndef T8424QUERY_H
#define T8424QUERY_H

#include <QObject>
#include "tr/trquery.h"
#include "tr/t8424/t8424item.h"
#include "data/commontype.h"
class T8424Query : public TrQuery
{
    Q_OBJECT
    Q_PROPERTY(QString gubun MEMBER _gubun READ gubun WRITE setGubun)
public:
    ~T8424Query();
    static T8424Query *createQuery(MARKET_TYPE upType=ALL, QObject *parent = 0);

    void setGubun(const QString& gubun) {_gubun = gubun;}
    QString gubun() { return _gubun; }

    virtual QString toString() override;
    QList<T8424Item *> getResult();

protected:
    explicit T8424Query(QObject *parent = 0);
    virtual T8424Item *createItem() override;
signals:

public slots:
    virtual void onReceiveData(const QString& trCode);
    virtual void onReceiveChartRealData(const QString& trCode);

private:
    QString _gubun;
    QList<T8424Item *> mItemList;
};

#endif // T8424QUERY_H
