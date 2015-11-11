#include "traderx.h"
#include <QtWidgets/QApplication>
#include <QtSql/QSqlDatabase>
#include "logger/log.h"
#include "logger/logbrowser.h"
#include "service/login/loginmngr.h"
#include "service/login/ui/logindialog.h"
#include "xinglib.h"
void initDatabaseConnection() {
	QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
	db.setHostName("192.168.219.250");
	db.setDatabaseName("XingDB");
	db.setUserName("seuki77");
	db.setPassword("folken77");
	if (!db.open()) {
		qCDebug(Main) << db.lastError();
		qCDebug(Main) << "Failed to connect";
	}
	else {
		qCDebug(Main) << "Database Connected";
	}
}
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	initXingContext();
	QCoreApplication::setOrganizationName("MyTrader");
	QCoreApplication::setApplicationName("TraderX");

	LogBrowser *logBrowser = LogBrowser::getInstance();
	logBrowser->start();

	LoginMngr loginMngr;
	LoginDialog dialog(&loginMngr);
	TraderX *w;
	if (dialog.exec() == QDialog::Accepted)
	{
		initDatabaseConnection();
		w = new TraderX();
		w->show();
	}
	return a.exec();
}
