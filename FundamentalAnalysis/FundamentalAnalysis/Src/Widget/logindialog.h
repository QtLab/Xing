#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include "../../Src/xing/xasession.h"
namespace Ui {class LoginDialog;};

class LoginDialog : public QDialog
{
	Q_OBJECT

public:
	typedef enum  { LOGIN_SUCCESS = 0 ,LOGIN_CANCEL = 1 } LOGIN_RESULT;
public:
	LoginDialog(QWidget *parent = 0);
	~LoginDialog();

private slots:
	void on_loginButton_clicked();
private:
	Ui::LoginDialog *ui;

	XASession m_session;
};

#endif // LOGINDIALOG_H
