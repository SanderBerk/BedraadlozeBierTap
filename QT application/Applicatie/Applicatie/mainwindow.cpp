#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QDebug>
#include <QIODevice>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    portList = QSerialPortInfo::availablePorts();
    for (int i = 0; i < portList.size(); ++i) {
        ui->cmbComPorten->insertItem(1, portList.at(i).portName());

    }
}

MainWindow::~MainWindow()
{
    if (serial->isOpen()){
        serial->close();
    }
    delete serial;
    delete ui;
}

void MainWindow::openSerialPort(){
    serial = new QSerialPort();
    qDebug() << ui->cmbComPorten->currentText();
    serial->setPortName(ui->cmbComPorten->currentText());
    serial->setBaudRate(QSerialPort::Baud9600);
    serial->setDataBits(QSerialPort::Data7);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);

    if(serial->open(QIODevice::ReadWrite)){
        connect(serial, SIGNAL(readyRead()), SLOT(handleReadyRead()));
    }else{
        QMessageBox::critical(this, tr("Error"), serial->errorString());
    }
}

void MainWindow::handleReadyRead(){
    qDebug() << serial->readAll();
}

void MainWindow::on_btnConnect_clicked()
{
    openSerialPort();
}

void MainWindow::on_btnLed1_clicked()
{
    QByteArray data = "\xfd";
    serial->write(data);
}

void MainWindow::on_btnLed2_clicked()
{
    QByteArray data = "\xfe";
    serial->write(data);
}

void MainWindow::on_btnLed3_clicked()
{
    QByteArray data = "\xff";
    serial->write(data);
}
