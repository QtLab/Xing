#ifndef T1102QUERY_H
#define T1102QUERY_H

#include <QObject>
#include <QString>
#include "tr/trquery.h"
class T1102Query : public TrQuery
{
    Q_OBJECT
public:
    static T1102Query *createQuery(const QString& shcode=tr("005930"), QObject *parent = 0);
    ~T1102Query();
    void setShcode(const QString& shcode);
protected:
    explicit T1102Query(QObject *parent = 0);

signals:

public slots:

private:
    QString mShcode;
};

#endif // T1102QUERY_H
