


#ifndef SERIALPORT_H
#define SERIALPORT_H

#include <QByteArray>
#include <QSerialPort>
#include <QTextStream>
#include <QTimer>
/**
  *\class Serialport
  *
  * \brief Class for using a Serial Port to connect to an Arduino
  *
  * This class is used to open/close and send/receive a Serial port.
  *
  * \version 1.0
  *
  *
  * \date 2019/15/1
  *
  * Created on 2019/10/1
*/
class Serialport : public QObject
{
public:
    explicit Serialport(QSerialPort *serialPort, QObject *parent = nullptr);
    bool SendData(char * data);

private slots:
    void handleReadyRead();

private:
    QSerialPort * m_serialPort = nullptr;
    QTextStream m_standardOutput;
};

#endif // SERIALPORT_H
