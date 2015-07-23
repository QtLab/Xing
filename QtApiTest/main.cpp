#include <QCoreApplication>
#include <QString>
#include <QObject>
#include <QDebug>
#include <windows.h>
#include "test/trtest.h"
#include "manager/querymngr.h"
#include "manager/loginmngr.h"
#include "util/logbrowser.h"


int main(int argc, char  *argv[])
{
    qSetMessagePattern("[%{time yyyyMMdd h:mm:ss.zzz} %{if-debug}D%{endif}%{if-warning}W%{endif}%{if-critical}C%{endif}%{if-fatal}F%{endif}] %{file}:%{line}:%{function} - %{message}");
    QCoreApplication a(argc, argv);
    CoInitialize(NULL);

    LoginMngr loginMngr;
    QueryMngr queryMngr;
    QObject::connect(&loginMngr, SIGNAL(notifyLogin(QString,QString)),&queryMngr, SLOT(start()));
    if(!loginMngr.requestLogin(QObject::tr("seuki77"), QObject::tr("folken77"),true)) {
        return -1;
    }
    TrTest test(&queryMngr);
    test.start();
    return a.exec();
}
