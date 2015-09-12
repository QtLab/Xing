#ifndef XASESSIONEVENTS_H
#define XASESSIONEVENTS_H

#include <QObject>
class XASession;
class QAxObject;
class XASessionEvents : public QObject
{
    Q_OBJECT
public:
    explicit XASessionEvents(QAxObject* session, QObject *parent = 0);
    
signals:
    void onLogin(const QString &szCode, const QString &szMsg);
    void onLogout();
    void onDisconnect();
    void eventTriggered(const QString&);
private slots:
    void Disconnect();
    void Login(const QString &szCode, const QString &szMsg);
    void Logout();
    void exception(int, const QString &, const QString &, const QString &);
    void propertyChanged(const QString &name);
};

#endif // XASESSIONEVENTS_H
