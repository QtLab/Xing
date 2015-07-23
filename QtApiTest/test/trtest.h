#ifndef TRTEST_H
#define TRTEST_H
#include <QObject>
#include "manager/querymngr.h"
#include "tr/t1102/t1102query.h"
#include "tr/t1702/t1702query.h"
#include "tr/t8430/t8430query.h"
class TrTest : public QObject
{
    Q_OBJECT
public:
    explicit TrTest(QueryMngr* queryMngr, QObject *parent = 0);
    ~TrTest();
    void start();
public slots:
    void testDone();
private:
    void handleT1102Result(T1102Query *query);
    void handleT8430Result(T8430Query *query);
    void handleT1702Result(T1702Query *query);
private :
    QueryMngr* mQueryMngr;
};

#endif // TRTEST_H
