#ifndef SUSGAME_H
#define SUSGAME_H

#include <QMainWindow>
#include <QPushButton>
#include "help_sus.h"
#include "win.h"
#include "draw.h"

namespace Ui {
class susGame;
}

class susGame : public QMainWindow {
    Q_OBJECT

public:
    explicit susGame(QWidget *parent = nullptr, const QString &firstPlayer = "", const QString &secondPlayer = "");
    ~susGame();
    void updateButton(QPushButton* button, int &turnCounter);
    int count_three();
    bool isWin();
    bool isDraw();
    bool gameIsOver();
    bool isPattern(const QString& a, const QString& b, const QString& c);
    void checkGameState();
    void random();

private slots:
    void on_helpButton_clicked();
    void on_exitButton_clicked();

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

signals:
    void backToManuWindow(); // Signal to notify return to ManuWindow

private:
    Ui::susGame *ui;
    Help_SUS *helpsus;
    QPushButton *lastClickedButton;
    Win *win;
    Draw *draw;
};

#endif // SUSGAME_H
