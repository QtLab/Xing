#include "dialog.h"
#include <QApplication>
#include <QList>
#include "tr/t1702/t1702item.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Dialog w;
    w.show();

    return a.exec();
}
