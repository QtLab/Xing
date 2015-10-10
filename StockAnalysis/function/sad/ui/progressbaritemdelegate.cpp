#include <QApplication>
#include <QString>
#include "progressbaritemdelegate.h"

ProgressBarItemDelegate::ProgressBarItemDelegate(QObject *parent) : QStyledItemDelegate(parent)
{

}

ProgressBarItemDelegate::~ProgressBarItemDelegate()
{

}

void ProgressBarItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    int percentage = index.data().toInt();
    QStyleOptionProgressBar progressBarOption;
    progressBarOption.rect = option.rect;
    progressBarOption.minimum = 0;
    progressBarOption.maximum = 100;
    progressBarOption.progress = percentage;
    progressBarOption.text = QString::number(percentage)+"%";
    progressBarOption.textVisible = true;
    progressBarOption.textAlignment = Qt::AlignCenter;
    QApplication::style()->drawControl(QStyle::CE_ProgressBar, &progressBarOption, painter);
}

