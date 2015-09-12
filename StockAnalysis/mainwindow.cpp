#include <QDebug>
#include <QMessageBox>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui/upcodeselectiondialog.h"
#include "ui/shcodeselectiondialog.h"
#include "util/xingutil.h"
#include "util/log.h"
MainWindow::MainWindow(LoginMngr *loginMngr, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), mStockInfoUpdater(&mQueryMngr), mMovementUpdater(&mQueryMngr),mLoginMngr(loginMngr)
{
    ui->setupUi(this);
    initAction();
    initMenu();
    mQueryMngr.start();
    connect(&mMovementUpdater, SIGNAL(updateDone()), this, SLOT(onMovementUpdated()));
    connect(mLoginMngr, SIGNAL(notifyLogin(QString,QString)), this, SLOT(onLogin()));
    connect(mLoginMngr, SIGNAL(notifyLogout()), this, SLOT(onLogout()));
    connect(mLoginMngr, SIGNAL(notifyDisconnect()), this, SLOT(onDisconnectServer()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onStockInfoUpdated()
{
    QMessageBox::information(this, qkor("StockInfo 업데이트"), qkor("업데이트 완료"));
}

void MainWindow::onUpjongCodeUpdated()
{
    QMessageBox::information(this, qkor("업종코드 업데이트"), qkor("업데이트 완료"));
}

void MainWindow::onMovementUpdated()
{
    QMessageBox::information(this, qkor("수급정보 업데이트"), qkor("업데이트 완료"));
}

void MainWindow::onDisconnectServer()
{
    qCDebug(mainWindow)<<qkor("서버와의 연결이 종료되었습니다.");
}

void MainWindow::onLogin()
{
    QMessageBox::information(this, qkor("로그인"), qkor("성공"));
}

void MainWindow::onLogout()
{
    qCDebug(mainWindow)<<qkor("로그아웃 되었습니다.");
}

void MainWindow::ReportEventLog(const QString &log)
{
    qCDebug(mainWindow)<<qkor("Xing 모듈로부터의 이벤트 - ")<<log;
}

void MainWindow::requestMovementUpdateByUpcode()
{
    UpCodeSelectionDialog dialog(&mQueryMngr);
    if(dialog.exec() == QDialog::Accepted){
        QList<QString> upCodeList = dialog.getUpcodeList();
        mMovementUpdater.updateByUpcodeList(upCodeList);
    }
}

void MainWindow::requestMovementUpdateByShcode()
{
    ShcodeSelectionDialog dialog(&mQueryMngr);
    dialog.exec();
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    qCDebug(mainWindow)<<"closeEvent";
}

void MainWindow::initAction()
{
    //StockInfo Update Action [START]
    mStockInfoUpdateAction = new QAction(qkor("StockInfo 업데이트"), this);
    connect(mStockInfoUpdateAction, &QAction::triggered, &mStockInfoUpdater,&StockInfoUpdater::updateStockInfo);
    connect(&mStockInfoUpdater, &StockInfoUpdater::updateStockInfoDone, this, &MainWindow::onStockInfoUpdated);
    //StockInfo Update Action [END]

    //Movement Update Action by Upcode [START]
    mMovementUpdateByUpcodeAction = new QAction(qkor("수급정보 업데이트(업종)"), this);
    connect(mMovementUpdateByUpcodeAction, &QAction::triggered, this, &MainWindow::requestMovementUpdateByUpcode);
    connect(&mMovementUpdater, &MovementUpdater::updateDone, this, &MainWindow::onMovementUpdated);
    //Movement Update Action by Upcode [END]

    //Movement Update Action by Shcode [START]
    mMovementUpdateByShcodeAction = new QAction(qkor("수급정보 업데이트(종목)"), this);
    connect(mMovementUpdateByShcodeAction, &QAction::triggered, this, &MainWindow::requestMovementUpdateByShcode);
    //Movement Update Action by Shcode [START]

    //UpjongCode Update Action [START]
    mUpjongCodeUpdateAction = new QAction(qkor("업종코드 업데이트"), this);
    connect(mUpjongCodeUpdateAction, &QAction::triggered,&mStockInfoUpdater, &StockInfoUpdater::updateUpjongCode);
    connect(&mStockInfoUpdater, &StockInfoUpdater::updateUpjongCodeDone, this, &MainWindow::onUpjongCodeUpdated);
    //UpjongCode Update Action [END]
}

void MainWindow::initMenu()
{
    m_pUpdateMenu = menuBar()->addMenu(tr("Update"));
    m_pUpdateMenu->addAction(mStockInfoUpdateAction);
    m_pUpdateMenu->addAction(mUpjongCodeUpdateAction);
    m_pUpdateMenu->addAction(mMovementUpdateByUpcodeAction);
    m_pUpdateMenu->addAction(mMovementUpdateByShcodeAction);
}
