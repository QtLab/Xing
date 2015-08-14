#ifndef UPCODESELECTIONDIALOG_H
#define UPCODESELECTIONDIALOG_H

#include <QDialog>
#include "manager/querymngr.h"
#include "tr/t8424/t8424query.h"

namespace Ui {
class UpCodeSelectionDialog;
}

class UpCodeSelectionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit UpCodeSelectionDialog(QueryMngr* queryMngr, QWidget *parent = 0);
    ~UpCodeSelectionDialog();
    QList<QString> getUpcodeList();
public slots:
    void onUpcodeUpdate();
private:
private:
    Ui::UpCodeSelectionDialog *ui;
    QueryMngr *mQueryMngr;
};

#endif // UPCODESELECTIONDIALOG_H
