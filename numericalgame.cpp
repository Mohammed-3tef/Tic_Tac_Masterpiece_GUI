#include "numericalgame.h"
#include "ui_numericalgame.h"
#include "help_numerical.h"
#include "win.h"
#include "draw.h"
#include <QDebug>
#include <cstdlib>
#include <ctime>
#include <QEventLoop>
#include <QTimer>
#include <QVector>
#include <QMessageBox>

char numericalChar = ' ';
bool numericalFlag = false;
int numerical = 0;
QVector<int> secondPlayer = {0, 2, 4, 6, 8};

numericalGame::numericalGame(QWidget *parent, const QString &firstPlayerName, const QString &secondPlayerName)
    : QMainWindow(parent),
    ui(new Ui::numericalGame),
    helpNumerical(nullptr),
    lastClickedButton(nullptr),
    win(nullptr),
    draw(nullptr)
{
    ui->setupUi(this);

    // Initialize random seed
    srand(static_cast<unsigned int>(time(nullptr)));

    // Set initial UI states
    ui->Score1->setText(firstPlayerName);
    ui->Score2->setText(secondPlayerName);

    numericalChar = ' ';
    numericalFlag = false;
    numerical = 0;
    secondPlayer = {0, 2, 4, 6, 8};
}

numericalGame::~numericalGame(){
    delete helpNumerical;
    delete win;
    delete draw;
    delete ui;
}

void numericalGame::on_xx0_clicked(){
    numericalChar = '0';
    if (!numericalFlag) {
        QMessageBox::warning(this, "Invalid Move", "It's not your number! Please choose your number.");
        ui->xx0->setStyleSheet("color: red;");  // Example: red border indicating an invalid move

        // Optionally, reset button style after 500 ms
        QTimer::singleShot(500, [this]() {
            ui->xx0->setStyleSheet("");  // Reset button style after 500 ms
        });
    }
}
void numericalGame::on_xx1_clicked(){
    numericalChar = '1';
    if (numericalFlag) {
        QMessageBox::warning(this, "Invalid Move", "It's not your number! Please choose your number.");
        ui->xx1->setStyleSheet("color: red;");  // Example: red border indicating an invalid move

        // Optionally, reset button style after 500 ms
        QTimer::singleShot(500, [this]() {
            ui->xx1->setStyleSheet("");  // Reset button style after 500 ms
        });
    }
}
void numericalGame::on_xx2_clicked(){
    numericalChar = '2';
    if (!numericalFlag) {
        QMessageBox::warning(this, "Invalid Move", "It's not your number! Please choose your number.");
        ui->xx2->setStyleSheet("color: red;");  // Example: red border indicating an invalid move

        // Optionally, reset button style after 500 ms
        QTimer::singleShot(500, [this]() {
            ui->xx2->setStyleSheet("");  // Reset button style after 500 ms
        });
    }
}
void numericalGame::on_xx3_clicked(){
    numericalChar = '3';
    if (numericalFlag) {
        QMessageBox::warning(this, "Invalid Move", "It's not your number! Please choose your number.");
        ui->xx3->setStyleSheet("color: red;");  // Example: red border indicating an invalid move

        // Optionally, reset button style after 500 ms
        QTimer::singleShot(500, [this]() {
            ui->xx3->setStyleSheet("");  // Reset button style after 500 ms
        });
    }
}
void numericalGame::on_xx4_clicked(){
    numericalChar = '4';
    if (!numericalFlag) {
        QMessageBox::warning(this, "Invalid Move", "It's not your number! Please choose your number.");
        ui->xx4->setStyleSheet("color: red;");  // Example: red border indicating an invalid move

        // Optionally, reset button style after 500 ms
        QTimer::singleShot(500, [this]() {
            ui->xx4->setStyleSheet("");  // Reset button style after 500 ms
        });
    }
}
void numericalGame::on_xx5_clicked(){
    numericalChar = '5';
    if (numericalFlag) {
        QMessageBox::warning(this, "Invalid Move", "It's not your number! Please choose your number.");
        ui->xx5->setStyleSheet("color: red;");  // Example: red border indicating an invalid move

        // Optionally, reset button style after 500 ms
        QTimer::singleShot(500, [this]() {
            ui->xx5->setStyleSheet("");  // Reset button style after 500 ms
        });
    }
}
void numericalGame::on_xx6_clicked(){
    numericalChar = '6';
    if (!numericalFlag) {
        QMessageBox::warning(this, "Invalid Move", "It's not your number! Please choose your number.");
        ui->xx6->setStyleSheet("color: red;");  // Example: red border indicating an invalid move

        // Optionally, reset button style after 500 ms
        QTimer::singleShot(500, [this]() {
            ui->xx6->setStyleSheet("");  // Reset button style after 500 ms
        });
    }
}
void numericalGame::on_xx7_clicked(){
    numericalChar = '7';
    if (numericalFlag) {
        QMessageBox::warning(this, "Invalid Move", "It's not your number! Please choose your number.");
        ui->xx7->setStyleSheet("color: red;");  // Example: red border indicating an invalid move

        // Optionally, reset button style after 500 ms
        QTimer::singleShot(500, [this]() {
            ui->xx7->setStyleSheet("");  // Reset button style after 500 ms
        });
    }
}
void numericalGame::on_xx8_clicked(){
    numericalChar = '8';
    if (!numericalFlag) {
        QMessageBox::warning(this, "Invalid Move", "It's not your number! Please choose your number.");
        ui->xx8->setStyleSheet("color: red;");  // Example: red border indicating an invalid move

        // Optionally, reset button style after 500 ms
        QTimer::singleShot(500, [this]() {
            ui->xx8->setStyleSheet("");  // Reset button style after 500 ms
        });
    }
}
void numericalGame::on_xx9_clicked(){
    numericalChar = '9';
    if (numericalFlag) {
        QMessageBox::warning(this, "Invalid Move", "It's not your number! Please choose your number.");
        ui->xx9->setStyleSheet("color: red;");  // Example: red border indicating an invalid move

        // Optionally, reset button style after 500 ms
        QTimer::singleShot(500, [this]() {
            ui->xx9->setStyleSheet("");  // Reset button style after 500 ms
        });
    }
}

