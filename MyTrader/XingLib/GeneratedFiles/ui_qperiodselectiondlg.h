/********************************************************************************
** Form generated from reading UI file 'qperiodselectiondlg.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QPERIODSELECTIONDLG_H
#define UI_QPERIODSELECTIONDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_QPeriodSelectionDlg
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QDateEdit *sDateEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QDateEdit *eDateEdit;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *okBtn;
    QPushButton *cancelBtn;

    void setupUi(QDialog *QPeriodSelectionDlg)
    {
        if (QPeriodSelectionDlg->objectName().isEmpty())
            QPeriodSelectionDlg->setObjectName(QStringLiteral("QPeriodSelectionDlg"));
        QPeriodSelectionDlg->resize(178, 101);
        gridLayout = new QGridLayout(QPeriodSelectionDlg);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(QPeriodSelectionDlg);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QStringLiteral("Algerian"));
        font.setPointSize(10);
        label->setFont(font);
        label->setScaledContents(false);

        horizontalLayout->addWidget(label);

        sDateEdit = new QDateEdit(QPeriodSelectionDlg);
        sDateEdit->setObjectName(QStringLiteral("sDateEdit"));
        sDateEdit->setMaximumSize(QSize(16777215, 16777215));
        sDateEdit->setCalendarPopup(true);

        horizontalLayout->addWidget(sDateEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(QPeriodSelectionDlg);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        horizontalLayout_2->addWidget(label_2);

        eDateEdit = new QDateEdit(QPeriodSelectionDlg);
        eDateEdit->setObjectName(QStringLiteral("eDateEdit"));
        eDateEdit->setCalendarPopup(true);

        horizontalLayout_2->addWidget(eDateEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        okBtn = new QPushButton(QPeriodSelectionDlg);
        okBtn->setObjectName(QStringLiteral("okBtn"));

        horizontalLayout_3->addWidget(okBtn);

        cancelBtn = new QPushButton(QPeriodSelectionDlg);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));

        horizontalLayout_3->addWidget(cancelBtn);


        verticalLayout->addLayout(horizontalLayout_3);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(QPeriodSelectionDlg);
        QObject::connect(okBtn, SIGNAL(clicked()), QPeriodSelectionDlg, SLOT(accept()));
        QObject::connect(cancelBtn, SIGNAL(clicked()), QPeriodSelectionDlg, SLOT(reject()));

        QMetaObject::connectSlotsByName(QPeriodSelectionDlg);
    } // setupUi

    void retranslateUi(QDialog *QPeriodSelectionDlg)
    {
        QPeriodSelectionDlg->setWindowTitle(QApplication::translate("QPeriodSelectionDlg", "QPeriodSelectionDlg", 0));
        label->setText(QApplication::translate("QPeriodSelectionDlg", "\354\213\234\354\236\221\353\202\240\354\247\234", 0));
        label_2->setText(QApplication::translate("QPeriodSelectionDlg", "\354\242\205\353\243\214\353\202\240\354\247\234", 0));
        okBtn->setText(QApplication::translate("QPeriodSelectionDlg", "OK", 0));
        cancelBtn->setText(QApplication::translate("QPeriodSelectionDlg", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class QPeriodSelectionDlg: public Ui_QPeriodSelectionDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QPERIODSELECTIONDLG_H
