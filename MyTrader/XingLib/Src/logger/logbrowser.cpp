#include "logbrowser.h"
#include <QMetaType>
#include "logbrowserdialog.h"
LogBrowser* LogBrowser::sInstance = nullptr;
LogBrowser *LogBrowser::getInstance()
{
	if (sInstance == nullptr) {
		sInstance = new LogBrowser();
	}
	return sInstance;
}

void LogBrowser::messageHandler(QtMsgType type, const QMessageLogContext& context, const QString& msg)
{
	if (sInstance != nullptr)
	{
		sInstance->outputMessage(type, context, msg);
	}
}

LogBrowser::LogBrowser(QObject *parent) : QObject(parent)
{
    qRegisterMetaType<QtMsgType>("QtMsgType");
    qRegisterMetaType<LogContext>("LogContext");
	browserDialog = new LogBrowserDialog;
    connect(this, &LogBrowser::sendMessage, browserDialog, &LogBrowserDialog::outputMessage, Qt::AutoConnection);
}

LogBrowser::~LogBrowser()
{
    delete browserDialog;
}

void LogBrowser::start()
{
	qInstallMessageHandler(messageHandler);
    browserDialog->show();
}

void LogBrowser::outputMessage(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    LogContext logContext;
    logContext.category = context.category;
    QString fullPath = context.file;
    QStringList fullPathList = fullPath.split("\\");
    logContext.file = fullPathList.at(fullPathList.size()-1);
    logContext.function = context.function;
    logContext.line = context.line;
    emit sendMessage(type,logContext, QObject::tr("[thread-%1]").arg((long)QThread::currentThreadId())+msg);
}

