#ifndef PYRAMIDGAME_H
#define PYRAMIDGAME_H

#include <QMainWindow>
#include <QPushButton>
#include "help_pyramid.h"
#include "win.h"
#include "draw.h"

namespace Ui {
class pyramidGame;
}

class pyramidGame : public QMainWindow
{
    Q_OBJECT

public:
    explicit pyramidGame(QWidget *parent = nullptr, const QString &firstPlayer = "", const QString &secondPlayer = "");
    ~pyramidGame();
    void updateButton(QPushButton* button, int &turnCounter);
    bool isWin();
    bool isDraw();
    bool gameIsOver();
    bool isPattern(const QString& a, const QString& b, const QString& c);
    void checkGameState();
    void random();

private slots:
    void on_helpButton_2_clicked();
    void on_exitButton_2_clicked();

    // Button click handlers
    void on_x13_2_clicked();
    void on_x22_2_clicked();
    void on_x23_2_clicked();
    void on_x24_2_clicked();
    void on_x31_2_clicked();
    void on_x32_2_clicked();
    void on_x33_2_clicked();
    void on_x34_2_clicked();
    void on_x35_2_clicked();

signals:
    void backToManuWindow(); // Signal to notify return to ManuWindow

private:
    Ui::pyramidGame *ui;
    help_pyramid *helppyramid;
    QPushButton *lastClickedButton;
    Win *win;
    Draw *draw;
};

#endif // PYRAMIDGAME_H
