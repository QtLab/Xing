#include "traderx.h"
#include "core/query/querymngr.h"
#include "service/info/updatecenter.h"
#include "common/ui/shcodeselectiondialog.h"
#include "service/chart/ui/chartwidget.h"
#include <QtWidgets/QMessageBox>

TraderX::TraderX(QWidget *parent)
	: QDialog(parent), mQueryMngr(new QueryMngr()), mUpdateCenter(new UpdateCenter(mQueryMngr)), mShcodeSelectionDialog(new ShcodeSelectionDialog(mQueryMngr)), mChartWidget(new ChartWidget(mQueryMngr))
{
	ui.setupUi(this);
	mQueryMngr->start();
	connect(mUpdateCenter, &UpdateCenter::updateStockInfoDone, this, [&]()
	{
		QMessageBox::information(this, "StockInfoUpdate", "Done");
	});
	connect(mUpdateCenter, &UpdateCenter::updateCodeTableDone, this, [&]()
	{
		QMessageBox::information(this, "Update Code Table", "Done");
	});
	connect(mUpdateCenter, &UpdateCenter::updateMovementTableDone, this,[&]()
	{
		QMessageBox::information(this, "Update Movement Data", "Done");
	});
}

TraderX::~TraderX()
{
	mQueryMngr->deleteLater();
	mUpdateCenter->deleteLater();
}

void TraderX::on_updateStockInfoBtn_clicked()
{
	mUpdateCenter->updateStockInfo();
}

void TraderX::on_updateCodeTableBtn_clicked()
{
	mUpdateCenter->updateCodeTable();
}

void TraderX::on_updateMovementBtn_clicked()
{
	mUpdateCenter->updateMovementTable();
}

void TraderX::on_showChartBtn_clicked()
{
	if (!mChartWidget->isVisible())
	{
		mChartWidget->show();
	}
}