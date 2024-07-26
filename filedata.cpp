#include "filedata.h"

void FileData::fildData(const QFileInfoList &list)
{
    fileNames.clear();
    filePath.clear();
    fileSizes.clear();

    foreach(QFileInfo file, list)
    {
        fileNames.append(file.fileName());
        filePath.append(file.filePath());
        fileSizes.append(file.size());
    }

    emit dataChanged(index(0,0), index(rowCount(), columnCount()));
    emit layoutChanged();
}

void FileData::setViewFlags(bool name, bool path, bool size)
{
    flags.name = name;
    flags.path = path;
    flags.size = size;
}

QVariant FileData::headerData(int section,
                              Qt::Orientation orientation,
                              int role) const
{
    if((orientation != Qt::Horizontal) ||
            (role != Qt::DisplayRole)) return QVariant();
    int pos = 0;
    if(!flags.name) pos--;
    if(section == pos) return "Name";

    pos++;
    if(!flags.path) pos--;
    if(section == pos) return "Path";

    pos++;
    if(!flags.size) pos--;
    if(section == pos) return "Size";

    return QVariant();
}

int FileData::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return fileNames.length();
}

int FileData::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return columns;
}

QVariant FileData::data(const QModelIndex &index, int role) const
{
    if((role != Qt::DisplayRole) || (!index.isValid()))
        return QVariant();

    int pos = 0;
    if(!flags.name) pos--;
    if(index.column() == pos) return fileNames[index.row()];

    pos++;
    if(!flags.path) pos--;
    if(index.column() == pos) return filePath[index.row()];

    pos++;
    if(!flags.size) pos--;
    if(index.column() == pos) return fileSizes[index.row()];


    return QVariant();
}




