#include "xingapitest.h"
#include "ui_xingapitest.h"
#include "xasession.h"
#include "xaquery.h"
#include <ActiveQt/QAxObject>

XingApiTest::XingApiTest(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::XingApiTest), xasession(new XASession(this))
{
   ui->setupUi(this);
    if(xasession->Init())
    {
        printLog(tr("XASession init success"));
        connect(xasession, SIGNAL(ReportEventLog(const QString&)), this, SLOT(onEventCallback(const QString&)));
        ui->loginButton->setEnabled(true);
    }else
    {
        printLog(tr("XASession init fail"));
    }
}
void XingApiTest::printLog(const QString & log)
{
    ui->logViewWidget->addItem(log);
}

void XingApiTest::onEventCallback(const QString& msg)
{
    printLog(tr("Event callback : ")+msg);
}

void XingApiTest::on_loginButton_clicked()
{
    printLog(tr("Login"));
    ui->logoutButton->setEnabled(true);
    ui->loginButton->setEnabled(false);
    //doLogin();
    if(xasession->ConnectServer(tr("Hts.etrade.co.kr"), 20001))
    {
        printLog(tr("connect server success"));
    }else
    {
        printLog(tr("connect server fail"));
        return;
    }


    if(xasession->Login(tr("seuki77"),tr("folken77"), tr("dudnrha2010"),0,true))
    {
        printLog(tr("login success"));
    }
    else{
        printLog(tr("login fail"));
        int errorcode = xasession->GetLastError();
        printLog(tr("error code : %1").arg(errorcode));
        //printLog(xasession->GetErrorMessage(errorcode));

    }
}
void XingApiTest::on_logoutButton_clicked()
{
    ui->logViewWidget->addItem(tr("Logout"));
    ui->logoutButton->setEnabled(false);
    ui->loginButton->setEnabled(true);
    //doLogout();
    if(xasession->Logout())
        printLog(tr("Logout success"));
    else
        printLog(tr("Logout fail"));
}

void XingApiTest::on_dumpButton_clicked()
{
//    XAQuery* query = XAQuery::getTransactionQuery(tr("t1102.res"),this);
//    if(query->init())
//        printLog(tr("XAQuery init success"));
//    else
//        printLog(tr("XAQuery init fail"));

//    query->SetFieldData(tr("t1102InBlock"), tr("shcode"), 0,tr("000270") );
//    query->Request(false);
//    connect(query, SIGNAL(ReceiveMessage()), this, SLOT(onReceiveMsg()));
//    xaquery = query;
    QAxObject* object = new QAxObject("XA_DataSet.XAReal");
    ui->textBrowser->setText(object->generateDocumentation());
}

void XingApiTest::onReceiveMsg()
{
//    printLog(tr("GetFieldData : ")+xaquery->GetFieldData(tr("t1102OutBlock"),tr("hname"),0));
//    delete xaquery;
}

XingApiTest::~XingApiTest()
{
    delete ui;
}
