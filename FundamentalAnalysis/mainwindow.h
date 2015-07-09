#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QMenu>
#include <QList>

#include "xing/xasession.h"
#include "xing/xaquery.h"
#include "function/stockinfomngr.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void updateShcode();
    void updateAllStockData();
    void onShcodeListUpdated();
private:
    void initAction();
    void initMenu();

protected:
    virtual void closeEvent(QCloseEvent * event);
    virtual bool nativeEvent(const QByteArray & eventType, void * message, long * result);
private:
    Ui::MainWindow *ui;
    XASession mSession;

    StockInfoMngr* mStockInfoMngr;
    QMenu* mUpdateMenu;

    QAction* mShcodeUpdateAction;
    QAction* mAllStockDataUpdateAction;
};

#endif // MAINWINDOW_H
