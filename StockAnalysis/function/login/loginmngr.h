#ifndef LOGINMNGR_H
#define LOGINMNGR_H

#include <QObject>
#include "XingLib/xasession.h"
class LoginMngr : public QObject
{
    Q_OBJECT
public:
    explicit LoginMngr(XASession* xasession, QObject *parent = 0);
    ~LoginMngr();
    bool requestLogin(const QString &id, const QString &passwd, const QString &certPasswd, bool toDemoServer);
    bool reLogin();
    QString getLastErrorMsg();
    bool isLogined();
    QStringList getServerList();
private:
    bool login();
signals:
    void notifyLogin(const QString &szCode, const QString &szMsg);
    void notifyLogout();
    void notifyDisconnect();
    void reportEventLog(const QString &log);
public slots:
    void onLogin(const QString &szCode, const QString &szMsg);
    void onLogout();
    void onDisconnect();
    void onReportEventLog(const QString &log);
private:
    XASession *mSession;
    QString mErrorMsg;
    bool mIsLogin;
    QString mId;
    QString mPasswd;
    QString mCertPasswd;
    bool mToDemoServer;
};

#endif // LOGINMNGR_H