// Help button
void numericalGame::on_helpButton_clicked() {
    helpNumerical = new Help_Numerical(this);
    helpNumerical->setAttribute(Qt::WA_DeleteOnClose);
    helpNumerical->show();
}

// Exit button
void numericalGame::on_exitButton_clicked() {
    numerical = 0;

    // Reset all buttons
    QList<QPushButton *> buttons = {ui->x11, ui->x12, ui->x13,
                                    ui->x21, ui->x22, ui->x23,
                                    ui->x31, ui->x32, ui->x33};
    for (auto button : buttons) {
        button->setText("");
        button->setEnabled(true);
    }

    emit backToManuWindow();
    this->close();
}

void numericalDelay(int milliseconds) {
    QEventLoop loop;
    QTimer::singleShot(milliseconds, &loop, &QEventLoop::quit);
    loop.exec(); // Start the event loop and wait
}

void numericalGame::regular(){
    ui->xx0->setStyleSheet("color: #000;");
    ui->xx1->setStyleSheet("color: #000;");
    ui->xx2->setStyleSheet("color: #000;");
    ui->xx3->setStyleSheet("color: #000;");
    ui->xx4->setStyleSheet("color: #000;");
    ui->xx5->setStyleSheet("color: #000;");
    ui->xx6->setStyleSheet("color: #000;");
    ui->xx7->setStyleSheet("color: #000;");
    ui->xx8->setStyleSheet("color: #000;");
    ui->xx9->setStyleSheet("color: #000;");
}

