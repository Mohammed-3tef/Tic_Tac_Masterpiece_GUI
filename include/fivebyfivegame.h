#ifndef FIVEBYFIVEGAME_H
#define FIVEBYFIVEGAME_H

#include <QMainWindow>
#include <QPushButton>
#include "help_fivebyfive.h"
#include "win.h"
#include "draw.h"

namespace Ui {
class fivebyfiveGame;
}

class fivebyfiveGame : public QMainWindow {
    Q_OBJECT

public:
    explicit fivebyfiveGame(QWidget *parent = nullptr, const QString &firstPlayer = "", const QString &secondPlayer = "");
    ~fivebyfiveGame();
    void updateButton(QPushButton* button, int &turnCounter);
    int count_three();
    bool isPattern(const QString& a, const QString& b, const QString& c);
    bool isWin();
    bool isDraw();
    bool gameIsOver();
    void checkGameState();
    void random();

private slots:
    void on_helpButton_clicked();
    void on_exitButton_clicked();

    //row1
    void on_x11_clicked();
    void on_x12_clicked();
    void on_x13_clicked();
    void on_x14_clicked();
    void on_x15_clicked();
    //row2
    void on_x21_clicked();
    void on_x22_clicked();
    void on_x23_clicked();
    void on_x24_clicked();
    void on_x25_clicked();
    //row3
    void on_x31_clicked();
    void on_x32_clicked();
    void on_x33_clicked();
    void on_x34_clicked();
    void on_x35_clicked();
    //row4
    void on_x41_clicked();
    void on_x42_clicked();
    void on_x43_clicked();
    void on_x44_clicked();
    void on_x45_clicked();
    //row5
    void on_x51_clicked();
    void on_x52_clicked();
    void on_x53_clicked();
    void on_x54_clicked();
    void on_x55_clicked();
signals:
    void backToManuWindow(); 

private:
    Ui::fivebyfiveGame *ui;
    Help_Fivebyfive *helpfivebyfive;
    QPushButton *lastClickedButton;
    Win *win;
    Draw *draw;
};

#endif 
