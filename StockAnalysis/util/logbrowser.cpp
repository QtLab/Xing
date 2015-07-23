#include "logbrowser.h"
#include <QMetaType>
#include "logbrowserdialog.h"
LogBrowser::LogBrowser(QObject *parent) : QObject(parent)
{
    qRegisterMetaType<QtMsgType>("QtMsgType");
    qRegisterMetaType<QMessageLogContext>("QMessageLogContext");
    browserDialog = new LogBrowserDialog;
    connect(this, SIGNAL(sendMessage(QtMsgType,QMessageLogContext,QString)), browserDialog, SLOT(outputMessage(QtMsgType,QMessageLogContext,QString)), Qt::QueuedConnection);
    browserDialog->show();
}

LogBrowser::~LogBrowser()
{
    delete browserDialog;
}

void LogBrowser::outputMessage(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    emit sendMessage(type, msg);
}

