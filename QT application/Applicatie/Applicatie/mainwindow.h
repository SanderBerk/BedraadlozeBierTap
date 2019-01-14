#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QThread>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    void openSerialPort();
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnConnect_clicked();
    void handleReadyRead();

    void on_btnLed1_clicked();

    void on_btnLed2_clicked();

    void on_btnLed3_clicked();

private:
    Ui::MainWindow *ui;
    QSerialPort *serial = nullptr;
    QList<QSerialPortInfo> portList;
};

#endif // MAINWINDOW_H
