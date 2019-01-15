#include "serialport.h"

#include <QCoreApplication>
#include <QDebug>

Serialport::Serialport (QSerialPort *serialPort, QObject *parent) :
    QObject(parent), m_serialPort(serialPort), m_standardOutput(stdout)
{
    connect(m_serialPort, &QSerialPort::readyRead, this, &Serialport::handleReadyRead);
}


void Serialport::handleReadyRead(){
    qDebug() << m_serialPort->readAll();
}

bool Serialport::SendData(char * data){
    m_serialPort->write(data);
    return true;
}
