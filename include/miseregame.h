#ifndef MISEREGAME_H
#define MISEREGAME_H

#include <QMainWindow>
#include <QPushButton>
#include "help_misere.h"
#include "win.h"
#include "draw.h"

namespace Ui {
class misereGame;
}

class misereGame : public QMainWindow {
    Q_OBJECT

public:
    explicit misereGame(QWidget *parent = nullptr, const QString &firstPlayer = "", const QString &secondPlayer = "");
    ~misereGame();
    void updateButton(QPushButton* button, int &turnCounter);
    bool isLose();
    bool isDraw();
    bool gameIsOver();
    void checkGameState();
    void random();
    bool isPattern(const QString& a, const QString& b, const QString& c);

private slots:
    void on_exitButton_clicked();

    void on_x11_clicked();
    void on_x12_clicked();
    void on_x13_clicked();
    void on_x21_clicked();
    void on_x22_clicked();
    void on_x23_clicked();
    void on_x31_clicked();
    void on_x32_clicked();
    void on_x33_clicked();

signals:
    void backToManuWindow(); 

private:
    Ui::misereGame *ui;
    Help_Misere *helpmisere;
    QPushButton *lastClickedButton;
    Win *win;
    Draw *draw;
    int turnCounter = 0; // Turn counter
    bool flag = false; // Flag for random player
};

#endif
