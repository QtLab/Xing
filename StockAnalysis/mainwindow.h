#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QMenu>
#include <QList>
#include "manager/stockinfomngr.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void onStockInfoUpdated();
    void onMsg(const QString& msg);
protected:
    virtual void closeEvent(QCloseEvent *event);

private:
    void initAction();
    void initMenu();

    Ui::MainWindow *ui;
    QMenu* m_pUpdateMenu;

    QAction* m_pAllStockDataUpdateAction;


    StockInfoMngr mStockInfoMngr;

};

#endif // MAINWINDOW_H
