#ifndef TRITEM_H
#define TRITEM_H

#include <QObject>
#include <QStringList>

class TrItem : public QObject
{
    Q_OBJECT
public:
    explicit TrItem(QObject *parent = 0);
    ~TrItem();

    virtual QStringList getPropertyList()=0;
signals:

public slots:
};

#endif // TRITEM_H
