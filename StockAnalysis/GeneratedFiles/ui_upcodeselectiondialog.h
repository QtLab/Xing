/********************************************************************************
** Form generated from reading UI file 'upcodeselectiondialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UPCODESELECTIONDIALOG_H
#define UI_UPCODESELECTIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTreeWidget>

QT_BEGIN_NAMESPACE

class Ui_UpCodeSelectionDialog
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QTreeWidget *upcodeList;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *UpCodeSelectionDialog)
    {
        if (UpCodeSelectionDialog->objectName().isEmpty())
            UpCodeSelectionDialog->setObjectName(QStringLiteral("UpCodeSelectionDialog"));
        UpCodeSelectionDialog->resize(357, 212);
        gridLayout = new QGridLayout(UpCodeSelectionDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        upcodeList = new QTreeWidget(UpCodeSelectionDialog);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        upcodeList->setHeaderItem(__qtreewidgetitem);
        upcodeList->setObjectName(QStringLiteral("upcodeList"));

        horizontalLayout->addWidget(upcodeList);

        buttonBox = new QDialogButtonBox(UpCodeSelectionDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout->addWidget(buttonBox);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);


        retranslateUi(UpCodeSelectionDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), UpCodeSelectionDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), UpCodeSelectionDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(UpCodeSelectionDialog);
    } // setupUi

    void retranslateUi(QDialog *UpCodeSelectionDialog)
    {
        UpCodeSelectionDialog->setWindowTitle(QApplication::translate("UpCodeSelectionDialog", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class UpCodeSelectionDialog: public Ui_UpCodeSelectionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UPCODESELECTIONDIALOG_H
