#include "trquery.h"
#include <QDebug>
TrQuery::TrQuery(const QWidget* requester, QString name, QObject *parent) : mRequester(requester), mName(name),bIsFinished(false), QObject(parent)
{

}

TrQuery::~TrQuery()
{
    qDebug()<<"TrQuery for "<<mName<<" is destoryed";
}

void TrQuery::setFinished()
{
    bIsFinished = true;
}

bool TrQuery::isFinished()
{
    return bIsFinished;
}

