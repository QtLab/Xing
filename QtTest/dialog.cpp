#include "dialog.h"
#include "ui_dialog.h"
#include <QLibrary>
#include <QWindow>
#include <qt_windows.h>
#include <qpa/qplatformnativeinterface.h>
#include <QMessageBox>
#include <QDebug>
#include "view/resultdialog.h"
#define MODE_ALL 0
#define MODE_KOSPI 1
#define MODE_KOSDAQ 2
#define MODE_ONE 3

//IXingAPI api;
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    QStringList serverList = m_session.GetServerList();
    ui->serverSelection->addItems(serverList);
    ui->buttonGroup->setId(ui->radioBtn_all,MODE_ALL);
    ui->buttonGroup->setId(ui->radioBtnKospi,MODE_KOSPI);
    ui->buttonGroup->setId(ui->radioBtnKosdaq,MODE_KOSDAQ);
    ui->buttonGroup->setId(ui->radioBtn_one, MODE_ONE);
    ui->radioBtn_all->setChecked(true);
    ui->runBtn->setEnabled(false);
    ui->idInput->setText("seuki77");
    ui->passwdInput->setText("folken77");

    connect(this, &Dialog::finished, this, &Dialog::onFinished);
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

        QMessageBox::information(this, "LoginMsg",msg);
        break;
    }
    case WM_USER+XM_RECEIVE_DATA:
        m_queryMngr.handleResponse(msg->wParam, msg->lParam);
        break;
    }
    return false;
}

void Dialog::closeEvent(QCloseEvent *event)
{
    qDebug()<<"closeEvent";
    if(clearResource()){
        event->accept();
    } else {
        event->ignore();
        QApplication::sendEvent(this,new QCloseEvent());
    }
}

void Dialog::showResult(QList<TrItem *> list)
{
    ResultDialog* dialog = new ResultDialog(this);
    dialog->setData(list);
    dialog->show();
}

void Dialog::t8430result(QList<T8430Item*> list)
{
    QList<TrItem*> itemList;

    foreach(T8430Item* item, list){
        itemList.append(item);
    }
    list.clear();
    showResult(itemList);


}

void Dialog::t1702result(QList<T1702Item *> list)
{
    QList<TrItem*> itemList;

    foreach(T1702Item* item, list){
        itemList.append(item);
    }
    list.clear();
    showResult(itemList);
}

void Dialog::onFinished(int result)
{
    qDebug()<<"onFinished";
    clearResource();
}

Dialog::~Dialog()
{
    delete ui;
}

bool Dialog::clearResource()
{
    if(m_queryMngr.isRunning()) {
        qDebug()<<"Thread is still running";
        m_queryMngr.exit();
        m_session.DisconnectServer();
        if(m_queryMngr.wait(5000)) {
            qDebug()<<"Thread is finished";
            return true;
        } else {
            qDebug()<<"Thread is not finished in 5s";
            return false;
        }
    }
    return true;
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
        return;
    }
    if(!m_session.Login(*this, id, passwd, ui->certpwInput->text())){
        QMessageBox::warning(this, "Login", "failed");
        return;
    }
    ui->runBtn->setEnabled(true);
}

void Dialog::on_runBtn_clicked()
{
/*
    if((ui->buttonGroup->checkedId()==MODE_ONE)&&(ui->shcodeInput->text().count()==0)){
        QMessageBox::warning(this, "Run","Input shcode");
        return;
    }
    T8430Query* query = T8430Query::createQuery(this, T8430Query::ALL);
    connect(query, &T8430Query::workDone,this,&Dialog::t8430result);
    m_queryMngr.requestQuery(query);
*/
    QDate fromdt(2015,5,1);
    QDate todt(2015,5,29);
    T1702Query* query = T1702Query::createQuery(this, "005930", fromdt, todt, T1702Query::QUANTITY, T1702Query::NET_BUY, T1702Query::DAILY);
    connect(query, &T1702Query::workDone, this, &Dialog::t1702result);
    m_queryMngr.requestQuery(query);
}
