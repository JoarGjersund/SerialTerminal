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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
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
    QListView *listView;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QCheckBox *autoScroll;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *serialqtClass)
    {
        if (serialqtClass->objectName().isEmpty())
            serialqtClass->setObjectName(QStringLiteral("serialqtClass"));
        serialqtClass->resize(796, 664);
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
        listView = new QListView(centralWidget);
        listView->setObjectName(QStringLiteral("listView"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(listView->sizePolicy().hasHeightForWidth());
        listView->setSizePolicy(sizePolicy1);

        verticalLayout_2->addWidget(listView);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(1);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy2);
        lineEdit->setMaximumSize(QSize(16777210, 16777215));

        horizontalLayout_4->addWidget(lineEdit);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy3);
        pushButton->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_4->addWidget(pushButton);

        autoScroll = new QCheckBox(centralWidget);
        autoScroll->setObjectName(QStringLiteral("autoScroll"));

        horizontalLayout_4->addWidget(autoScroll);


        verticalLayout_2->addLayout(horizontalLayout_4);

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
        pushButton->setText(QApplication::translate("serialqtClass", "Send", nullptr));
        autoScroll->setText(QApplication::translate("serialqtClass", "Autoscroll", nullptr));
    } // retranslateUi

};

namespace Ui {
    class serialqtClass: public Ui_serialqtClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERIALQT_H
