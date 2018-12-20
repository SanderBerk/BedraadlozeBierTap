#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "newnode.h"
#include "Node.h"
#include <>


Node ListNodes[100];
int CNodes = 0;
bool rbC = false;
bool rbR = false;
bool rbE = false;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    init_port(); //initiation of the port

    //creation and attribute of the slider
    slider = new QSlider(this);
    slider->resize(255,20);
    slider->setOrientation( Qt::Horizontal);
    slider->setRange(0,255);

    //creation and attribute of the lcd
    lcd = new QLCDNumber(this);
    lcd->setSegmentStyle(QLCDNumber::Flat);
    lcd->setFixedSize(180,100);

    //creation of a layout containing the slider and lcd
    main_layout = new QVBoxLayout(this);
    main_layout->addWidget(slider);
    main_layout->addWidget(lcd);

    //set the layout to the widget
    this->setLayout(main_layout);

    //connection between the slider event and the transmission function
    connect(slider, SIGNAL(valueChanged(int)), this, SLOT(transmitCmd(int)));
    //connection between the slider event and the lcd value
    connect(slider, SIGNAL(valueChanged(int)), lcd, SLOT(display(int)));


}
void init_port()
{
    port = new QextSerialPort("COM7"); //we create the port

    port->open(QIODevice::ReadWrite | QIODevice::Unbuffered); //we open the port
    if(!port->isOpen())
    {
        QMessageBox::warning(this, "port error", "Impossible to open the port!");
    }

    //we set the port properties
    port->setBaudRate(BAUD9600);//modify the port settings on your own
    port->setFlowControl(FLOW_OFF);
    port->setParity(PAR_NONE);
    port->setDataBits(DATA_8);
    port->setStopBits(STOP_1);

}

void transmitCmd(int value)
{
  if(value < 0 || value >255)return; //if the value is not between 0 and 255
                                     //no transmission

  char *buf; //creation of a buffer
  *buf = value;

  //for messages longer than 1 character :
  /*
  char *buf[255]; //buffer size = 255char;
  sprintf(buf,"%c",value);
  */

  port->write(buf); //send the buffer


}
MainWindow::~MainWindow()
{
    delete ui;
    port->close(); //we close the port at the end of the program
}

void MainWindow::on_btnAddNode_clicked()
{
    NewNode AddnewNode;
    AddnewNode.setModal(true);
    AddnewNode.exec();
    AddnewNode.show();
}

void MainWindow::on_btnRemoveNode_clicked()
{
    //ListNodes[0].NodeInfo(ListNodes[0])
    Node node;
    ui->lwNodes->addItem(node.NodeInfo());
}


