#include "trquery.h"
#include <QDebug>
TrQuery::TrQuery(QString name, HWND winId, QObject *parent) : mHwnd(winId), mName(name),bIsFinished(false), QObject(parent)
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

