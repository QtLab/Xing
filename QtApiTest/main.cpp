#include <QApplication>
#include <QObject>
#include <QPointer>
#include <QThread>
#include "util/logbrowser.h"
#include "util/log.h"
#include "testdialog.h"
#include <stdlib.h>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include "tr/t1102/t1102query.h"

QPointer<LogBrowser> logBrowser=NULL;
QtMessageHandler defaultHandler;
void messageOutput(QtMsgType type,const QMessageLogContext &context,const QString &msg) {
    if(logBrowser)
        logBrowser->outputMessage(type, context, QObject::tr("[thread-%1]").arg((long)QThread::currentThreadId())+msg);
}

int main(int argc, char  *argv[])
{
    QApplication a(argc, argv);
//    CoInitialize(NULL);
    defaultHandler = qInstallMessageHandler(messageOutput);
    logBrowser = new LogBrowser();

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("192.168.219.250");
    db.setDatabaseName("XingDB");
    db.setUserName("seuki77");
    db.setPassword("folken77");
    if(!db.open()) {
        qCDebug(Main)<<db.lastError();
        qCDebug(Main)<<"Failed to connect";
    }else {
        qCDebug(Main)<<"Database Connected";
    }
    TestDialog testDialog;
    testDialog.show();
    return a.exec();
}
