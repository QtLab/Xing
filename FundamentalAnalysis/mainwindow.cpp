#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "util/xingutil.h"

#include <QMessageBox>
#include <QCloseEvent>

#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mShcodeListUpdater = new ShcodeListUpdater(this);
    initAction();
    initMenu();
    connect(mShcodeListUpdater, &ShcodeListUpdater::shcodeListUpdated, this, &MainWindow::onShcodeListUpdated);
}

MainWindow::~MainWindow()
{
    delete ui;
}
bool MainWindow::nativeEvent(const QByteArray & eventType, void * message, long * result){
    MSG *msg = static_cast<MSG *>( message );

    switch ( msg->message ){
    case WM_USER+XM_RECEIVE_DATA:
        m_queryMngr.handleResponse(msg->wParam, msg->lParam);
        break;
    }
    return false;
}
void MainWindow::updateShcode()
{
    mShcodeListUpdater->updateShcodeList(this, &m_queryMngr);
}
void MainWindow::onShcodeListUpdated()
{
    QMessageBox::information(this, "shcodeListUpdate", "finished");
}

void MainWindow::initAction()
{
    mShcodeUpdateAction = new QAction(qkor("종목코드 업데이트"), this);
    connect(mShcodeUpdateAction, &QAction::triggered, this, &MainWindow::updateShcode);

}

void MainWindow::initMenu()
{
    mUpdateMenu = menuBar()->addMenu(tr("Update"));
    mUpdateMenu->addAction(mShcodeUpdateAction);
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    mSession.Logout(*this);
    mSession.DisconnectServer();
    event->accept();
}
