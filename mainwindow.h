#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include "filesearchmodel.h"
#include "fileflags.h"
#include "filedata.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    void setFileNameVisible(bool);
    void setFilePathVisible(bool);
    void setFileSizeVisible(bool);
    void setFileFlags(struct FileFlags&);
    void setFileFlags(void);

    void printFile(QString);
    void showResults(void);

    bool isFileNameVisible(void) const { return flags.name;}
    bool isFilePathVisible(void) const { return flags.path; }
    bool isFileSizeVisible(void) const { return flags.size;}


    FileInfo::FileSearchModel getFSearch(void) {return fSearch; }
    QList<QFileInfo> getFiles(void);

    virtual ~MainWindow();

    const FileFlags &getFlags() const;
    void setFlags(const FileFlags &newFlags);

private slots:
    void on_actionExit_triggered();

    void on_actionNew_triggered();

    void on_actionAbout_triggered();

    void on_actionSettings_triggered();

    void on_actionSave_triggered();

    void on_actionSearch_by_name_triggered();

    void on_actionAll_files_triggered();

    void on_tableView_clicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    FileInfo::FileSearchModel fSearch;
    struct FileFlags flags;
    FileData fileData;
    QList<QFileInfo> fList;

    int flagsCount(void);
};
#endif // MAINWINDOW_H
