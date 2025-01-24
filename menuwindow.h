#ifndef MENUWINDOW_H
#define MENUWINDOW_H

#include <QMainWindow>
#include "ultimategame.h"
#include "susgame.h"
#include "pyramidgame.h"

namespace Ui {
class ManuWindow;
}

class ManuWindow : public QMainWindow
{
    Q_OBJECT

signals:
    void backToMainWindow();

public:
    explicit ManuWindow(QWidget *parent = nullptr);
    ~ManuWindow();

private slots:
    void on_manuBackBtn_clicked();

    void on_onePlayerChoice_clicked();

    void on_nextBtn_clicked();

    void on_twoPlayerChoice_clicked();

private:
    Ui::ManuWindow *ui;
    ultimateGame *ultimategame;
    susGame *susgame;
    pyramidGame *pyramidgame;
};

#endif // MENUWINDOW_H
