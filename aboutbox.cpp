#include "aboutbox.h"
#include "ui_aboutbox.h"
#include <QPixmap>

AboutBox::AboutBox(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutBox)
{
    ui->setupUi(this);
    setFixedSize(300, 500);
    QPixmap pic("image.png");
    ui->label_2->setPixmap(pic);
}

AboutBox::~AboutBox()
{
    delete ui;
}

void AboutBox::on_pushButton_clicked()
{
    close();
}