// Update button content and style
void numericalGame::updateButton(QPushButton *button, int &turnCounter, char c) {
    if (button->text().isEmpty()) {
        turnCounter++;
        numericalChar = ' ';
        // numericalFlag = true;
        QString selectedNum(1, c); // Convert char to QString

        if (turnCounter % 2 != 1) {
            button->setStyleSheet("color: #000; font-size: 50px; font-weight: bold; background-color: rgb(81, 220, 224);");
        }
        else {
            button->setStyleSheet("color: #000; font-size: 50px; font-weight: bold; background-color: #cbbf7a;");
        }
        button->setText(selectedNum);
        if (ui->xx0->text() == selectedNum) ui->xx0->setEnabled(false);
        else if (ui->xx1->text() == selectedNum) ui->xx1->setEnabled(false);
        else if (ui->xx2->text() == selectedNum) ui->xx2->setEnabled(false);
        else if (ui->xx3->text() == selectedNum) ui->xx3->setEnabled(false);
        else if (ui->xx4->text() == selectedNum) ui->xx4->setEnabled(false);
        else if (ui->xx5->text() == selectedNum) ui->xx5->setEnabled(false);
        else if (ui->xx6->text() == selectedNum) ui->xx6->setEnabled(false);
        else if (ui->xx7->text() == selectedNum) ui->xx7->setEnabled(false);
        else if (ui->xx8->text() == selectedNum) ui->xx8->setEnabled(false);
        else if (ui->xx9->text() == selectedNum) ui->xx9->setEnabled(false);
    }
}

bool numericalGame::isPattern(const QString &a, const QString &b, const QString &c) {
    return (a.toInt() + b.toInt() + c.toInt() == 15 && !a.isEmpty() && !b.isEmpty() && !c.isEmpty());
}

// Handle random move for computer player
void numericalGame::random() {
    QVector<QPushButton *> emptyButtons;

    // Collect all empty buttons
    QList<QPushButton *> buttons = {ui->x11, ui->x12, ui->x13,
                                    ui->x21, ui->x22, ui->x23,
                                    ui->x31, ui->x32, ui->x33};
    for (auto *button : buttons) {
        if (button->text().isEmpty()) {
            emptyButtons.append(button);
        }
    }

    if (emptyButtons.isEmpty()) return;

    // Select random available number
    int rIndex = rand() % secondPlayer.size();
    char selectedNum = secondPlayer[rIndex] + '0';

    // Select random button and update it
    int randomIndex = rand() % emptyButtons.size();
    QPushButton *selectedButton = emptyButtons[randomIndex];

    // Delay for seconds
    numericalDelay(100);

    updateButton(selectedButton, numerical, selectedNum);
    secondPlayer.erase(secondPlayer.begin() +rIndex);

    numericalFlag = !numericalFlag;

    if (ui->xx0->text() == QString(selectedNum)) ui->xx0->setEnabled(false);
    else if (ui->xx1->text() == QString(selectedNum)) ui->xx1->setEnabled(false);
    else if (ui->xx2->text() == QString(selectedNum)) ui->xx2->setEnabled(false);
    else if (ui->xx3->text() == QString(selectedNum)) ui->xx3->setEnabled(false);
    else if (ui->xx4->text() == QString(selectedNum)) ui->xx4->setEnabled(false);
    else if (ui->xx5->text() == QString(selectedNum)) ui->xx5->setEnabled(false);
    else if (ui->xx6->text() == QString(selectedNum)) ui->xx6->setEnabled(false);
    else if (ui->xx7->text() == QString(selectedNum)) ui->xx7->setEnabled(false);
    else if (ui->xx8->text() == QString(selectedNum)) ui->xx8->setEnabled(false);
    else if (ui->xx9->text() == QString(selectedNum)) ui->xx9->setEnabled(false);

    checkGameState();
}

