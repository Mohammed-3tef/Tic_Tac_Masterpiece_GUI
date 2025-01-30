#ifndef HELP_FIVEBYFIVE_H
#define HELP_FIVEBYFIVE_H

#include <QMainWindow>

namespace Ui {
class Help_Fivebyfive;
}

class Help_Fivebyfive : public QMainWindow
{
    Q_OBJECT

public:
    explicit Help_Fivebyfive(QWidget *parent = nullptr);
    ~Help_Fivebyfive();

private slots:
    void on_backPtn_clicked();

private:
    Ui::Help_Fivebyfive *ui;
};

#endif // HELP_FIVEBYFIVE_H
