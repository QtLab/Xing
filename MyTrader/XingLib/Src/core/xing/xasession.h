#ifndef XASESSION_H
#define XASESSION_H

#include <QObject>

#define REAL_SERVER_ADDR "hts.etrade.co.kr"
#define DEMO_SERVER_ADDR "demo.etrade.co.kr"
#define DEFAULT_SERVER_PORT 20001
class QAxObject;
class XASessionEvents;
class XASession : public QObject
{
    Q_OBJECT
public:
    explicit XASession(QObject *parent = 0);

    QStringList GetServerList();
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

signals:
    void onLogin(const QString &szCode, const QString &szMsg);
    void onLogout();
    void onDisconnect();
    void ReportEventLog(const QString&); // event signal to report event

public slots:
    bool Init();
    bool ConnectServer(bool toDemoServer);
    void DisconnectServer();    
    bool Login(QString szID, QString szPwd, QString szCertPwd, int nServerType=0, bool bShowCertErrDlg = false);
    bool Logout();
    void SetConnectTimeOut(int ConnectTimeOut);
    void SetSendPacketSize(int SendPacketSize);

private slots:
    void ReportXASessionEventLog(const QString&); //event slot from XASessionEvents
private:
    XASessionEvents *sessionEvents;
    QAxObject *session;
    friend class XASessionEvents;
};

#endif // XASESSION_H
