#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class SettingsDialog;
}

class SettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SettingsDialog(QWidget *parent = nullptr);
    ~SettingsDialog();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::SettingsDialog *ui;
    MainWindow *frame;
};

#endif // SETTINGSDIALOG_H
