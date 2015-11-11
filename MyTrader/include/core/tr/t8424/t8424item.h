#ifndef T8424ITEM_H
#define T8424ITEM_H

#include "core/tr/tritem.h"
class T8424Item : public TrItem
{
    Q_OBJECT
    Q_PROPERTY(QString hname MEMBER _hname READ hname WRITE setHname)
    Q_PROPERTY(QString upcode MEMBER _upcode READ upcode WRITE setUpCode)

public:
    explicit T8424Item(QObject *parent = 0);
    ~T8424Item();

    QString hname() { return _hname;}
    void setHname(const QString& hname) {
        _hname = hname;
    }

    QString upcode() { return _upcode; }
    void setUpCode(const QString &upcode) {
        _upcode = upcode;
    }

private:
    QString _upcode;	//업종코드
    QString _hname;		//업종명
signals:

public slots:
};

#endif // T8424ITEM_H
