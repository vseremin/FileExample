#ifndef REDACTOR_H
#define REDACTOR_H

#include <QDialog>
#include <QFile>

namespace Ui {
class Redactor;
}

class Redactor : public QDialog
{
    Q_OBJECT

public:
    explicit Redactor(QWidget *parent = nullptr);
    void readFile(QString);
    virtual ~Redactor();

private:
    Ui::Redactor *ui;
};

#endif // REDACTOR_H
