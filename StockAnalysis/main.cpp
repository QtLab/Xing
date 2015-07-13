#include "mainwindow.h"
#include <QApplication>
#include "ui/logindialog.h"
int main(int argc, char *argv[])
{
    bool withServer = true;
    QApplication a(argc, argv);
    QCoreApplication::setOrganizationName("foxbear");
    QCoreApplication::setApplicationName("FundamentalAnalysis");
    MainWindow w;
    if(withServer) {
        LoginDialog dialog;
        if(dialog.exec()==QDialog::Accepted) {
            w.show();
        }
    } else {
        w.show();
    }

    return a.exec();
}
