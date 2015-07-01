#ifndef TRQUERY_H
#define TRQUERY_H

#include <QObject>
#include <QWidget>
class TrQuery : public QObject
{
    Q_OBJECT
public:

    ~TrQuery();

    QString getName() {return mName;}

    HWND getHWnd() {return (HWND)mRequester->winId();}
    void setFinished();
    bool isFinished();
private:
    bool bIsFinished;
protected:
    explicit TrQuery(const QWidget* requester, QString name, QObject *parent = 0);
    QString mName;
    const QWidget* mRequester;
signals:
    void messageReceived(const QString& msg);
    void errorReceived(const QString& msg);
public slots:
};
#endif // TRQUERY_H
