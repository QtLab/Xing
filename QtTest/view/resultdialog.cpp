#include "resultdialog.h"
#include <QGridLayout>
#include <QDebug>
#include <QHeaderView>

ResultDialog::ResultDialog(QWidget *parent) : QDialog(parent)
{

}

ResultDialog::~ResultDialog()
{

}

void ResultDialog::setData(QList<TrItem *> list)
{

    if(list.size()>0){
        mLayout = new QGridLayout(this);
        mTableWidget = new QTableWidget(this);
        mLayout->addWidget(mTableWidget);
        setLayout(mLayout);
        TrItem* item = list.at(0);
        QStringList headerList = item->getPropertyNameList();
        mTableWidget->setRowCount(list.size());
        mTableWidget->setColumnCount(headerList.size());

        mTableWidget->setHorizontalHeaderLabels(headerList);
        int rowCnt=0;

        foreach(TrItem* item, list) {
            int columnCnt = 0;
            foreach(QString propertyName, item->getPropertyNameList()) {
                QString property = item->getPropertyByName(propertyName);
                QVariant propertyValue = item->property(property.toLocal8Bit());
                mTableWidget->setItem(rowCnt,columnCnt, new QTableWidgetItem(propertyValue.toString()));
                columnCnt++;
            }
            rowCnt++;
        }

        mTableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        mTableWidget->resizeColumnsToContents();

        resize(mTableWidget->horizontalHeader()->length()+90, 500);
        qDebug()<<"setData done";
    }

}

