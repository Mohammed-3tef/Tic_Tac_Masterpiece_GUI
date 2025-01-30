#ifndef ULTIMATEGAME_H
#define ULTIMATEGAME_H

#include <QMainWindow>
#include <QPair>
#include "help_ultimate.h"
#include "ui_help_ultimate.h"
#include "win.h"
#include "draw.h"

namespace Ui {
class ultimateGame;
}

class ultimateGame : public QMainWindow
{
    Q_OBJECT

public:
    explicit ultimateGame(QWidget *parent = nullptr, const QString &firstPlayer="", const QString &secondPlayer="");
    ~ultimateGame();
    bool gameIsOver();

    bool isWin(int startRow, int startCol, int endRow, int endCol);
    bool isWinBig();
    bool isDrawBig();

    void random();
    void run();
    void checkGameState();
    void updateButton(QPushButton* button, int &turnCounter);
    bool isPattern(const QString& a, const QString& b, const QString& c);
    int countThree(int startRow, int startCol, int endRow, int endCol);
    QPair<bool, char> checkBigBoardWinner();

signals:
    void backToManuWindow(); // Signal to notify return to ManuWindow

private slots:
    void on_helpButton_clicked();
    void on_exitButton_clicked();

    void on_x11_clicked();
    void on_x12_clicked();
    void on_x13_clicked();
    void on_x14_clicked();
    void on_x15_clicked();
    void on_x16_clicked();
    void on_x17_clicked();
    void on_x18_clicked();
    void on_x19_clicked();
    void on_x21_clicked();
    void on_x22_clicked();
    void on_x23_clicked();
    void on_x24_clicked();
    void on_x25_clicked();
    void on_x26_clicked();
    void on_x27_clicked();
    void on_x28_clicked();
    void on_x29_clicked();
    void on_x31_clicked();
    void on_x32_clicked();
    void on_x33_clicked();
    void on_x34_clicked();
    void on_x35_clicked();
    void on_x36_clicked();
    void on_x37_clicked();
    void on_x38_clicked();
    void on_x39_clicked();
    void on_x41_clicked();
    void on_x42_clicked();
    void on_x43_clicked();
    void on_x44_clicked();
    void on_x45_clicked();
    void on_x46_clicked();
    void on_x47_clicked();
    void on_x48_clicked();
    void on_x49_clicked();
    void on_x51_clicked();
    void on_x52_clicked();
    void on_x53_clicked();
    void on_x54_clicked();
    void on_x55_clicked();
    void on_x56_clicked();
    void on_x57_clicked();
    void on_x58_clicked();
    void on_x59_clicked();
    void on_x61_clicked();
    void on_x62_clicked();
    void on_x63_clicked();
    void on_x64_clicked();
    void on_x65_clicked();
    void on_x66_clicked();
    void on_x67_clicked();
    void on_x68_clicked();
    void on_x69_clicked();
    void on_x71_clicked();
    void on_x72_clicked();
    void on_x73_clicked();
    void on_x74_clicked();
    void on_x75_clicked();
    void on_x76_clicked();
    void on_x77_clicked();
    void on_x78_clicked();
    void on_x79_clicked();
    void on_x81_clicked();
    void on_x82_clicked();
    void on_x83_clicked();
    void on_x84_clicked();
    void on_x85_clicked();
    void on_x86_clicked();
    void on_x87_clicked();
    void on_x88_clicked();
    void on_x89_clicked();
    void on_x91_clicked();
    void on_x92_clicked();
    void on_x93_clicked();
    void on_x94_clicked();
    void on_x95_clicked();
    void on_x96_clicked();
    void on_x97_clicked();
    void on_x98_clicked();
    void on_x99_clicked();

private:
    Ui::ultimateGame *ui;
    Help_Ultimate *helpultimate;
    Win *win;
    Draw *draw;
};

#endif // ULTIMATEGAME_H
