#include "TrHandler.h"

TrHandler::TrHandler(QObject *parent):QObject(parent)
{

}
TrHandler::~TrHandler()
{

}

long TrHandler::changeStringToLong(char *strLong, int length)
{
    int multiply = 1;
    long result = 0;

    for (int i=length-1; i>=0; i--) {
        result += ((unsigned int)(strLong[i] - '0') * multiply);
        multiply *= 10;
    }

    return result;
}

void TrHandler::printLog(const QString &log)
{
    QMetaObject* metaObj = metaObject();
    qDebug()<<"["<<metaObj->className()<<"] "<<log;
}

void TrHandler::addTrQuery(TrQuery* query)
{
    int requestId = sendRequest(query);
    mQueryMap.insert(requestId, query);
}

