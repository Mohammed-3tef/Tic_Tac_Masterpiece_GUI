#ifndef WORDGAME_H
#define WORDGAME_H

#include <QMainWindow>

namespace Ui {
class wordgame;
}

class wordgame : public QMainWindow
{
    Q_OBJECT

public:
    explicit wordgame(QWidget *parent = nullptr);
    ~wordgame();

private:
    Ui::wordgame *ui;
};

#endif // WORDGAME_H
