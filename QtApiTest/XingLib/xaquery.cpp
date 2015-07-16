#include "xaquery.h"
#include <ActiveQt/QAxObject>

XAQuery::XAQuery(QObject *parent) :
    QObject(parent),xaquery(new QAxObject("XA_DataSet.XAQuery"))
{
    connect(xaquery, SIGNAL(ReceiveData(QString)), this, SLOT(onReceiveData(const QString&)));
    connect(xaquery, SIGNAL(ReceiveMessage(bool, QString, QString)), this, SLOT(onReceiveMessage(bool, const QString&, const QString&)));
    connect(xaquery, SIGNAL(ReceiveChartRealData(QString)), this, SLOT(onReceiveChartRealData(const QString&)));
}


XAQuery* XAQuery::newTrInstance(const QString& _transaction, QObject *parent)
{
    XAQuery *query_instance = new XAQuery(parent);
    if(query_instance->LoadFromResFile(_transaction))
        return query_instance;
    else
        return NULL;
}
long XAQuery::Request(bool bNext)
{
    return xaquery->dynamicCall("Request(bool)", bNext).toInt();
}
QString XAQuery::GetFieldData(const QString& szBlockName, const QString& szFieldName, long nOccursIndex)
{
    return xaquery->dynamicCall("GetFieldData(QString, QString, int)", szBlockName,szFieldName,nOccursIndex).toString();

}
void XAQuery::SetFieldData (const QString& szBlockName, const QString& szFieldName, long nOccursIndex, const QString& szData){
    xaquery->dynamicCall("SetFieldData(QString, QString, int, QString)", szBlockName,szFieldName,nOccursIndex,szData );
}
long XAQuery::GetBlockCount(const QString& szBlockName)
{
    return xaquery->dynamicCall("GetBlockCount(QString)", szBlockName).toInt();
}

void XAQuery::SetBlockCount(const QString& szBlockName, long nCount)
{
    xaquery->dynamicCall("SetBlockCount(QString, int)", szBlockName,nCount);
}
bool XAQuery::LoadFromResFile(const QString& trCode)
{
    static const QString res_root_path= tr("C:\\eBest\\xingAPI\\Res\\");
    return xaquery->dynamicCall("LoadFromResFile(QString)", res_root_path+trCode+".res").toBool();
}
void XAQuery::ClearBlockdata(const QString& szFieldName)
{
    xaquery->dynamicCall("ClearBlockdata(QString)", szFieldName);
}

QString XAQuery::GetBlockData(const QString &szBlockName)
{
    return xaquery->dynamicCall("GetBlockData(QString)", szBlockName).toString();
}

int XAQuery::GetTrCountPerSec(const QString &trCode)
{
    return xaquery->dynamicCall("GetTrCountPerSec(QString)", trCode).toInt();
}

long XAQuery::RequestService(const QString &trCode, const QString &szData)
{
    return xaquery->dynamicCall("RequestService(QString, QString)", trCode, szData).toLongLong();
}



void XAQuery::GetBlockInfo(const QString& szFieldName, QString& szNameK, QString& szNameE, int& nRecordType)
{
    xaquery->dynamicCall("GetBlockInfo(QString, QString&, QString&, int&)", szFieldName, szNameK, szNameE, nRecordType);
}

int XAQuery::GetBlockSize(const QString& szBlockName)
{
    return xaquery->dynamicCall("GetBlockSize(QString)", szBlockName).toInt();
}

int XAQuery::GetBlockType(const QString& szBlockName)
{
    return xaquery->dynamicCall("GetBlockType(QString)", szBlockName).toInt();
}

QString XAQuery::GetFieldDescList(const QString& szBlockName)
{
    return xaquery->dynamicCall("GetFieldDescList(QString)", szBlockName).toString();
}

void XAQuery::GetFieldInfo(const QString& szFieldName, const QString& szItemName, int& nItemType, int& nDataSize, int& nDotPoint, int& nOffSet)
{
    xaquery->dynamicCall("GetFieldInfo(QString, QString, int&, int&, int&, int&)", szFieldName,szItemName,nItemType,nDataSize,nDotPoint,nOffSet);
}

QString XAQuery::GetResData()
{
    return xaquery->dynamicCall("GetResData()").toString();
}

QString XAQuery::GetTrCode()
{
    return xaquery->dynamicCall("GetTrCode()").toString();
}

QString XAQuery::GetTrDesc()
{
    return xaquery->dynamicCall("GetTrDesc()").toString();
}


void XAQuery::SetResFileName(const QString& ResFileName)
{
    xaquery->dynamicCall("SetResFileName(QString)", ResFileName);
}

void XAQuery::onReceiveMessage(bool bIsSystemError, const QString &msgCode, const QString &msg)
{
    emit ReceiveMessage(bIsSystemError, msgCode, msg);
}

void XAQuery::onReceiveData(const QString &trCode)
{
    emit ReceiveData(trCode);
}

void XAQuery::onReceiveChartRealData(const QString &trCode)
{
    emit ReceiveChartRealData(trCode);
}




