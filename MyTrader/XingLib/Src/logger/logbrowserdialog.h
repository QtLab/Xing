#ifndef LOGBROWSERDIALOG_H
#define LOGBROWSERDIALOG_H

#include <QDialog>
#include <QMutex>

namespace Ui {
class LogBrowserDialog;
}

typedef struct _LogContext {
    QString category;
    QString file;
    QString function;
    int  line;
}LogContext;

class LogBrowserDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LogBrowserDialog(QWidget *parent = 0);
    ~LogBrowserDialog();
public slots:
    void outputMessage(QtMsgType type, const LogContext &context, const QString &msg);
protected slots:
    void save();
protected:
    virtual void keyPressEvent( QKeyEvent *e );
    virtual void closeEvent( QCloseEvent *e );
private:
    Ui::LogBrowserDialog *ui;
    QMutex mLogMutex;
};

#endif // LOGBROWSERDIALOG_H
