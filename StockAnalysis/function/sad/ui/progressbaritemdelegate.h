#ifndef PROGRESSBARITEMDELEGATE_H
#define PROGRESSBARITEMDELEGATE_H

#include <QObject>
#include <QStyledItemDelegate>
class ProgressBarItemDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit ProgressBarItemDelegate(QObject *parent = 0);
    ~ProgressBarItemDelegate();

    virtual void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
signals:

public slots:
};

#endif // PROGRESSBARITEMDELEGATE_H
