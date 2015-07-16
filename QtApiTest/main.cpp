#include <QCoreApplication>
#include <QString>
#include <QObject>
#include <ActiveQt/QAxObject>
#include <QDebug>
#include <QFile>
#include <QIODevice>
#include <QTextStream>
#include <windows.h>
#include "XingLib/xaquery.h"
#include "tr/trmetainfo.h"
#include "util/xingutil.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    CoInitialize(NULL);

    QAxObject* xaquery = new QAxObject("XA_DataSet.XAQuery");
    static const QString res_root_path= QObject::tr("C:\\eBest\\xingAPI\\Res\\");
//    if(xaquery->dynamicCall("LoadFromResFile(QString)", res_root_path+"t1102.res").toBool()) {
//        QString doc = xaquery->generateDocumentation();
//        QString filename = "doc.html";
//        QFile file(filename);
//        if(file.open(QIODevice::ReadWrite)) {
//            QTextStream stream(&file);
//            stream<<doc;
//        }
//        qDebug()<<doc;
//    }
    QString testData1 = qkor("		한글명,hname,hname,char,20;");
    TrFieldInfo* info1 = TrFieldInfo::parse(testData1);

    QString testData2 = qkor("		현재가,price,price,long,8;");
    TrFieldInfo* info2 = TrFieldInfo::parse(testData2);

    QString testData3 = qkor("		등락율,diff,diff,float,6.2;");
    TrFieldInfo* info3 = TrFieldInfo::parse(testData3);

    QString testData4 = qkor("		시가시간,opentime,opentime,char,6;");
    TrFieldInfo* info4 = TrFieldInfo::parse(testData4);

    QString testData5 = qkor("		52최고가일,high52wdate,high52wdate,char,8;");
    TrFieldInfo* info5 = TrFieldInfo::parse(testData5);

    qDebug()<<info1->toString();
    qDebug()<<info2->toString();
    qDebug()<<info3->toString();
    qDebug()<<info4->toString();
    qDebug()<<info5->toString();


    //return a.exec();
    return 0;
}
