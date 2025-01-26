#ifndef HELP_NUMERICAL_H
#define HELP_NUMERICAL_H

#include <QMainWindow>

namespace Ui {
class Help_Numerical;
}

class Help_Numerical : public QMainWindow
{
    Q_OBJECT

public:
    explicit Help_Numerical(QWidget *parent = nullptr);
    ~Help_Numerical();

private slots:
    void on_backPtn_clicked();

private:
    Ui::Help_Numerical *ui;
};

#endif // HELP_NUMERICAL_H
