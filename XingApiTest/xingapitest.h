#ifndef XINGAPITEST_H
#define XINGAPITEST_H

#include <QWidget>

class XASession;
class XAQuery;
namespace Ui {
class XingApiTest;
}

class XingApiTest : public QWidget
{
    Q_OBJECT
    
public:
    explicit XingApiTest(QWidget *parent = 0);
    ~XingApiTest();
private slots:
    void on_loginButton_clicked();
    void on_logoutButton_clicked();
    void on_dumpButton_clicked();

public slots:
    void onEventCallback(const QString&);
    void onReceiveMsg();
private:
//    void doLogin();
//    void doLogout();
    void printLog(const QString&);
    XAQuery* xaquery;
    Ui::XingApiTest *ui;
    XASession *xasession;
};

#endif // XINGAPITEST_H
