#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include "xing/xasession.h"

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = 0);
    ~LoginDialog();

private slots:
    void on_connectBtn_clicked();

    void on_closeBtn_clicked();

private:
    Ui::LoginDialog *ui;
    XASession m_session;
};

#endif // LOGINDIALOG_H
