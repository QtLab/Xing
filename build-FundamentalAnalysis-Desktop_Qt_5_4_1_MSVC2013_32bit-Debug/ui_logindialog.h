/********************************************************************************
** Form generated from reading UI file 'logindialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_LoginDialog
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *lineEditId;
    QLabel *label_2;
    QLineEdit *lineEditPasswd;
    QLabel *label_3;
    QLineEdit *lineEditCertPasswd;
    QLabel *label_4;
    QComboBox *comboBoxServerType;
    QCheckBox *checkBoxSaveId;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName(QStringLiteral("LoginDialog"));
        LoginDialog->resize(226, 171);
        gridLayout = new QGridLayout(LoginDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label = new QLabel(LoginDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setLayoutDirection(Qt::LeftToRight);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        lineEditId = new QLineEdit(LoginDialog);
        lineEditId->setObjectName(QStringLiteral("lineEditId"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEditId);

        label_2 = new QLabel(LoginDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        lineEditPasswd = new QLineEdit(LoginDialog);
        lineEditPasswd->setObjectName(QStringLiteral("lineEditPasswd"));

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEditPasswd);

        label_3 = new QLabel(LoginDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        lineEditCertPasswd = new QLineEdit(LoginDialog);
        lineEditCertPasswd->setObjectName(QStringLiteral("lineEditCertPasswd"));

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEditCertPasswd);

        label_4 = new QLabel(LoginDialog);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        comboBoxServerType = new QComboBox(LoginDialog);
        comboBoxServerType->setObjectName(QStringLiteral("comboBoxServerType"));

        formLayout->setWidget(3, QFormLayout::FieldRole, comboBoxServerType);


        verticalLayout->addLayout(formLayout);

        checkBoxSaveId = new QCheckBox(LoginDialog);
        checkBoxSaveId->setObjectName(QStringLiteral("checkBoxSaveId"));

        verticalLayout->addWidget(checkBoxSaveId);

        buttonBox = new QDialogButtonBox(LoginDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(LoginDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), LoginDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), LoginDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QDialog *LoginDialog)
    {
        LoginDialog->setWindowTitle(QApplication::translate("LoginDialog", "Dialog", 0));
        label->setText(QApplication::translate("LoginDialog", "ID", 0));
        label_2->setText(QApplication::translate("LoginDialog", "\353\271\204\353\260\200\353\262\210\355\230\270", 0));
        label_3->setText(QApplication::translate("LoginDialog", "\352\263\265\354\235\270\354\235\270\354\246\235", 0));
        label_4->setText(QApplication::translate("LoginDialog", "\354\240\221\354\206\215\354\204\234\353\262\204", 0));
        checkBoxSaveId->setText(QApplication::translate("LoginDialog", "\354\225\204\354\235\264\353\224\224 \354\240\200\354\236\245", 0));
    } // retranslateUi

};

namespace Ui {
    class LoginDialog: public Ui_LoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
