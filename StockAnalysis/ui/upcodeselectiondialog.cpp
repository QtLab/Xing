#include "upcodeselectiondialog.h"
#include "ui_upcodeselectiondialog.h"
#include "util/xingutil.h"

UpCodeSelectionDialog::UpCodeSelectionDialog(QueryMngr *queryMngr, QWidget *parent) :
    QDialog(parent),mQueryMngr(queryMngr),
    ui(new Ui::UpCodeSelectionDialog)
{
    ui->setupUi(this);
    ui->upcodeList->setColumnCount(2);
    QStringList headerLabels = {qkor("업종코드"), qkor("업종명")};
    ui->upcodeList->setHeaderLabels(headerLabels);
    ui->upcodeList->setSelectionMode(QAbstractItemView::MultiSelection);
    ui->upcodeList->setSelectionBehavior(QAbstractItemView::SelectRows);
    T8424Query *query = T8424Query::createQuery();
    connect(query, SIGNAL(workDone()), this, SLOT(onUpcodeUpdate()));
    mQueryMngr->requestQuery(query);
}

UpCodeSelectionDialog::~UpCodeSelectionDialog()
{
    delete ui;
}

QList<QString> UpCodeSelectionDialog::getUpcodeList()
{
    QList<QString> list;
    foreach(QTreeWidgetItem* item , ui->upcodeList->selectedItems()){
        QString value = item->data(0, Qt::DisplayRole).toString();
        list.append(value);
    }

    return list;
}

void UpCodeSelectionDialog::onUpcodeUpdate()
{
    QObject *sender = QObject::sender();
    if(sender!=NULL) {
        T8424Query *query = qobject_cast<T8424Query *>(sender);
        if(query!= NULL) {
            QList<T8424Item *> itemList = query->getResult();
            QList<QTreeWidgetItem *> widgetItemList;
            foreach(T8424Item *item , itemList) {
                QStringList list = {item->upcode(), item->hname()};
                widgetItemList.append(new QTreeWidgetItem(list));
                item->deleteLater();
            }
            ui->upcodeList->addTopLevelItems(widgetItemList);
            query->deleteLater();
        }
    }
}

