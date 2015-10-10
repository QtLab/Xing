#ifndef SHCODESELECTIONDIALOG_H
#define SHCODESELECTIONDIALOG_H

#include <QDialog>
#include "data/commontype.h"
#include "function/query/querymngr.h"
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
	typedef enum { ALL_STOCK_BTN_ID = 0, KOSPI_BTN_ID = 1, KOSDAQ_BTN_ID = 2, ETF_BTN_ID = 3, ETN_BTN_ID = 4, KONEX_BTN_ID = 5, KOTC_BTN_ID = 6, ELW_BTN_ID = 7, KOSPI_UPJONG_BTN_ID = 8, KOSDAQ_UPJONG_BTN_ID = 9, SECTOR_UPJONG_BTN_ID = 10, SPECIAL_INDEX_UPJONG_BTN_ID = 11, REGISTERED_BTN_ID = 12, SECTOR_THEME_BTN_ID = 13, SECTOR_INDEX_BTN_ID = 14 } BUTTON_ID;
	QString getSelectedShcode();
	QString getSelectedUpcode();
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
	void showSectorIndex();
	void showKospiUpjong();
	void showKosdaqUpjong();
	void showSectorIndexUpjong();
	void showSpecialSectorIndexUpjong();
	void updateUpjongCombo(const QString &queryStr);
	void updateTableView(const QString &queryStr);
private slots:
	void onBtnToggled(int id, bool toggled);
	void onShowShcodeListByUpjong(const QString& upjong);
	void onShowUpjongCodeListByUpjongType(const UPJONG_TYPE upjongType);
public slots:
	void onTableViewClicked(const QModelIndex &index);
signals:
	void shcodeSelected(const QString &shcode);
	void upcodeSelected(const QString &upcode);

private:
	Ui::ShcodeSelectionDialog *ui;
	QueryMngr *mQueryMngr;
	QButtonGroup *mBtnGroup;
	QSqlQueryModel *mSqlQueryModel;
	BUTTON_ID mCurrentSelectedBtnId;
	QString mCurrentSelectedCode;
};

#endif // SHCODESELECTIONDIALOG_H
