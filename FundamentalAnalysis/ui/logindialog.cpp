#include "logindialog.h"
#include "ui_logindialog.h"

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    loadSettings();
    connect(ui->checkBoxSaveId, &QCheckBox::stateChanged, this, &LoginDialog::saveIdChecked);

}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_connectBtn_clicked()
{
    String id = ui->lineEditId->text();
    String passwd = ui->lineEditPasswd->text();
    String certPasswd = ui->lineEditCertPasswd->text();
    if(!m_session.ConnectServer(*this, !isDemoServer())){
        QMessageBox::warning(this, "Connect Server", "Failed");
        return;
    }

    if(!m_session.Login(*this, id, passwd, isDemoServer()?"":certPasswd)){
        QMessageBox::warning(this, "Login", "failed");
        return;
    }


    saveSettings();
    done(QDialog::Accepted);
}

void LoginDialog::on_closeBtn_clicked()
{
    saveSettings();
    done(QDialog::Rejected);
}

void LoginDialog::saveIdChecked(int state)
{
    if(state == Qt::Checked) {
        mSettings.setValue(KEY_SAVE_ID, true);
    } else if(state==Qt::Unchecked) {
        mSettings.setValue(KEY_SAVE_ID, false);
    }
    mSettings.sync();
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
