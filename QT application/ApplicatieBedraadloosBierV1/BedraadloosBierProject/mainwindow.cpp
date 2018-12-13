#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "newnode.h"
#include "Node.h"

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


}

MainWindow::~MainWindow()
{
    delete ui;
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
