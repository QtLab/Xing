#ifndef XASESSION_H
#define XASESSION_H

#include <QObject>

class QAxObject;
class XASessionEvents;
class XASession : public QObject
{
    Q_OBJECT
public:
    explicit XASession(QObject *parent = 0);
signals:
    void ReportEventLog(const QString&); // event signal to report event
public slots:
    bool Init();
    bool ConnectServer(const QString&, int);
    void DisconnectServer();
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
    bool Login(QString szID, QString szPwd, QString szCertPwd, int nServerType, bool bShowCertErrDlg);
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
