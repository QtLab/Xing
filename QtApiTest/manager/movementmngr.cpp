#include <QMetaObject>
#include <QDateTime>
#include "movementmngr.h"
#include "util/log.h"

MovementMngr::MovementMngr(QObject *parent) : QObject(parent)
{
    moveToThread(&mThread);
    mThread.start();
}

MovementMngr::~MovementMngr()
{

}

void MovementMngr::reqestMovementInfo(const QString &shcode)
{
    QMetaObject::invokeMethod(this, "makeMovementInfo", Qt::QueuedConnection, Q_ARG(QString, shcode));
}

void MovementMngr::makeMovementInfo(const QString &shcode)
{
    qCDebug(movementMngr)<<"start makeMovementInfo at "<<QDateTime::currentDateTime().toString(Qt::ISODate);
    MovementInfo* info = MovementInfo::createMovementInfo(shcode, MovementInfo::INDIVISUAL);
    emit responseMovementInfo(info);
    qCDebug(movementMngr)<<"end makeMovementInfo at "<<QDateTime::currentDateTime().toString(Qt::ISODate);

}

