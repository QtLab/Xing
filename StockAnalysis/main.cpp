#include "mainwindow.h"
#include <QApplication>
#include "ui/logindialog.h"
#include "util/logbrowser.h"
#include "manager/loginmngr.h"
QPointer<LogBrowser> logBrowser;

void messageOutput(QtMsgType type,const QMessageLogContext &context,const QString &msg) {
    if(logBrowser)
        logBrowser->outputMessage(type, context, msg);
}
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qInstallMessageHandler(messageOutput);

    QCoreApplication::setOrganizationName("foxbear");
    QCoreApplication::setApplicationName("FundamentalAnalysis");
    MainWindow w;
    LoginMngr loginMngr;
    LoginDialog dialog(&loginMngr);
    if(dialog.exec()==QDialog::Accepted) {
        w.show();
    }

    return a.exec();
}
