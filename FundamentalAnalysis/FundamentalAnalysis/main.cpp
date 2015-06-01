#include "stdafx.h"
#include "fundamentalanalysis.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	FundamentalAnalysis w;
	w.show();
	return a.exec();
}
