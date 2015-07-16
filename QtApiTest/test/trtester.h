#ifndef TRTESTER_H
#define TRTESTER_H

#include <QObject>
#include "tr/trquery.h"
class TrTester : public QObject
{
    Q_OBJECT
public:
    explicit TrTester(QObject *parent = 0);
    ~TrTester();
    void addQuery(TrQuery* query);
signals:
    void testOver();
public slots:

private:

};

#endif // TRTESTER_H
