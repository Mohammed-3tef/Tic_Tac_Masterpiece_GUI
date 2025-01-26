#include "pyramidgame.h"
#include "ui_pyramidgame.h"
#include "help_pyramid.h"
#include "win.h"
#include "draw.h"
#include <QDebug>
#include <cstdlib>
#include <ctime>
#include <QEventLoop>
#include <QTimer>

int n3 = 0; // Turn counter
bool flag3 = false;

// Constructor
pyramidGame::pyramidGame(QWidget *parent, const QString &firstPlayer, const QString &secondPlayer)
    : QMainWindow(parent),
    ui(new Ui::pyramidGame),
    helppyramid(nullptr),
    lastClickedButton(nullptr),
    win(nullptr),
    draw(nullptr) {
    ui->setupUi(this);

    // Initialize random seed
    srand(static_cast<unsigned int>(time(nullptr)));

    // Set initial UI states
    ui->ScoreX_2->setText(firstPlayer);
    ui->ScoreO_2->setText(secondPlayer);
}

// Destructor
pyramidGame::~pyramidGame() {
    delete helppyramid; helppyramid = nullptr;
    delete win; win = nullptr;
    delete draw; draw = nullptr;
    delete ui;
}

void delay3(int milliseconds) {
    QEventLoop loop;
    QTimer::singleShot(milliseconds, &loop, &QEventLoop::quit);
    loop.exec(); // Start the event loop and wait
}

// Help button
void pyramidGame::on_helpButton_2_clicked() {
    helppyramid = new help_pyramid(this);
    helppyramid->setAttribute(Qt::WA_DeleteOnClose);
    helppyramid->show();
}

// Exit button
void pyramidGame::on_exitButton_2_clicked() {
    n3 = 0;

    // Reset all buttons
    ui->x13_2->setText("");
    ui->x22_2->setText("");
    ui->x23_2->setText("");
    ui->x24_2->setText("");
    ui->x31_2->setText("");
    ui->x32_2->setText("");
    ui->x33_2->setText("");
    ui->x34_2->setText("");
    ui->x35_2->setText("");

    emit backToManuWindow();
    this->close();
}

// Update button content and style
void pyramidGame::updateButton(QPushButton *button, int &turnCounter) {
    if (button->text().isEmpty()) {
        turnCounter++;
        flag3 = true;
        if (turnCounter % 2 != 1) {
            button->setText("O");
            button->setStyleSheet("color: #000; font-size: 50px; font-weight: bold; background-color: rgb(81, 220, 224);");
        } else {
            button->setText("X");
            button->setStyleSheet("color: #000; font-size: 50px; font-weight: bold; background-color: #cbbf7a;");
        }
    }
}

// Button click handlers
void pyramidGame::on_x13_2_clicked() { updateButton(ui->x13_2, n3); checkGameState();}
void pyramidGame::on_x22_2_clicked() { updateButton(ui->x22_2, n3); checkGameState();}
void pyramidGame::on_x23_2_clicked() { updateButton(ui->x23_2, n3); checkGameState();}
void pyramidGame::on_x24_2_clicked() { updateButton(ui->x24_2, n3); checkGameState();}
void pyramidGame::on_x31_2_clicked() { updateButton(ui->x31_2, n3); checkGameState();}
void pyramidGame::on_x32_2_clicked() { updateButton(ui->x32_2, n3); checkGameState();}
void pyramidGame::on_x33_2_clicked() { updateButton(ui->x33_2, n3); checkGameState();}
void pyramidGame::on_x34_2_clicked() { updateButton(ui->x34_2, n3); checkGameState();}
void pyramidGame::on_x35_2_clicked() { updateButton(ui->x35_2, n3); checkGameState();}


// Check for "pyramid" pattern
bool pyramidGame::isPattern(const QString &a, const QString &b, const QString &c) {
    return ((a == "X" && b == "X" && c == "X") || (a == "O" && b == "O" && c == "O"));
}

