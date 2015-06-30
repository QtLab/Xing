#include "logindialog.h"
#include "ui_logindialog.h"
#include <QMessageBox>
#include <QComboBox>
LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    loadSettings();
    connect(&m_session, &XASession::LoginResult, this, &LoginDialog::onLogin);

}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::onLogin(bool success, const QString &msg)
{
    if(success) {
        QMessageBox::information(this, "LoginResult", msg);
        done(QDialog::Accepted);
    } else {
        QMessageBox::warning(this, "Login Result", msg);
    }
}

void LoginDialog::on_connectBtn_clicked()
{
    saveSettings();
    QString id = ui->lineEditId->text();
    QString passwd = ui->lineEditPasswd->text();
    QString certPasswd = ui->lineEditCertPasswd->text();
    if(!m_session.ConnectServer(*this, !isDemoServer())){
        QMessageBox::warning(this, "Connect Server", "Failed");
        return;
    }

    if(!m_session.Login(*this, id, passwd, isDemoServer()?"":certPasswd)){
        QMessageBox::warning(this, "Login", "failed");
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
    bool saveId = mSettings.value(KEY_SAVE_ID, false).toBool();
    if(saveId) {
        mSettings.setValue(KEY_ID, id);
    }else {
        mSettings.remove(KEY_ID);
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

bool LoginDialog::nativeEvent(const QByteArray &eventType, void *message, long *result)
{
    MSG *msg = static_cast<MSG *>( message );

    switch ( msg->message ){
    case WM_USER+XM_LOGIN:
        {
            m_session.handleResponse(this, msg->wParam, msg->lParam);
            break;
        }
    }
    return false;
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
