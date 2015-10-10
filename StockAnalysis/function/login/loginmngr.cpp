#include "loginmngr.h"
#include "util/log.h"
#include "util/xingutil.h"
LoginMngr::LoginMngr(XASession* xasession,QObject *parent) : QObject(parent),mSession(xasession), mErrorMsg("None"),mIsLogin(false), mId(""), mPasswd(""), mCertPasswd(""), mToDemoServer(false)
{
    connect(mSession, SIGNAL(onLogin(QString,QString)), this, SLOT(onLogin(QString,QString)));
    connect(mSession, SIGNAL(onLogout()), this, SLOT(onLogout()));
    connect(mSession, SIGNAL(onDisconnect()), this, SLOT(onDisconnect()));
    connect(mSession, SIGNAL(ReportEventLog(QString)), this, SLOT(onReportEventLog(QString)));
}

LoginMngr::~LoginMngr()
{

}

bool LoginMngr::requestLogin(const QString &id, const QString &passwd, const QString &certPasswd, bool toDemoServer)
{
    mId = id;
    mPasswd = passwd;
    mCertPasswd = certPasswd;
    mToDemoServer = toDemoServer;

    if(mSession->Init()) {
        return login();
    } else {
        mErrorMsg = mSession->GetErrorMessage(mSession->GetLastError());
    }
    qCWarning(loginMngr)<<mErrorMsg;
    return false;
}

bool LoginMngr::reLogin()
{
    if((mId==tr("")||(mPasswd==tr("")))) {
        mErrorMsg = qkor("아이디와 패스워드가 설정되지 않았습니다.");
        return false;
    }
    return login();
}

QString LoginMngr::getLastErrorMsg()
{
    return mErrorMsg;
}

bool LoginMngr::isLogined()
{
    return mIsLogin;
}

QStringList LoginMngr::getServerList()
{
    return mSession->GetServerList();
}

bool LoginMngr::login()
{
    if(mSession->ConnectServer(mToDemoServer)) {
        mSession->Login(mId, mPasswd, mCertPasswd, 0, false);
        return true;
    } else {
        mErrorMsg = mSession->GetErrorMessage(mSession->GetLastError());
        qCCritical(loginMngr)<<mErrorMsg;
    }
    return false;
}

void LoginMngr::onLogin(const QString &szCode, const QString &szMsg)
{
    mIsLogin = true;
    qCDebug(loginMngr)<<"onLogin";
    emit notifyLogin(szCode, szMsg);
}

void LoginMngr::onLogout()
{
    mIsLogin = false;
    qCDebug(loginMngr)<<"onLogout";
    emit notifyLogout();
}

void LoginMngr::onDisconnect()
{
    mIsLogin = false;
    qCDebug(loginMngr)<<"onDisconnect";
    emit notifyDisconnect();
}

void LoginMngr::onReportEventLog(const QString &log)
{
    qCDebug(loginMngr)<<"onReportEventLog - "<<log;
    emit reportEventLog(log);
}

