#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "util/xingutil.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),mStockInfoMngr(this)
{
    ui->setupUi(this);
    initAction();
    initMenu();
    connect(&mStockInfoMngr, &StockInfoMngr::notifyMsg,this, &MainWindow::onMsg);
    mStockInfoMngr.start();
    qDebug()<<"Main thread id = "<<QThread::currentThreadId();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onStockInfoUpdated()
{

}

void MainWindow::onMsg(const QString &msg)
{

}

void MainWindow::closeEvent(QCloseEvent *event)
{
    qDebug()<<"closeEvent";
}
void MainWindow::initAction()
{
    m_pAllStockDataUpdateAction = new QAction(qkor("업데이트"), this);
    connect(m_pAllStockDataUpdateAction, &QAction::triggered, &mStockInfoMngr,&StockInfoMngr::update);
    connect(&mStockInfoMngr, &StockInfoMngr::onUpdated, this, &MainWindow::onStockInfoUpdated);

}

void MainWindow::initMenu()
{
    m_pUpdateMenu = menuBar()->addMenu(tr("Update"));
    m_pUpdateMenu->addAction(m_pAllStockDataUpdateAction);

}
