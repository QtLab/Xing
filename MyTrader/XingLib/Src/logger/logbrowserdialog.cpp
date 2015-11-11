#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QCloseEvent>
#include <QKeyEvent>
#include <QDateTime>
#include "logbrowserdialog.h"
#include "ui_logbrowserdialog.h"
#include <QMutex>
#include <QMutexLocker>

LogBrowserDialog::LogBrowserDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LogBrowserDialog)
{
    ui->setupUi(this);
    ui->showTime->setChecked(true);
    ui->showCategory->setChecked(false);
    ui->showFileName->setChecked(true);
    ui->showFunction->setChecked(true);
    ui->showLine->setChecked(true);
    connect(ui->clearButton, SIGNAL(clicked()), ui->browser, SLOT(clear()));
    connect(ui->saveButton, SIGNAL(clicked()), this, SLOT(save()));
}

LogBrowserDialog::~LogBrowserDialog()
{
    delete ui;
}

void LogBrowserDialog::outputMessage(QtMsgType type,const LogContext &context, const QString &msg)
{
    QMutexLocker locker(&mLogMutex);
    QString log;
    QTextStream stream(&log);
    if(ui->showTime->isChecked()){
        QDateTime time = QDateTime::currentDateTime();
        stream<<"["<<time.toString(Qt::ISODate)<<"]";
    }
    if(ui->showCategory->isChecked()) {
        stream<<" ["<<context.category<<"]";
    }
    if(ui->showFileName->isChecked()) {
        stream<<" ["<<context.file<<"]";
    }
    if(ui->showFunction->isChecked()) {
        stream<<" ["<<context.function<<"]";
    }
    if(ui->showLine->isChecked()) {
        stream<<" ["<<QString::number(context.line)<<"]";
    }
    switch(type) {
    case QtDebugMsg:
        stream<<" D: ";
        break;
    case QtWarningMsg:
        stream<<" W: ";
        break;
    case QtCriticalMsg:
        stream<<" C: ";
        break;
    case QtFatalMsg:
        stream<<" F: ";
        break;
    default:
        stream<<" : ";
    }
    stream<<msg;
    ui->browser->append(log);
}

void LogBrowserDialog::save()
{
    QString saveFileName = QFileDialog::getSaveFileName(
                               this,
                               tr("Save Log Output"),
                               tr("%1/logfile.txt").arg(QDir::homePath()),
                               tr("Text Files ('''.txt);;All Files (*)")
                           );

    if(saveFileName.isEmpty())
        return;

    QFile file(saveFileName);
    if(!file.open(QIODevice::WriteOnly)) {
        QMessageBox::warning(
            this,
            tr("Error"),
            QString(tr("<nobr>File '%1'<br/>cannot be opened for writing.<br/><br/>"
                       "The log output could <b>not</b> be saved!</nobr>"))
            .arg(saveFileName));
        return;
    }
}
void LogBrowserDialog::closeEvent(QCloseEvent *e)
{
    QMessageBox::StandardButton answer = QMessageBox::question(
            this,
            tr("Close Log Browser?"),
            tr("Do you really want to close the log browser?"),
            QMessageBox::Yes | QMessageBox::No
                                         );

    if (answer == QMessageBox::Yes)
        e->accept();
    else
        e->ignore();
}

void LogBrowserDialog::keyPressEvent(QKeyEvent *e)
{
// ignore all keyboard events
// protects against accidentally closing of the dialog
// without asking the user
    e->ignore();
}
