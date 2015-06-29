#include "tritem.h"
#include <QTextCodec>
TrItem::TrItem(QObject *parent) : QObject(parent)
{

}

TrItem::~TrItem()
{

}

QList<QString> TrItem::getPropertyList()
{
    return mPropertyNameMap.values();
}

QList<QString> TrItem::getPropertyNameList()
{
    return mPropertyNameList;
}

QString TrItem::getPropertyByName(const QString &name)
{
    return mPropertyNameMap.value(name);
}
QString TrItem::qkor(const char *strKor)
{
    static QTextCodec *codec = QTextCodec::codecForName("eucKR");
    return codec->toUnicode(strKor);
}

void TrItem::addItemProperty(QString name, QString property)
{
    mPropertyNameMap.insert(name, property);
    mPropertyNameList.append(name);
}

