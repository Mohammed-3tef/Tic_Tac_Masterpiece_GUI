#ifndef ULTIMATE_H
#define ULTIMATE_H

#include <QDialog>

namespace Ui {
class Ultimate;
}

class Ultimate : public QDialog
{
    Q_OBJECT

public:
    explicit Ultimate(QWidget *parent = nullptr);
    ~Ultimate();

private:
    Ui::Ultimate *ui;
};

#endif // ULTIMATE_H
