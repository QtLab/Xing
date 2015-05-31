#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QCloseEvent>
#include "xing/xasession.h"
#include "xing/xaquery.h"
#include "tr/t8430/t8430query.h"
#include "tr/t1702/t1702query.h"

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

    bool clearResource();
protected:
    bool nativeEvent(const QByteArray & eventType, void * message, long * result);
    HWND getWindowHandle();
    virtual void closeEvent(QCloseEvent *event) override;
    void showResult(QList<TrItem*> list);
public slots:
    void t8430result(QList<T8430Item*> list);
    void t1702result(QList<T1702Item*> list);


private slots:
    void onFinished(int result);
    void on_connectBtn_clicked();
    void on_runBtn_clicked();
};

#endif // DIALOG_H
