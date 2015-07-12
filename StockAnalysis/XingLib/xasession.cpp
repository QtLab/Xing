#include "xasession.h"
#include "xasessionevents.h"
#include <ActiveQt/QAxObject>
XASession::XASession(QObject *parent) :
    QObject(parent),session(new QAxObject("XA_Session.XASession"))
{

}
bool XASession::Init()
{
    QVariant result = session->dynamicCall("IsLoadAPI()");

    return result.toBool();
}

bool XASession::ConnectServer(bool toDemoServer)
{
    if(toDemoServer) {
        QVariant result = session->dynamicCall("ConnectServer(QString szServerIP, int nServerPort)", DEMO_SERVER_ADDR, DEFAULT_SERVER_PORT);
    } else {
        QVariant result = session->dynamicCall("ConnectServer(QString szServerIP, int nServerPort)", REAL_SERVER_ADDR, DEFAULT_SERVER_PORT);
    }

    sessionEvents = new XASessionEvents(session, this);
    connect(sessionEvents, &XASessionEvents::onLogin, this, &XASession::onLogin);
    connect(sessionEvents, &XASessionEvents::onLogout, this, &XASession::onLogout);
    connect(sessionEvents, &XASessionEvents::onDisconnect, this, &XASession::onDisconnect);
    connect(sessionEvents, SIGNAL(eventTriggered(const QString&)), this, SLOT(ReportXASessionEventLog(const QString&)));
    return result.toBool();
}
void XASession::DisconnectServer()
{
    session->dynamicCall("DisconnectServer()");
}

QString XASession::GetAccountList(int _nIndex)
{
    QVariant nIndex(_nIndex);
    QVariant result = session->dynamicCall("GetAccountList(int nIndex)", nIndex);
    return result.toString();
}

int XASession::GetAccountListCount()
{
    QVariant result = session->dynamicCall("GetAccountListCount()");
    return result.toInt();
}

QString XASession::GetClientIP()
{
    QVariant result = session->dynamicCall("GetClientIP()");
    return result.toString();
}

QString XASession::GetCommMedia()
{
    QVariant result = session->dynamicCall("GetCommMedia()");
    return result.toString();
}

QString XASession::GetETKMedia()
{
    QVariant result = session->dynamicCall("GetETKMedia()");
    return result.toString();
}

QString XASession::GetErrorMessage(int nErrorCode)
{
    QVariant result = session->dynamicCall("GetErrorMessage(int nErrorCode)");
    return result.toString();
}

int XASession::GetLastError()
{
    QVariant result = session->dynamicCall("GetLastError()");
    return result.toInt();
}

QString XASession::GetServerName()
{
    QVariant result = session->dynamicCall("GetServerName()");
    return result.toString();
}

bool XASession::IsConnected()
{
    QVariant result = session->dynamicCall("IsConnected()");
    return result.toBool();
}

bool XASession::IsLoadAPI()
{
    QVariant result = session->dynamicCall("IsLoadAPI()");
    return result.toBool();
}

bool XASession::Login(QString szID, QString szPwd, QString szCertPwd, int nServerType, bool bShowCertErrDlg)
{
    QVariant result = session->dynamicCall("Login(QString szID, QString szPwd, QString szCertPwd, int nServerType, bool bShowCertErrDlg)", szID, szPwd, szCertPwd, nServerType, bShowCertErrDlg);
    return result.toBool();
}

bool XASession::Logout()
{
    QVariant result = session->dynamicCall("Logout()");
    return result.toBool();
}

void XASession::SetConnectTimeOut(int ConnectTimeOut)
{
    session->dynamicCall("SetConnectTimeOut(int ConnectTimeOut)");
}

void XASession::SetSendPacketSize(int SendPacketSize){
    session->dynamicCall("SetSendPacketSize(int SendPacketSize)");
}


void XASession::ReportXASessionEventLog(const QString& log)
{
    emit ReportEventLog(log);
}
