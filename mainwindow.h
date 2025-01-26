#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "helpwindow.h"
#include "creditswindow.h"
#include "menuwindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_helpBtn_clicked(); // Help button click handler
    void showMainWindow();     // Slot to show MainWindow

    void on_quitBtn_clicked();

    void on_creditsBtn_clicked();

    void on_startBtn_clicked();

private:
    Ui::MainWindow *ui;
    HelpWindow *helpWindow;
    CreditsWindow *creditWindow;
    ManuWindow *manuWindow;
};

#endif // MAINWINDOW_H
