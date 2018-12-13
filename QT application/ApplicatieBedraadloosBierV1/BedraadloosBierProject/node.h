

#ifndef NODE_H
#define NODE_H
#include <QString>

enum Function { COORDINATOR, END_DEVICE, ROUTER };

class Node
{
public:
    Node();
    Node(int,int,int,int,Function);
    int Node_ID;
    int Pan_ID;
    int LowAddress;
    int HighAddress;
    Function Name;
    int Sensor;
    int Actuator;
    QString NodeInfo();

private:

};

#endif // NODE_H
