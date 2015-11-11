/********************************************************************************
** Form generated from reading UI file 'chartwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHARTWIDGET_H
#define UI_CHARTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "service/chart/ui/qchartviewer.h"

QT_BEGIN_NAMESPACE

class Ui_ChartWidget
{
public:
    QGridLayout *gridLayout_4;
    QHBoxLayout *horizontalLayout_4;
    QFrame *frame;
    QGridLayout *gridLayout;
    QGridLayout *gridLayout_3;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_8;
    QLineEdit *stockName;
    QVBoxLayout *verticalLayout_6;
    QToolBox *mToolBox;
    QWidget *mChartType;
    QWidget *mIndicatorType;
    QWidget *mChannelType;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QPushButton *shcodeSearchBtn;
    QFrame *line;
    QFrame *rightPanel;
    QGridLayout *gridLayout_6;
    QFrame *chartViewerFrame;
    QGridLayout *gridLayout_5;
    QChartViewer *chartViewer;
    QFrame *viewPortFrame;
    QGridLayout *gridLayout_2;
    QViewPortControl *viewPortControl;

    void setupUi(QWidget *ChartWidget)
    {
        if (ChartWidget->objectName().isEmpty())
            ChartWidget->setObjectName(QStringLiteral("ChartWidget"));
        ChartWidget->resize(1218, 842);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        QBrush brush1(QColor(240, 240, 240, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        ChartWidget->setPalette(palette);
        gridLayout_4 = new QGridLayout(ChartWidget);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        frame = new QFrame(ChartWidget);
        frame->setObjectName(QStringLiteral("frame"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        verticalSpacer = new QSpacerItem(20, 60, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer, 4, 0, 1, 1);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));

        gridLayout_3->addLayout(verticalLayout_8, 3, 0, 1, 1);

        stockName = new QLineEdit(frame);
        stockName->setObjectName(QStringLiteral("stockName"));
        stockName->setMinimumSize(QSize(180, 0));
        stockName->setReadOnly(true);

        gridLayout_3->addWidget(stockName, 1, 0, 1, 1);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        mToolBox = new QToolBox(frame);
        mToolBox->setObjectName(QStringLiteral("mToolBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(mToolBox->sizePolicy().hasHeightForWidth());
        mToolBox->setSizePolicy(sizePolicy1);
        mToolBox->setFrameShape(QFrame::Panel);
        mToolBox->setFrameShadow(QFrame::Raised);
        mChartType = new QWidget();
        mChartType->setObjectName(QStringLiteral("mChartType"));
        mChartType->setGeometry(QRect(0, 0, 176, 283));
        mToolBox->addItem(mChartType, QStringLiteral("Chart Type"));
        mIndicatorType = new QWidget();
        mIndicatorType->setObjectName(QStringLiteral("mIndicatorType"));
        mIndicatorType->setGeometry(QRect(0, 0, 88, 69));
        mToolBox->addItem(mIndicatorType, QStringLiteral("Indicator"));
        mChannelType = new QWidget();
        mChannelType->setObjectName(QStringLiteral("mChannelType"));
        mChannelType->setGeometry(QRect(0, 0, 88, 69));
        mToolBox->addItem(mChannelType, QStringLiteral("Channel Type"));

        verticalLayout_6->addWidget(mToolBox);


        gridLayout_3->addLayout(verticalLayout_6, 2, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetFixedSize);
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        shcodeSearchBtn = new QPushButton(frame);
        shcodeSearchBtn->setObjectName(QStringLiteral("shcodeSearchBtn"));

        horizontalLayout->addWidget(shcodeSearchBtn);


        gridLayout_3->addLayout(horizontalLayout, 0, 0, 1, 1);


        gridLayout->addLayout(gridLayout_3, 0, 0, 1, 1);


        horizontalLayout_4->addWidget(frame);

        line = new QFrame(ChartWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setBaseSize(QSize(800, 550));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout_4->addWidget(line);

        rightPanel = new QFrame(ChartWidget);
        rightPanel->setObjectName(QStringLiteral("rightPanel"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(rightPanel->sizePolicy().hasHeightForWidth());
        rightPanel->setSizePolicy(sizePolicy2);
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::Base, brush);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush);
        rightPanel->setPalette(palette1);
        rightPanel->setFrameShape(QFrame::Box);
        rightPanel->setFrameShadow(QFrame::Raised);
        rightPanel->setLineWidth(0);
        gridLayout_6 = new QGridLayout(rightPanel);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        gridLayout_6->setContentsMargins(20, 20, 20, 20);
        chartViewerFrame = new QFrame(rightPanel);
        chartViewerFrame->setObjectName(QStringLiteral("chartViewerFrame"));
        sizePolicy2.setHeightForWidth(chartViewerFrame->sizePolicy().hasHeightForWidth());
        chartViewerFrame->setSizePolicy(sizePolicy2);
        chartViewerFrame->setFrameShape(QFrame::Box);
        chartViewerFrame->setFrameShadow(QFrame::Raised);
        gridLayout_5 = new QGridLayout(chartViewerFrame);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        chartViewer = new QChartViewer(chartViewerFrame);
        chartViewer->setObjectName(QStringLiteral("chartViewer"));
        sizePolicy2.setHeightForWidth(chartViewer->sizePolicy().hasHeightForWidth());
        chartViewer->setSizePolicy(sizePolicy2);
        chartViewer->setFrameShape(QFrame::Box);

        gridLayout_5->addWidget(chartViewer, 0, 0, 1, 1);


        gridLayout_6->addWidget(chartViewerFrame, 0, 0, 1, 1);

        viewPortFrame = new QFrame(rightPanel);
        viewPortFrame->setObjectName(QStringLiteral("viewPortFrame"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(viewPortFrame->sizePolicy().hasHeightForWidth());
        viewPortFrame->setSizePolicy(sizePolicy3);
        viewPortFrame->setMinimumSize(QSize(0, 0));
        viewPortFrame->setFrameShape(QFrame::Box);
        viewPortFrame->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(viewPortFrame);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        viewPortControl = new QViewPortControl(viewPortFrame);
        viewPortControl->setObjectName(QStringLiteral("viewPortControl"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(viewPortControl->sizePolicy().hasHeightForWidth());
        viewPortControl->setSizePolicy(sizePolicy4);
        viewPortControl->setMinimumSize(QSize(0, 150));
        viewPortControl->setFrameShape(QFrame::StyledPanel);

        gridLayout_2->addWidget(viewPortControl, 0, 0, 1, 1);


        gridLayout_6->addWidget(viewPortFrame, 1, 0, 1, 1);


        horizontalLayout_4->addWidget(rightPanel);


        gridLayout_4->addLayout(horizontalLayout_4, 0, 0, 1, 1);


        retranslateUi(ChartWidget);

        mToolBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ChartWidget);
    } // setupUi

    void retranslateUi(QWidget *ChartWidget)
    {
        ChartWidget->setWindowTitle(QApplication::translate("ChartWidget", "ChartWidget", 0));
        mToolBox->setItemText(mToolBox->indexOf(mChartType), QApplication::translate("ChartWidget", "Chart Type", 0));
        mToolBox->setItemText(mToolBox->indexOf(mIndicatorType), QApplication::translate("ChartWidget", "Indicator", 0));
        mToolBox->setItemText(mToolBox->indexOf(mChannelType), QApplication::translate("ChartWidget", "Channel Type", 0));
        label->setText(QApplication::translate("ChartWidget", "\354\242\205\353\252\251", 0));
        shcodeSearchBtn->setText(QApplication::translate("ChartWidget", "Search", 0));
        chartViewer->setText(QString());
        viewPortControl->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ChartWidget: public Ui_ChartWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHARTWIDGET_H
