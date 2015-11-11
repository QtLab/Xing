#include "qperiodselectiondlg.h"
QPeriodSelectionDlg::QPeriodSelectionDlg(const QString &title, QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	setWindowTitle(title);
	ui.sDateEdit->setDate(QDate::currentDate());
	ui.eDateEdit->setDate(QDate::currentDate());
}

QPeriodSelectionDlg::~QPeriodSelectionDlg()
{

}

QDate QPeriodSelectionDlg::startDate()
{
	return ui.sDateEdit->date();
}

QDate QPeriodSelectionDlg::endDate()
{
	return ui.eDateEdit->date();
}