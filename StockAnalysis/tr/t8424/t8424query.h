#ifndef T8424QUERY_H
#define T8424QUERY_H

#include <QObject>
#include "tr/blocktrquery.h"
#include "tr/t8424/t8424item.h"
#include "data/commontype.h"
class T8424Query : public BlockTrQuery
{
    Q_OBJECT
    Q_PROPERTY(QString gubun MEMBER _gubun READ gubun WRITE setGubun)
public:
    ~T8424Query();
    static T8424Query *createQuery(MARKET_TYPE upType=ALL, QObject *parent = 0);

    void setGubun(const QString& gubun) {_gubun = gubun;}
    QString gubun() { return _gubun; }

protected:
    explicit T8424Query(QObject *parent = 0);
    virtual T8424Item *createItem() override;

private:
    QString _gubun;
};

#endif // T8424QUERY_H
