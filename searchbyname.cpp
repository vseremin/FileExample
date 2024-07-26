#include "searchbyname.h"
#include "ui_searchbyname.h"

SearchByName::SearchByName(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SearchByName)
{
    ui->setupUi(this);
    ui->label->setText("");

    frame = qobject_cast<MainWindow*>(parent);
}

SearchByName::~SearchByName()
{
    delete ui;
}

void SearchByName::on_push_search_Btn_clicked()
{
    QString fileName = ui->lineEdit->text();
    bool isExist = false;

    QList<QFileInfo> fList = frame->getFiles();
    if(fList.size() == 0) {
        ui->label->setText("Enter the path");
    } else {
        foreach(QFileInfo file, fList)
            if (file.fileName() == fileName && fileName != "") isExist = true;
        if(isExist == true)
            ui->label->setText("File is exist");
        else
            ui->label->setText("File not exist");
    }
}

