#include "logindialog.h"
#include "ui_logindialog.h"
#include <QMessageBox>
#include <QComboBox>
LoginDialog::LoginDialog(LoginMngr *loginMngr, QWidget *parent) :
    QDialog(parent),ui(new Ui::LoginDialog),mLoginMngr(loginMngr)
{
    ui->setupUi(this);
	loadServerAddr();
    connect(mLoginMngr, &LoginMngr::notifyLogin, this, &LoginDialog::onLogin);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::onLogin(const QString &szCode, const QString &szMsg)
{
    //disconnect(mLoginMngr, &LoginMngr::notifyLogin, this, &LoginDialog::onLogin);
    if(szCode=="0000") {
        QMessageBox::information(this, "Login", szMsg);
        done(QDialog::Accepted);
    } else {
        QMessageBox::warning(this, "Login", szMsg);
    }
}

void LoginDialog::on_connectBtn_clicked()
{
    saveSettings();
    QString id = ui->lineEditId->text();
    QString passwd = ui->lineEditPasswd->text();
    QString certPasswd = ui->lineEditCertPasswd->text();

    if(!mLoginMngr->requestLogin(id, passwd,isDemoServer()?"":certPasswd, isDemoServer())){
        showErrorDialog("Login");
        return;
    }
}

void LoginDialog::on_closeBtn_clicked()
{
    saveSettings();
    done(QDialog::Rejected);
}

void LoginDialog::saveSettings()
{
    QString id = ui->lineEditId->text();
    QString passwd = ui->lineEditPasswd->text();
    bool saveId = mSettings.value(KEY_SAVE_ID, false).toBool();
    if(saveId) {
		if (isDemoServer())
		{
			mSettings.setValue(KEY_DEMO_ID, id);
			mSettings.setValue(KEY_DEMO_PASSWD, passwd);
		} else
		{
			mSettings.setValue(KEY_REAL_ID, id);
			mSettings.setValue(KEY_REAL_PASSWD, passwd);
		}
    }else {
		if (isDemoServer())
		{
			mSettings.remove(KEY_DEMO_ID);
			mSettings.remove(KEY_DEMO_PASSWD);
		} else
		{
			mSettings.remove(KEY_REAL_ID);
			mSettings.remove(KEY_REAL_PASSWD);
		}
    }
    QString serverType = ui->comboBoxServerType->currentText();
    mSettings.setValue(KEY_SERVERTYPE, serverType);
    mSettings.sync();
}

void LoginDialog::loadSettings()
{
    bool saveId = mSettings.value(KEY_SAVE_ID, false).toBool();
    ui->checkBoxSaveId->setChecked(saveId);

    if(saveId) {
        QString id = mSettings.value(isDemoServer()?KEY_DEMO_ID:KEY_REAL_ID).toString();
        ui->lineEditId->setText(id);
        QString passwd = mSettings.value(isDemoServer()?KEY_DEMO_PASSWD:KEY_REAL_PASSWD).toString();
        ui->lineEditPasswd->setText(passwd);
    }
    if(isDemoServer()) {
        ui->lineEditCertPasswd->setEnabled(false);
    }
}

bool LoginDialog::isDemoServer()
{
    QString serverType = ui->comboBoxServerType->currentText();
    if(serverType=="demo.etrade.co.kr")
        return true;
    else
        return false;
}

void LoginDialog::loadServerAddr()
{
	QStringList serverList = mLoginMngr->getServerList();
    ui->comboBoxServerType->addItems(serverList);
    QString serverType = mSettings.value(KEY_SERVERTYPE, serverList.at(0)).toString();
    ui->comboBoxServerType->setCurrentText(serverType);
}

void LoginDialog::showErrorDialog(const QString &title)
{
    QMessageBox::warning(this, title, mLoginMngr->getLastErrorMsg());
    return;
}

void LoginDialog::on_comboBoxServerType_currentTextChanged(const QString &currentServer)
{
    if(currentServer=="demo.etrade.co.kr") {
        ui->lineEditCertPasswd->setEnabled(false);
    } else {
        ui->lineEditCertPasswd->setEnabled(true);
    }
	loadSettings();
}

void LoginDialog::on_checkBoxSaveId_stateChanged(int state)
{
    if(state == Qt::Checked) {
        mSettings.setValue(KEY_SAVE_ID, true);
    } else if(state==Qt::Unchecked) {
        mSettings.setValue(KEY_SAVE_ID, false);
    }
    mSettings.sync();
}
