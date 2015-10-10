#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QMenu>
#include <QList>
#include "function/query/querymngr.h"
#include "function/login/loginmngr.h"
#include "function/chart/stockchartdatamanager.h"
#include "function/info/stockinfoupdater.h"
#include "function/sad/movementupdater.h"
#include "function/info/UpjongCodeUpdater.h"
#include "function/info/themeupjongupdater.h"
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
	void onShowChart();
	void onShowChart(const QString &shcode);
	void showMessage(const QString &title, const QString &body);
private slots:
    void requestMovementUpdateByUpcode();
    void requestMovementUpdateByShcode();
protected:
    virtual void closeEvent(QCloseEvent *event) override;

private:
    void initAction();
    void initMenu();
    Ui::MainWindow *ui;
    QMenu* m_pUpdateMenu;						//������Ʈ �޴�
	QMenu* m_pTestMenu;							//�׽�Ʈ �޴�
	QMenu* m_pTradingManageMenu;			//�ŷ� ���� �޴�

    QAction* mUpjongCodeUpdateAction;
	QAction* mThemeUpdateAction;
    QAction* mStockInfoUpdateAction;
    QAction* mMovementUpdateByUpcodeAction;
    QAction* mMovementUpdateByShcodeAction;
	QAction* mShowChartAction;
	QAction* mTradingLogAction;

    QueryMngr mQueryMngr;

	ThemeUpjongUpdater mThemeUpdater;
    StockInfoUpdater mStockInfoUpdater;
    MovementUpdater mMovementUpdater;
	UpjongCodeUpdater mUpjongCodeUpdater;
	StockChartDataManager mStockChartMngr;
    LoginMngr *mLoginMngr;
	XingThread mBackgroundWorker;
};

#endif // MAINWINDOW_H
