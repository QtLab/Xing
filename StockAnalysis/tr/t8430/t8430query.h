#ifndef T8430QUERY_H
#define T8430QUERY_H

#include <QObject>
#include "XingLib/xaquery.h"
#include "tr/trquery.h"
#include "tr/t8430/t8430item.h"
class T8430Query : public TrQuery
{
    Q_OBJECT
public:
    typedef enum { ALL=0, KOSPI, KOSDAQ } MODE;

    ~T8430Query();
    static T8430Query* createQuery(MODE mode, QObject *parent=0);
    void setMode(MODE mode);
    virtual T8430Query *getQuery() override;
protected:
    explicit T8430Query(QObject *parent = 0);
signals:

public slots:
    virtual void request() override;
    virtual void onReceiveData(const QString& trCode) override;
    virtual void onReceiveChartRealData(const QString& trCode) override;
private:
    MODE mMode;

    static constexpr QString TR_NAME = "t8430";
    static constexpr QString IN_BLOCK_NAME = "t8430InBlock";
    static constexpr QString OUT_BLOCK_NAME = "t8430OutBlock";
};

#endif // T8430QUERY_H
