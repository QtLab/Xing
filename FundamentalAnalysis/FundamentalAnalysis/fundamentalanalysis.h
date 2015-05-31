#ifndef FUNDAMENTALANALYSIS_H
#define FUNDAMENTALANALYSIS_H

#include <QtWidgets/QDialog>
#include "ui_fundamentalanalysis.h"

class FundamentalAnalysis : public QDialog
{
	Q_OBJECT

public:
	FundamentalAnalysis(QWidget *parent = 0);
	~FundamentalAnalysis();

private:
	Ui::FundamentalAnalysisClass ui;
};

#endif // FUNDAMENTALANALYSIS_H
