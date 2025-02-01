#include "../include/miseregame.h"
#include "ui_miseregame.h"
#include "../include/help_misere.h"
#include "../include/win.h"
#include "../include/draw.h"
#include <QDebug>
#include <cstdlib>
#include <ctime>
#include <QEventLoop>
#include <QTimer>

// Constructor
misereGame::misereGame(QWidget *parent, const QString &firstPlayer, const QString &secondPlayer)
    : QMainWindow(parent),
    ui(new Ui::misereGame),
    helpmisere(nullptr),
    lastClickedButton(nullptr),
    win(nullptr),
    draw(nullptr) {
    ui->setupUi(this);

    // Initialize random seed
    srand(static_cast<unsigned int>(time(nullptr)));

    // Set initial UI states
    ui->ScoreX->setText(firstPlayer);
    ui->ScoreO->setText(secondPlayer);
}

// Destructor
misereGame::~misereGame() {
    delete helpmisere; helpmisere = nullptr;
    delete win; win = nullptr;
    delete draw; draw = nullptr;
    delete ui;
}

void delay(int milliseconds) {
    QEventLoop loop;
    QTimer::singleShot(milliseconds, &loop, &QEventLoop::quit);
    loop.exec(); // Start the event loop and wait
}

// Update button content and style
void misereGame::updateButton(QPushButton *button, int &turnCounter) {
    if (button->text().isEmpty()) {
        turnCounter++;
        flag = true;
        if (turnCounter % 2 == 0) {
            button->setText("O");
            button->setStyleSheet("color: #000; font-size: 50px; font-weight: bold; background-color: rgb(81, 220, 224);");
        } else {
            button->setText("X");
            button->setStyleSheet("color: #000; font-size: 50px; font-weight: bold; background-color: #cbbf7a;");
        }
        checkGameState();
    }
}

// Check for a pattern of three consecutive symbols
bool misereGame::isPattern(const QString &a, const QString &b, const QString &c) {
    return ((a == "X" && b == "X" && c == "X") || (a == "O" && b == "O" && c == "O"));
}

// Check if the current player has lost (connected three symbols)
bool misereGame::isLose() {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (isPattern(ui->gridLayout->itemAtPosition(i, 0)->widget()->property("text").toString(),
                      ui->gridLayout->itemAtPosition(i, 1)->widget()->property("text").toString(),
                      ui->gridLayout->itemAtPosition(i, 2)->widget()->property("text").toString())) {
            return true;
        }
    }

    // Check columns
    for (int j = 0; j < 3; j++) {
        if (isPattern(ui->gridLayout->itemAtPosition(0, j)->widget()->property("text").toString(),
                      ui->gridLayout->itemAtPosition(1, j)->widget()->property("text").toString(),
                      ui->gridLayout->itemAtPosition(2, j)->widget()->property("text").toString())) {
            return true;
        }
    }

    // Check diagonals
    if (isPattern(ui->gridLayout->itemAtPosition(0, 0)->widget()->property("text").toString(),
                  ui->gridLayout->itemAtPosition(1, 1)->widget()->property("text").toString(),
                  ui->gridLayout->itemAtPosition(2, 2)->widget()->property("text").toString())) {
        return true;
    }

    if (isPattern(ui->gridLayout->itemAtPosition(0, 2)->widget()->property("text").toString(),
                  ui->gridLayout->itemAtPosition(1, 1)->widget()->property("text").toString(),
                  ui->gridLayout->itemAtPosition(2, 0)->widget()->property("text").toString())) {
        return true;
    }

    return false; // No losing condition met
}

// Check draw condition
bool misereGame::isDraw() {
    if (turnCounter == 9 && !isLose()) {
        return true;
    }
    return false;
}

// Check if game is over
void misereGame::checkGameState() {
    if (isLose()) {
        win = new Win(this);
        QString loser = (turnCounter % 2 == 0) ? ui->ScoreX->text() + " Loses!" : ui->ScoreO->text() + " Loses!";
        win->setWinnerText(loser);
        win->setAttribute(Qt::WA_DeleteOnClose);
        win->showFullScreen();
        return;
    }

    if (isDraw()) {
        draw = new Draw(this);
        draw->setWindowTitle("Draw!");
        draw->setAttribute(Qt::WA_DeleteOnClose);
        draw->showFullScreen();
        return;
    }

    // Handle computer player
    if (flag && turnCounter % 2 == 1 && ui->ScoreO->text() == "Random Player") {
        random();
        checkGameState();
    }
    flag = false;
}

// Handle random move for computer player
void misereGame::random() {
    QVector<QPushButton *> emptyButtons;

    // Collect all empty buttons
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            QPushButton *button = qobject_cast<QPushButton*>(ui->gridLayout->itemAtPosition(i, j)->widget());
            if (button && button->text().isEmpty()) {
                emptyButtons.append(button);
            }
        }
    }

    if (emptyButtons.isEmpty()) return;

    // Select random button and update it
    int randomIndex = rand() % emptyButtons.size();
    QPushButton *selectedButton = emptyButtons[randomIndex];

    // Delay for seconds
    delay(100);

    updateButton(selectedButton, turnCounter);
    checkGameState();
}

// Exit button
void misereGame::on_exitButton_clicked() {
    turnCounter = 0;

    // Reset all buttons
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            QPushButton *button = qobject_cast<QPushButton*>(ui->gridLayout->itemAtPosition(i, j)->widget());
            if (button) {
                button->setText("");
            }
        }
    }

    emit backToManuWindow();
    this->close();
}

// Button click handlers
void misereGame::on_x11_clicked() { updateButton(ui->x11, turnCounter); }
void misereGame::on_x12_clicked() { updateButton(ui->x12, turnCounter); }
void misereGame::on_x13_clicked() { updateButton(ui->x13, turnCounter); }
void misereGame::on_x21_clicked() { updateButton(ui->x21, turnCounter); }
void misereGame::on_x22_clicked() { updateButton(ui->x22, turnCounter); }
void misereGame::on_x23_clicked() { updateButton(ui->x23, turnCounter); }
void misereGame::on_x31_clicked() { updateButton(ui->x31, turnCounter); }
void misereGame::on_x32_clicked() { updateButton(ui->x32, turnCounter); }
void misereGame::on_x33_clicked() { updateButton(ui->x33, turnCounter); }
