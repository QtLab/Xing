#include "logindialog.h"
#include "ui_logindialog.h"

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    QStringList serverList = m_session.GetServerList();
    ui->comboBoxServerType->addItems(serverList);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_connectBtn_clicked()
{
    QString id = ui->lineEditId->text();
    QString passwd = ui->lineEditPasswd->text();
}

void LoginDialog::on_closeBtn_clicked()
{

}
