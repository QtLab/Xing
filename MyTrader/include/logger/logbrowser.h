#ifndef LOGBROWSER_H
#define LOGBROWSER_H

#include <QObject>
#include <QThread>
#include "logger/logbrowserdialog.h"

class LogBrowserDialog;

class LogBrowser : public QObject
{
    Q_OBJECT
public:
	static LogBrowser *getInstance();
	static void messageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg);
    ~LogBrowser();
	void start();
private:
	explicit LogBrowser(QObject *parent = 0);
signals:
    void sendMessage(QtMsgType type, const LogContext &context, const QString &msg);
public slots:
    void outputMessage(QtMsgType type, const QMessageLogContext &context, const QString &msg);
private:
	static LogBrowser *sInstance;
    LogBrowserDialog *browserDialog;
};

#endif // LOGBROWSER_H
