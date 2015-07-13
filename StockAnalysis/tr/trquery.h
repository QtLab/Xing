#ifndef TRQUERY_H
#define TRQUERY_H

#include <QObject>
#include "XingLib/xaquery.h"
class TrQuery : public QObject
{
    Q_OBJECT
public:
    explicit TrQuery(const QString& trName, QObject *parent = 0);
    ~TrQuery();

    virtual TrQuery* getQuery() = 0;
signals:
    void ReceiveMsg(const QString& msg);

protected:
    const XAQuery *xaquery();
public slots:
    virtual void request()=0;
    void onReceiveMsg(const QString& msg);
    virtual void onReceiveData(const QString& trCode) = 0;
    virtual void onReceiveChartRealData(const QString& trCode) = 0;
private:
    const XAQuery* mXaQuery;
    const QString mTrName;
};

#endif // TRQUERY_H
