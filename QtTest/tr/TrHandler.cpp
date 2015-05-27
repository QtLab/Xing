#include "TrHandler.h"
#include <QDebug>
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

float TrHandler::changeStringToFloat(char *strFloat, int length)
{
    int i, j, multiply;
    float result = 0;

    for (i=0; i<length; i++) {
        multiply = 1;
        for (j=0; j<i; j++)
            multiply *= 10;

        result += (float)((int)(strFloat[length-1-i] - '0') * 0.01 * multiply);
    }

    return result;
}

float changeStringToFloat(char * strFloat)
{

}
void TrHandler::printLog(const QString &log)
{
    const QMetaObject* metaObj = metaObject();
    qDebug()<<"["<<metaObj->className()<<"] "<<log;
}

void TrHandler::changeReqId(int fromId, int toId)
{
    TrQuery* query = mQueryMap.value(fromId);
    mQueryMap.remove(fromId);
    mQueryMap.insert(toId, query);
}

void TrHandler::addTrQuery(TrQuery* query)
{
    int requestId = sendRequest(query);
    mQueryMap.insert(requestId, query);
}

