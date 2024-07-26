#ifndef FILEDATA_H
#define FILEDATA_H

#include <QAbstractTableModel>
#include <QFileInfoList>
#include "fileflags.h"

class FileData : public QAbstractTableModel
{
public:
    FileData() { columns = 0; }

    void fildData(const QFileInfoList&);
    void setColumnCount(int columns) { this->columns = columns; }
    void setViewFlags(bool, bool, bool);
    QVariant headerData(int, Qt::Orientation,
                        int role = Qt::DisplayRole) const;
    QList<QString> getFileNames(void) { return fileNames; }
    virtual ~FileData() {}

private:
    QList<QString> fileNames;
    QList<QString> filePath;
    QList<int> fileSizes;
    int columns;
    struct FileFlags flags;

    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role) const;

};



#endif // FILEDATA_H
