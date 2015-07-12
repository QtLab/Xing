#ifndef XAQUERY_H
#define XAQUERY_H

#include <QObject>
#include <QWaitCondition>
#include <QMutex>
#include <QMessageBox>



class QAxObject;

class XAQuery : public QObject
{
    Q_OBJECT
private:
    explicit XAQuery(QObject *parent = 0);

public:
    static XAQuery* newTrInstance(const QString& _transaction, QObject *parent = 0);

    bool XAQuery::LoadFromResFile(const QString& trCode);
    bool Request(bool);
    void SetFieldData (const QString&, const QString&, int nOccursIndex, const QString&);
    void ClearBlockdata(const QString& szFieldName);
    int GetBlockCount(const QString& szBlockName);
    void GetBlockInfo(const QString& szFieldName, QString& szNameK, QString& szNameE, int& nRecordType);
    int GetBlockSize(const QString& szBlockName);
    int GetBlockType(const QString& szBlockName);
    QString GetFieldData(const QString& szBlockName, const QString& szFieldName, int nRecordIndex);
    QString GetFieldDescList(const QString& szBlockName);
    void GetFieldInfo(const QString& szFieldName, const QString& szItemName, int& nItemType, int& nDataSize, int& nDotPoint, int& nOffSet);
    QString GetResData();
    QString GetTrCode();
    QString GetTrDesc();
    void SetBlockCount(const QString& szBlockName, int nCount);
    void SetResFileName(const QString& ResFileName);

signals:        //signals to be used to notify COM event
    void ReceiveMessage(bool , const QString& , const QString& );
    void ReceiveData(const QString&);
    void exception(int code, const QString&, const QString&, const QString&);
    void propertyChanged(const QString& name);
    void signal(const QString& name, int argc, void*argv);

private slots:      //slots to receive COM event
    void onReceiveData(const QString& szTrCode);
    void onReceiveMessage(bool bIsSystemError, const QString& nMessageCode, const QString& szMessage);
    void onException(int code, const QString& source, const QString& disc, const QString& help);
    void onPropertyChanged(const QString& name);
    void onSignal(const QString& name, int argc, void* argv);

private:
    QAxObject* xaquery;

};

#endif // XAQUERY_H
