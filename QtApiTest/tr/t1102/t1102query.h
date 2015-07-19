#ifndef T1102QUERY_H
#define T1102QUERY_H

#include <QObject>
#include <QString>
#include "tr/trquery.h"
#include "tr/t1102/t1102item.h"
class T1102Query : public TrQuery
{
    Q_OBJECT
    Q_PROPERTY(QString shcode MEMBER _shcode READ shcode WRITE setShcode)
public:
    static T1102Query *createQuery(const QString& _shcode=tr("005930"), QObject *parent = 0);
    ~T1102Query();

    void setShcode(const QString& _shcode);
    QString shcode();

    virtual QString toString() override;
protected:
    explicit T1102Query(QObject *parent = 0);
    virtual T1102Item *createItem() override;
signals:
    void queryDone(T1102Item* item);
public slots:

    virtual void onReceiveData(const QString& trCode);
    virtual void onReceiveChartRealData(const QString& trCode);
private:
    QString _shcode;
};

#endif // T1102QUERY_H
