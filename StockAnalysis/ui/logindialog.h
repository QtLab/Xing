#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <QSettings>
#include "XingLib/xasession.h"

namespace Ui {
class LoginDialog;
}

#define KEY_SERVERTYPE "serverType"
#define KEY_SAVE_ID "isSaveId"
#define KEY_ID "id"
#define KEY_PASSWD "passwd"

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = 0);
    ~LoginDialog();

public slots:
    void onLogin(const QString &szCode, const QString &szMsg);

private slots:
    void on_connectBtn_clicked();
    void on_closeBtn_clicked();
    void on_comboBoxServerType_currentTextChanged(const QString &arg1);
    void on_checkBoxSaveId_stateChanged(int arg1);

private:
    Ui::LoginDialog *ui;
    XASession m_session;
    QSettings mSettings;

    void saveSettings();
    void loadSettings();
    bool isDemoServer();

    void showErrorDialog(const QString& title);
};

#endif // LOGINDIALOG_H
