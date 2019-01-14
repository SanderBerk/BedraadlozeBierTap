/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *btnLed2;
    QComboBox *cmbComPorten;
    QPushButton *btnConnect;
    QPushButton *btnLed3;
    QPushButton *btnLed1;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(576, 440);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        btnLed2 = new QPushButton(centralWidget);
        btnLed2->setObjectName(QStringLiteral("btnLed2"));
        btnLed2->setGeometry(QRect(10, 70, 75, 23));
        cmbComPorten = new QComboBox(centralWidget);
        cmbComPorten->setObjectName(QStringLiteral("cmbComPorten"));
        cmbComPorten->setGeometry(QRect(10, 10, 91, 22));
        btnConnect = new QPushButton(centralWidget);
        btnConnect->setObjectName(QStringLiteral("btnConnect"));
        btnConnect->setGeometry(QRect(110, 10, 75, 23));
        btnLed3 = new QPushButton(centralWidget);
        btnLed3->setObjectName(QStringLiteral("btnLed3"));
        btnLed3->setGeometry(QRect(10, 100, 75, 23));
        btnLed1 = new QPushButton(centralWidget);
        btnLed1->setObjectName(QStringLiteral("btnLed1"));
        btnLed1->setGeometry(QRect(10, 40, 75, 23));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 576, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        btnLed2->setText(QApplication::translate("MainWindow", "Led 2", nullptr));
        btnConnect->setText(QApplication::translate("MainWindow", "Connect", nullptr));
        btnLed3->setText(QApplication::translate("MainWindow", "Led 3", nullptr));
        btnLed1->setText(QApplication::translate("MainWindow", "Led 1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
