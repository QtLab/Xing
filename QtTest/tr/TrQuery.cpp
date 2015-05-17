#include "trquery.h"

TrQuery::TrQuery(const QWidget& requester, QString name, QObject *parent) : mRequester(requester), mName(name), QObject(parent)
{

}

TrQuery::~TrQuery()
{

}

