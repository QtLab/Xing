#ifndef TESTDIALOG_H
#define TESTDIALOG_H

#include <QDialog>
#include "manager/loginmngr.h"
#include "manager/querymngr.h"
#include "manager/stockinfoupdater.h"
#include "manager/movementupdater.h"
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
public slots:
    void enableTestButtons();
    void onStockInfoUpdateDone();
    void onMovementUpdateDone();
private:
    Ui::TestDialog *ui;
    LoginMngr mLoginMngr;
    QueryMngr mQueryMngr;
    StockInfoUpdater *mStockInfoUpdater;
    MovementUpdater *mMovementUpdater;
};

#endif // TESTDIALOG_H
