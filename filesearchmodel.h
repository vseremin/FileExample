#ifndef FILESEARCHMODEL_H
#define FILESEARCHMODEL_H

#include <QString>
//class QString;
#include <QFileInfoList>

namespace FileInfo
{

class FileSearchModel
{
public:
    FileSearchModel();
    FileSearchModel(QString);

    QFileInfoList getFileList() const { return fileList; }
    void setPath(QString path) { this -> path = path; }
    virtual void search(void);
    virtual void searchFiles(void);

    virtual ~FileSearchModel() {}

private:
//    QString *path;
    QString path;
    QFileInfoList fileList;
};

} //FileInfo

#endif // FILESEARCHMODEL_H
