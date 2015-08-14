#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QMenu>
#include <QList>
#include "manager/querymngr.h"
#include "manager/stockinfoupdater.h"
#include "manager/movementupdater.h"

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
    void onMovementUpdated();
    void onDisconnectServer();
    void onLogout();
    void ReportEventLog(const QString &log);
private slots:
    void requestMovementUpdate();
protected:
    virtual void closeEvent(QCloseEvent *event);

private:
    void initAction();
    void initMenu();

    Ui::MainWindow *ui;
    QMenu* m_pUpdateMenu;

    QAction* mStockInfoUpdateAction;
    QAction* mMovementUpdateAction;
    QueryMngr mQueryMngr;
    StockInfoUpdater mStockInfoUpdater;
    MovementUpdater mMovementUpdater;
};

#endif // MAINWINDOW_H
