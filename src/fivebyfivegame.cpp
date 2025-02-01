#include "../include/fivebyfivegame.h"
#include "ui_fivebyfivegame.h"
#include "../include/help_fivebyfive.h"
#include "../include/win.h"
#include "../include/draw.h"
#include <QDebug>
#include <cstdlib>
#include <ctime>
#include <QEventLoop>
#include <QTimer>

// Constructor
fivebyfiveGame::fivebyfiveGame(QWidget *parent, const QString &firstPlayer, const QString &secondPlayer)
    : QMainWindow(parent),
    ui(new Ui::fivebyfiveGame),
    helpfivebyfive(nullptr),
    lastClickedButton(nullptr),
    win(nullptr),
    draw(nullptr) {
    ui->setupUi(this);

    // Initialize random seed
    srand(static_cast<unsigned int>(time(nullptr)));

    // Set initial UI states
    ui->ScoreX->setText(firstPlayer);
    ui->ScoreO->setText(secondPlayer);
    ui->XX->setText("0");
    ui->OO->setText("0");
}

// Destructor
fivebyfiveGame::~fivebyfiveGame() {
    delete helpfivebyfive; helpfivebyfive = nullptr;
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
void fivebyfiveGame::updateButton(QPushButton *button, int &turnCounter) {
    if (button->text().isEmpty()) {
        turnCounter++;
        flag = true;
        if (turnCounter % 2 != 1) {
            button->setText("O");
            button->setStyleSheet("color: #000; font-size: 50px; font-weight: bold; background-color: rgb(81, 220, 224);");
        } else {
            button->setText("X");
            button->setStyleSheet("color: #000; font-size: 50px; font-weight: bold; background-color: #cbbf7a;");
        }
    }
}

// Check for a pattern of three consecutive symbols
bool fivebyfiveGame::isPattern(const QString &a, const QString &b, const QString &c, const QString &symbol) {
    return (a == symbol && b == symbol && c == symbol);
}

// Count patterns for a given symbol
int fivebyfiveGame::countPatterns(const QString &symbol) {
    int count = 0;

    // Check rows
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 3; j++) {
            if (isPattern(ui->gridLayout->itemAtPosition(i, j)->widget()->property("text").toString(),
                          ui->gridLayout->itemAtPosition(i, j + 1)->widget()->property("text").toString(),
                          ui->gridLayout->itemAtPosition(i, j + 2)->widget()->property("text").toString(), symbol)) {
                count++;
            }
        }
    }

    // Check columns
    for (int j = 0; j < 5; j++) {
        for (int i = 0; i < 3; i++) {
            if (isPattern(ui->gridLayout->itemAtPosition(i, j)->widget()->property("text").toString(),
                          ui->gridLayout->itemAtPosition(i + 1, j)->widget()->property("text").toString(),
                          ui->gridLayout->itemAtPosition(i + 2, j)->widget()->property("text").toString(), symbol)) {
                count++;
            }
        }
    }

    // Check diagonals (top-left to bottom-right)
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (isPattern(ui->gridLayout->itemAtPosition(i, j)->widget()->property("text").toString(),
                          ui->gridLayout->itemAtPosition(i + 1, j + 1)->widget()->property("text").toString(),
                          ui->gridLayout->itemAtPosition(i + 2, j + 2)->widget()->property("text").toString(), symbol)) {
                count++;
            }
        }
    }

    // Check diagonals (bottom-left to top-right)
    for (int i = 2; i < 5; i++) {
        for (int j = 0; j < 3; j++) {
            if (isPattern(ui->gridLayout->itemAtPosition(i, j)->widget()->property("text").toString(),
                          ui->gridLayout->itemAtPosition(i - 1, j + 1)->widget()->property("text").toString(),
                          ui->gridLayout->itemAtPosition(i - 2, j + 2)->widget()->property("text").toString(), symbol)) {
                count++;
            }
        }
    }

    return count;
}

// Check win condition
bool fivebyfiveGame::isWin() {
    int countX = countPatterns("X");
    int countO = countPatterns("O");

    scoreX = countX;
    scoreO = countO;

    ui->XX->setText(QString::number(scoreX));
    ui->OO->setText(QString::number(scoreO));

    if (turnCounter == 24) { // Game ends after 24 moves
        if (scoreX > scoreO) {
            win = new Win(this);
            win->setWinnerText(ui->ScoreX->text() + " Wins!");
            win->setAttribute(Qt::WA_DeleteOnClose);
            win->showFullScreen();
            return true;
        } else if (scoreO > scoreX) {
            win = new Win(this);
            win->setWinnerText(ui->ScoreO->text() + " Wins!");
            win->setAttribute(Qt::WA_DeleteOnClose);
            win->showFullScreen();
            return true;
        }
    }

    return false;
}

