#ifndef HELP_ULTIMATE_H
#define HELP_ULTIMATE_H

#include <QMainWindow>

namespace Ui {
class Help_Ultimate;
}

class Help_Ultimate : public QMainWindow
{
    Q_OBJECT

public:
    explicit Help_Ultimate(QWidget *parent = nullptr);
    ~Help_Ultimate();

private slots:
    void on_backPtn_clicked();

private:
    Ui::Help_Ultimate *ui;
};

#endif // HELP_ULTIMATE_H
