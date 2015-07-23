#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QCloseEvent>
#include <QKeyEvent>
#include "logbrowserdialog.h"
#include "ui_logbrowserdialog.h"

LogBrowserDialog::LogBrowserDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LogBrowserDialog)
{
    ui->setupUi(this);
    connect(ui->clearButton, SIGNAL(clicked()), ui->browser, SLOT(clear()));
    connect(ui->saveButton, SIGNAL(clicked()), this, SLOT(save()));
}

LogBrowserDialog::~LogBrowserDialog()
{
    delete ui;
}

void LogBrowserDialog::outputMessage(QtMsgType type, const QString &msg)
{
    switch(type) {
    case QtDebugMsg:
    case QtWarningMsg:
    case QtCriticalMsg:
    case QtFatalMsg:
    default:
        ui->browser->append(msg);
    }
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
