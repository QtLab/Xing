#include "loginmngr.h"
#include "util/log.h"
LoginMngr::LoginMngr(QObject *parent) : QObject(parent),mErrorMsg("None"),mIsLogin(false)
{
}

LoginMngr::~LoginMngr()
{

}

bool LoginMngr::requestLogin(const QString &id, const QString &passwd, const QString &certPasswd, bool toDemoServer)
{
    connect(&mSession, SIGNAL(onLogin(QString,QString)), this, SLOT(onLogin(QString,QString)));
    if(mSession.Init()) {
        if(mSession.ConnectServer(toDemoServer)) {
            mSession.Login(id, passwd, certPasswd, 0, false);
            return true;
        } else {
            mErrorMsg = mSession.GetErrorMessage(mSession.GetLastError());
        }
    }else {
            mErrorMsg = mSession.GetErrorMessage(mSession.GetLastError());
    }
    qCWarning(loginMngr)<<mErrorMsg;
    return false;
}

QString LoginMngr::getLastErrorMsg()
{
    return mErrorMsg;
}

bool LoginMngr::isLogined()
{
    return mIsLogin;
}

void LoginMngr::onLogin(const QString &szCode, const QString &szMsg)
{
    mIsLogin = true;
    emit notifyLogin(szCode, szMsg);
}

