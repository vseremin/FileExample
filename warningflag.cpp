#include "warningflag.h"
#include "ui_warningflag.h"

WarningFlag::WarningFlag(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WarningFlag)
{
    ui->setupUi(this);
}

WarningFlag::~WarningFlag()
{
    delete ui;
}

void WarningFlag::on_pushButton_clicked()
{
    close();
}

