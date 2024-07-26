#ifndef WARNINGFLAG_H
#define WARNINGFLAG_H

#include <QDialog>

namespace Ui {
class WarningFlag;
}

class WarningFlag : public QDialog
{
    Q_OBJECT

public:
    explicit WarningFlag(QWidget *parent = nullptr);
    ~WarningFlag();

private slots:
    void on_pushButton_clicked();

private:
    Ui::WarningFlag *ui;
};

#endif // WARNINGFLAG_H
