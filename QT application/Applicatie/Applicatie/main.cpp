#include "mainwindow.h"
#include <QApplication>

/**
 * @file Main.h
 * @date January, 2019
 * @brief
 * ! \mainpage Arduino/Xbee Serial connector
 *
 * QT Gui for connecting to an Arduino/Xbee mesh network through Serial and controlling LED's.
 *
 *
 *
 * This project was made by second year students from Avans Hogeschool Den Bosch Technische Informatica.
 *
 * \note https://wiki.qt.io/Main
 *
 */


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