// Check draw condition
bool fivebyfiveGame::isDraw() {
    if (turnCounter == 24 && scoreX == scoreO) {
        draw = new Draw(this);
        draw->setWindowTitle("Draw!");
        draw->setAttribute(Qt::WA_DeleteOnClose);
        draw->showFullScreen();
        return true;
    }
    return false;
}

// Check if game is over
void fivebyfiveGame::checkGameState() {
    if (isWin() || isDraw()) {
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
void fivebyfiveGame::random() {
    QVector<QPushButton *> emptyButtons;

    // Collect all empty buttons
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
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
void fivebyfiveGame::on_exitButton_clicked() {
    turnCounter = 0;
    scoreX = 0;
    scoreO = 0;

    // Reset all buttons
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            QPushButton *button = qobject_cast<QPushButton*>(ui->gridLayout->itemAtPosition(i, j)->widget());
            if (button) {
                button->setText("");
            }
        }
    }

    ui->XX->setText("0");
    ui->OO->setText("0");

    emit backToManuWindow();
    this->close();
}

// Button click handlers
void fivebyfiveGame::on_x11_clicked() { updateButton(ui->x11, turnCounter); checkGameState(); }
void fivebyfiveGame::on_x12_clicked() { updateButton(ui->x12, turnCounter); checkGameState(); }
void fivebyfiveGame::on_x13_clicked() { updateButton(ui->x13, turnCounter); checkGameState(); }
void fivebyfiveGame::on_x14_clicked() { updateButton(ui->x14, turnCounter); checkGameState(); }
void fivebyfiveGame::on_x15_clicked() { updateButton(ui->x15, turnCounter); checkGameState(); }
void fivebyfiveGame::on_x21_clicked() { updateButton(ui->x21, turnCounter); checkGameState(); }
void fivebyfiveGame::on_x22_clicked() { updateButton(ui->x22, turnCounter); checkGameState(); }
void fivebyfiveGame::on_x23_clicked() { updateButton(ui->x23, turnCounter); checkGameState(); }
void fivebyfiveGame::on_x24_clicked() { updateButton(ui->x24, turnCounter); checkGameState(); }
void fivebyfiveGame::on_x25_clicked() { updateButton(ui->x25, turnCounter); checkGameState(); }
void fivebyfiveGame::on_x31_clicked() { updateButton(ui->x31, turnCounter); checkGameState(); }
void fivebyfiveGame::on_x32_clicked() { updateButton(ui->x32, turnCounter); checkGameState(); }
void fivebyfiveGame::on_x33_clicked() { updateButton(ui->x33, turnCounter); checkGameState(); }
void fivebyfiveGame::on_x34_clicked() { updateButton(ui->x34, turnCounter); checkGameState(); }
void fivebyfiveGame::on_x35_clicked() { updateButton(ui->x35, turnCounter); checkGameState(); }
void fivebyfiveGame::on_x41_clicked() { updateButton(ui->x41, turnCounter); checkGameState(); }
void fivebyfiveGame::on_x42_clicked() { updateButton(ui->x42, turnCounter); checkGameState(); }
void fivebyfiveGame::on_x43_clicked() { updateButton(ui->x43, turnCounter); checkGameState(); }
void fivebyfiveGame::on_x44_clicked() { updateButton(ui->x44, turnCounter); checkGameState(); }
void fivebyfiveGame::on_x45_clicked() { updateButton(ui->x45, turnCounter); checkGameState(); }
void fivebyfiveGame::on_x51_clicked() { updateButton(ui->x51, turnCounter); checkGameState(); }
void fivebyfiveGame::on_x52_clicked() { updateButton(ui->x52, turnCounter); checkGameState(); }
void fivebyfiveGame::on_x53_clicked() { updateButton(ui->x53, turnCounter); checkGameState(); }
void fivebyfiveGame::on_x54_clicked() { updateButton(ui->x54, turnCounter); checkGameState(); }
void fivebyfiveGame::on_x55_clicked() { updateButton(ui->x55, turnCounter); checkGameState(); }
