#ifndef WARRING_H
#define WARRING_H

#include <QDialog>

namespace Ui {
class Warring;
}

class AboutBox : public QDialog
{
    Q_OBJECT

public:
    explicit Warring(QWidget *parent = nullptr);
    virtual ~AboutBox();


private:
    Ui::Warring *ui;
};

#endif // WARRING_H