// Check win condition
bool numericalGame::isWin() {
    ui->xx0->setStyleSheet("hover:color:#fff;");
    ui->xx1->setStyleSheet("hover:color:#fff;");
    ui->xx2->setStyleSheet("hover:color:#fff;");
    ui->xx3->setStyleSheet("hover:color:#fff;");
    ui->xx4->setStyleSheet("hover:color:#fff;");
    ui->xx5->setStyleSheet("hover:color:#fff;");
    ui->xx6->setStyleSheet("hover:color:#fff;");
    ui->xx7->setStyleSheet("hover:color:#fff;");
    ui->xx8->setStyleSheet("hover:color:#fff;");
    ui->xx9->setStyleSheet("hover:color:#fff;");

    // Check rows   // Check columns   // Check diagonals
    if (isPattern(ui->x11->text(), ui->x12->text(), ui->x13->text())||
        isPattern(ui->x21->text(), ui->x22->text(), ui->x23->text())||
        isPattern(ui->x31->text(), ui->x32->text(), ui->x33->text())||

        isPattern(ui->x11->text(), ui->x21->text(), ui->x31->text())||
        isPattern(ui->x12->text(), ui->x22->text(), ui->x32->text())||
        isPattern(ui->x13->text(), ui->x23->text(), ui->x33->text())||

        isPattern(ui->x11->text(), ui->x22->text(), ui->x33->text())||
        isPattern(ui->x33->text(), ui->x22->text(), ui->x11->text())||
        isPattern(ui->x13->text(), ui->x22->text(), ui->x31->text())||
        isPattern(ui->x31->text(), ui->x22->text(), ui->x13->text()))
    {

        QList<QPushButton *> buttons = {ui->x11, ui->x12, ui->x13,
                                        ui->x21, ui->x22, ui->x23,
                                        ui->x31, ui->x32, ui->x33};
        for (auto *button : buttons) {
            button->setDisabled(button);
        }

        ui->xx0->setEnabled(false);
        ui->xx1->setEnabled(false);
        ui->xx2->setEnabled(false);
        ui->xx3->setEnabled(false);
        ui->xx4->setEnabled(false);
        ui->xx5->setEnabled(false);
        ui->xx6->setEnabled(false);
        ui->xx7->setEnabled(false);
        ui->xx8->setEnabled(false);
        ui->xx9->setEnabled(false);

        win = new Win(this);
        QString winner = (numerical % 2 == 1) ? ui->Score1->text() + " Wins!" : ui->Score2->text() + " Wins!";
        win->setWinnerText(winner);
        win->setAttribute(Qt::WA_DeleteOnClose);

        win->showFullScreen();
        return true;
    }
    else return false;
}

// Check draw condition
bool numericalGame::isDraw() {
    if (numerical == 9 && !isWin()) {
        QList<QPushButton *> buttons = {ui->x11, ui->x12, ui->x13,
                                        ui->x21, ui->x22, ui->x23,
                                        ui->x31, ui->x32, ui->x33};
        for (auto *button : buttons) {
            button->setDisabled(button);
        }

        ui->xx0->setEnabled(false);
        ui->xx1->setEnabled(false);
        ui->xx2->setEnabled(false);
        ui->xx3->setEnabled(false);
        ui->xx4->setEnabled(false);
        ui->xx5->setEnabled(false);
        ui->xx6->setEnabled(false);
        ui->xx7->setEnabled(false);
        ui->xx8->setEnabled(false);
        ui->xx9->setEnabled(false);

        draw = new Draw(this);
        draw->setWindowTitle("Draw!");
        draw->setAttribute(Qt::WA_DeleteOnClose);

        draw->showFullScreen();
        return true;
    }
    return false;
}

void numericalGame::checkGameState() {
    if (isWin() || isDraw()) {
        return;
    }

    // Handle computer player
    if (!numericalFlag && numerical % 2 == 1 && ui->Score2->text() == "Random Player") {
        random();
        checkGameState();
    }
    // numericalFlag = false;
}

// Optimized Button click handler
void numericalGame::handleButtonClick(QPushButton *button) {
    if (numericalChar != ' ') {
        if ((!numericalFlag && (numericalChar - '0') %2 != 0) || (numericalFlag && (numericalChar - '0') %2 == 0)) {
            updateButton(button, numerical, numericalChar);
            regular();
            checkGameState();

            numericalFlag = !numericalFlag;
        }
    }
}
// Now, each button click handler simply calls the optimized function
void numericalGame::on_x11_clicked() { handleButtonClick(ui->x11); }
void numericalGame::on_x12_clicked() { handleButtonClick(ui->x12); }
void numericalGame::on_x13_clicked() { handleButtonClick(ui->x13); }
void numericalGame::on_x21_clicked() { handleButtonClick(ui->x21); }
void numericalGame::on_x22_clicked() { handleButtonClick(ui->x22); }
void numericalGame::on_x23_clicked() { handleButtonClick(ui->x23); }
void numericalGame::on_x31_clicked() { handleButtonClick(ui->x31); }
void numericalGame::on_x32_clicked() { handleButtonClick(ui->x32); }
void numericalGame::on_x33_clicked() { handleButtonClick(ui->x33); }
