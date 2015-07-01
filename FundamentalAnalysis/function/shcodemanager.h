#ifndef SHCODEMANAGER_H
#define SHCODEMANAGER_H

#include <QObject>
#include <QWidget>

#include "xing/xaquery.h"
#include "tr/t8430/t8430query.h"
#include "tr/t8430/t8430item.h"

#define USE_THREAD 0
class ShcodeManager : public QObject
{
    Q_OBJECT
public:
    explicit ShcodeManager(QObject *parent = 0);
    ~ShcodeManager();
    void requestUpdate(QWidget* requester);

    QStringList getShcodeList();
    QString getStockName(const QString& shcode);
signals:
    void updateDone();

public slots:
    void init();
private slots:
    void onT8430ItemReceived(QList<T8430Item*> list);

private:
    void insertShcodeListToDB(T8430Item *item);
    bool connectDB();
    bool createTable();

private:
    QMap<QString, QString> mShcodeMap;
};

#endif // SHCODEMANAGER_H
