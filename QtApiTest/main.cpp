#include <QCoreApplication>
#include <QString>
#include <QObject>
#include <QDebug>
#include <windows.h>
#include "test/trtester.h"
#include "tr/t1102/t1102query.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    CoInitialize(NULL);

    TrTester tester;

    QObject::connect(&tester, &TrTester::testOver, &a, QCoreApplication::close());

    T1102Query *query = T1102Query::createQuery();

    tester.addQuery(query);

    return a.exec();
}
