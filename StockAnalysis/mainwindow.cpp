#include <QDebug>
#include <QMessageBox>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "util/xingutil.h"
#include "util/log.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), mStockInfoUpdater(&mQueryMngr), mMovementUpdater(&mQueryMngr)
{
    ui->setupUi(this);
    initAction();
    initMenu();
    mQueryMngr.start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onStockInfoUpdated()
{
    QMessageBox::information(this, qkor("StockInfo 업데이트"), qkor("업데이트 완료"));
}

void MainWindow::onMovementUpdated()
{
    QMessageBox::information(this, qkor("수급정보 업데이트"), qkor("업데이트 완료"));
}

void MainWindow::onDisconnectServer()
{
    qCDebug(mainWindow)<<qkor("서버와의 연결이 종료되었습니다.");
}

void MainWindow::onLogout()
{
    qCDebug(mainWindow)<<qkor("로그아웃 되었습니다.");
}

void MainWindow::ReportEventLog(const QString &log)
{
    qCDebug(mainWindow)<<qkor("Xing 모듈로부터의 이벤트 - ")<<log;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    qCDebug(mainWindow)<<"closeEvent";
}

void MainWindow::initAction()
{
    //StockInfo Update Action [START]
    mStockInfoUpdateAction = new QAction(qkor("StockInfo 업데이트"), this);
    connect(mStockInfoUpdateAction, &QAction::triggered, &mStockInfoUpdater,&StockInfoUpdater::update);
    connect(&mStockInfoUpdater, &StockInfoUpdater::updateDone, this, &MainWindow::onStockInfoUpdated);
    //StockInfo Update Action [END]

    //Movement Update Action [START]
    mMovementUpdateAction = new QAction(qkor("수급정보 업데이트"), this);
    connect(mMovementUpdateAction, &QAction::triggered, &mMovementUpdater, &MovementUpdater::update);
    connect(&mMovementUpdater, &MovementUpdater::updateDone, this, &MainWindow::onMovementUpdated);
    //Movement Update Action [END]
}

void MainWindow::initMenu()
{
    m_pUpdateMenu = menuBar()->addMenu(tr("Update"));
    m_pUpdateMenu->addAction(mStockInfoUpdateAction);
    m_pUpdateMenu->addAction(mMovementUpdateAction);
}
