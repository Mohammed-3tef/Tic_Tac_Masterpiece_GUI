#include "susgame.h"
#include "ui_susgame.h"
#include "help_sus.h"
#include "win.h"
#include "draw.h"
#include <QDebug>
#include <cstdlib>
#include <ctime>

int n = 0; // Turn counter
int scoreS = 0; // Player S score
int scoreU = 0; // Player U score
bool flag = false;

// Constructor
susGame::susGame(QWidget *parent, const QString &firstPlayer, const QString &secondPlayer)
    : QMainWindow(parent),
    ui(new Ui::susGame),
    helpsus(nullptr),
    lastClickedButton(nullptr),
    win(nullptr),
    draw(nullptr) {
    ui->setupUi(this);

    // Initialize random seed
    srand(static_cast<unsigned int>(time(nullptr)));

    // Set initial UI states
    ui->ScoreS->setText(firstPlayer);
    ui->ScoreU->setText(secondPlayer);
    ui->SS->setText("0");
    ui->UU->setText("0");
}

// Destructor
susGame::~susGame() {
    delete helpsus; helpsus = nullptr;
    delete win; win = nullptr;
    delete draw; draw = nullptr;
    delete ui;
}

// Update button content and style
void susGame::updateButton(QPushButton *button, int &turnCounter) {
    if (button->text().isEmpty()) {
        turnCounter++;
        flag = true;
        if (turnCounter % 2 != 1) {
            button->setText("U");
            button->setStyleSheet("color: rgb(86, 143, 151); font-size: 50px; font-weight: bold; background-color: rgb(155, 90, 215);");
        } else {
            button->setText("S");
            button->setStyleSheet("color: rgb(155, 90, 215); font-size: 50px; font-weight: bold; background-color: rgb(86, 143, 151);");
        }
    }
}

// Button click handlers
void susGame::on_x11_clicked() { updateButton(ui->x11, n); checkGameState(); }
void susGame::on_x12_clicked() { updateButton(ui->x12, n); checkGameState(); }
void susGame::on_x13_clicked() { updateButton(ui->x13, n); checkGameState(); }
void susGame::on_x21_clicked() { updateButton(ui->x21, n); checkGameState(); }
void susGame::on_x22_clicked() { updateButton(ui->x22, n); checkGameState(); }
void susGame::on_x23_clicked() { updateButton(ui->x23, n); checkGameState(); }
void susGame::on_x31_clicked() { updateButton(ui->x31, n); checkGameState(); }
void susGame::on_x32_clicked() { updateButton(ui->x32, n); checkGameState(); }
void susGame::on_x33_clicked() { updateButton(ui->x33, n); checkGameState(); }

// Help button
void susGame::on_helpButton_clicked() {
    helpsus = new Help_SUS(this);
    helpsus->setAttribute(Qt::WA_DeleteOnClose);
    helpsus->show();
}

// Exit button
void susGame::on_exitButton_clicked() {
    n = 0;
    scoreS = 0;
    scoreU = 0;

    // Reset all buttons
    ui->x11->setText("");
    ui->x12->setText("");
    ui->x13->setText("");
    ui->x21->setText("");
    ui->x22->setText("");
    ui->x23->setText("");
    ui->x31->setText("");
    ui->x32->setText("");
    ui->x33->setText("");

    ui->SS->setText("0");
    ui->UU->setText("0");

    emit backToManuWindow();
    this->close();
}

// Check for "SUS" pattern
bool susGame::isPattern(const QString &a, const QString &b, const QString &c) {
    return (a == "S" && b == "U" && c == "S");
}

// Count specific patterns
int susGame::count_three() {
    int count = 0;

    // Check rows
    count += isPattern(ui->x11->text(), ui->x12->text(), ui->x13->text());
    count += isPattern(ui->x21->text(), ui->x22->text(), ui->x23->text());
    count += isPattern(ui->x31->text(), ui->x32->text(), ui->x33->text());

    // Check columns
    count += isPattern(ui->x11->text(), ui->x21->text(), ui->x31->text());
    count += isPattern(ui->x12->text(), ui->x22->text(), ui->x32->text());
    count += isPattern(ui->x13->text(), ui->x23->text(), ui->x33->text());

    // Check diagonals
    count += isPattern(ui->x11->text(), ui->x22->text(), ui->x33->text());
    count += isPattern(ui->x13->text(), ui->x22->text(), ui->x31->text());

    return count;
}

// Check win condition
bool susGame::isWin() {
    int countSus = count_three();

    if (n % 2 == 0)
        scoreU = countSus != 0 ? (countSus - scoreS) : scoreS;
    else
        scoreS = countSus != 0 ? (countSus - scoreU) : scoreU;

    ui->SS->setText(QString::number(scoreS));
    ui->UU->setText(QString::number(scoreU));

    if (countSus > 0 && n == 9) { // Winning condition met
        if (scoreS == scoreU) {return false;}
        win = new Win(this);
        QString winner = (scoreS > scoreU) ? ui->ScoreS->text() + " Wins!" : ui->ScoreU->text() + " Wins!";
        win->setWinnerText(winner);
        win->setAttribute(Qt::WA_DeleteOnClose);
        win->showFullScreen();
        return true;
    }

    return false;
}

// Check draw condition
bool susGame::isDraw() {
    if (n == 9 && scoreS == scoreU) {
        draw = new Draw(this);
        draw->setWindowTitle("Draw!");
        draw->setAttribute(Qt::WA_DeleteOnClose);
        draw->showFullScreen();
        return true;
    }
    return false;
}

// Check if game is over
void susGame::checkGameState() {
    if (isWin() || isDraw()) {
        return;
    }

    // Handle computer player
    if (flag && n % 2 == 1 && ui->ScoreU->text() == "Random Player") {
        random();
        checkGameState();
    }
    flag = false;
}

// Handle random move for computer player
void susGame::random() {
    QVector<QPushButton *> emptyButtons;

    // Collect all empty buttons
    if (ui->x11->text().isEmpty()) emptyButtons.append(ui->x11);
    if (ui->x12->text().isEmpty()) emptyButtons.append(ui->x12);
    if (ui->x13->text().isEmpty()) emptyButtons.append(ui->x13);
    if (ui->x21->text().isEmpty()) emptyButtons.append(ui->x21);
    if (ui->x22->text().isEmpty()) emptyButtons.append(ui->x22);
    if (ui->x23->text().isEmpty()) emptyButtons.append(ui->x23);
    if (ui->x31->text().isEmpty()) emptyButtons.append(ui->x31);
    if (ui->x32->text().isEmpty()) emptyButtons.append(ui->x32);
    if (ui->x33->text().isEmpty()) emptyButtons.append(ui->x33);

    if (emptyButtons.isEmpty()) return;

    // Select random button and update it
    int randomIndex = rand() % emptyButtons.size();
    QPushButton *selectedButton = emptyButtons[randomIndex];
    updateButton(selectedButton, n);
    checkGameState();
}
