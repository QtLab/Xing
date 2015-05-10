#ifndef XAQUERY_H
#define XAQUERY_H

#include <QThread>

class XAQuery : public QThread
{
    Q_OBJECT
public:
    XAQuery();
    ~XAQuery();

protected:
    void run();

signals:

public slots:
};

#endif // XAQUERY_H
