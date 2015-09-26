#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QMenu>
#include <QList>
#include "manager/querymngr.h"
#include "updater/stockinfoupdater.h"
#include "updater/movementupdater.h"
#include "updater/UpjongCodeUpdater.h"
#include "updater/themeupjongupdater.h"
#include "manager/loginmngr.h"
#include "util/xingthread.h"
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
    void onUpjongCodeUpdated();
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
	QAction* mThemeUpdateAction;
    QAction* mStockInfoUpdateAction;
    QAction* mMovementUpdateByUpcodeAction;
    QAction* mMovementUpdateByShcodeAction;
    QueryMngr mQueryMngr;

	ThemeUpjongUpdater mThemeUpdater;
    StockInfoUpdater mStockInfoUpdater;
    MovementUpdater mMovementUpdater;
	UpjongCodeUpdater mUpjongCodeUpdater;
    LoginMngr *mLoginMngr;
	XingThread mBackgroundWorker;
};

#endif // MAINWINDOW_H
