#include <QApplication>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QPointer>
#include <QThread>
#include "mainwindow.h"
#include "ui/logindialog.h"
#include "util/logbrowser.h"
#include "util/log.h"
#include "XingLib/xasession.h"

QPointer<LogBrowser> logBrowser=NULL;
QtMessageHandler defaultHandler;

void messageOutput(QtMsgType type,const QMessageLogContext &context,const QString &msg) {
    if(logBrowser)
        logBrowser->outputMessage(type, context, QObject::tr("[thread-%1]").arg((long)QThread::currentThreadId())+msg);
}
void initDatabaseConnection() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("192.168.219.250");
    db.setDatabaseName("XingDB");
    db.setUserName("seuki77");
    db.setPassword("folken77");
    if(!db.open()) {
        qCDebug(Main)<<db.lastError();
        qCDebug(Main)<<"Failed to connect";
    } else {
        qCDebug(Main)<<"Database Connected";
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    defaultHandler = qInstallMessageHandler(messageOutput);
    logBrowser = new LogBrowser();

    QCoreApplication::setOrganizationName("foxbear");
    QCoreApplication::setApplicationName("FundamentalAnalysis");

    initDatabaseConnection();
    XASession xasession;
    LoginMngr loginMngr = LoginMngr(&xasession);
    MainWindow *w;
    LoginDialog dialog(&loginMngr);
    if(dialog.exec()==QDialog::Accepted) {
        w = new MainWindow(&loginMngr);
        w->show();
    }

    return a.exec();
}
