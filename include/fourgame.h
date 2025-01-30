#ifndef FOURGAME_H
#define FOURGAME_H

#include <QMainWindow>
#include <QPushButton>
#include "help_four.h"
#include "win.h"
#include "draw.h"

namespace Ui {
class fourGame;
}

class fourGame : public QMainWindow
{
    Q_OBJECT

public:
    explicit fourGame(QWidget *parent = nullptr, const QString &firstPlayer="", const QString &secondPlayer="");
    ~fourGame();

    void resetButtons();
    void handleColumnClick(int column);
    void updateButton(QPushButton* button, int& turnConut);
    bool isWin();
    bool declareWin();
    bool isDraw();
    bool gameIsOver();
    bool isPattern(const QString& a, const QString& b, const QString& c, const QString& d);
    void checkGameState();
    void random();
    void regular();

private slots:
    void on_exitButton_clicked();
    void on_helpButton_clicked();

    // Button click handlers
    void on_click1_clicked();
    void on_click2_clicked();
    void on_click3_clicked();
    void on_click4_clicked();
    void on_click5_clicked();
    void on_click6_clicked();
    void on_click7_clicked();

signals:
    void backToManuWindow(); // Signal to notify return to ManuWindow

private:
    Ui::fourGame *ui;
    Help_Four *helpFour;
    QPushButton *lastClickedButton;
    Win *win;
    Draw *draw;
};

#endif // FOURGAME_H
