#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <QSettings>
#include "core/xing/xasession.h"
#include "service/login/loginmngr.h"
namespace Ui {
class LoginDialog;
}

#define KEY_SERVERTYPE "serverType"
#define KEY_SAVE_ID "isSaveId"
#define KEY_DEMO_ID "demo_id"
#define KEY_DEMO_PASSWD "demo_passwd"
#define KEY_REAL_ID "real_id"
#define KEY_REAL_PASSWD "real_passwd"

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(LoginMngr *loginMngr, QWidget *parent = 0);
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
    QSettings mSettings;

    void saveSettings();
    void loadSettings();
    bool isDemoServer();
	void loadServerAddr();
    void showErrorDialog(const QString& title);
private:
    LoginMngr *mLoginMngr;
};

#endif // LOGINDIALOG_H
