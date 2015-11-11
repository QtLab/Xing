#include <QButtonGroup>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QCompleter>
#include "core/util/xingutil.h"
#include "shcodeselectiondialog.h"
#include "ui_shcodeselectiondialog.h"

ShcodeSelectionDialog::ShcodeSelectionDialog(QueryMngr *queryMngr, QWidget *parent) :
QDialog(parent),
ui(new Ui::ShcodeSelectionDialog), mQueryMngr(queryMngr), mCurrentSelectedBtnId(ALL_STOCK_BTN_ID), mCurrentSelectedCode(""), mSearchCompleter(new QCompleter(this))
{
    ui->setupUi(this);
	initButtonGroups();
	initUI();
	initTable();
	initCompleter();
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
	mBtnGroup->addButton(ui->showAllStockBtn, ALL_STOCK_BTN_ID);
	mBtnGroup->addButton(ui->showKospiBtn, KOSPI_BTN_ID);
	mBtnGroup->addButton(ui->showKosdaqBtn, KOSDAQ_BTN_ID);
	mBtnGroup->addButton(ui->showETFBtn, ETF_BTN_ID);
	mBtnGroup->addButton(ui->showETNBtn, ETN_BTN_ID);
	mBtnGroup->addButton(ui->showKonexBtn, KONEX_BTN_ID);
	mBtnGroup->addButton(ui->showKotcBtn, KOTC_BTN_ID);
	mBtnGroup->addButton(ui->showElwBtn, ELW_BTN_ID);
	mBtnGroup->addButton(ui->showKospiUpjongBtn, KOSPI_UPJONG_BTN_ID);
	mBtnGroup->addButton(ui->showKosdaqUpjongBtn, KOSDAQ_UPJONG_BTN_ID);
	mBtnGroup->addButton(ui->showSectorUpjongBtn, SECTOR_UPJONG_BTN_ID);
	mBtnGroup->addButton(ui->showSpecialIndexUpjongBtn, SPECIAL_INDEX_UPJONG_BTN_ID);
	mBtnGroup->addButton(ui->showRegisteredBtn, REGISTERED_BTN_ID);
	mBtnGroup->addButton(ui->showSectorThemeBtn, SECTOR_THEME_BTN_ID);
	mBtnGroup->addButton(ui->showSectorindexBtn, SECTOR_INDEX_BTN_ID);
	
	connect(mBtnGroup, SIGNAL(buttonToggled(int, bool)), this, SLOT(onBtnToggled(int, bool)));
}

void ShcodeSelectionDialog::showAllStocks()
{
	ui->upjongCombo->setVisible(true);
	ui->upjongCombo->clear();
	ui->upjongCombo->addItem(qkor("전체"));
	//updateUpjongCombo("SELECT upcode, hname FROM UpjongCodeTable WHERE CAST(upcode AS UNSIGNED) <600");
	updateUpjongCombo("SELECT upcode, hname FROM UpjongCodeTable WHERE upjong_type=0 OR upjong_type=1 OR upjong_type=2");
	ui->upjongCombo->setCurrentIndex(0);
}

void ShcodeSelectionDialog::showKospiStocks()
{
	ui->upjongCombo->setVisible(true);
	ui->upjongCombo->clear();
	updateUpjongCombo("SELECT upcode, hname FROM UpjongCodeTable WHERE upjong_type=0");
	ui->upjongCombo->setCurrentIndex(0);
}

void ShcodeSelectionDialog::showKosdaqStocks()
{
	ui->upjongCombo->setVisible(true);
	ui->upjongCombo->clear();
	updateUpjongCombo("SELECT upcode, hname FROM UpjongCodeTable WHERE upjong_type=1");
	ui->upjongCombo->setCurrentIndex(0);
}

void ShcodeSelectionDialog::showETF()
{
	ui->upjongCombo->setVisible(false);
	updateTableView("SELECT shcode, hname FROM StockInfoTable WHERE isETF=1");
}

void ShcodeSelectionDialog::showETN()
{
	//Not Support
}

void ShcodeSelectionDialog::showKonex()
{
	//Not Support
}

void ShcodeSelectionDialog::showKotc()
{
	//Not Support
}

void ShcodeSelectionDialog::showElw()
{
	//Not Support
}

void ShcodeSelectionDialog::showRegistered()
{
	//It will be supported after implementing stock registering
}

