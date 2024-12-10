#ifndef HELP_SUS_H
#define HELP_SUS_H

#include <QMainWindow>

namespace Ui {
class Help_SUS;
}

class Help_SUS : public QMainWindow
{
    Q_OBJECT

public:
    explicit Help_SUS(QWidget *parent = nullptr);
    ~Help_SUS();

private slots:
    void on_pushButton_clicked();

    void on_backPtn_clicked();

private:
    Ui::Help_SUS *ui;
};

#endif // HELP_SUS_H
