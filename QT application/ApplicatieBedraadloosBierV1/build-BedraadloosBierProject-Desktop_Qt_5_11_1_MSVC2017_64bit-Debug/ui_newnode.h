/********************************************************************************
** Form generated from reading UI file 'newnode.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWNODE_H
#define UI_NEWNODE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_NewNode
{
public:
    QGroupBox *groupBox;
    QTextEdit *txtNodeID;
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLabel *label_2;
    QTextEdit *txtPanID;
    QTextEdit *txtLowAdd;
    QLabel *label_3;
    QLabel *label_4;
    QTextEdit *txtHighAdd;
    QRadioButton *rbCood;
    QRadioButton *rbRouter;
    QRadioButton *rbEnd;

    void setupUi(QDialog *NewNode)
    {
        if (NewNode->objectName().isEmpty())
            NewNode->setObjectName(QStringLiteral("NewNode"));
        NewNode->resize(400, 300);
        groupBox = new QGroupBox(NewNode);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 381, 281));
        txtNodeID = new QTextEdit(groupBox);
        txtNodeID->setObjectName(QStringLiteral("txtNodeID"));
        txtNodeID->setGeometry(QRect(90, 20, 111, 21));
        buttonBox = new QDialogButtonBox(groupBox);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(210, 240, 161, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 20, 51, 21));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 50, 51, 21));
        txtPanID = new QTextEdit(groupBox);
        txtPanID->setObjectName(QStringLiteral("txtPanID"));
        txtPanID->setGeometry(QRect(90, 50, 111, 21));
        txtLowAdd = new QTextEdit(groupBox);
        txtLowAdd->setObjectName(QStringLiteral("txtLowAdd"));
        txtLowAdd->setGeometry(QRect(90, 80, 111, 21));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 80, 71, 21));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 110, 71, 21));
        txtHighAdd = new QTextEdit(groupBox);
        txtHighAdd->setObjectName(QStringLiteral("txtHighAdd"));
        txtHighAdd->setGeometry(QRect(90, 110, 111, 21));
        rbCood = new QRadioButton(groupBox);
        rbCood->setObjectName(QStringLiteral("rbCood"));
        rbCood->setGeometry(QRect(230, 20, 91, 21));
        rbRouter = new QRadioButton(groupBox);
        rbRouter->setObjectName(QStringLiteral("rbRouter"));
        rbRouter->setGeometry(QRect(230, 50, 91, 21));
        rbEnd = new QRadioButton(groupBox);
        rbEnd->setObjectName(QStringLiteral("rbEnd"));
        rbEnd->setGeometry(QRect(230, 80, 91, 21));

        retranslateUi(NewNode);
        QObject::connect(buttonBox, SIGNAL(accepted()), NewNode, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), NewNode, SLOT(reject()));

        QMetaObject::connectSlotsByName(NewNode);
    } // setupUi

    void retranslateUi(QDialog *NewNode)
    {
        NewNode->setWindowTitle(QApplication::translate("NewNode", "Dialog", nullptr));
        groupBox->setTitle(QApplication::translate("NewNode", "GroupBox", nullptr));
        label->setText(QApplication::translate("NewNode", "Node ID", nullptr));
        label_2->setText(QApplication::translate("NewNode", "Pan_ID", nullptr));
        label_3->setText(QApplication::translate("NewNode", "Low Address", nullptr));
        label_4->setText(QApplication::translate("NewNode", "High Address", nullptr));
        rbCood->setText(QApplication::translate("NewNode", "Coordinator", nullptr));
        rbRouter->setText(QApplication::translate("NewNode", "Router", nullptr));
        rbEnd->setText(QApplication::translate("NewNode", "End Device", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NewNode: public Ui_NewNode {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWNODE_H
