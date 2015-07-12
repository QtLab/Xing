#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QMenu>
#include <QList>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void initAction();
    void initMenu();
    Ui::MainWindow *ui;
    QMenu* mUpdateMenu;
    QMenu* mTestMenu;
    QAction* mAllStockDataUpdateAction;
    QAction* m8430Action;
};

#endif // MAINWINDOW_H
