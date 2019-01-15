#ifndef SERIALPORT_H
#define SERIALPORT_H

#include <QByteArray>
#include <QSerialPort>
#include <QTextStream>
#include <QTimer>

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
