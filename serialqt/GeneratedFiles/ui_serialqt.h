/********************************************************************************
** Form generated from reading UI file 'serialqt.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERIALQT_H
#define UI_SERIALQT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_serialqtClass
{
public:
    QAction *export_2;
    QAction *quit;
    QAction *connect;
    QAction *disconnect;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_3;
    QGridLayout *gridLayout;
    QCheckBox *autoScroll;
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *serialqtClass)
    {
        if (serialqtClass->objectName().isEmpty())
            serialqtClass->setObjectName(QStringLiteral("serialqtClass"));
        serialqtClass->resize(767, 568);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(serialqtClass->sizePolicy().hasHeightForWidth());
        serialqtClass->setSizePolicy(sizePolicy);
        export_2 = new QAction(serialqtClass);
        export_2->setObjectName(QStringLiteral("export_2"));
        quit = new QAction(serialqtClass);
        quit->setObjectName(QStringLiteral("quit"));
        connect = new QAction(serialqtClass);
        connect->setObjectName(QStringLiteral("connect"));
        disconnect = new QAction(serialqtClass);
        disconnect->setObjectName(QStringLiteral("disconnect"));
        centralWidget = new QWidget(serialqtClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setSizeConstraint(QLayout::SetMaximumSize);
        verticalLayout_3->setContentsMargins(-1, 0, -1, -1);

        verticalLayout->addLayout(verticalLayout_3);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout->setHorizontalSpacing(5);
        gridLayout->setVerticalSpacing(8);
        autoScroll = new QCheckBox(centralWidget);
        autoScroll->setObjectName(QStringLiteral("autoScroll"));

        gridLayout->addWidget(autoScroll, 1, 1, 1, 1);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy1);
        pushButton->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(pushButton, 0, 1, 1, 1);

        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(1);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy2);
        lineEdit->setMaximumSize(QSize(16777210, 16777215));

        gridLayout->addWidget(lineEdit, 0, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);


        verticalLayout_2->addLayout(verticalLayout);

        serialqtClass->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(serialqtClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        serialqtClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(serialqtClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        serialqtClass->setStatusBar(statusBar);

        retranslateUi(serialqtClass);

        QMetaObject::connectSlotsByName(serialqtClass);
    } // setupUi

    void retranslateUi(QMainWindow *serialqtClass)
    {
        serialqtClass->setWindowTitle(QApplication::translate("serialqtClass", "serialqt", nullptr));
        export_2->setText(QApplication::translate("serialqtClass", "export", nullptr));
        quit->setText(QApplication::translate("serialqtClass", "Quit", nullptr));
        connect->setText(QApplication::translate("serialqtClass", "connect", nullptr));
        disconnect->setText(QApplication::translate("serialqtClass", "disconnect", nullptr));
        autoScroll->setText(QApplication::translate("serialqtClass", "Autoscroll", nullptr));
        pushButton->setText(QApplication::translate("serialqtClass", "Send", nullptr));
    } // retranslateUi

};

namespace Ui {
    class serialqtClass: public Ui_serialqtClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERIALQT_H
