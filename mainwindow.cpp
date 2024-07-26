#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "aboutbox.h"
#include "redactor.h"
#include "settingsdialog.h"
#include "warningflag.h"
#include "searchbyname.h"
#include <QMessageBox>
#include <iostream>
#include <fstream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFileFlags();
    ui->tableView->setModel(&fileData);

    connect(&fileData, SIGNAL(dataChanged(QModelIndex, QModelIndex)),
            ui->tableView, SLOT(update()));
}

void MainWindow::setFileNameVisible(bool name)
{
    flags.name = name;
}

void MainWindow::setFilePathVisible(bool path)
{
    flags.path = path;
}

void MainWindow::setFileSizeVisible(bool size)
{
    flags.size = size;
}

void MainWindow::setFileFlags(struct FileFlags &flags)
{
    this->flags = flags;
}

void MainWindow::setFileFlags()
{
    flags.name = flags.path = flags.size = true;
}

void MainWindow::showResults()
{
    fileData.setColumnCount(flagsCount());
    fileData.setViewFlags(isFileNameVisible(),
                          isFilePathVisible(), isFileSizeVisible());
    fileData.fildData(fSearch.getFileList());
}

QList<QFileInfo> MainWindow::getFiles() { return fList; }

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionExit_triggered()
{
    close();
}


void MainWindow::on_actionNew_triggered()
{
    if(ui->lineEdit->text().isEmpty())
    {
        QMessageBox mBox;
        mBox.setWindowTitle("Empty path!");
        mBox.setText("Cannot use empty path, setting default value!");
        mBox.setIcon(QMessageBox::Information);
        mBox.setStandardButtons(QMessageBox::Ok);
        mBox.exec();
        ui->lineEdit->setText(".");
    }

    fSearch.setPath(ui->lineEdit->text());
    fSearch.search();

    fList = fSearch.getFileList();
    showResults();
}


void MainWindow::on_actionAbout_triggered()
{
    AboutBox about(this);
    about.exec();
}

const FileFlags &MainWindow::getFlags() const
{
    return flags;
}

void MainWindow::setFlags(const FileFlags &newFlags)
{
    flags = newFlags;
}


void MainWindow::on_actionSettings_triggered()
{
    SettingsDialog dialog(this);
    dialog.exec();
}


void MainWindow::on_actionSave_triggered()
{
    std::fstream fileWrite("testfile", std::ofstream::out | std::ofstream::trunc);
    fileWrite.clear();
    foreach(QFileInfo file, fSearch.getFileList())
        fileWrite << file.fileName().toStdString() << std::endl;
    fileWrite.close();

}


void MainWindow::on_actionSearch_by_name_triggered()
{
    SearchByName searchByName(this);
    searchByName.exec();
}


void MainWindow::on_actionAll_files_triggered()
{
    QString path = ui->lineEdit->text() != "" ? ui->lineEdit->text() : "";
    printFile(path);

}

void MainWindow::printFile(QString list)
{
    fSearch.setPath(list);
    fSearch.search();

    fList = fSearch.getFileList();
    foreach(QFileInfo file, fList) {
        std::cout << file.fileName().toStdString() << std::endl;
        if (file.isDir()) {
            printFile(list+file.fileName());
        }
    }

}

int MainWindow::flagsCount()
{
    int i = 0;
    if(flags.name) i++;
    if(flags.path) i++;
    if(flags.size) i++;

    return i;
}

void MainWindow::on_tableView_clicked(const QModelIndex &index)
{

    int i = index.row();

    Redactor redactor(this);
    redactor.readFile(fileData.getFileNames().at(i));
    redactor.exec();
}

