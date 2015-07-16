#ifndef TRQUERY_H
#define TRQUERY_H

#include <QObject>
#include "tr/trmetainfo.h"
#include "XingLib/xaquery.h"
class TrQuery : public QObject
{
    Q_OBJECT
public:
    explicit TrQuery(const QString& trName, QObject *parent = 0);
    ~TrQuery();

    virtual TrQuery* getQuery() = 0;
    virtual void toString() = 0;

    QString str(const QVariant &value);
signals:
    void ReceiveMsg(const QString& msg);

protected:
    XAQuery* xaquery();
    QString getTrName();

public slots:
    virtual void request();
    void onReceiveMsg(const QString& msg);
    virtual void onReceiveData(const QString& trCode) = 0;
    virtual void onReceiveChartRealData(const QString& trCode) = 0;
private:
    XAQuery* mXaQuery;
    TrMetaInfo mTrInfo;
    const QString mTrName;
};

#endif // TRQUERY_H
