#include "stdafx.h"
#include "src/widget/fundamentalanalysis.h"
#include "Src/Widget/LoginDialog.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	FundamentalAnalysis w;
	LoginDialog loginDialog;
	
	switch (loginDialog.exec()){
	case QDialog::Accepted:
			w.show();
			return a.exec();
	case QDialog::Rejected:
			return 0;
	}

	
}
