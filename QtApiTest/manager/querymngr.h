#ifndef QUERYMNGR_H
#define QUERYMNGR_H

#include <QObject>
#include <QThread>
#include <QTimer>
class QueryMngr : public QObject
{
    Q_OBJECT
public:
    explicit QueryMngr(QObject *parent = 0);
    ~QueryMngr();

signals:

public slots:
    void doJob();
    void doTimeoutJob();
private:
    void initRequestTimer();
private:
    QThread mThread;
    QTimer mRequestTimer;
    QList<TrQuery*> mQueryList;

};

#endif // QUERYMNGR_H
