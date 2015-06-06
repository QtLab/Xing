#ifndef TRITEM_H
#define TRITEM_H

#include <QObject>
#include <QList>
#include <QString>
#include <QMap>

#define TO_STRING_AUX( x )  #x
#define TO_STRING( x )      TO_STRING_AUX( x )

#define DEFINE_PROPERTY_NAME(name, property) mPropertyNameMap.insert(qkor(name), property)
class TrItem : public QObject
{
    Q_OBJECT
public:
    explicit TrItem(QObject *parent = 0);
    ~TrItem();

    QList<QString> getPropertyList();
    QList<QString> getPropertyNameList();
    QString getPropertyByName(const QString &name);
protected:
    QMap<QString,QString> mPropertyNameMap;

    QString qkor(const char *strKor);
signals:

public slots:
};

#endif // TRITEM_H
