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
    QString getLastErrorMsg();
    bool isLogined();
    QStringList getServerList();
signals:
    void notifyLogin(const QString &szCode, const QString &szMsg);
public slots:
    void onLogin(const QString &szCode, const QString &szMsg);
private:
    XASession *mSession;
    QString mErrorMsg;
    bool mIsLogin;
};

#endif // LOGINMNGR_H
