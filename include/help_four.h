#ifndef HELP_FOUR_H
#define HELP_FOUR_H

#include <QMainWindow>

namespace Ui {
class Help_Four;
}

class Help_Four : public QMainWindow
{
    Q_OBJECT

public:
    explicit Help_Four(QWidget *parent = nullptr);
    ~Help_Four();

private slots:
    void on_backPtn_clicked();

private:
    Ui::Help_Four *ui;
};

#endif // HELP_FOUR_H
