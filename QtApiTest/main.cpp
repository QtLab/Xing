#include <QCoreApplication>
#include <QString>
#include <QObject>
#include <QDebug>
#include <windows.h>
#include "test/trtester.h"
#include "tr/t1102/t1102query.h"
#include "tr/t8430/t8430query.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    CoInitialize(NULL);

    TrTester tester;

    QObject::connect(&tester, &TrTester::testOver, &a, &QCoreApplication::quit);

    tester.start();
    T1102Query *t1102query = T1102Query::createQuery();
    T8430Query *t8430query = T8430Query::createQuery();
    tester.addQuery(t1102query);
    tester.addQuery(t8430query);

    tester.startTest();
    return a.exec();
}
