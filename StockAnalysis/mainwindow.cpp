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
    QMessageBox::information(this, qkor("StockInfo ������Ʈ"), qkor("������Ʈ �Ϸ�"));
}

void MainWindow::onMovementUpdated()
{
    QMessageBox::information(this, qkor("�������� ������Ʈ"), qkor("������Ʈ �Ϸ�"));
}

void MainWindow::onDisconnectServer()
{
    qCDebug(mainWindow)<<qkor("�������� ������ ����Ǿ����ϴ�.");
}

void MainWindow::onLogout()
{
    qCDebug(mainWindow)<<qkor("�α׾ƿ� �Ǿ����ϴ�.");
}

void MainWindow::ReportEventLog(const QString &log)
{
    qCDebug(mainWindow)<<qkor("Xing ���κ����� �̺�Ʈ - ")<<log;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    qCDebug(mainWindow)<<"closeEvent";
}

void MainWindow::initAction()
{
    //StockInfo Update Action [START]
    mStockInfoUpdateAction = new QAction(qkor("StockInfo ������Ʈ"), this);
    connect(mStockInfoUpdateAction, &QAction::triggered, &mStockInfoUpdater,&StockInfoUpdater::update);
    connect(&mStockInfoUpdater, &StockInfoUpdater::updateDone, this, &MainWindow::onStockInfoUpdated);
    //StockInfo Update Action [END]

    //Movement Update Action [START]
    mMovementUpdateAction = new QAction(qkor("�������� ������Ʈ"), this);
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