void ShcodeSelectionDialog::showSectorTheme()
{
	ui->upjongCombo->setVisible(true);
	ui->upjongCombo->clear();
	updateUpjongCombo("SELECT tmcode, tmname FROM ThemeCodeTable");
	ui->upjongCombo->setCurrentIndex(0);
}

void ShcodeSelectionDialog::showSectorIndex()
{
	ui->upjongCombo->setVisible(true);
	ui->upjongCombo->clear();
	updateUpjongCombo("SELECT upcode, hname FROM UpjongCodeTable WHERE upjong_type=2");
	ui->upjongCombo->setCurrentIndex(0);
}

void ShcodeSelectionDialog::showKospiUpjong()
{
	ui->upjongCombo->setVisible(false);
	onShowUpjongCodeListByUpjongType(KOSPI_UPJONG);
}

void ShcodeSelectionDialog::showKosdaqUpjong()
{
	ui->upjongCombo->setVisible(false);
	onShowUpjongCodeListByUpjongType(KOSDAQ_UPJONG);
}

void ShcodeSelectionDialog::showSectorIndexUpjong()
{
	ui->upjongCombo->setVisible(false);
	onShowUpjongCodeListByUpjongType(SECTOR_UPJONG);
}

void ShcodeSelectionDialog::showSpecialSectorIndexUpjong()
{
	ui->upjongCombo->setVisible(false);
	onShowUpjongCodeListByUpjongType(SPECIAL_UPJONG);
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

void ShcodeSelectionDialog::updateTableView(const QString &queryStr)
{
	mSqlQueryModel->setQuery(queryStr);
	ui->codeTable->setModel(mSqlQueryModel);
	mSearchCompleter->setModel(mSqlQueryModel);
	mSearchCompleter->setCompletionColumn(1);
	mSqlQueryModel->setHeaderData(0, Qt::Horizontal, qkor("코드"));
	mSqlQueryModel->setHeaderData(1, Qt::Horizontal, qkor("종목명"));
	ui->codeTable->resizeColumnsToContents();
	ui->codeTable->resizeRowsToContents();
}

void ShcodeSelectionDialog::onBtnToggled(int id, bool toggled)
{
	if (toggled) {
		mCurrentSelectedBtnId = static_cast<BUTTON_ID>(id);
		switch (id) {
		case ALL_STOCK_BTN_ID:						//전종목
			showAllStocks();
			break;
		case KOSPI_BTN_ID:							//코스피 종목
			showKospiStocks();
			break;
		case KOSDAQ_BTN_ID:							//코스닥 종목
			showKosdaqStocks();
			break;
		case ETF_BTN_ID:								//ETF
			showETF();
			break;
		case SECTOR_THEME_BTN_ID:
			showSectorTheme();
			break;
		case SECTOR_INDEX_BTN_ID:				//섹터 지수 종목
			showSectorIndex();
			break;
		case KOSPI_UPJONG_BTN_ID:				//코스피업종
			showKospiUpjong();
			break;
		case KOSDAQ_UPJONG_BTN_ID:				//코스닥업종
			showKosdaqUpjong();
			break;
		case SECTOR_UPJONG_BTN_ID:				//섹터지수(업종)
			showSectorIndexUpjong();
			break;
		case SPECIAL_INDEX_UPJONG_BTN_ID:	//특수계열지수(업종)
			showSpecialSectorIndexUpjong();
			break;
		}
	}
}

void ShcodeSelectionDialog::onShowShcodeListByUpjong(const QString& upjong)
{
	if (ui->upjongCombo->currentText() == qkor("전체")) {
		updateTableView("SELECT shcode, hname FROM StockInfoTable WHERE isETF=0");
	}
	else {
		if (mCurrentSelectedBtnId == SECTOR_THEME_BTN_ID) {
			QString themeCode = upjong.mid(0, 4);
			updateTableView(tr("SELECT shcode, hname FROM ThemeUpjongTable_%1").arg(themeCode));
		}
		else {
			QString upjongCode = upjong.mid(0, 3);
			updateTableView(tr("SELECT shcode, hname FROM UpjongTable_%1").arg(upjongCode));
		}
	}
}

void ShcodeSelectionDialog::onShowUpjongCodeListByUpjongType(const UPJONG_TYPE upjongType)
{
	updateTableView(tr("SELECT upcode, hname FROM UpjongCodeTable WHERE upjong_type=%1").arg(static_cast<int>(upjongType)));
}

void ShcodeSelectionDialog::onTableViewClicked(const QModelIndex &index)
{
	int row = index.row();
	QString code = mSqlQueryModel->record(row).value(0).toString();
	mCurrentSelectedCode = code;
	switch (mCurrentSelectedBtnId) {
	case ALL_STOCK_BTN_ID:
	case KOSPI_BTN_ID:
	case KOSDAQ_BTN_ID:
	case ETF_BTN_ID:
	case SECTOR_INDEX_BTN_ID:
	case SECTOR_THEME_BTN_ID:
		emit shcodeSelected(code);
		break;
	case KOSPI_UPJONG_BTN_ID:
	case KOSDAQ_UPJONG_BTN_ID:
	case SECTOR_UPJONG_BTN_ID:
	case SPECIAL_INDEX_UPJONG_BTN_ID:
		emit upcodeSelected(code);
		break;
	}
}

void ShcodeSelectionDialog::onSearchCompleted(const QModelIndex& index)
{
	QAbstractItemModel *model = mSearchCompleter->completionModel();
	mCurrentSelectedCode = model->data(model->index(index.row(), 0), Qt::DisplayRole).toString();
	accept();
}

void ShcodeSelectionDialog::onSearching(const QModelIndex& index)
{
	QAbstractItemModel *model = mSearchCompleter->completionModel();
	QString shcode = model->data(model->index(index.row(), 0)).toString();
	QModelIndexList indexList = mSqlQueryModel->match(model->index(0,0), Qt::DisplayRole, QVariant::fromValue(shcode), 2, Qt::MatchRecursive);
	ui->codeTable->selectRow(indexList.at(0).row());
}

QString ShcodeSelectionDialog::getSelectedShcode()
{
	switch (mCurrentSelectedBtnId) {
	case ALL_STOCK_BTN_ID:
	case KOSPI_BTN_ID:
	case KOSDAQ_BTN_ID:
	case ETF_BTN_ID:
	case SECTOR_INDEX_BTN_ID:
	case SECTOR_THEME_BTN_ID:
		return mCurrentSelectedCode;
		break;
	case KOSPI_UPJONG_BTN_ID:
	case KOSDAQ_UPJONG_BTN_ID:
	case SECTOR_UPJONG_BTN_ID:
	case SPECIAL_INDEX_UPJONG_BTN_ID:
		return "";
		break;
	}
	return "";
}

QString ShcodeSelectionDialog::getSelectedUpcode()
{
	switch (mCurrentSelectedBtnId) {
	case ALL_STOCK_BTN_ID:
	case KOSPI_BTN_ID:
	case KOSDAQ_BTN_ID:
	case ETF_BTN_ID:
	case SECTOR_INDEX_BTN_ID:
		return "";
		break;
	case KOSPI_UPJONG_BTN_ID:
	case KOSDAQ_UPJONG_BTN_ID:
	case SECTOR_UPJONG_BTN_ID:
	case SPECIAL_INDEX_UPJONG_BTN_ID:
		return mCurrentSelectedCode;
		break;
	}
	return "";
}

void ShcodeSelectionDialog::initUI()
{
	QPalette palette = ui->codeTable->palette();
	palette.setColor(QPalette::Highlight, Qt::darkGray);
	palette.setColor(QPalette::HighlightedText, Qt::white);
	ui->codeTable->setPalette(palette);
}

void ShcodeSelectionDialog::initTable()
{
	mSqlQueryModel = new QSqlQueryModel();
	mSqlQueryModel->setHeaderData(0, Qt::Horizontal, qkor("코드"));
	mSqlQueryModel->setHeaderData(1, Qt::Horizontal, qkor("종목명"));
	ui->codeTable->setModel(mSqlQueryModel);
	ui->codeTable->verticalHeader()->hide();
	ui->codeTable->setSelectionMode(QAbstractItemView::SingleSelection);
	ui->codeTable->setSelectionBehavior(QAbstractItemView::SelectRows);
	connect(ui->upjongCombo, SIGNAL(currentIndexChanged(QString)), this, SLOT(onShowShcodeListByUpjong(QString)));
	connect(ui->codeTable->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(onTableViewClicked(QModelIndex)));
}

void ShcodeSelectionDialog::initCompleter()
{
	mSearchCompleter->setModel(mSqlQueryModel);
	mSearchCompleter->setCompletionColumn(1);
	ui->searchEdit->setCompleter(mSearchCompleter);
	connect(mSearchCompleter, SIGNAL(activated(QModelIndex)), this, SLOT(onSearchCompleted(QModelIndex)));
	connect(mSearchCompleter, SIGNAL(highlighted(QModelIndex)), this, SLOT(onSearching(QModelIndex)));
}