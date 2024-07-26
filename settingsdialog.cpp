#include "settingsdialog.h"
#include "warningflag.h"
#include "ui_settingsdialog.h"

SettingsDialog::SettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsDialog)
{
    ui->setupUi(this);

    frame = qobject_cast<MainWindow*>(parent);

    ui->checkBox->setChecked(frame->isFileNameVisible());
    ui->checkBox_2->setChecked(frame->isFilePathVisible());
    ui->checkBox_3->setChecked(frame->isFileSizeVisible());
}

SettingsDialog::~SettingsDialog()
{
    delete ui;
}

void SettingsDialog::on_buttonBox_accepted()
{
    if (!ui->checkBox->isChecked()&&!ui->checkBox_2->isChecked()&&!ui->checkBox_3->isChecked())
    {
        WarningFlag wf(frame);
        wf.exec();
    } else {
        frame->setFileNameVisible(ui->checkBox->isChecked());
        frame->setFilePathVisible(ui->checkBox_2->isChecked());
        frame->setFileSizeVisible(ui->checkBox_3->isChecked());


        frame->showResults();
    }
}

