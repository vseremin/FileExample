#include "filesearchmodel.h"
//#include <QString>
#include <QDir>


namespace FileInfo {

FileSearchModel::FileSearchModel() :
    FileSearchModel(".")
{

}

FileSearchModel::FileSearchModel(QString path)
{
//    this -> path = new QString(path);
    this -> path = path;
}

void FileSearchModel::search(void)
{
    if(path.isEmpty()) return;

    QDir dir(path);
    fileList = dir.entryInfoList();
}

void FileSearchModel::searchFiles(void)
{
    if(path.isEmpty()) return;

    QDir dir(path);
    dir.setFilter(QDir::Files);
    fileList = dir.entryInfoList();
}

}//FileInfo
