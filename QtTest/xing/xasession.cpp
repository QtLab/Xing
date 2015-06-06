#include "xasession.h"

XASession::XASession(QObject *parent) : QObject(parent),m_timeout(DEFAULT_TIMEOUT_LIMIT), m_sendPacketSize(DEFAULT_MAX_PACKET_SIZE)
{

}

XASession::~XASession()
{
    IXingAPI::GetInstance()->Uninit();
}

bool XASession::ConnectServer(const QWidget& widget, bool isRealServer)
{
    if(!IXingAPI::GetInstance()->IsInit()){
        if(!IXingAPI::GetInstance()->Init())
            return false;
    }
    if(isRealServer) {
        return IXingAPI::GetInstance()->Connect((HWND)widget.winId(), REAL_SERVER_ADDR, DEFAULT_SERVER_PORT, WM_USER, m_timeout, m_sendPacketSize);
    } else {
        return IXingAPI::GetInstance()->Connect((HWND)widget.winId(), DEMO_SERVER_ADDR, DEFAULT_SERVER_PORT, WM_USER, m_timeout, m_sendPacketSize);
    }
}

bool XASession::DisconnectServer()
{
    if(IXingAPI::GetInstance()->IsInit())
        return IXingAPI::GetInstance()->Disconnect();
    else
        return false;
}

QString XASession::GetAccountList(int nIndex)
{
    char account[20];
    if(IXingAPI::GetInstance()->GetAccountList(nIndex, account, sizeof(account))){
        return QString::fromLocal8Bit(account);
    } else {
        return "";
    }
}

int XASession::GetAccountListCount()
{
    return IXingAPI::GetInstance()->GetAccountListCount();
}

QString XASession::GetClientIP()
{
    return IXingAPI::GetInstance()->GetClientIP();
}

QString XASession::GetCommMedia()
{
    return IXingAPI::GetInstance()->GetCommMedia();
}

QString XASession::GetETKMedia()
{
    return IXingAPI::GetInstance()->GetETKMedia();
}

QString XASession::GetErrorMessage(int nErrorCode)
{
    return IXingAPI::GetInstance()->GetErrorMessage(nErrorCode);
}

int XASession::GetLastError()
{
    return IXingAPI::GetInstance()->GetLastError();
}

QString XASession::GetServerName()
{
    return IXingAPI::GetInstance()->GetServerName();
}

bool XASession::IsConnected()
{
    return IXingAPI::GetInstance()->IsConnected();
}

bool XASession::IsLoadAPI()
{
    return IXingAPI::GetInstance()->IsInit();
}

bool XASession::Login(const QWidget& widget, const QString& id, const QString& pwd, const QString& certPwd, int serverType, bool bShowCertErrDlg)
{
    return IXingAPI::GetInstance()->Login((HWND)widget.winId(), id.toLocal8Bit().constData(), pwd.toLocal8Bit().constData(), certPwd.toLocal8Bit().constData(), serverType, bShowCertErrDlg);
}

bool XASession::Logout(const QWidget& widget)
{
    return IXingAPI::GetInstance()->Logout((HWND)widget.winId());
}

void XASession::SetConnectTimeOut(int ConnectTimeOut)
{
    m_timeout = ConnectTimeOut;
}

void XASession::SetSendPacketSize(int SendPacketSize)
{
    m_sendPacketSize = SendPacketSize;
}

QStringList XASession::GetServerList()
{
    QStringList list;
    list.push_front(REAL_SERVER_ADDR);
    list.push_front(DEMO_SERVER_ADDR);
    return list;
}


