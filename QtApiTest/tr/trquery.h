#ifndef TRQUERY_H
#define TRQUERY_H

#include <QObject>
#include "tr/trmetainfo.h"
#include "tr/tritem.h"
#include "XingLib/xaquery.h"
class TrQuery : public QObject
{
    Q_OBJECT
public:
    explicit TrQuery(const QString& trName, QObject *parent = 0);
    ~TrQuery();

    virtual QString toString() = 0;

    QString str(const QVariant &value);
signals:
    void ReceiveMsg(const QString& msg);
    void workDone();
    void scheduleNextQuery();
protected:
    XAQuery* xaquery();
    TrMetaInfo *trInfo();
    QString getTrName();
    virtual TrItem *createItem()=0;
    TrItem *getTrItemFromReceivedData(int occurIndex);
public slots:
    virtual void request();
    virtual void onReceiveMsg(bool bIsSystemError, const QString &msgCode, const QString &msg);
    virtual void onReceiveData(const QString& trCode) = 0;
    virtual void onReceiveChartRealData(const QString& trCode)=0;
private:
    XAQuery* mXaQuery;
    TrMetaInfo mTrInfo;
    const QString mTrName;
};

#endif // TRQUERY_H
