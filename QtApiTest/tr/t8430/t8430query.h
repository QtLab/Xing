#ifndef T8430QUERY_H
#define T8430QUERY_H

#include <QObject>
#include "tr/trquery.h"
#include "tr/t8430/t8430item.h"

class T8430Query : public TrQuery
{
    Q_OBJECT
    Q_PROPERTY(QString gubun MEMBER _gubun READ gubun WRITE setGubun)
public:
    static T8430Query *createQuery(const QString& gubun = tr("0"), QObject *parent = 0);
    ~T8430Query();

    void setGubun(const QString& gubun){ _gubun = gubun; }
    QString gubun() { return _gubun; }

    virtual QString toString() override;
    QList<T8430Item *> getResult();
protected:
    explicit T8430Query(QObject *parent = 0);
    virtual T8430Item *createItem() override;
signals:
public slots:
    virtual void onReceiveData(const QString& trCode);
    virtual void onReceiveChartRealData(const QString& trCode);
private:
    QString _gubun;
    QList<T8430Item *> mItemList;
};

#endif // T8430QUERY_H
