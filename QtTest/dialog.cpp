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
    m_api.Init();
}

bool Dialog::nativeEvent(const QByteArray & eventType, void * message, long * result){
    MSG *msg = static_cast<MSG *>( message );

    switch ( msg->message ){
        case WM_USER+XM_LOGIN:
            //LPCSTR pszCode = (LPCSTR)msg->wParam;
            //LPCSTR pszMsg = (LPCSTR)msg->lParam;

            const char * pszCode = (const char *)msg->wParam;
            const char * pszMsg = (const char *)msg->lParam;

            QString code = QString::fromLocal8Bit(pszCode);
            QString msg = QString::fromLocal8Bit(pszMsg);
            QString result = QString("code=%s, msg=%s").arg(code).arg(msg);

            QMessageBox::information(this, "Login",msg);
        break;
    }
    return false;
}
HWND Dialog::getWindowHandle() {
    return (HWND)winId();
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_testButton1_clicked()
{

    QString server = "demo.etrade.co.kr";
    BOOL result = m_api.Connect(getWindowHandle(), server.toLocal8Bit().constData(), 20001, WM_USER, 3000, 512);
    if(result) {
        QMessageBox::information(this, "Connection", "success");
    } else {
        QMessageBox::information(this, "Connection", "failed");
    }
}

void Dialog::on_testButton2_clicked()
{
    if(m_api.Disconnect()){
        QMessageBox::information(this, "Disconnect", "success");
    } else {
        QMessageBox::information(this, "Disconnect", "failed");
    }
}

void Dialog::on_testButton3_clicked()
{
    QString id = "seuki77";
    QString passwd = "folken77";
    QString certPwd = "";
    int type = 0;
    if(m_api.Login(getWindowHandle(), id.toLocal8Bit().constData(), passwd.toLocal8Bit().constData(), certPwd.toLocal8Bit().constData(),0, FALSE)){
        QMessageBox::information(this, "Login", "request success");
    } else {
        QMessageBox::information(this, "Login", "request failed");
    }
}
