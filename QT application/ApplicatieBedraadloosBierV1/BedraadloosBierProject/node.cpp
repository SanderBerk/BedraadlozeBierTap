#include "node.h"
#include <QString>
#include <QVariant>

Node::Node()
{

}

Node::Node(int Node_ID,int Pan_ID,int LowAddress,int HighAddress,Function Name)
{
    this->Node_ID = Node_ID;
    this->Pan_ID = Pan_ID;
    this->LowAddress = LowAddress;
    this->HighAddress = HighAddress;
    this->Name = Name;
    this->Sensor = Sensor;
    this->Actuator = Actuator;
}

QString NodeInfo()
{
    QString test = "test";
    return test;
}


