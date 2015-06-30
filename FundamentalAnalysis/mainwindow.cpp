#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "util/xingutil.h"
#include <QMessageBox>
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

void MainWindow::updateShcode()
{
    QMessageBox::information(this, "debug","updateShcode");
}

void MainWindow::initAction()
{
    mShcodeUpdateAction = new QAction(qkor("�����ڵ� ������Ʈ"), this);
    connect(mShcodeUpdateAction, &QAction::triggered, this, &MainWindow::updateShcode);

}

void MainWindow::initMenu()
{
    mUpdateMenu = menuBar()->addMenu(tr("Update"));
    mUpdateMenu->addAction(mShcodeUpdateAction);
}

void MainWindow::closeEvent(QCloseEvent *event)
{

}
