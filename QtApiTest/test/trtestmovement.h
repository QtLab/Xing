#ifndef TRTESTMOVEMENT_H
#define TRTESTMOVEMENT_H

#include <QObject>

class TrTestMovement : public QObject
{
    Q_OBJECT
public:
    explicit TrTestMovement(QObject *parent = 0);
    ~TrTestMovement();

signals:

public slots:
    void start();
};

#endif // TRTESTMOVEMENT_H
