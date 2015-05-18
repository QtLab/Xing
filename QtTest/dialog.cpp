#include "dialog.h"
#include "ui_dialog.h"
#include <QLibrary>
#include <QWindow>
#include <qt_windows.h>
#include <qpa/qplatformnativeinterface.h>
#include <QMessageBox>

//IXingAPI api;
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    QStringList serverList = m_session.GetServerList();
    ui->serverSelection->addItems(serverList);

    m_queryMngr.start();
}

bool Dialog::nativeEvent(const QByteArray & eventType, void * message, long * result){
    MSG *msg = static_cast<MSG *>( message );

    switch ( msg->message ){
    case WM_USER+XM_LOGIN:
    {
        //LPCSTR pszCode = (LPCSTR)msg->wParam;
        //LPCSTR pszMsg = (LPCSTR)msg->lParam;

        const char * pszCode = (const char *)msg->wParam;
        const char * pszMsg = (const char *)msg->lParam;

        QString code = QString::fromLocal8Bit(pszCode);
        QString msg = QString::fromLocal8Bit(pszMsg);
        //QString result = QString("code=%s, msg=%s").arg(code).arg(msg);

        QMessageBox::information(this, "Login",msg);
        break;
    }
    case WM_USER+XM_RECEIVE_DATA:
        m_queryMngr.handleResponse(msg->wParam, msg->lParam);
        break;
    }
    return false;
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_connectBtn_clicked()
{
    QString id = ui->idInput->text();
    QString passwd = ui->passwdInput->text();
    QString serverAddr = ui->serverSelection->currentText();
    bool isRealServer = false;
    if(!serverAddr.compare("hts.etrade.co.kr",Qt::CaseInsensitive)){
        isRealServer = true;
    } else {
        isRealServer = false;
    }
    if(!m_session.ConnectServer(*this, isRealServer)){
        QMessageBox::warning(this, "Connect Server", "failed");
    }
    if(!m_session.Login(*this, id, passwd, ui->certpwInput->text())){
        QMessageBox::warning(this, "Login", "failed");
    }
}
