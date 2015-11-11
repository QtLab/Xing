#ifndef TRADERX_H
#define TRADERX_H

#include <QtWidgets/QDialog>
#include "ui_traderx.h"

class QueryMngr;
class UpdateCenter;
class ShcodeSelectionDialog;
class ChartWidget;
class TraderX : public QDialog
{
	Q_OBJECT

public:
	TraderX(QWidget *parent = 0);
	~TraderX();

private slots:
	void on_updateStockInfoBtn_clicked();
	void on_updateCodeTableBtn_clicked();
	void on_updateMovementBtn_clicked();
	void on_showChartBtn_clicked();
private:
	Ui::TraderXClass ui;
	QueryMngr *mQueryMngr;
	UpdateCenter *mUpdateCenter;
	ShcodeSelectionDialog *mShcodeSelectionDialog;
	ChartWidget *mChartWidget;
};

#endif // TRADERX_H
