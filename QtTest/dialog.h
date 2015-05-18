#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "xing/xasession.h"
#include "xing/xaquery.h"
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private:
    Ui::Dialog *ui;
    XASession m_session;
    XAQueryMngr m_queryMngr;
protected:
    bool nativeEvent(const QByteArray & eventType, void * message, long * result);
    HWND getWindowHandle();
private slots:

    void on_connectBtn_clicked();
};

#endif // DIALOG_H
