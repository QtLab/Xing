#include <QMessageBox>
#include "testdialog.h"
#include "ui_testdialog.h"
#include "util/xingutil.h"
#include "data/sadmodel.h"
#include <QTableWidget>
TestDialog::TestDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TestDialog),
    mStockInfoUpdater(new StockInfoUpdater(&mQueryMngr)),
    mMovementUpdater(new MovementUpdater(&mQueryMngr)),
    mStockExchangeMngr(new StockExchangeMngr)
{
    ui->setupUi(this);
    ui->stockInfoUpdateButton->setEnabled(false);
    ui->movementUpdateButton->setEnabled(false);

    connect(&mLoginMngr, SIGNAL(notifyLogin(QString,QString)), this, SLOT(enableTestButtons()));
    connect(mStockInfoUpdater, SIGNAL(updateDone()), this, SLOT(onStockInfoUpdateDone()));
    connect(mMovementUpdater, SIGNAL(updateDone()), this, SLOT(onMovementUpdateDone()));
    connect(mStockExchangeMngr, SIGNAL(responseWarehouseHistory(WarehouseInfo *)), this, SLOT(onWarehouseHistoryReceived(WarehouseInfo *)));
    connect(mStockExchangeMngr, SIGNAL(responseStockExchangeInfo(StockExchangeInfo*)), this, SLOT(onStockExchangeInfoReceived(StockExchangeInfo*)));
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
    ui->volumeStatisticTestBtn->setEnabled(true);
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

void TestDialog::onWarehouseHistoryReceived(WarehouseInfo *warehouseMap)
{
    WarehouseHistory* info = warehouseMap->value(INVESTMENT_C);
    QTableWidget *widget = new QTableWidget(info->getCount(), 9);
    QStringList headerList;
    headerList<<qkor("날짜")<<qkor("가격")<<qkor("평균단가")<<qkor("매수")<<qkor("누적합계")<<qkor("최고저점")<<qkor("매집수량")<<qkor("매집고점")<<qkor("분산비율");
    widget->setHorizontalHeaderLabels(headerList);
    widget->horizontalHeader();

    for(int i = 0; i<info->getCount(); i++) {
        widget->setItem(i, 0,  new QTableWidgetItem(((*info)[i]->date).toString("yyyyMMdd")));
        widget->setItem(i, 1, new QTableWidgetItem(tr("%1").arg((*info)[i]->price)));
        widget->setItem(i, 2, new QTableWidgetItem(tr("%1").arg((*info)[i]->avgPrice)));

        widget->setItem(i, 3, new QTableWidgetItem(tr("%1").arg((*info)[i]->volume)));
        widget->setItem(i, 4, new QTableWidgetItem(tr("%1").arg((*info)[i]->cumulativeSum)));
        widget->setItem(i, 5, new QTableWidgetItem(tr("%1").arg((*info)[i]->minCumulativeSum)));
        widget->setItem(i, 6, new QTableWidgetItem(tr("%1").arg((*info)[i]->currentWareHousing)));
        widget->setItem(i, 7, new QTableWidgetItem(tr("%1").arg((*info)[i]->maxWareHousing)));
        widget->setItem(i, 8, new QTableWidgetItem(tr("%1").arg((*info)[i]->distPercent)));
    }
    widget->show();
}

void TestDialog::onStockExchangeInfoReceived(StockExchangeInfo *stockExchangeInfo)
{
    QTableView *view = new QTableView();
    view->setModel(new SADModel(stockExchangeInfo));
    view->resizeColumnsToContents();
    view->resizeRowsToContents();
    view->resize(view->horizontalHeader()->length()+100, view->verticalHeader()->height()+250);
    view->show();
}

void TestDialog::on_volumeStatisticTestBtn_clicked()
{
    mStockExchangeMngr->requestStockExchangeInfo("005930");
}

void TestDialog::on_warehouseTestBtn_clicked()
{
    mStockExchangeMngr->requestWarehouseHistory("005930");
}
