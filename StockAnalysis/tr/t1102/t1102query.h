#ifndef T1102QUERY_H
#define T1102QUERY_H

#include <QObject>
#include <QString>
#include "tr/simpletrquery.h"
#include "tr/t1102/t1102item.h"
class T1102Query : public SimpleTrQuery
{
    Q_OBJECT
    Q_PROPERTY(QString shcode MEMBER _shcode READ shcode WRITE setShcode)

public:
    static T1102Query *createQuery(const QString& _shcode=tr("005930"), QObject *parent = 0);
    ~T1102Query();
    void setShcode(const QString& _shcode);
    QString shcode();

protected:
    explicit T1102Query(QObject *parent = 0);
    virtual T1102Item *createItem() override;

private:
    QString _shcode;
};

#endif // T1102QUERY_H
