#include <QMessageBox>
#include "testdialog.h"
#include "ui_testdialog.h"

TestDialog::TestDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TestDialog),
    mStockInfoUpdater(new StockInfoUpdater(&mQueryMngr,this)),
    mMovementUpdater(new MovementUpdater(&mQueryMngr))
{
    ui->setupUi(this);
    ui->stockInfoUpdateButton->setEnabled(false);
    ui->movementUpdateButton->setEnabled(false);

    connect(&mLoginMngr, SIGNAL(notifyLogin(QString,QString)), this, SLOT(enableTestButtons()));
    connect(mStockInfoUpdater, SIGNAL(updateDone()), this, SLOT(onStockInfoUpdateDone()));
    connect(mMovementUpdater, SIGNAL(updateDone()), this, SLOT(onMovementUpdateDone()));
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
