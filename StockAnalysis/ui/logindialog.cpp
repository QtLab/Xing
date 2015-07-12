#include "logindialog.h"
#include "ui/ui_logindialog.h"
#include <QMessageBox>
#include <QComboBox>
LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog),m_session(this)
{
    ui->setupUi(this);
    m_session.Init();

    loadSettings();
    connect(&m_session, &XASession::onLogin, this, &LoginDialog::onLogin);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::onLogin(const QString &szCode, const QString &szMsg)
{
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
    if(!m_session.ConnectServer(isDemoServer())){
        showErrorDialog("ConnectServer");
        return;
    }

    if(!m_session.Login(id, passwd, isDemoServer()?"":certPasswd)){
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
        mSettings.setValue(KEY_ID, id);
        mSettings.setValue(KEY_PASSWD, passwd);
    }else {
        mSettings.remove(KEY_ID);
        mSettings.remove(KEY_PASSWD);
    }
    QString serverType = ui->comboBoxServerType->currentText();
    mSettings.setValue(KEY_SERVERTYPE, serverType);
    mSettings.sync();
}

void LoginDialog::loadSettings()
{
    QStringList serverList = m_session.GetServerList();
    ui->comboBoxServerType->addItems(serverList);
    QString serverType = mSettings.value(KEY_SERVERTYPE, serverList.at(0)).toString();
    ui->comboBoxServerType->setCurrentText(serverType);

    bool saveId = mSettings.value(KEY_SAVE_ID, false).toBool();
    ui->checkBoxSaveId->setChecked(saveId);

    if(saveId) {
        QString id = mSettings.value(KEY_ID).toString();
        ui->lineEditId->setText(id);
        QString passwd = mSettings.value(KEY_PASSWD).toString();
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

void LoginDialog::showErrorDialog(const QString &title)
{
    int errorCode = m_session.GetLastError();
    QMessageBox::warning(this, title, m_session.GetErrorMessage(errorCode));
    return;
}

void LoginDialog::on_comboBoxServerType_currentTextChanged(const QString &currentServer)
{
    if(currentServer=="demo.etrade.co.kr") {
        ui->lineEditCertPasswd->setEnabled(false);
    } else {
        ui->lineEditCertPasswd->setEnabled(true);
    }
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
