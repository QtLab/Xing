#include "mainwindow.h"
#include "ui/logindialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    LoginDialog dialog;
    MainWindow w;
    if(dialog.exec()==QDialog::Accepted) {
        w.show();
    }
    return a.exec();
}
