#ifndef MOVEMENTMNGR_H
#define MOVEMENTMNGR_H

#include <QObject>
#include "data/movementinfo.h"
#include "util/xingthread.h"
class MovementMngr : public QObject
{
    Q_OBJECT
public:
    explicit MovementMngr(QObject *parent = 0);
    ~MovementMngr();
    void reqestMovementInfo(const QString& shcode);
signals:
    void responseMovementInfo(MovementInfo* info);
private slots:
    void makeMovementInfo(const QString& shcode);
private:
    XingThread mThread;
};

#endif // MOVEMENTMNGR_H
