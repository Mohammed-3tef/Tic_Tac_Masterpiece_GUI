#ifndef NUMERICALGAME_H
#define NUMERICALGAME_H

#include <QMainWindow>
#include <QPushButton>
#include "help_numerical.h"
#include "win.h"
#include "draw.h"

namespace Ui {
class numericalGame;
}

class numericalGame : public QMainWindow
{
    Q_OBJECT

public:
    explicit numericalGame(QWidget *parent = nullptr, const QString &firstPlayer="", const QString &secondPlayer="");
    ~numericalGame();
    void handleButtonClick(QPushButton *button);
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

    void on_xx0_clicked();
    void on_xx1_clicked();
    void on_xx2_clicked();
    void on_xx3_clicked();
    void on_xx4_clicked();
    void on_xx5_clicked();
    void on_xx6_clicked();
    void on_xx7_clicked();
    void on_xx8_clicked();
    void on_xx9_clicked();

signals:
    void backToManuWindow(); // Signal to notify return to ManuWindow

private:
    Ui::numericalGame *ui;
    Help_Numerical *helpNumerical;
    QPushButton *lastClickedButton;
    Win *win;
    Draw *draw;
};

#endif // NUMERICALGAME_H
