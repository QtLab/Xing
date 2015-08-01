#include "tritem.h"
#include <QTextStream>
#include <QTextCodec>
#include <QMetaObject>
#include <QMetaProperty>
#include <QtSql/QSqlQuery>
#include <QVariant>
#include <QTime>
#include <QDate>
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

QString TrItem::toString()
{

    QString desc;
    QTextStream stream(&desc);
    foreach(QString name, this->getPropertyNameList())
    {
        QString prop = this->getPropertyByName(name);
        stream<<name<<"("<<prop<<") = "<<this->property(prop.toLocal8Bit()).toString()<<endl;
    }
    return desc;

}

void TrItem::setPropertyFromQuery(QSqlQuery *query)
{
    const QMetaObject *metaObj = metaObject();
    for(int i = 1; i<metaObj->propertyCount(); i++) {
        QMetaProperty metaProp = metaObj->property(i);
        switch(metaProp.type()) {
        case QMetaType::Bool:
            setProperty(metaProp.name(), query->value(tr(metaProp.name())).toBool());
            break;
        case QMetaType::Long:
            setProperty(metaProp.name(), query->value(tr(metaProp.name())).toInt());
            break;
        case QMetaType::Float:
            setProperty(metaProp.name(), query->value(tr(metaProp.name())).toFloat());
            break;
        case QMetaType::QTime:
            setProperty(metaProp.name(), query->value(tr(metaProp.name())).toTime());
            break;
        case QMetaType::QDate:
            setProperty(metaProp.name(), query->value((metaProp.name())).toDate());
            break;
        default:
            setProperty(metaProp.name(), query->value((metaProp.name())).toString());
            break;
        }
    }
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

QString TrItem::makeSqlInsertQuery(const QString &tableName)
{
    QString query = QString("INSERT INTO %1 ").arg(tableName);
    QString columnStr;
    QString valuesStr;
    QTextStream columnsStream(&columnStr);
    QTextStream valuesStream(&valuesStr);
    const QMetaObject* metaObject = this->metaObject();
    for(int i = 1; i<metaObject->propertyCount();i++) {
        QMetaProperty metaProperty = metaObject->property(i);
        columnsStream<<"`"<<metaProperty.name()<<"`";
        switch(metaProperty.type()){
        case QMetaType::Bool:
            valuesStream<<"'"<<this->property(metaProperty.name()).toBool()<<"'";
            break;
        case QMetaType::Long:
            valuesStream<<this->property(metaProperty.name()).toInt();
            break;
        case QMetaType::Float:
            valuesStream<<this->property(metaProperty.name()).toFloat();
            break;
        case QMetaType::QTime:
            valuesStream<<"'"<<this->property(metaProperty.name()).toTime().toString(tr("hh:mm:ss"))<<"'";
            break;
        case QMetaType::QDate:
            valuesStream<<"'"<<this->property(metaProperty.name()).toDate().toString(tr("yyyyMMdd"))<<"'";
            break;
        default:
            valuesStream<<"'"<<this->property(metaProperty.name()).toString()<<"'";
            break;
        }
        if(i != metaObject->propertyCount()-1){
            columnsStream<<",";
            valuesStream<<",";
        }
    }
    return query + "("+columnStr+") VALUES ("+valuesStr+")";

}

QString TrItem::makeSqlUpdateQuery(const QString &tableName, const QString &where)
{
    QString query = QString("UPDATE %1 SET ").arg(tableName);
    QString updateValues;
    QTextStream valuesStream(&updateValues);
    const QMetaObject* metaObject = this->metaObject();
    for(int i = 1; i<metaObject->propertyCount();i++) {
        QMetaProperty metaProperty = metaObject->property(i);
        valuesStream<<"`"<<metaProperty.name()<<"`"<<"=";
        switch(metaProperty.type()){
        case QMetaType::Bool:
            valuesStream<<"'"<<this->property(metaProperty.name()).toBool()<<"'";
            break;
        case QMetaType::Long:
            valuesStream<<this->property(metaProperty.name()).toInt();
            break;
        case QMetaType::Float:
            valuesStream<<this->property(metaProperty.name()).toFloat();
            break;
        case QMetaType::QTime:
            valuesStream<<"'"<<this->property(metaProperty.name()).toTime().toString(tr("hh:mm:ss"))<<"'";
            break;
        case QMetaType::QDate:
            valuesStream<<"'"<<this->property(metaProperty.name()).toDate().toString(tr("yyyyMMdd"))<<"'";
            break;
        default:
            valuesStream<<"'"<<this->property(metaProperty.name()).toString()<<"'";
            break;
        }
        if(i != metaObject->propertyCount()-1){
            valuesStream<<",";
        }
    }
    return query+updateValues+where;
}

