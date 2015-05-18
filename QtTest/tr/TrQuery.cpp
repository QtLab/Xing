#include "trquery.h"
#include <QDebug>
TrQuery::TrQuery(const QWidget& requester, QString name, QObject *parent) : mRequester(requester), mName(name), QObject(parent)
{

}

TrQuery::~TrQuery()
{
    qDebug()<<"TrQuery for "<<mName<<" is destoryed";
}

