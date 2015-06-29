#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <QSettings>
#include "xing/xasession.h"

namespace Ui {
class LoginDialog;
}

#define KEY_SERVERTYPE "serverType"
#define KEY_SAVE_ID "isSaveId"
#define KEY_ID "id"

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = 0);
    ~LoginDialog();

private slots:
    void on_connectBtn_clicked();
    void on_closeBtn_clicked();
    void saveIdChecked(int);

private:
    Ui::LoginDialog *ui;
    XASession m_session;
    QSettings mSettings;

    void saveSettings();
    void loadSettings();
    bool isDemoServer();
protected:
    bool nativeEvent(const QByteArray & eventType, void * message, long * result);
};

#endif // LOGINDIALOG_H
