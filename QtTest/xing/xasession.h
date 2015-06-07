#ifndef XASESSION_H
#define XASESSION_H

#include <QObject>
#include <QWidget>

#include "IXingAPI.h"

#define REAL_SERVER_ADDR "hts.etrade.co.kr"
#define DEMO_SERVER_ADDR "demo.etrade.co.kr"

#define DEFAULT_SERVER_PORT 20001
#define DEFAULT_TIMEOUT_LIMIT 3000
#define DEFAULT_MAX_PACKET_SIZE 512

class XASession : public QObject
{
    Q_OBJECT
public:
    explicit XASession(QObject *parent = 0);
    ~XASession();

private:
    int m_timeout;
    int m_sendPacketSize;
signals:

public slots:
    bool ConnectServer(const QWidget& widget, bool isRealServer=false);
    bool DisconnectServer();
    QString GetAccountList(int nIndex);
    int GetAccountListCount();
    QString GetClientIP();
    QString GetCommMedia();
    QString GetETKMedia();
    QString GetErrorMessage(int nErrorCode);
    int GetLastError();
    QString GetServerName();
    bool IsConnected();
    bool IsLoadAPI();
    bool Login(const QWidget& widget, const QString& id, const QString& pwd, const QString& certPwd, int serverType=0, bool bShowCertErrDlg=false);
    bool Logout(const QWidget& widget);
    void SetConnectTimeOut(int ConnectTimeOut);
    void SetSendPacketSize(int SendPacketSize);
    QStringList GetServerList();

    void handleResponse(const QWidget* receiver, WPARAM wParam, LPARAM lParam);
};

#endif // XASESSION_H
