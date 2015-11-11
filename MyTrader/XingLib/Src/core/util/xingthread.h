#ifndef XINGTHREAD_H
#define XINGTHREAD_H

#include <QThread>
class XingThread : public QThread
{
    Q_OBJECT
public:
    explicit XingThread(QObject *parent = 0);
    ~XingThread();
protected:
    virtual void run() override;
signals:

public slots:
};

#endif // XINGTHREAD_H
