#include "logbrowser.h"
#include <QMetaType>
#include "logbrowserdialog.h"
LogBrowser::LogBrowser(QObject *parent) : QObject(parent)
{
    qRegisterMetaType<QtMsgType>("QtMsgType");
    qRegisterMetaType<LogContext>("LogContext");
    browserDialog = new LogBrowserDialog;
    connect(this, &LogBrowser::sendMessage, browserDialog, &LogBrowserDialog::outputMessage, Qt::AutoConnection);
    browserDialog->show();
}

LogBrowser::~LogBrowser()
{
    delete browserDialog;
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
    emit sendMessage(type,logContext, msg);
}

