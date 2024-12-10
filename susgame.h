#ifndef SUSGAME_H
#define SUSGAME_H

#include <QMainWindow>
#include "help_sus.h"
#include "ui_help_sus.h"


namespace Ui {
class susGame;
}

class susGame : public QMainWindow
{
    Q_OBJECT

public:
    explicit susGame(QWidget *parent = nullptr);
    ~susGame();

signals:
    void backToManuWindow(); // Signal to notify return to ManuWindow

private slots:
    void on_helpButton_clicked();

    void on_exitButton_clicked();

private:
    Ui::susGame *ui;
    Help_SUS *helpsus;
};

#endif // SUSGAME_H
