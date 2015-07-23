#ifndef LOGBROWSER_H
#define LOGBROWSER_H

#include <QObject>
class LogBrowserDialog;
class LogBrowser : public QObject
{
    Q_OBJECT
public:
    explicit LogBrowser(QObject *parent = 0);
    ~LogBrowser();

signals:
    void sendMessage(QtMsgType type, const QMessageLogContext &context, const QString &msg);
public slots:
    void outputMessage(QtMsgType type, const QMessageLogContext &context, const QString &msg);
private:
    LogBrowserDialog *browserDialog;
};

#endif // LOGBROWSER_H
