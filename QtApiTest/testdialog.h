#ifndef TESTDIALOG_H
#define TESTDIALOG_H

#include <QDialog>
#include "manager/loginmngr.h"
#include "manager/querymngr.h"
#include "manager/stockinfoupdater.h"
#include "manager/movementupdater.h"
#include "manager/stockexchangemngr.h"
namespace Ui {
class TestDialog;
}

class TestDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TestDialog(QWidget *parent = 0);
    ~TestDialog();

private slots:
    void on_stockInfoUpdateButton_clicked();

    void on_movementUpdateButton_clicked();

    void on_loginButton_clicked();

    void on_volumeStatisticTestBtn_clicked();

    void on_warehouseTestBtn_clicked();

    void on_summaryTestButton_clicked();

public slots:
    void enableTestButtons();
    void onStockInfoUpdateDone();
    void onMovementUpdateDone();
    void onWarehouseHistoryReceived(WarehouseInfo* warehouseMap);
    void onStockExchangeInfoReceived(StockExchangeInfo* stockExchangeInfo);
private:
    Ui::TestDialog *ui;
    LoginMngr mLoginMngr;
    QueryMngr mQueryMngr;
    StockInfoUpdater *mStockInfoUpdater;
    MovementUpdater *mMovementUpdater;
    StockExchangeMngr *mStockExchangeMngr;
    StockExchangeInfo *mStockExchangeInfo;
};

#endif // TESTDIALOG_H
