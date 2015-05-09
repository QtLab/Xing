#ifndef XAQUERY_H
#define XAQUERY_H


class XAQuery : public QObject
{
    Q_OBJECT
public:
    explicit XAQuery(QObject *parent = 0);
    ~XAQuery();

signals:

public slots:
};

#endif // XAQUERY_H
