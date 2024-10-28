/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *dotButton;
    QPushButton *movlButton;
    QPushButton *movrButton;
    QTextBrowser *screen;
    QLabel *label_2;
    QPushButton *computeButton;
    QPushButton *addStateButton;
    QPushButton *delStateButton;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *stateNum;
    QLabel *label;
    QLabel *nState;
    QTextEdit *inputBox;
    QLabel *label_3;
    QPushButton *confirmButton;
    QMenuBar *menubar;
    QMenu *menuAbout;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1293, 668);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        dotButton = new QPushButton(centralwidget);
        dotButton->setObjectName("dotButton");
        dotButton->setGeometry(QRect(630, 20, 81, 31));
        movlButton = new QPushButton(centralwidget);
        movlButton->setObjectName("movlButton");
        movlButton->setGeometry(QRect(450, 20, 81, 31));
        movrButton = new QPushButton(centralwidget);
        movrButton->setObjectName("movrButton");
        movrButton->setGeometry(QRect(540, 20, 81, 31));
        screen = new QTextBrowser(centralwidget);
        screen->setObjectName("screen");
        screen->setGeometry(QRect(25, 20, 401, 171));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(30, 200, 71, 16));
        computeButton = new QPushButton(centralwidget);
        computeButton->setObjectName("computeButton");
        computeButton->setGeometry(QRect(630, 60, 81, 31));
        addStateButton = new QPushButton(centralwidget);
        addStateButton->setObjectName("addStateButton");
        addStateButton->setGeometry(QRect(450, 60, 81, 31));
        delStateButton = new QPushButton(centralwidget);
        delStateButton->setObjectName("delStateButton");
        delStateButton->setGeometry(QRect(540, 60, 81, 31));
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(450, 110, 131, 31));
        stateNum = new QHBoxLayout(horizontalLayoutWidget);
        stateNum->setObjectName("stateNum");
        stateNum->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName("label");

        stateNum->addWidget(label);

        nState = new QLabel(horizontalLayoutWidget);
        nState->setObjectName("nState");

        stateNum->addWidget(nState);

        inputBox = new QTextEdit(centralwidget);
        inputBox->setObjectName("inputBox");
        inputBox->setGeometry(QRect(30, 440, 411, 151));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(30, 420, 51, 16));
        confirmButton = new QPushButton(centralwidget);
        confirmButton->setObjectName("confirmButton");
        confirmButton->setGeometry(QRect(30, 600, 61, 21));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1293, 17));
        menuAbout = new QMenu(menubar);
        menuAbout->setObjectName("menuAbout");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuAbout->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        dotButton->setText(QCoreApplication::translate("MainWindow", "W", nullptr));
        movlButton->setText(QCoreApplication::translate("MainWindow", "MOVL", nullptr));
        movrButton->setText(QCoreApplication::translate("MainWindow", "MOVR", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "PROGRAM:", nullptr));
        computeButton->setText(QCoreApplication::translate("MainWindow", "COMPUTE", nullptr));
        addStateButton->setText(QCoreApplication::translate("MainWindow", "ADD STATE", nullptr));
        delStateButton->setText(QCoreApplication::translate("MainWindow", "DEL STATE", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "TOTAL STATES: ", nullptr));
        nState->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "INPUT", nullptr));
        confirmButton->setText(QCoreApplication::translate("MainWindow", "CONFIRM", nullptr));
        menuAbout->setTitle(QCoreApplication::translate("MainWindow", "About", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
