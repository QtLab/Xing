#include "xaquery.h"
#include <ActiveQt/QAxObject>

XAQuery::XAQuery(QObject *parent) :
    QObject(parent),xaquery(new QAxObject("XA_DataSet.XAQuery"))
{
    connect(xaquery, SIGNAL(ReceiveData(QString)), this, SLOT(onReceiveData(const QString&)));
    connect(xaquery, SIGNAL(ReceiveMessage(bool, QString, QString)), this, SLOT(onReceiveMessage(bool, const QString&, const QString&)));
    connect(xaquery, SIGNAL(exception(int, QString, QString, QString)), this, SLOT(onException(int, const QString&, const QString&, const QString&)));
    connect(xaquery, SIGNAL(propertyChanged(QString)), this, SLOT(onPropertyChanged(const QString&)));
    connect(xaquery, SIGNAL(signal(QString, int, void*)), this, SLOT(onSignal(const QString&, int, void*)));

}
bool XAQuery::LoadFromResFile(const QString& trCode)
{
    static const QString res_root_path= tr("C:\\XING\\COM\\Res\\");
    return xaquery->dynamicCall("LoadFromResFile(QString)", res_root_path+trCode).toBool();
}

XAQuery* XAQuery::newTrInstance(const QString& _transaction, QObject *parent)
{
    XAQuery *query_instance = new XAQuery(parent);
    if(query_instance->LoadFromResFile(_transaction))
        return query_instance;
    else
        return NULL;
}
bool XAQuery::Request(bool bNext)
{
    return xaquery->dynamicCall("Request(bool)", bNext).toInt()==1?true:false;
}
void XAQuery::ClearBlockdata(const QString& szFieldName)
{
    xaquery->dynamicCall("ClearBlockdata(QString)", szFieldName);
}

int XAQuery::GetBlockCount(const QString& szBlockName)
{
    return xaquery->dynamicCall("GetBlockCount(QString)", szBlockName).toInt();
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

void XAQuery::SetBlockCount(const QString& szBlockName, int nCount)
{
    xaquery->dynamicCall("SetBlockCount(QString, int)", szBlockName,nCount);
}

void XAQuery::SetResFileName(const QString& ResFileName)
{
    xaquery->dynamicCall("SetResFileName(QString)", ResFileName);
}
void XAQuery::SetFieldData (const QString& szBlockName, const QString& szFieldName, int nOccursIndex, const QString& szData){
    xaquery->dynamicCall("SetFieldData(QString, QString, int, QString)", szBlockName,szFieldName,nOccursIndex,szData );
}
QString XAQuery::GetFieldData(const QString& szBlockName, const QString& szFieldName, int nRecordIndex)
{
    return xaquery->dynamicCall("GetFieldData(QString, QString, int)", szBlockName,szFieldName,nRecordIndex).toString();

}

void XAQuery::onReceiveData(const QString& szTrCode)
{
     QMessageBox::warning(qobject_cast<QWidget*>(this->parent()),tr("onReceiveData"),szTrCode);
     emit ReceiveData(szTrCode);
}

void XAQuery::onReceiveMessage(bool bIsSystemError, const QString& nMessageCode, const QString& szMessage)
{
    QMessageBox::warning(qobject_cast<QWidget*>(this->parent()),tr("onReceiveMessage"),szMessage);
    emit ReceiveMessage(bIsSystemError, nMessageCode, szMessage);
}

void XAQuery::onException(int code, const QString& source, const QString& disc, const QString& help)
{
    emit exception(code, source, disc, help);
}

void XAQuery::onPropertyChanged(const QString& name)
{
    emit propertyChanged(name);
}

void XAQuery::onSignal(const QString& name, int argc, void* argv)
{
    emit signal(name, argc, argv);
}
