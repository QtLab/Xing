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
    T1102Query *query = T1102Query::createQuery();
    T8430Query *query = T8430Query::createQuery();
    tester.addQuery(query);

    tester.startTest();
    return a.exec();
}
