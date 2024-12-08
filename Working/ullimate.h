#ifndef ULLIMATE_H
#define ULLIMATE_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

    public:
        explicit Dialog(QWidget *parent = nullptr);
        ~Dialog();

    private:
        Ui::Dialog *ui;
};

#endif // ULLIMATE_H
