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

    HWND getHWnd() {return mHwnd;}
    void setFinished();
    bool isFinished();
private:
    bool bIsFinished;
    HWND mHwnd;
protected:
    explicit TrQuery(QString name, HWND winId, QObject *parent = 0);
    QString mName;
    const QWidget* mRequester;
signals:
    void messageReceived(const QString& msg);
    void errorReceived(const QString& msg);
public slots:
};

#endif // TRQUERY_H
