#include <QMessageBox>
#include "testdialog.h"
#include "ui_testdialog.h"
#include "util/xingutil.h"
#include <QTableWidget>
TestDialog::TestDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TestDialog),
    mStockInfoUpdater(new StockInfoUpdater(&mQueryMngr)),
    mMovementUpdater(new MovementUpdater(&mQueryMngr)),
    mMovementMngr(new MovementMngr)
{
    ui->setupUi(this);
    ui->stockInfoUpdateButton->setEnabled(false);
    ui->movementUpdateButton->setEnabled(false);
    ui->movementBtn->setEnabled(false);

    connect(&mLoginMngr, SIGNAL(notifyLogin(QString,QString)), this, SLOT(enableTestButtons()));
    connect(mStockInfoUpdater, SIGNAL(updateDone()), this, SLOT(onStockInfoUpdateDone()));
    connect(mMovementUpdater, SIGNAL(updateDone()), this, SLOT(onMovementUpdateDone()));
    connect(mMovementMngr, SIGNAL(responseMovementInfo(MovementInfo*)), this, SLOT(onMovementInfoReceived(MovementInfo*)));
}

TestDialog::~TestDialog()
{
    delete ui;
}

void TestDialog::on_stockInfoUpdateButton_clicked()
{
    mStockInfoUpdater->update();
}

void TestDialog::on_movementUpdateButton_clicked()
{
    mMovementUpdater->update();
}

void TestDialog::on_loginButton_clicked()
{
    mLoginMngr.requestLogin(tr("seuki77"), tr("folken77"),tr(""),true);
}

void TestDialog::enableTestButtons()
{
    ui->stockInfoUpdateButton->setEnabled(true);
    ui->movementUpdateButton->setEnabled(true);
    ui->movementBtn->setEnabled(true);
    mQueryMngr.start();
}

void TestDialog::onStockInfoUpdateDone()
{
    QMessageBox::information(this, "StockInfoUpdate", "Done");
}

void TestDialog::onMovementUpdateDone()
{
    QMessageBox::information(this, "MovementUpdate", "Done");
}

void TestDialog::onMovementInfoReceived(MovementInfo *info)
{
    QTableWidget *widget = new QTableWidget(info->getCount(), 6);
    QStringList headerList;
    headerList<<qkor("날짜")<<qkor("누적합계")<<qkor("최고저점")<<qkor("매집수량")<<qkor("매집고점")<<qkor("분산비율");
    widget->setHorizontalHeaderLabels(headerList);
    widget->horizontalHeader();
    for(int i = 0; i<info->getCount(); i++) {
       widget->setItem(i, 0,  new QTableWidgetItem((info->date(i)).toString("yyyyMMdd")));
       widget->setItem(i, 1, new QTableWidgetItem(tr("%1").arg(info->cumulativeSum(i))));
       widget->setItem(i, 2, new QTableWidgetItem(tr("%1").arg(info->minCumulativeSum(i))));
       widget->setItem(i, 3, new QTableWidgetItem(tr("%1").arg(info->currentWareHousing(i))));
       widget->setItem(i, 4, new QTableWidgetItem(tr("%1").arg(info->maxWareHousing(i))));
       widget->setItem(i, 5, new QTableWidgetItem(tr("%1").arg(info->distPercent(i))));
    }
    widget->show();
}

void TestDialog::on_movementBtn_clicked()
{
    mMovementMngr->reqestMovementInfo("005930");
}
