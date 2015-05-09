#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "xing/IXingAPI.h"

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
    IXingAPI m_api;
protected:
    bool nativeEvent(const QByteArray & eventType, void * message, long * result);
    HWND getWindowHandle();
private slots:
    void on_testButton1_clicked();
    void on_testButton2_clicked();
    void on_testButton3_clicked();
};

#endif // DIALOG_H
