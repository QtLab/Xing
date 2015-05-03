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
    connect(session, SIGNAL(signal(QString, int, void*)), this, SLOT(signal(const QString&, int, void*)));
}
void XASessionEvents::Disconnect()
{
    emit eventTriggered(tr("XASessionEvents : Disconnect"));
}
void XASessionEvents::Login(const QString &szCode, const QString &szMsg)
{
    emit eventTriggered(tr("XASessionEvents : Login code=%1, msg=%2").arg(szCode).arg(szMsg));
}

void XASessionEvents::Logout()
{
    emit eventTriggered(tr("XASessionEvents : Logout"));
}

void XASessionEvents::exception(int code, const QString &source, const QString &disc, const QString &help)
{
    emit eventTriggered(tr("XASessionEvents : exception code=%1, source=%2, disc=%3, help=%4").arg(code).arg(source).arg(disc).arg(help));
}

void XASessionEvents::propertyChanged(const QString &name)
{
    emit eventTriggered(tr("XASessionEvents : propertyChanged name=%1").arg(name));
}

void XASessionEvents::signal(const QString &name, int argc, void* argv)
{
    emit eventTriggered(tr("XASessionEvents : signal name=%1").arg(name));
}
