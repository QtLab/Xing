#ifndef SHCODESELECTIONDIALOG_H
#define SHCODESELECTIONDIALOG_H

#include <QDialog>

#include "manager/querymngr.h"
namespace Ui {
	class ShcodeSelectionDialog;
}
class QButtonGroup;
class QPushButton;
class QSqlQueryModel;
class ShcodeSelectionDialog : public QDialog
{
	Q_OBJECT

public:
	explicit ShcodeSelectionDialog(QueryMngr *queryMngr, QWidget *parent = 0);
	~ShcodeSelectionDialog();
	typedef enum { ALL_STOCK = 0, KOSPI = 1, KOSDAQ = 2, ETF = 3, ETN = 4, KONEX = 5, KOTC = 6, ELW = 7, KOSPI_UPJONG = 8, KOSDAQ_UPJONG = 9, SECTOR_UPJONG = 10, SPECIAL_INDEX_UPJONG = 11, REGISTERED = 12, SECTOR_THEME = 13, SECTOR_INDEX = 14 } BUTTON_ID;
private:
	void initButtonGroups();
	void showAllStocks();
	void showKospiStocks();
	void showKosdaqStocks();
	void showETF();
	void showETN();
	void showKonex();
	void showKotc();
	void showElw();
	void showRegistered();
	void showSectorTheme();
	void showSectorIndexUpjong();
	void showKospiUpjong();
	void showKosdaqUpjong();
	void showSectorIndex();
	void showSpecialSectorIndex();
	void updateUpjongCombo(const QString &queryStr);
	void updateShcodeTable(const QString &queryStr);
private slots:
	void onBtnToggled(int id, bool toggled);
	void onShowUpjong(const QString& upjong);
private:
	Ui::ShcodeSelectionDialog *ui;
	QueryMngr *mQueryMngr;
	QButtonGroup *mBtnGroup;
	QSqlQueryModel *mSqlQueryModel;
};

#endif // SHCODESELECTIONDIALOG_H
