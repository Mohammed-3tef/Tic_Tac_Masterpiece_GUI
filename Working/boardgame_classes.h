#ifndef BOARDGAME_CLASSES_H
#define BOARDGAME_CLASSES_H

#include <QDialog>

namespace Ui {
class BoardGame_Classes;
}

class BoardGame_Classes : public QDialog
{
    Q_OBJECT

public:
    explicit BoardGame_Classes(QWidget *parent = nullptr);
    ~BoardGame_Classes();

private:
    Ui::BoardGame_Classes *ui;
};

#endif // BOARDGAME_CLASSES_H
