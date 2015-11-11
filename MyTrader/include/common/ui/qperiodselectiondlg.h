#ifndef QPERIODSELECTIONDLG_H
#define QPERIODSELECTIONDLG_H

#include <QDialog>
#include <QDate>
#include "ui_qperiodselectiondlg.h"

class QPeriodSelectionDlg : public QDialog
{
	Q_OBJECT

public:
	explicit QPeriodSelectionDlg(const QString &title, QWidget *parent = 0);
	~QPeriodSelectionDlg();
	QDate startDate();
	QDate endDate();

private:
	Ui::QPeriodSelectionDlg ui;
};

#endif // QPERIODSELECTIONDLG_H
