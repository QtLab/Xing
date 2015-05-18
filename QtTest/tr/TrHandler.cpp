#include "TrHandler.h"

template < typename T >
TrHandler<T>::TrHandler(QObject *parent):QObject(parent)
{

}
template < typename T >
TrHandler<T>::~TrHandler()
{

}

template < typename T >
long TrHandler<T>::changeStringToLong(char *strLong, int length)
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

template < typename T >
void TrHandler<T>::addTrQuery(T query)
{
    int requestId = sendRequest(query);
    mQueryMap.insert(requestId, query);
}

