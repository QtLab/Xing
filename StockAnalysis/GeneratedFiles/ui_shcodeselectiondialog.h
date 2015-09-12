/********************************************************************************
** Form generated from reading UI file 'shcodeselectiondialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHCODESELECTIONDIALOG_H
#define UI_SHCODESELECTIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ShcodeSelectionDialog
{
public:
    QGridLayout *gridLayout_5;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_5;
    QFrame *frame;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QPushButton *showAllStockBtn;
    QPushButton *showKospiBtn;
    QPushButton *showKosdaqBtn;
    QPushButton *showETFBtn;
    QPushButton *showETNBtn;
    QFrame *frame_2;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_2;
    QPushButton *showKonexBtn;
    QPushButton *showKotcBtn;
    QPushButton *showElwBtn;
    QFrame *frame_4;
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout_3;
    QPushButton *showKospiUpjongBtn;
    QPushButton *showKosdaqUpjongBtn;
    QPushButton *showSectorUpjongBtn;
    QPushButton *showSpecialIndexUpjongBtn;
    QFrame *frame_3;
    QGridLayout *gridLayout_4;
    QVBoxLayout *verticalLayout_4;
    QPushButton *showRegisteredBtn;
    QPushButton *showSectorThemeBtn;
    QPushButton *showSectorindexBtn;
    QVBoxLayout *verticalLayout_6;
    QComboBox *upjongCombo;
    QTableView *codeTable;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *searchEdit;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *keepDialog;
    QSpacerItem *horizontalSpacer;
    QPushButton *closeBtn;

    void setupUi(QDialog *ShcodeSelectionDialog)
    {
        if (ShcodeSelectionDialog->objectName().isEmpty())
            ShcodeSelectionDialog->setObjectName(QStringLiteral("ShcodeSelectionDialog"));
        ShcodeSelectionDialog->resize(390, 572);
        gridLayout_5 = new QGridLayout(ShcodeSelectionDialog);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        frame = new QFrame(ShcodeSelectionDialog);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        showAllStockBtn = new QPushButton(frame);
        showAllStockBtn->setObjectName(QStringLiteral("showAllStockBtn"));
        showAllStockBtn->setCheckable(true);

        verticalLayout->addWidget(showAllStockBtn);

        showKospiBtn = new QPushButton(frame);
        showKospiBtn->setObjectName(QStringLiteral("showKospiBtn"));
        showKospiBtn->setCheckable(true);

        verticalLayout->addWidget(showKospiBtn);

        showKosdaqBtn = new QPushButton(frame);
        showKosdaqBtn->setObjectName(QStringLiteral("showKosdaqBtn"));
        showKosdaqBtn->setCheckable(true);

        verticalLayout->addWidget(showKosdaqBtn);

        showETFBtn = new QPushButton(frame);
        showETFBtn->setObjectName(QStringLiteral("showETFBtn"));
        showETFBtn->setCheckable(true);

        verticalLayout->addWidget(showETFBtn);

        showETNBtn = new QPushButton(frame);
        showETNBtn->setObjectName(QStringLiteral("showETNBtn"));
        showETNBtn->setCheckable(true);

        verticalLayout->addWidget(showETNBtn);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        verticalLayout_5->addWidget(frame);

        frame_2 = new QFrame(ShcodeSelectionDialog);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame_2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        showKonexBtn = new QPushButton(frame_2);
        showKonexBtn->setObjectName(QStringLiteral("showKonexBtn"));
        showKonexBtn->setCheckable(true);

        verticalLayout_2->addWidget(showKonexBtn);

        showKotcBtn = new QPushButton(frame_2);
        showKotcBtn->setObjectName(QStringLiteral("showKotcBtn"));
        showKotcBtn->setCheckable(true);

        verticalLayout_2->addWidget(showKotcBtn);

        showElwBtn = new QPushButton(frame_2);
        showElwBtn->setObjectName(QStringLiteral("showElwBtn"));
        showElwBtn->setCheckable(true);

        verticalLayout_2->addWidget(showElwBtn);


        gridLayout_2->addLayout(verticalLayout_2, 0, 0, 1, 1);


        verticalLayout_5->addWidget(frame_2);

        frame_4 = new QFrame(ShcodeSelectionDialog);
        frame_4->setObjectName(QStringLiteral("frame_4"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(frame_4);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        showKospiUpjongBtn = new QPushButton(frame_4);
        showKospiUpjongBtn->setObjectName(QStringLiteral("showKospiUpjongBtn"));
        showKospiUpjongBtn->setCheckable(true);

        verticalLayout_3->addWidget(showKospiUpjongBtn);

        showKosdaqUpjongBtn = new QPushButton(frame_4);
        showKosdaqUpjongBtn->setObjectName(QStringLiteral("showKosdaqUpjongBtn"));
        showKosdaqUpjongBtn->setCheckable(true);

        verticalLayout_3->addWidget(showKosdaqUpjongBtn);

        showSectorUpjongBtn = new QPushButton(frame_4);
        showSectorUpjongBtn->setObjectName(QStringLiteral("showSectorUpjongBtn"));
        showSectorUpjongBtn->setCheckable(true);

        verticalLayout_3->addWidget(showSectorUpjongBtn);

        showSpecialIndexUpjongBtn = new QPushButton(frame_4);
        showSpecialIndexUpjongBtn->setObjectName(QStringLiteral("showSpecialIndexUpjongBtn"));
        showSpecialIndexUpjongBtn->setCheckable(true);

        verticalLayout_3->addWidget(showSpecialIndexUpjongBtn);


        gridLayout_3->addLayout(verticalLayout_3, 0, 0, 1, 1);


        verticalLayout_5->addWidget(frame_4);

        frame_3 = new QFrame(ShcodeSelectionDialog);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        gridLayout_4 = new QGridLayout(frame_3);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        showRegisteredBtn = new QPushButton(frame_3);
        showRegisteredBtn->setObjectName(QStringLiteral("showRegisteredBtn"));
        showRegisteredBtn->setCheckable(true);

        verticalLayout_4->addWidget(showRegisteredBtn);

        showSectorThemeBtn = new QPushButton(frame_3);
        showSectorThemeBtn->setObjectName(QStringLiteral("showSectorThemeBtn"));
        showSectorThemeBtn->setCheckable(true);

        verticalLayout_4->addWidget(showSectorThemeBtn);

        showSectorindexBtn = new QPushButton(frame_3);
        showSectorindexBtn->setObjectName(QStringLiteral("showSectorindexBtn"));
        showSectorindexBtn->setCheckable(true);

        verticalLayout_4->addWidget(showSectorindexBtn);


        gridLayout_4->addLayout(verticalLayout_4, 0, 0, 1, 1);


        verticalLayout_5->addWidget(frame_3);


        horizontalLayout_2->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        upjongCombo = new QComboBox(ShcodeSelectionDialog);
        upjongCombo->setObjectName(QStringLiteral("upjongCombo"));

        verticalLayout_6->addWidget(upjongCombo);

        codeTable = new QTableView(ShcodeSelectionDialog);
        codeTable->setObjectName(QStringLiteral("codeTable"));
        codeTable->setGridStyle(Qt::NoPen);

        verticalLayout_6->addWidget(codeTable);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(ShcodeSelectionDialog);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        searchEdit = new QLineEdit(ShcodeSelectionDialog);
        searchEdit->setObjectName(QStringLiteral("searchEdit"));

        horizontalLayout->addWidget(searchEdit);


        verticalLayout_6->addLayout(horizontalLayout);


        horizontalLayout_2->addLayout(verticalLayout_6);


        verticalLayout_7->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        keepDialog = new QCheckBox(ShcodeSelectionDialog);
        keepDialog->setObjectName(QStringLiteral("keepDialog"));

        horizontalLayout_3->addWidget(keepDialog);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        closeBtn = new QPushButton(ShcodeSelectionDialog);
        closeBtn->setObjectName(QStringLiteral("closeBtn"));

        horizontalLayout_3->addWidget(closeBtn);


        verticalLayout_7->addLayout(horizontalLayout_3);


        gridLayout_5->addLayout(verticalLayout_7, 0, 0, 1, 1);


        retranslateUi(ShcodeSelectionDialog);

        QMetaObject::connectSlotsByName(ShcodeSelectionDialog);
    } // setupUi

    void retranslateUi(QDialog *ShcodeSelectionDialog)
    {
        ShcodeSelectionDialog->setWindowTitle(QApplication::translate("ShcodeSelectionDialog", "\354\227\205\354\242\205/\354\242\205\353\252\251 \354\204\240\355\203\235", 0));
        showAllStockBtn->setText(QApplication::translate("ShcodeSelectionDialog", "\354\240\204\354\242\205\353\252\251", 0));
        showKospiBtn->setText(QApplication::translate("ShcodeSelectionDialog", "\354\275\224\354\212\244\355\224\274\354\242\205\353\252\251", 0));
        showKosdaqBtn->setText(QApplication::translate("ShcodeSelectionDialog", "\354\275\224\354\212\244\353\213\245\354\242\205\353\252\251", 0));
        showETFBtn->setText(QApplication::translate("ShcodeSelectionDialog", "ETF", 0));
        showETNBtn->setText(QApplication::translate("ShcodeSelectionDialog", "ETN", 0));
        showKonexBtn->setText(QApplication::translate("ShcodeSelectionDialog", "\354\275\224\353\204\245\354\212\244", 0));
        showKotcBtn->setText(QApplication::translate("ShcodeSelectionDialog", "K-OTC", 0));
        showElwBtn->setText(QApplication::translate("ShcodeSelectionDialog", "ELW", 0));
        showKospiUpjongBtn->setText(QApplication::translate("ShcodeSelectionDialog", "\354\275\224\354\212\244\355\224\274\354\227\205\354\242\205", 0));
        showKosdaqUpjongBtn->setText(QApplication::translate("ShcodeSelectionDialog", "\354\275\224\354\212\244\353\213\245\354\227\205\354\242\205", 0));
        showSectorUpjongBtn->setText(QApplication::translate("ShcodeSelectionDialog", "\354\204\271\355\204\260\354\247\200\354\210\230", 0));
        showSpecialIndexUpjongBtn->setText(QApplication::translate("ShcodeSelectionDialog", "\355\212\271\354\210\230\352\263\204\354\227\264\354\247\200\354\210\230", 0));
        showRegisteredBtn->setText(QApplication::translate("ShcodeSelectionDialog", "\352\264\200\354\213\254", 0));
        showSectorThemeBtn->setText(QApplication::translate("ShcodeSelectionDialog", "\354\204\271\355\204\260(\355\205\214\353\247\210)", 0));
        showSectorindexBtn->setText(QApplication::translate("ShcodeSelectionDialog", "\354\204\271\355\204\260\354\247\200\354\210\230\354\242\205\353\252\251", 0));
        label->setText(QApplication::translate("ShcodeSelectionDialog", "\352\262\200\354\203\211\354\226\264", 0));
        keepDialog->setText(QApplication::translate("ShcodeSelectionDialog", "\355\231\224\353\251\264\354\234\240\354\247\200", 0));
        closeBtn->setText(QApplication::translate("ShcodeSelectionDialog", "\353\213\253\352\270\260[ESC]", 0));
    } // retranslateUi

};

namespace Ui {
    class ShcodeSelectionDialog: public Ui_ShcodeSelectionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHCODESELECTIONDIALOG_H
