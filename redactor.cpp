#include "redactor.h"
#include "ui_redactor.h"

Redactor::Redactor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Redactor)
{
    ui->setupUi(this);
}

Redactor::~Redactor()
{
    delete ui;
}

void Redactor::readFile(QString name)
{
    QFile file(name);
    QByteArray data;
    if (!file.open(QIODevice::ReadOnly))
        return;
    data = file.readAll();
    ui->textBrowser->setText(QString(data));
}
