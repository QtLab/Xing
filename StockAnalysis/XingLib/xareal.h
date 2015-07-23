#ifndef XAREAL_H
#define XAREAL_H

#include <QObject>

class QAxObject;

class XAReal : public QObject
{
    Q_OBJECT
private:
     explicit XAReal(QObject *parent = 0);

public:
    static XAReal* newTrInstance(const QString& _transaction, QObject *parent = 0);
    bool LoadFromResFile(const QString&);
    void AdviseRealData();
    QString GetFieldData(const QString& szBlockName, const QString& szFieldName);
    QString GetTrCode();
    void SetFieldData(const QString& szBlockName, const QString& szFieldName, const QString& szData);
    void SetResFileName(const QString& ResFileName);
    void UnadviseRealData();
    void UnadviseRealDataWithKey(const QString& szCode);

signals:
    void ReceiveRealData(const QString& szTrCode);
    void exception(int code, const QString& source, const QString& disc, const QString& help);
    void propertyChanged(const QString& name);
    void signal(const QString& name, int argc, void* argv);
private slots:
    void onReceiveRealData(const QString& szTrCode);
    void onException(int code, const QString& source, const QString& disc, const QString& help);
    void onPropertyChanged(const QString& name);
    void onSignal(const QString& name, int argc, void* argv);

private:
    QAxObject* xareal;
};

#endif // XAREAL_H
