#include "xasessionevents.h"
#include "xasession.h"
#include <ActiveQt/QAxObject>
XASessionEvents::XASessionEvents(QAxObject *session, QObject *parent) :
    QObject(parent)
{
    connect(session, SIGNAL(Disconnect()), this, SLOT(Disconnect()));
    connect(session, SIGNAL(Login(QString, QString)), this, SLOT(Login(const QString&, const QString&)));
    connect(session, SIGNAL(Logout()), this, SLOT(Logout()));
    connect(session, SIGNAL(exception(int, QString, QString, QString)), this, SLOT(exception(int, const QString&, const QString&, const QString&)));
    connect(session, SIGNAL(propertyChanged(QString)), this, SLOT(propertyChanged(const QString&)));
}
void XASessionEvents::Disconnect()
{
    emit onDisconnect();
}
void XASessionEvents::Login(const QString &szCode, const QString &szMsg)
{
    emit onLogin(szCode, szMsg);
}

void XASessionEvents::Logout()
{
    emit onLogout();
}

void XASessionEvents::exception(int code, const QString &source, const QString &disc, const QString &help)
{
    emit eventTriggered(tr("XASessionEvents : exception code=%1, source=%2, disc=%3, help=%4").arg(code).arg(source).arg(disc).arg(help));
}

void XASessionEvents::propertyChanged(const QString &name)
{
    emit eventTriggered(tr("XASessionEvents : propertyChanged name=%1").arg(name));
}

