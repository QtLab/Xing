#ifndef T8430QUERY_H
#define T8430QUERY_H

#include <QObject>
#include "tr/trquery.h"
class T8430Query : public TrQuery
{
    Q_OBJECT
public:
    explicit T8430Query(QObject *parent = 0);
    ~T8430Query();

signals:

public slots:
};

#endif // T8430QUERY_H
