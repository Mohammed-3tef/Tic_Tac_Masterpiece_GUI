#ifndef HELP_MISERE_H
#define HELP_MISERE_H

#include <QMainWindow>

namespace Ui {
class Help_Misere;
}

class Help_Misere : public QMainWindow
{
    Q_OBJECT

public:
    explicit Help_Misere(QWidget *parent = nullptr);
    ~Help_Misere();

private slots:
    void on_backPtn_clicked();

private:
    Ui::Help_Misere *ui;
};

#endif // HELP_MISERE_H
