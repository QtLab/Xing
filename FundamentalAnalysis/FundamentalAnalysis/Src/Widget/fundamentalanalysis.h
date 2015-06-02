#ifndef FUNDAMENTALANALYSIS_H
#define FUNDAMENTALANALYSIS_H

#include <QtWidgets/QMainWindow>
#include "ui_fundamentalanalysis.h"

class FundamentalAnalysis : public QMainWindow
{
	Q_OBJECT

public:
	FundamentalAnalysis(QWidget *parent = 0);
	~FundamentalAnalysis();
protected:
	


private:
	Ui::FundamentalAnalysisClass ui;

};

#endif // FUNDAMENTALANALYSIS_H
