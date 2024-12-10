#ifndef ULTIMATEGAME_H
#define ULTIMATEGAME_H

#include <QMainWindow>
#include "help_ultimate.h"
#include "ui_help_ultimate.h"

namespace Ui {
class ultimateGame;
}

class ultimateGame : public QMainWindow
{
    Q_OBJECT

public:
    explicit ultimateGame(QWidget *parent = nullptr);
    ~ultimateGame();

signals:
    void backToManuWindow(); // Signal to notify return to ManuWindow

private slots:
    void on_helpButton_clicked();

    void on_exitButton_clicked();

private:
    Ui::ultimateGame *ui;
    Help_Ultimate *helpultimate;
};

#endif // ULTIMATEGAME_H
