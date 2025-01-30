#ifndef WORDGAME_H
#define WORDGAME_H

#include <QMainWindow>
#include <QPushButton>
#include "help_word.h"
#include "win.h"
#include "draw.h"

namespace Ui {
class wordGame;
}

class wordGame : public QMainWindow
{
    Q_OBJECT

public:
    explicit wordGame(QWidget *parent = nullptr, const QString &firstPlayer="", const QString &secondPlayer="");
    ~wordGame();
    void updateButton(QPushButton* button, int &turnCounter, char c);
    bool isWin();
    bool isDraw();
    bool gameIsOver();
    bool isPattern(const QString& a, const QString& b, const QString& c);
    void checkGameState();
    void random();
    void regular();

private slots:
    void on_exitButton_clicked();
    void on_helpButton_clicked();

    // Button click handlers
    void on_x11_clicked();
    void on_x12_clicked();
    void on_x13_clicked();
    void on_x21_clicked();
    void on_x22_clicked();
    void on_x23_clicked();
    void on_x31_clicked();
    void on_x32_clicked();
    void on_x33_clicked();


    void on_xx1_clicked();
    void on_xx2_clicked();
    void on_xx3_clicked();
    void on_xx4_clicked();
    void on_xx5_clicked();
    void on_xx6_clicked();
    void on_xx7_clicked();
    void on_xx8_clicked();
    void on_xx9_clicked();
    void on_xx10_clicked();
    void on_xx11_clicked();
    void on_xx12_clicked();
    void on_xx13_clicked();
    void on_xx14_clicked();
    void on_xx15_clicked();
    void on_xx16_clicked();
    void on_xx17_clicked();
    void on_xx18_clicked();
    void on_xx19_clicked();
    void on_xx20_clicked();
    void on_xx21_clicked();
    void on_xx22_clicked();
    void on_xx23_clicked();
    void on_xx24_clicked();
    void on_xx25_clicked();
    void on_xx26_clicked();

signals:
    void backToManuWindow(); // Signal to notify return to ManuWindow

private:
    Ui::wordGame *ui;
    help_word *helpword;
    QPushButton *lastClickedButton;
    Win *win;
    Draw *draw;
};

#endif // WORDGAME_H
