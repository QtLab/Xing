#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QMenu>
#include <QList>
#include "manager/querymngr.h"
#include "manager/stockinfoupdater.h"
#include "manager/movementupdater.h"
#include "manager/loginmngr.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(LoginMngr *loginMngr, QWidget *parent = 0);
    ~MainWindow();

public slots:
    void onStockInfoUpdated();
    void onUpjongCodeUpdated();
    void onMovementUpdated();
    void onDisconnectServer();
    void onLogin();
    void onLogout();
    void ReportEventLog(const QString &log);
private slots:
    void requestMovementUpdateByUpcode();
    void requestMovementUpdateByShcode();
protected:
    virtual void closeEvent(QCloseEvent *event);

private:
    void initAction();
    void initMenu();

    Ui::MainWindow *ui;
    QMenu* m_pUpdateMenu;

    QAction* mUpjongCodeUpdateAction;
    QAction* mStockInfoUpdateAction;
    QAction* mMovementUpdateByUpcodeAction;
    QAction* mMovementUpdateByShcodeAction;
    QueryMngr mQueryMngr;
    StockInfoUpdater mStockInfoUpdater;
    MovementUpdater mMovementUpdater;
    LoginMngr *mLoginMngr;
};

#endif // MAINWINDOW_H
