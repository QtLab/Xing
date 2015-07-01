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
    qDebug()<<"MainWindow executed in "<<QThread::currentThreadId();
    initAction();
    initMenu();
    XAQueryMngr::init(this);
    XAQueryMngr::getInstance()->start();
    mShcodeListUpdater = new ShcodeManager(NULL);
    mShcodeListUpdater->moveToThread(XAQueryMngr::getInstance());
    connect(mShcodeListUpdater, &ShcodeManager::updateDone, this, &MainWindow::onShcodeListUpdated);
    QMetaObject::invokeMethod(mShcodeListUpdater,"init", Qt::QueuedConnection );
}

MainWindow::~MainWindow()
{
    delete ui;
}
bool MainWindow::nativeEvent(const QByteArray & eventType, void * message, long * result){
    MSG *msg = static_cast<MSG *>( message );

    switch ( msg->message ){
    case WM_USER+XM_RECEIVE_DATA:
        XAQueryMngr::getInstance()->handleResponse(msg->wParam, msg->lParam);
        break;
    }
    return false;
}
void MainWindow::updateShcode()
{
    mShcodeListUpdater->requestUpdate(this);
}

void MainWindow::updateAllStockData()
{

}
void MainWindow::onShcodeListUpdated()
{
    QMessageBox::information(this, "shcodeListUpdate", "finished");
}

void MainWindow::initAction()
{
    mShcodeUpdateAction = new QAction(qkor("종목코드 업데이트"), this);
    connect(mShcodeUpdateAction, &QAction::triggered, this, &MainWindow::updateShcode);

    mAllStockDataUpdateAction = new QAction(qkor("수급 현황 업데이트"), this);
    connect(mAllStockDataUpdateAction, &QAction::triggered, this, &MainWindow::updateAllStockData);
}

void MainWindow::initMenu()
{
    mUpdateMenu = menuBar()->addMenu(tr("Update"));
    mUpdateMenu->addAction(mShcodeUpdateAction);
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if(XAQueryMngr::getInstance()->isRunning()) {
        qDebug()<<"Thread is still running";
        XAQueryMngr::getInstance()->exit();
        mSession.DisconnectServer();
        if(XAQueryMngr::getInstance()->wait(5000)) {
            qDebug()<<"Thread is finished";
            event->accept();
        } else {
            qDebug()<<"Thread is not finished in 5s";
            QCoreApplication::sendEvent(this, new QCloseEvent());
        }
    }
    event->accept();
}
