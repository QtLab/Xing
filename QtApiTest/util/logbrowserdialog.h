#ifndef LOGBROWSERDIALOG_H
#define LOGBROWSERDIALOG_H

#include <QDialog>

namespace Ui {
class LogBrowserDialog;
}

class LogBrowserDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LogBrowserDialog(QWidget *parent = 0);
    ~LogBrowserDialog();
public slots:
    void outputMessage(QtMsgType type, const QString &msg);
protected slots:
    void save();
protected:
    virtual void keyPressEvent( QKeyEvent *e );
    virtual void closeEvent( QCloseEvent *e );
private:
    Ui::LogBrowserDialog *ui;
};

#endif // LOGBROWSERDIALOG_H
