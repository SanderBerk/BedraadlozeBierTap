#include <QCoreApplication>
#include <QDebug>
#include <QSerialPort>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QSerialPort *m_serial = nullptr;
    m_serial = new QSerialPort();

    m_serial->setPortName("COM10");
    m_serial->setBaudRate(QSerialPort::Baud9600);
    m_serial->setDataBits(QSerialPort::Data7);
    m_serial->setParity(QSerialPort::NoParity);
    m_serial->setStopBits(QSerialPort::OneStop);
    m_serial->setFlowControl(QSerialPort::NoFlowControl);

    if(m_serial->open(QIODevice::ReadWrite)){
        qDebug() << "opened";
        m_serial->write("b");
    }else{
        qDebug() << "Not opened";
    }
    return a.exec();
}
