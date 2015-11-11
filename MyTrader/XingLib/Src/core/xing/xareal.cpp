#include "xareal.h"
#include <ActiveQt/QAxObject>

XAReal::XAReal(QObject *parent) :
    QObject(parent),xareal(new QAxObject("XA_DataSet.XAReal"))
{
}
XAReal* XAReal::newTrInstance(const QString& _transactionCode, QObject *parent)
{
    XAReal* real_instance = new XAReal(parent);
    if(real_instance->LoadFromResFile(_transactionCode))
        return real_instance;
    else
        return NULL;
}
bool XAReal::LoadFromResFile(const QString& trCode)
{
    static const QString res_root_path= tr("C:\\XING\\COM\\Res\\");
    return  xareal->dynamicCall("LoadFromResFile(QString)", res_root_path+trCode).toBool();
}

void XAReal::AdviseRealData()
{
    xareal->dynamicCall("AdviseRealData()");
}

QString XAReal::GetFieldData(const QString &szBlockName, const QString &szFieldName)
{
    QString result = xareal->dynamicCall("GetFieldData(QString, QString)", szBlockName,szFieldName ).toString();
    return result;
}

QString XAReal::GetTrCode()
{
    QString result = xareal->dynamicCall("GetTrCode()").toString();
    return result;
}

void XAReal::SetFieldData(const QString &szBlockName, const QString &szFieldName, const QString &szData)
{
    xareal->dynamicCall("SetFieldData(QString, QString, QString)", szBlockName,szFieldName, szData);
}

void XAReal::SetResFileName(const QString &ResFileName)
{
    xareal->dynamicCall("SetResFileName(QString)", ResFileName);
}

void XAReal::UnadviseRealData()
{
    xareal->dynamicCall("UnadviseRealData()");

}

void XAReal::UnadviseRealDataWithKey(const QString &szCode)
{
    xareal->dynamicCall("UnadviseRealDataWithKey(QString)", szCode);
}


void XAReal::onReceiveRealData(const QString &szTrCode)
{
    emit ReceiveRealData(szTrCode);
}

void XAReal::onException(int code, const QString &source, const QString &disc, const QString &help)
{
    emit exception(code, source, disc, help);
}

void XAReal::onPropertyChanged(const QString &name)
{
    emit propertyChanged(name);
}

void XAReal::onSignal(const QString &name, int argc, void *argv)
{
    emit signal(name, argc, argv);
}


