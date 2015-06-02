#ifndef TRITEM_H
#define TRITEM_H

#include <QObject>
#include <QList>
#include <QString>
#include <QMap>

class TrItem : public QObject
{
    Q_OBJECT
public:
    explicit TrItem(QObject *parent = 0);
    ~TrItem();

    virtual QList<QString> getPropertyList() = 0;
    virtual QList<QString> getPropertyNameList() = 0;
    virtual QString getPropertyByName(const QString &name)=0;
protected:
    QMap<QString,QString> mPropertyNameMap;
signals:

public slots:
};

#endif // TRITEM_H
