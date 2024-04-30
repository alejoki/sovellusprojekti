/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *btnShowCars;
    QTextEdit *textCars;
    QPushButton *btnNewCar;
    QPushButton *btnDeleteCar;
    QPushButton *btnUpdateCar;
    QTextEdit *textId;
    QTextEdit *textBranch;
    QTextEdit *textModel;
    QStatusBar *statusbar;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(681, 340);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        btnShowCars = new QPushButton(centralwidget);
        btnShowCars->setObjectName("btnShowCars");
        btnShowCars->setGeometry(QRect(340, 10, 331, 31));
        textCars = new QTextEdit(centralwidget);
        textCars->setObjectName("textCars");
        textCars->setGeometry(QRect(10, 10, 321, 281));
        btnNewCar = new QPushButton(centralwidget);
        btnNewCar->setObjectName("btnNewCar");
        btnNewCar->setGeometry(QRect(340, 90, 101, 31));
        btnDeleteCar = new QPushButton(centralwidget);
        btnDeleteCar->setObjectName("btnDeleteCar");
        btnDeleteCar->setGeometry(QRect(570, 90, 101, 31));
        btnUpdateCar = new QPushButton(centralwidget);
        btnUpdateCar->setObjectName("btnUpdateCar");
        btnUpdateCar->setGeometry(QRect(450, 90, 111, 31));
        textId = new QTextEdit(centralwidget);
        textId->setObjectName("textId");
        textId->setGeometry(QRect(340, 50, 51, 31));
        textBranch = new QTextEdit(centralwidget);
        textBranch->setObjectName("textBranch");
        textBranch->setGeometry(QRect(390, 50, 141, 31));
        textModel = new QTextEdit(centralwidget);
        textModel->setObjectName("textModel");
        textModel->setGeometry(QRect(530, 50, 141, 31));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 681, 21));
        MainWindow->setMenuBar(menubar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Car Database", nullptr));
        btnShowCars->setText(QCoreApplication::translate("MainWindow", "Show All Cars", nullptr));
        btnNewCar->setText(QCoreApplication::translate("MainWindow", "New Car", nullptr));
        btnDeleteCar->setText(QCoreApplication::translate("MainWindow", "Delete Car", nullptr));
        btnUpdateCar->setText(QCoreApplication::translate("MainWindow", "Update Car", nullptr));
        textId->setPlaceholderText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        textBranch->setPlaceholderText(QCoreApplication::translate("MainWindow", "Branch", nullptr));
        textModel->setPlaceholderText(QCoreApplication::translate("MainWindow", "Model", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
