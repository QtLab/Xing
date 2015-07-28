#include <QApplication>
#include <QString>
#include <QObject>
#include <QDebug>
#include <QPointer>
#include "test/trtest.h"
#include "test/trteststockinfoupdater.h"
#include "manager/querymngr.h"
#include "manager/loginmngr.h"
#include "util/logbrowser.h"
#include "util/log.h"
#include "testdialog.h"
#include <stdlib.h>
#include <iostream>
QPointer<LogBrowser> logBrowser=NULL;
QtMessageHandler defaultHandler;
void messageOutput(QtMsgType type,const QMessageLogContext &context,const QString &msg) {
    if(strcmp(context.category, "default")==0){
        defaultHandler(type, context, msg);
        return;
    }
    if(logBrowser)
        logBrowser->outputMessage(type, context, msg);
}

int main(int argc, char  *argv[])
{
    QApplication a(argc, argv);
//    CoInitialize(NULL);
    defaultHandler = qInstallMessageHandler(messageOutput);
    logBrowser = new LogBrowser();
    TestDialog testDialog;
    testDialog.show();
    return a.exec();
}
