#ifndef SERIALPORT_H
#define SERIALPORT_H

#include <QSerialPort>
#include <QIODevice>

class Serialport
{
public:
    Serialport();
private:
    QSerialPort * m_serialPort = nullptr;
};

#endif // SERIALPORT_H
