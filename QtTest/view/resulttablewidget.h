#ifndef RESULTTABLEWIDGET_H
#define RESULTTABLEWIDGET_H

#include <QWidget>
#include <QTableWidget>
#include <QList>

template <class T>
class ResultTableWidget : public QTableWidget
{
    Q_OBJECT
public:
    explicit ResultTableWidget(const QList<T> &contentList, QWidget *parent = 0);
    ~ResultTableWidget();

private:
    QList<T> mContentList;
signals:

public slots:
};

#endif // RESULTTABLEWIDGET_H
