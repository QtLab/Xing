#ifndef RESULTDIALOG_H
#define RESULTDIALOG_H

#include <QDialog>
#include <QList>
#include <QTableWidget>
#include <QGridLayout>
#include "tr/tritem.h"
class ResultDialog : public QDialog
{
    Q_OBJECT
public:
    explicit ResultDialog(QWidget *parent = 0);
    ~ResultDialog();
    void setData(QList<TrItem*> list);
private:
    QTableWidget* mTableWidget;
    QGridLayout* mLayout;
signals:

public slots:
};

#endif // RESULTDIALOG_H
