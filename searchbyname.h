#ifndef SEARCHBYNAME_H
#define SEARCHBYNAME_H

#include <QDialog>
//#include "../FileInfoModelHW/filesearchmodel.h"
#include "mainwindow.h"

namespace Ui {
class SearchByName;
}

class SearchByName : public QDialog
{
    Q_OBJECT

public:
    explicit SearchByName(QWidget *parent = nullptr);
    virtual ~SearchByName();

private slots:
    void on_push_search_Btn_clicked();

private:
    Ui::SearchByName *ui;
    FileInfo::FileSearchModel fSearch;
    MainWindow *frame;
};

#endif // SEARCHBYNAME_H