// Check win condition
bool pyramidGame::isWin() {
    // Check rows   // Check columns   // Check diagonals
    if (isPattern(ui->x22_2->text(), ui->x23_2->text(), ui->x24_2->text())||
        isPattern(ui->x31_2->text(), ui->x32_2->text(), ui->x33_2->text())||
        isPattern(ui->x32_2->text(), ui->x33_2->text(), ui->x34_2->text())||
        isPattern(ui->x33_2->text(), ui->x34_2->text(), ui->x35_2->text())||

        isPattern(ui->x13_2->text(), ui->x23_2->text(), ui->x33_2->text())||

        isPattern(ui->x13_2->text(), ui->x22_2->text(), ui->x31_2->text())||
        isPattern(ui->x13_2->text(), ui->x24_2->text(), ui->x35_2->text()))
    {
        ui->x13_2->setDisabled(ui->x13_2);
        ui->x22_2->setDisabled(ui->x22_2);
        ui->x23_2->setDisabled(ui->x23_2);
        ui->x24_2->setDisabled(ui->x24_2);
        ui->x31_2->setDisabled(ui->x31_2);
        ui->x32_2->setDisabled(ui->x32_2);
        ui->x33_2->setDisabled(ui->x33_2);
        ui->x34_2->setDisabled(ui->x34_2);
        ui->x35_2->setDisabled(ui->x35_2);

        win = new Win(this);
        QString winner = (n3 % 2 == 1) ? ui->ScoreX_2->text() + " Wins!" : ui->ScoreO_2->text() + " Wins!";
        win->setWinnerText(winner);
        win->setAttribute(Qt::WA_DeleteOnClose);

        win->showFullScreen();
        return true;
    }
    else
        return false;
}

// Check draw condition
bool pyramidGame::isDraw() {
    if (n3 == 9 && !isWin()) {
        ui->x13_2->setDisabled(ui->x13_2);
        ui->x22_2->setDisabled(ui->x22_2);
        ui->x23_2->setDisabled(ui->x23_2);
        ui->x24_2->setDisabled(ui->x24_2);
        ui->x31_2->setDisabled(ui->x31_2);
        ui->x32_2->setDisabled(ui->x32_2);
        ui->x33_2->setDisabled(ui->x33_2);
        ui->x34_2->setDisabled(ui->x34_2);
        ui->x35_2->setDisabled(ui->x35_2);

        draw = new Draw(this);
        draw->setWindowTitle("Draw!");
        draw->setAttribute(Qt::WA_DeleteOnClose);

        draw->showFullScreen();
        return true;
    }
    return false;
}

// Handle random move for computer player
void pyramidGame::random() {
    QVector<QPushButton *> emptyButtons;

    // Collect all empty buttons
    if (ui->x13_2->text().isEmpty()) emptyButtons.append(ui->x13_2);
    if (ui->x22_2->text().isEmpty()) emptyButtons.append(ui->x22_2);
    if (ui->x23_2->text().isEmpty()) emptyButtons.append(ui->x23_2);
    if (ui->x24_2->text().isEmpty()) emptyButtons.append(ui->x24_2);
    if (ui->x31_2->text().isEmpty()) emptyButtons.append(ui->x31_2);
    if (ui->x32_2->text().isEmpty()) emptyButtons.append(ui->x32_2);
    if (ui->x33_2->text().isEmpty()) emptyButtons.append(ui->x33_2);
    if (ui->x34_2->text().isEmpty()) emptyButtons.append(ui->x34_2);
    if (ui->x35_2->text().isEmpty()) emptyButtons.append(ui->x35_2);

    if (emptyButtons.isEmpty()) return;

    // Select random button and update it
    int randomIndex = rand() % emptyButtons.size();
    QPushButton *selectedButton = emptyButtons[randomIndex];

    // Delay for seconds
    delay3(100);

    updateButton(selectedButton, n3);
    checkGameState();
}

// Check if game is over
void pyramidGame::checkGameState() {
    if (isWin() || isDraw()) {
        return;
    }

    // Handle computer player
    if (flag3 && n3 % 2 == 1 && ui->ScoreO_2->text() == "Random Player") {
        random();
        checkGameState();
    }
    flag3 = false;
}
