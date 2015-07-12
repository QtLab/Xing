#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "util/xingutil.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initAction();
    initMenu();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::initAction()
{
    mAllStockDataUpdateAction = new QAction(qkor("업데이트"), this);
    connect(mAllStockDataUpdateAction, &QAction::triggered, this, &MainWindow::updateAllStockData);

    m8430Action = new QAction("t8430", this);
    connect(m8430Action, &QAction::triggered, this,&QAction::triggered);
}

void MainWindow::initMenu()
{
    mUpdateMenu = menuBar()->addMenu(tr("Update"));
    mUpdateMenu->addAction(mAllStockDataUpdateAction);
    mTestMenu = menuBar()->addMenu(tr("Test"));
    mTestMenu->addAction(m8430Action);
}
