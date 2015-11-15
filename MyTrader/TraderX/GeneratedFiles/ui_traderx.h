/********************************************************************************
** Form generated from reading UI file 'traderx.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRADERX_H
#define UI_TRADERX_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_TraderXClass
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QPushButton *updateStockInfoBtn;
    QPushButton *updateCodeTableBtn;
    QPushButton *updateMovementBtn;
    QPushButton *showChartBtn;

    void setupUi(QDialog *TraderXClass)
    {
        if (TraderXClass->objectName().isEmpty())
            TraderXClass->setObjectName(QStringLiteral("TraderXClass"));
        TraderXClass->resize(137, 130);
        gridLayout = new QGridLayout(TraderXClass);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        updateStockInfoBtn = new QPushButton(TraderXClass);
        updateStockInfoBtn->setObjectName(QStringLiteral("updateStockInfoBtn"));

        verticalLayout->addWidget(updateStockInfoBtn);

        updateCodeTableBtn = new QPushButton(TraderXClass);
        updateCodeTableBtn->setObjectName(QStringLiteral("updateCodeTableBtn"));

        verticalLayout->addWidget(updateCodeTableBtn);

        updateMovementBtn = new QPushButton(TraderXClass);
        updateMovementBtn->setObjectName(QStringLiteral("updateMovementBtn"));

        verticalLayout->addWidget(updateMovementBtn);

        showChartBtn = new QPushButton(TraderXClass);
        showChartBtn->setObjectName(QStringLiteral("showChartBtn"));

        verticalLayout->addWidget(showChartBtn);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(TraderXClass);

        QMetaObject::connectSlotsByName(TraderXClass);
    } // setupUi

    void retranslateUi(QDialog *TraderXClass)
    {
        TraderXClass->setWindowTitle(QApplication::translate("TraderXClass", "TraderX", 0));
        updateStockInfoBtn->setText(QApplication::translate("TraderXClass", "Update StockInfo", 0));
        updateCodeTableBtn->setText(QApplication::translate("TraderXClass", "Update Code Table", 0));
        updateMovementBtn->setText(QApplication::translate("TraderXClass", "Update Movement", 0));
        showChartBtn->setText(QApplication::translate("TraderXClass", "Show Chart", 0));
    } // retranslateUi

};

namespace Ui {
    class TraderXClass: public Ui_TraderXClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRADERX_H
