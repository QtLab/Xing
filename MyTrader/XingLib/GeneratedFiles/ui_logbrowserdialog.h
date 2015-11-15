/********************************************************************************
** Form generated from reading UI file 'logbrowserdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGBROWSERDIALOG_H
#define UI_LOGBROWSERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_LogBrowserDialog
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QTextBrowser *browser;
    QVBoxLayout *verticalLayout_2;
    QPushButton *clearButton;
    QPushButton *saveButton;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QCheckBox *showTime;
    QCheckBox *showFileName;
    QCheckBox *showLine;
    QCheckBox *showFunction;
    QCheckBox *showCategory;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *LogBrowserDialog)
    {
        if (LogBrowserDialog->objectName().isEmpty())
            LogBrowserDialog->setObjectName(QStringLiteral("LogBrowserDialog"));
        LogBrowserDialog->resize(1187, 691);
        gridLayout = new QGridLayout(LogBrowserDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        browser = new QTextBrowser(LogBrowserDialog);
        browser->setObjectName(QStringLiteral("browser"));

        horizontalLayout->addWidget(browser);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        clearButton = new QPushButton(LogBrowserDialog);
        clearButton->setObjectName(QStringLiteral("clearButton"));

        verticalLayout_2->addWidget(clearButton);

        saveButton = new QPushButton(LogBrowserDialog);
        saveButton->setObjectName(QStringLiteral("saveButton"));

        verticalLayout_2->addWidget(saveButton);

        groupBox = new QGroupBox(LogBrowserDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        showTime = new QCheckBox(groupBox);
        showTime->setObjectName(QStringLiteral("showTime"));

        verticalLayout->addWidget(showTime);

        showFileName = new QCheckBox(groupBox);
        showFileName->setObjectName(QStringLiteral("showFileName"));

        verticalLayout->addWidget(showFileName);

        showLine = new QCheckBox(groupBox);
        showLine->setObjectName(QStringLiteral("showLine"));

        verticalLayout->addWidget(showLine);

        showFunction = new QCheckBox(groupBox);
        showFunction->setObjectName(QStringLiteral("showFunction"));

        verticalLayout->addWidget(showFunction);

        showCategory = new QCheckBox(groupBox);
        showCategory->setObjectName(QStringLiteral("showCategory"));

        verticalLayout->addWidget(showCategory);


        verticalLayout_2->addWidget(groupBox);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout_2);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);


        retranslateUi(LogBrowserDialog);

        QMetaObject::connectSlotsByName(LogBrowserDialog);
    } // setupUi

    void retranslateUi(QDialog *LogBrowserDialog)
    {
        LogBrowserDialog->setWindowTitle(QApplication::translate("LogBrowserDialog", "Dialog", 0));
        clearButton->setText(QApplication::translate("LogBrowserDialog", "Clear", 0));
        saveButton->setText(QApplication::translate("LogBrowserDialog", "Save", 0));
        groupBox->setTitle(QApplication::translate("LogBrowserDialog", "Show", 0));
        showTime->setText(QApplication::translate("LogBrowserDialog", "Time", 0));
        showFileName->setText(QApplication::translate("LogBrowserDialog", "File", 0));
        showLine->setText(QApplication::translate("LogBrowserDialog", "Line", 0));
        showFunction->setText(QApplication::translate("LogBrowserDialog", "Function", 0));
        showCategory->setText(QApplication::translate("LogBrowserDialog", "Category", 0));
    } // retranslateUi

};

namespace Ui {
    class LogBrowserDialog: public Ui_LogBrowserDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGBROWSERDIALOG_H
