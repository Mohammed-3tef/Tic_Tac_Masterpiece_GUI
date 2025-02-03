#include "../include/menuwindow.h"
#include "../include/ultimategame.h"
#include "../include/susgame.h"
#include "../include/pyramidgame.h"
#include "../include/wordgame.h"
#include "../include/numericalgame.h"
#include "../include/fourgame.h"
#include "../include/fivebyfivegame.h"
#include "../include/miseregame.h"
#include "ui_menuwindow.h"
#include "QMessageBox"
#include <QIcon>

ManuWindow::ManuWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ManuWindow)
    , ultimategame(nullptr)
    , susgame(nullptr)
{
    ui->setupUi(this);
    ui->onePlayerChoice->setChecked(false);
    ui->twoPlayerChoice->setChecked(false);
    ui->susGameChoice->setChecked(false);
    ui->ultimateGameChoice->setChecked(false);
    ui->pyramidGameChoice->setChecked(false);
    ui->wordGameChoice->setChecked(false);
    ui->numericalGameChoice->setChecked(false);
    ui->fourGameChoice->setChecked(false);
    ui->fiveGameChoice->setChecked(false);
    ui->misereGameChoice->setChecked(false);
    ui->firstInput->setEnabled(false);
    ui->secondInput->setEnabled(false);
}

ManuWindow::~ManuWindow()
{
    delete ui;
    delete ultimategame;
    delete susgame;
    delete pyramidgame;
    delete wordgame;
    delete numericalgame;
    delete fourgame;
    delete fivebyfivegame;
    delete miseregame;
}

void ManuWindow::on_manuBackBtn_clicked()
{
    emit backToMainWindow();
    this->close();
}

void ManuWindow::on_nextBtn_clicked()
{
    // Check if a player mode is selected
    if (!ui->onePlayerChoice->isChecked() && !ui->twoPlayerChoice->isChecked()) {
        QMessageBox::warning(this, "Selection Missing", "Please select a player mode!");
        return;
    }

    // Check if a game mode is selected
    if (!ui->susGameChoice->isChecked() && !ui->ultimateGameChoice->isChecked() && !ui->pyramidGameChoice->isChecked() && !ui->wordGameChoice->isChecked() && !ui->numericalGameChoice->isChecked() && !ui->fourGameChoice->isChecked() && !ui->misereGameChoice->isChecked() ) {
        QMessageBox::warning(this, "Selection Missing", "Please select a game mode!");
        return;
    }

    // Check if the first input is filled
    if (ui->firstInput->text().isEmpty()) {
        QMessageBox::warning(this, "Input Missing", "Please fill in the first input field!");
        return;
    }

    // If two-player mode is selected, check if the second input is filled
    if (ui->twoPlayerChoice->isChecked() && ui->secondInput->text().isEmpty()) {
        QMessageBox::warning(this, "Input Missing", "Please fill in the second input field for two-player mode!");
        return;
    }

    // If the first input = the second input
    if (ui->firstInput->text() == ui->secondInput->text()) {
        QMessageBox::warning(this, "Invalid Input", "Both players cannot have the same name.");
        return;
    }

    if (ui->susGameChoice->isChecked()) {
        QString firstPlayer = ui->firstInput->text();
        QString secondPlayer = ui->twoPlayerChoice->isChecked() ? ui->secondInput->text() : "Random Player";
        susgame = new susGame(this, firstPlayer, secondPlayer);
        susgame->showFullScreen();
    }

    if (ui->ultimateGameChoice->isChecked()) {
        QString firstPlayer = ui->firstInput->text();
        QString secondPlayer = ui->twoPlayerChoice->isChecked() ? ui->secondInput->text() : "Random Player";
        ultimategame = new ultimateGame(this, firstPlayer, secondPlayer);
        ultimategame->showFullScreen();
    }

    if (ui->pyramidGameChoice->isChecked()) {
        QString firstPlayer = ui->firstInput->text();
        QString secondPlayer = ui->twoPlayerChoice->isChecked() ? ui->secondInput->text() : "Random Player";
        pyramidgame = new pyramidGame(this, firstPlayer, secondPlayer);
        pyramidgame->showFullScreen();
    }

    if (ui->wordGameChoice->isChecked()) {
        QString firstPlayer = ui->firstInput->text();
        QString secondPlayer = ui->twoPlayerChoice->isChecked() ? ui->secondInput->text() : "Random Player";
        wordgame = new wordGame(this, firstPlayer, secondPlayer);
        wordgame->showFullScreen();
    }

    if (ui->numericalGameChoice->isChecked()) {
        QString firstPlayer = ui->firstInput->text();
        QString secondPlayer = ui->twoPlayerChoice->isChecked() ? ui->secondInput->text() : "Random Player";
        numericalgame = new numericalGame(this, firstPlayer, secondPlayer);
        numericalgame->showFullScreen();
    }

    if (ui->fourGameChoice->isChecked()) {
        QString firstPlayer = ui->firstInput->text();
        QString secondPlayer = ui->twoPlayerChoice->isChecked() ? ui->secondInput->text() : "Random Player";
        fourgame = new fourGame(this, firstPlayer, secondPlayer);
        fourgame->showFullScreen();
    }
    if (ui->fiveGameChoice->isChecked()) {
        QString firstPlayer = ui->firstInput->text();
        QString secondPlayer = ui->twoPlayerChoice->isChecked() ? ui->secondInput->text() : "Random Player";
        fourgame = new fourGame(this, firstPlayer, secondPlayer);
        fourgame->showFullScreen();
    }

   if (ui->misereGameChoice->isChecked()) {
        QString firstPlayer = ui->firstInput->text();
        QString secondPlayer = ui->twoPlayerChoice->isChecked() ? ui->secondInput->text() : "Random Player";
        miseregame = new misereGame(this, firstPlayer, secondPlayer); // Initialize miseregame
        miseregame->showFullScreen();
    }
}


void ManuWindow::on_onePlayerChoice_clicked()
{
    ui->firstInput->setEnabled(true);
    ui->secondInput->setEnabled(false);
    ui->secondInput->setText("Random Player");
}

void ManuWindow::on_twoPlayerChoice_clicked()
{
    ui->firstInput->setEnabled(true);
    ui->secondInput->setEnabled(true);
    ui->secondInput->clear();
}

