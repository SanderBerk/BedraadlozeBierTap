#include "newnode.h"
#include "node.h"
#include "ui_newnode.h"

extern Node ListNodes[100];
extern int CNodes;
extern bool rbC;
extern bool rbR;
extern bool rbE;


NewNode::NewNode(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewNode)
{
    ui->setupUi(this);

}

NewNode::~NewNode()
{
    delete ui;
}

void NewNode::on_buttonBox_accepted()
{
    //Node::Node(int Node_ID,int Pan_ID,int LowAddress,int HighAddress,Function Name)
    int Node_id = CNodes;
    int Pan_id = ui->txtPanID->toPlainText().toInt();
    int LA = ui->txtLowAdd->toPlainText().toInt();
    int HD = ui->txtHighAdd->toPlainText().toInt();

    Function FNode;
    if(ui->rbEnd->isChecked() == true)
    {
        FNode = END_DEVICE;
    }
    else if(ui->rbCood->isChecked() == true)
    {
        FNode = COORDINATOR;
    }
    else {
        FNode = ROUTER;
    }

    Node newnode(Node_id,Pan_id,LA,HD,FNode);
    ListNodes[CNodes] = newnode;
    CNodes ++;
}



void NewNode::on_buttonBox_rejected()
{

}

void NewNode::on_rbCood_toggled(bool checked)
{
    rbC = checked;

}

void NewNode::on_rbRouter_toggled(bool checked)
{
    rbR = checked;


}

void NewNode::on_rbEnd_toggled(bool checked)
{
    rbE = checked;
}

void NewNode::on_rbCood_clicked()
{

}
