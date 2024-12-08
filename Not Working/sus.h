#ifndef SUS_H
#define SUS_H

#include <QDialog>

namespace Ui {
class SUS;
}

class SUS : public QDialog
{
    Q_OBJECT

public:
    explicit SUS(QWidget *parent = nullptr);
    ~SUS();

private:
    Ui::SUS *ui;
};

#endif // SUS_H
