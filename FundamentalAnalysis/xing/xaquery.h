#ifndef XAQUERY_H
#define XAQUERY_H

#include <QObject>
#include <QMap>
#include <QThread>
#include "xing/IXingAPI.h"
#include "tr/trquery.h"
#include "tr/TrHandler.h"
class TrHandler;

class XAQueryMngr : public QThread
{
    Q_OBJECT
public:
    ~XAQueryMngr();
    static XAQueryMngr* getInstance();
    static void init(QObject *parent);
private :
    explicit XAQueryMngr(QObject *parent=0);

private:
    static XAQueryMngr* sInstance;
    QMap<QString,TrHandler*> mHandlerMap;

public slots:
    void requestQuery(TrQuery* query);
    void handleResponse(WPARAM wparam, LPARAM lparam);
};



#endif // XAQUERY_H
