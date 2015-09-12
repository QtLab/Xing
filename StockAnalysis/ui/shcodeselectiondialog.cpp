#include <QButtonGroup>
#include <QSqlQueryModel>
#include <QSqlQuery>

#include "util/xingutil.h"
#include "shcodeselectiondialog.h"
#include "ui_shcodeselectiondialog.h"

ShcodeSelectionDialog::ShcodeSelectionDialog(QueryMngr *queryMngr, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShcodeSelectionDialog),mQueryMngr(queryMngr)
{
    ui->setupUi(this);
	initButtonGroups();
	mSqlQueryModel = new QSqlQueryModel();	
	mSqlQueryModel->setHeaderData(0, Qt::Horizontal, qkor("코드"));
	mSqlQueryModel->setHeaderData(1, Qt::Horizontal, qkor("종목명"));
	ui->codeTable->setModel(mSqlQueryModel);
	ui->codeTable->verticalHeader()->hide();
	connect(ui->upjongCombo, SIGNAL(currentIndexChanged(QString)), this, SLOT(onShowUpjong(QString)));
	showAllStocks();
}

ShcodeSelectionDialog::~ShcodeSelectionDialog()
{
	mBtnGroup->deleteLater();
	delete mSqlQueryModel;
    delete ui;
}

void ShcodeSelectionDialog::initButtonGroups()
{
	mBtnGroup = new QButtonGroup(this);
	mBtnGroup->addButton(ui->showAllStockBtn, ALL_STOCK);
	mBtnGroup->addButton(ui->showKospiBtn, KOSPI);
	mBtnGroup->addButton(ui->showKosdaqBtn, KOSDAQ);
	mBtnGroup->addButton(ui->showETFBtn, ETF);
	mBtnGroup->addButton(ui->showETNBtn, ETN);
	mBtnGroup->addButton(ui->showKonexBtn, KONEX);
	mBtnGroup->addButton(ui->showKotcBtn, KOTC);
	mBtnGroup->addButton(ui->showElwBtn, ELW);
	mBtnGroup->addButton(ui->showKospiUpjongBtn, KOSPI_UPJONG);
	mBtnGroup->addButton(ui->showKosdaqUpjongBtn, KOSDAQ_UPJONG);
	mBtnGroup->addButton(ui->showSectorUpjongBtn, SECTOR_UPJONG);
	mBtnGroup->addButton(ui->showSpecialIndexUpjongBtn, SPECIAL_INDEX_UPJONG);
	mBtnGroup->addButton(ui->showRegisteredBtn, REGISTERED);
	mBtnGroup->addButton(ui->showSectorThemeBtn, SECTOR_THEME);
	mBtnGroup->addButton(ui->showSectorindexBtn, SECTOR_INDEX);
	
	connect(mBtnGroup, SIGNAL(buttonToggled(int, bool)), this, SLOT(onBtnToggled(int, bool)));
}

void ShcodeSelectionDialog::showAllStocks()
{
	ui->upjongCombo->setVisible(true);
	ui->upjongCombo->clear();
	ui->upjongCombo->addItem(qkor("전체"));
	updateUpjongCombo("SELECT upcode, hname FROM UpjongCodeTable WHERE CAST(upcode AS UNSIGNED) <600");
	ui->upjongCombo->setCurrentIndex(0);
}

void ShcodeSelectionDialog::showKospiStocks()
{
	ui->upjongCombo->setVisible(true);
	ui->upjongCombo->clear();
	updateUpjongCombo("SELECT upcode, hname FROM UpjongCodeTable WHERE CAST(upcode AS UNSIGNED) <300");
	ui->upjongCombo->setCurrentIndex(0);
}

void ShcodeSelectionDialog::showKosdaqStocks()
{
	ui->upjongCombo->setVisible(true);
	ui->upjongCombo->clear();
	updateUpjongCombo("SELECT upcode, hname FROM UpjongCodeTable WHERE CAST(upcode AS UNSIGNED) >= 300 AND CAST(upcode AS UNSIGNED) <500");
	ui->upjongCombo->setCurrentIndex(0);
}

void ShcodeSelectionDialog::showETF()
{
	ui->upjongCombo->setVisible(false);
	updateShcodeTable("SELECT shcode, hname FROM StockInfoTable WHERE isETF=1");
}

void ShcodeSelectionDialog::showETN()
{

}

void ShcodeSelectionDialog::showKonex()
{

}

void ShcodeSelectionDialog::showKotc()
{

}

void ShcodeSelectionDialog::showElw()
{

}

void ShcodeSelectionDialog::showRegistered()
{

}

void ShcodeSelectionDialog::showSectorTheme()
{

}

void ShcodeSelectionDialog::showSectorIndexUpjong()
{

}

void ShcodeSelectionDialog::showKospiUpjong()
{

}

void ShcodeSelectionDialog::showKosdaqUpjong()
{

}

void ShcodeSelectionDialog::showSectorIndex()
{

}

void ShcodeSelectionDialog::showSpecialSectorIndex()
{

}

void ShcodeSelectionDialog::updateUpjongCombo(const QString &queryStr)
{
	QSqlQuery query;
	query.prepare(queryStr);
	if (query.exec()) {
		while (query.next()) {
			ui->upjongCombo->addItem(query.value(0).toString() + " " + query.value(1).toString());
		}
	}
	ui->upjongCombo->setCurrentIndex(0);
}

void ShcodeSelectionDialog::updateShcodeTable(const QString &queryStr)
{
	mSqlQueryModel->setQuery(queryStr);
}

void ShcodeSelectionDialog::onBtnToggled(int id, bool toggled)
{
	if (toggled) {
		switch (id) {
		case ALL_STOCK:
			showAllStocks();
			break;
		case KOSPI:
			showKospiStocks();
			break;
		case KOSDAQ:
			showKosdaqStocks();
			break;
		case ETF:
			showETF();
			break;
		}
	}
}

void ShcodeSelectionDialog::onShowUpjong(const QString& upjong)
{
	if (ui->upjongCombo->currentText() == qkor("전체")) {
		updateShcodeTable("SELECT shcode, hname FROM StockInfoTable WHERE isETF=0");
	}
	else {
		QString upjongCode = upjong.mid(0, 3);
		updateShcodeTable(tr("SELECT shcode, hname FROM UpjongTable_%1").arg(upjongCode));
	}
	ui->codeTable->setModel(mSqlQueryModel);
	mSqlQueryModel->setHeaderData(0, Qt::Horizontal, qkor("코드"));
	mSqlQueryModel->setHeaderData(1, Qt::Horizontal, qkor("종목명"));
	ui->codeTable->resizeColumnsToContents();
	ui->codeTable->resizeRowsToContents();
}

