#ifndef TRQUERY_H
#define TRQUERY_H

#include <QObject>
#include <QWidget>
class TrQuery : public QObject
{
    Q_OBJECT
public:

    ~TrQuery();

    QString getName() {return mName;}
protected:
    explicit TrQuery(const QWidget& requester, QString name, QObject *parent = 0);
    QString mName;
    const QWidget& mRequester;
signals:

public slots:
};

#endif // TRQUERY_H
