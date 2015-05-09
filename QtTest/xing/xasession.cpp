#include "xasession.h"

XASession::XASession(QObject *parent) : QObject(parent),m_timeout(DEFAULT_TIMEOUT_LIMIT), m_sendPacketSize(DEFAULT_MAX_PACKET_SIZE)
{

}

XASession::~XASession()
{
    m_api.Uninit();
}

bool XASession::Init()
{
    return m_api.Init();
}

bool XASession::ConnectServer(const QWidget& widget, bool isRealServer)
{
    if(!m_api.IsInit()){
        if(!m_api.Init())
            return false;
    }
    if(isRealServer) {
        return m_api.Connect((HWND)widget.winId(), REAL_SERVER_ADDR, DEFAULT_SERVER_PORT, WM_USER, m_timeout, m_sendPacketSize);
    } else {
        return m_api.Connect((HWND)widget.winId(), DEMO_SERVER_ADDR, DEFAULT_SERVER_PORT, WM_USER, m_timeout, m_sendPacketSize);
    }
}

bool XASession::DisconnectServer()
{
    if(m_api.IsInit())
        return m_api.Disconnect();
    else
        return false;
}

QString XASession::GetAccountList(int nIndex)
{
    char account[20];
    if(m_api.GetAccountList(nIndex, account, sizeof(account))){
        return QString::fromLocal8Bit(account);
    } else {
        return "";
    }
}

int XASession::GetAccountListCount()
{
    return m_api.GetAccountListCount();
}

QString XASession::GetClientIP()
{
    return m_api.GetClientIP();
}

QString XASession::GetCommMedia()
{
    return m_api.GetCommMedia();
}

QString XASession::GetETKMedia()
{
    return m_api.GetETKMedia();
}

QString XASession::GetErrorMessage(int nErrorCode)
{
    return m_api.GetErrorMessage(nErrorCode);
}

int XASession::GetLastError()
{
    return m_api.GetLastError();
}

QString XASession::GetServerName()
{
    return m_api.GetServerName();
}

bool XASession::IsConnected()
{
    return m_api.IsConnected();
}

bool XASession::IsLoadAPI()
{
    return m_api.IsInit();
}

bool XASession::Login(const QWidget& widget, const QString& id, const QString& pwd, const QString& certPwd, int serverType, bool bShowCertErrDlg)
{
    return m_api.Login((HWND)widget.winId(), id.toLocal8Bit().constData(), pwd.toLocal8Bit().constData(), certPwd.toLocal8Bit().constData(), serverType, bShowCertErrDlg);
}

bool XASession::Logout(const QWidget& widget)
{
    return m_api.Logout((HWND)widget.winId());
}

void XASession::SetConnectTimeOut(int ConnectTimeOut)
{
    m_timeout = ConnectTimeOut;
}

void XASession::SetSendPacketSize(int SendPacketSize)
{
    m_sendPacketSize = SendPacketSize;
}

