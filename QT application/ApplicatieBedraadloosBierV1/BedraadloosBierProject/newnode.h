#ifndef NEWNODE_H
#define NEWNODE_H

#include <QDialog>

namespace Ui {
class NewNode;
}

class NewNode : public QDialog
{
    Q_OBJECT

public:
    explicit NewNode(QWidget *parent = nullptr);
    ~NewNode();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void on_rbCood_toggled(bool checked);

    void on_rbRouter_toggled(bool checked);

    void on_rbEnd_toggled(bool checked);

    void on_rbCood_clicked();

private:
    Ui::NewNode *ui;
};

#endif // NEWNODE_H
