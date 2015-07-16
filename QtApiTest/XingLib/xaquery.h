#ifndef XAQUERY_H
#define XAQUERY_H

#include <QObject>
#include <QWaitCondition>
#include <QMutex>




class QAxObject;

class XAQuery : public QObject
{
    Q_OBJECT
private:
    explicit XAQuery(QObject *parent = 0);

public:
    static XAQuery* newTrInstance(const QString& _transaction, QObject *parent = 0);


    long Request(bool);
    QString GetFieldData(const QString& szBlockName, const QString& szFieldName, long nOccursIndex);
    void SetFieldData (const QString& szBlockName, const QString& szFieldName, long nOccursIndex, const QString& szData);
    long GetBlockCount(const QString& szBlockName);
    void SetBlockCount(const QString& szBlockName, long nCount);
    bool LoadFromResFile(const QString& trCode);
    void ClearBlockdata(const QString& szFieldName);
    QString GetBlockData(const QString& szBlockName);
    int GetTrCountPerSec(const QString& trCode);
    long RequestService(const QString& trCode, const QString& szData);

    void GetBlockInfo(const QString& szFieldName, QString& szNameK, QString& szNameE, int& nRecordType);
    int GetBlockSize(const QString& szBlockName);
    int GetBlockType(const QString& szBlockName);

    QString GetFieldDescList(const QString& szBlockName);
    void GetFieldInfo(const QString& szFieldName, const QString& szItemName, int& nItemType, int& nDataSize, int& nDotPoint, int& nOffSet);
    QString GetResData();
    QString GetTrCode();
    QString GetTrDesc();

    void SetResFileName(const QString& ResFileName);

signals:        //signals to be used to notify COM event
    void ReceiveMessage(bool bIsSystemError, const QString& msgCode, const QString& msg);
    void ReceiveData(const QString& trCode);
    void ReceiveChartRealData(const QString& trCode);

public slots:
    void onReceiveMessage(bool bIsSystemError, const QString& msgCode, const QString& msg);
    void onReceiveData(const QString& trCode);
    void onReceiveChartRealData(const QString& trCode);
private:
    QAxObject* xaquery;

};

#endif // XAQUERY_H
