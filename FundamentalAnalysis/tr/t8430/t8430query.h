#ifndef T8430QUERY_H
#define T8430QUERY_H

#include <QObject>
#include "tr/t8430/t8430.h"
#include "tr/t8430/t8430item.h"
#include "tr/trquery.h"

class T8430Query : public TrQuery
{
    Q_OBJECT
public:
    typedef enum { ALL=0, KOSPI, KOSDAQ } MODE;

    static T8430Query *createQuery(const QWidget* requester,MODE mode,QObject *parent = 0);

    MODE getMode(){ return mMode;}
    ~T8430Query();
protected:
    explicit T8430Query(const QWidget* requester,QObject *parent = 0);

private:
    MODE mMode;
signals:
    void workDone(QList<T8430Item*> list);
};

#endif // T8430QUERY_H
