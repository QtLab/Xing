#ifndef SHCODELISTUPDATER_H
#define SHCODELISTUPDATER_H

#include <QObject>
#include <QWidget>

#include "xing/xaquery.h"
#include "tr/t8430/t8430query.h"
#include "tr/t8430/t8430item.h"

#define USE_THREAD 0
class ShcodeListUpdater : public QObject
{
    Q_OBJECT
public:
    explicit ShcodeListUpdater(QObject *parent = 0);
    ~ShcodeListUpdater();

    void updateShcodeList(QWidget* requester, XAQueryMngr *queryMngr);
signals:
    void shcodeListUpdated();
private slots:
    void onT8430ItemReceived(QList<T8430Item*> list);
    void shcodelistUpdateFinished();
private:
    bool connectDB();
    bool createTable();
};

#endif // SHCODELISTUPDATER_H
