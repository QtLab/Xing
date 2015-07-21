#include <QCoreApplication>
#include <QString>
#include <QObject>
#include <QDebug>
#include <windows.h>
#include <QMetaObject>
#include <QThread>
#include "test/trtester.h"
#include "tr/t1102/t1102query.h"
#include "tr/t8430/t8430query.h"
#include "tr/t1702/t1702query.h"
#include "tr/t1702/t1702item.h"
#include "manager/querymngr.h"
int main(int argc, char  *argv[])
{
    qSetMessagePattern("[%{time yyyyMMdd h:mm:ss.zzz t} %{if-debug}D%{endif}%{if-info}I%{endif}%{if-warning}W%{endif}%{if-critical}C%{endif}%{if-fatal}F%{endif}] %{file}:%{line} - %{message}");
    QCoreApplication a(argc, argv);
    CoInitialize(NULL);

    /*
    TrTester tester;

    QObject::connect(&tester, &TrTester::testOver, &a, &QCoreApplication::quit);

    tester.start();
    T1102Query *t1102query = T1102Query::createQuery();
    T8430Query *t8430query = T8430Query::createQuery();
    T1702Query *t1702query = T1702Query::createQuery();
    tester.addQuery(t1102query);
    tester.addQuery(t8430query);
    tester.addQuery(t1702query);

    tester.startTest();
    */
    QueryMngr mngr;
    return a.exec();
}
