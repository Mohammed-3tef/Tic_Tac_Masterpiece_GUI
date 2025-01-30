#include "../include/fourgame.h"
#include "ui_fourgame.h"
#include "../include/help_four.h"
#include "../include/win.h"
#include "../include/draw.h"
#include <QDebug>
#include <cstdlib>
#include <ctime>
#include <QEventLoop>
#include <QTimer>
#include <QVector>
#include <QMessageBox>

int fourInARow = 0;
bool fourFlag = false;
QVector<int> secondPlayerCol = {1, 2, 3, 4, 5, 6, 7};

fourGame::fourGame(QWidget *parent, const QString &firstPlayerName, const QString &secondPlayerName)
    : QMainWindow(parent),
    ui(new Ui::fourGame),
    helpFour(nullptr),
    lastClickedButton(nullptr),
    win(nullptr),
    draw(nullptr)
{
    ui->setupUi(this);

    // Initialize random seed
    srand(static_cast<unsigned int>(time(nullptr)));

    // Set initial UI states
    ui->ScoreX->setText(firstPlayerName);
    ui->ScoreO->setText(secondPlayerName);
    secondPlayerCol = {1, 2, 3, 4, 5, 6, 7};

    // Reset all buttons
    QList<QPushButton *> buttons = {ui->x11, ui->x12, ui->x13, ui->x14, ui->x15, ui->x16,ui->x17,
                                    ui->x21, ui->x22, ui->x23, ui->x24, ui->x25, ui->x26,ui->x27,
                                    ui->x31, ui->x32, ui->x33, ui->x34, ui->x35, ui->x36,ui->x37,
                                    ui->x41, ui->x42, ui->x43, ui->x44, ui->x45, ui->x46,ui->x47,
                                    ui->x51, ui->x52, ui->x53, ui->x54, ui->x55, ui->x56,ui->x57,
                                    ui->x61, ui->x62, ui->x63, ui->x64, ui->x65, ui->x66,ui->x67};

    for (auto button : buttons) {
        button->setEnabled(false);
    }
}

fourGame::~fourGame(){
    delete helpFour;
    delete win;
    delete draw;
    delete ui;
}

// Help button
void fourGame::on_helpButton_clicked() {
    helpFour = new Help_Four(this);
    helpFour->setAttribute(Qt::WA_DeleteOnClose);
    helpFour->show();
}

// Exit button
void fourGame::on_exitButton_clicked() {
    fourInARow = 0;

    // Reset all buttons
    QList<QPushButton *> buttons = {ui->x11, ui->x12, ui->x13, ui->x14, ui->x15, ui->x16,ui->x17,
                                    ui->x21, ui->x22, ui->x23, ui->x24, ui->x25, ui->x26,ui->x27,
                                    ui->x31, ui->x32, ui->x33, ui->x34, ui->x35, ui->x36,ui->x37,
                                    ui->x41, ui->x42, ui->x43, ui->x44, ui->x45, ui->x46,ui->x47,
                                    ui->x51, ui->x52, ui->x53, ui->x54, ui->x55, ui->x56,ui->x57,
                                    ui->x61, ui->x62, ui->x63, ui->x64, ui->x65, ui->x66,ui->x67};

    for (auto button : buttons) {
        button->setText("");
    }

    emit backToManuWindow();
    this->close();
}

void fourDelay(int milliseconds) {
    QEventLoop loop;
    QTimer::singleShot(milliseconds, &loop, &QEventLoop::quit);
    loop.exec();    // Start the event loop and wait
}

void fourGame::regular() {
    ui->click1->setStyleSheet("color: #000;");
    ui->click2->setStyleSheet("color: #000;");
    ui->click3->setStyleSheet("color: #000;");
    ui->click4->setStyleSheet("color: #000;");
    ui->click5->setStyleSheet("color: #000;");
    ui->click6->setStyleSheet("color: #000;");
    ui->click7->setStyleSheet("color: #000;");
}

// Update button content and style
void fourGame::updateButton(QPushButton *button, int &turnCounter) {
    if (button->text().isEmpty()) {
        turnCounter++;

        if (turnCounter % 2 != 1) {
            button->setText("O");
            button->setStyleSheet("color: #000; font-size: 25px; font-weight: bold; background-color: rgb(81, 220, 224);");
        }
        else {
            button->setText("X");
            button->setStyleSheet("color: #000; font-size: 25px; font-weight: bold; background-color: #cbbf7a;");
        }

        if (button == ui->x11) {ui->click1->setEnabled(false);}
        else if (button == ui->x12) {ui->click2->setEnabled(false);}
        else if (button == ui->x13) {ui->click3->setEnabled(false);}
        else if (button == ui->x14) {ui->click4->setEnabled(false);}
        else if (button == ui->x15) {ui->click5->setEnabled(false);}
        else if (button == ui->x16) {ui->click6->setEnabled(false);}
        else if (button == ui->x17) {ui->click7->setEnabled(false);}
    }
}

bool fourGame::isPattern(const QString &a, const QString &b, const QString &c, const QString &d) {
    return (a == b && b == c && c == d && !a.isEmpty());
}

bool fourGame::isWin() {
    const int rows = 6;  // Number of rows
    const int columns = 7;  // Number of columns

    ui->click1->setStyleSheet("hover:color:#fff;");
    ui->click2->setStyleSheet("hover:color:#fff;");
    ui->click3->setStyleSheet("hover:color:#fff;");
    ui->click4->setStyleSheet("hover:color:#fff;");
    ui->click5->setStyleSheet("hover:color:#fff;");
    ui->click6->setStyleSheet("hover:color:#fff;");
    ui->click7->setStyleSheet("hover:color:#fff;");

    // Check all possible winning conditions
    for (int i = 1; i <= rows; ++i) {
        for (int j = 1; j <= columns; ++j) {
            // Horizontal win (left to right)
            if (j + 3 <= columns) {
                QPushButton* button1 = this->findChild<QPushButton*>(QString("x%1%2").arg(i).arg(j));
                QPushButton* button2 = this->findChild<QPushButton*>(QString("x%1%2").arg(i).arg(j + 1));
                QPushButton* button3 = this->findChild<QPushButton*>(QString("x%1%2").arg(i).arg(j + 2));
                QPushButton* button4 = this->findChild<QPushButton*>(QString("x%1%2").arg(i).arg(j + 3));

                if (button1 && button2 && button3 && button4 &&
                    isPattern(button1->text(), button2->text(), button3->text(), button4->text())) {
                    return declareWin();
                }
            }

            // Vertical win (top to bottom)
            if (i + 3 <= rows) {
                QPushButton* button1 = this->findChild<QPushButton*>(QString("x%1%2").arg(i).arg(j));
                QPushButton* button2 = this->findChild<QPushButton*>(QString("x%1%2").arg(i + 1).arg(j));
                QPushButton* button3 = this->findChild<QPushButton*>(QString("x%1%2").arg(i + 2).arg(j));
                QPushButton* button4 = this->findChild<QPushButton*>(QString("x%1%2").arg(i + 3).arg(j));

                if (button1 && button2 && button3 && button4 &&
                    isPattern(button1->text(), button2->text(), button3->text(), button4->text())) {
                    return declareWin();
                }
            }

            // Diagonal win (bottom-left to top-right)
            if (i + 3 <= rows && j + 3 <= columns) {
                QPushButton* button1 = this->findChild<QPushButton*>(QString("x%1%2").arg(i).arg(j));
                QPushButton* button2 = this->findChild<QPushButton*>(QString("x%1%2").arg(i + 1).arg(j + 1));
                QPushButton* button3 = this->findChild<QPushButton*>(QString("x%1%2").arg(i + 2).arg(j + 2));
                QPushButton* button4 = this->findChild<QPushButton*>(QString("x%1%2").arg(i + 3).arg(j + 3));

                if (button1 && button2 && button3 && button4 &&
                    isPattern(button1->text(), button2->text(), button3->text(), button4->text())) {
                    return declareWin();
                }
            }

            // Diagonal win (top-left to bottom-right)
            if (i + 3 <= rows && j - 3 >= 1) {
                QPushButton* button1 = this->findChild<QPushButton*>(QString("x%1%2").arg(i).arg(j));
                QPushButton* button2 = this->findChild<QPushButton*>(QString("x%1%2").arg(i + 1).arg(j - 1));
                QPushButton* button3 = this->findChild<QPushButton*>(QString("x%1%2").arg(i + 2).arg(j - 2));
                QPushButton* button4 = this->findChild<QPushButton*>(QString("x%1%2").arg(i + 3).arg(j - 3));

                if (button1 && button2 && button3 && button4 &&
                    isPattern(button1->text(), button2->text(), button3->text(), button4->text())) {
                    return declareWin();
                }
            }
        }
    }

    return false;  // No win detected
}

// Declare the win and update the UI
bool fourGame::declareWin() {
    // Disable all buttons
    ui->click1->setEnabled(false);
    ui->click2->setEnabled(false);
    ui->click3->setEnabled(false);
    ui->click4->setEnabled(false);
    ui->click5->setEnabled(false);
    ui->click6->setEnabled(false);
    ui->click7->setEnabled(false);

    // Show win dialog
    win = new Win(this);
    QString winner = (fourInARow % 2 != 0) ? ui->ScoreX->text() + " Wins!" : ui->ScoreO->text() + " Wins!";
    win->setWinnerText(winner);
    win->setAttribute(Qt::WA_DeleteOnClose);

    win->showFullScreen();
    return true;
}


// Check draw condition
bool fourGame::isDraw() {
    if (fourInARow == 42 && !isWin()) {
        // Disable all buttons
        ui->click1->setEnabled(false);
        ui->click2->setEnabled(false);
        ui->click3->setEnabled(false);
        ui->click4->setEnabled(false);
        ui->click5->setEnabled(false);
        ui->click6->setEnabled(false);
        ui->click7->setEnabled(false);

        draw = new Draw(this);
        draw->setWindowTitle("Draw!");
        draw->setAttribute(Qt::WA_DeleteOnClose);

        draw->showFullScreen();
        return true;
    }
    return false;
}

void fourGame::checkGameState() {
    if (isWin() || isDraw()) {
        return;
    }

    // Handle computer player
    if (!fourFlag && fourInARow % 2 == 1 && ui->ScoreO->text() == "Random Player") {
        random();
        checkGameState();
    }
}

void fourGame::random() {
    if (secondPlayerCol.empty()) return;  // No available columns

    int rIndex = rand() % secondPlayerCol.size();
    int column = secondPlayerCol[rIndex];

    // Find the first empty spot in the selected column
    bool columnFull = true;
    for (int i = 6; i >= 1; --i) {
        QString buttonName = QString("x%1%2").arg(i).arg(column);
        QPushButton* button = this->findChild<QPushButton*>(buttonName);
        if (button && button->text().isEmpty()) {
            // Delay for seconds
            fourDelay(100);

            updateButton(button, fourInARow);
            columnFull = false;
            break;
        }
    }

    fourFlag = !fourFlag;

    // Remove the column if it's full
    if (columnFull) {
        secondPlayerCol.remove(rIndex);
        QString buttonName = QString("click%1").arg(column);
        QPushButton* button = this->findChild<QPushButton*>(buttonName);
        if (button) button->setEnabled(false);
    }

    checkGameState();
}

void fourGame::handleColumnClick(int column) {
    for (int i = 6; i >= 1; --i) {
        QString buttonName = QString("x%1%2").arg(i).arg(column);
        QPushButton* button = this->findChild<QPushButton*>(buttonName);
        if (button && button->text().isEmpty()) {  // Check if the button is empty
            updateButton(button, fourInARow);
            regular();
            checkGameState();

            fourFlag = !fourFlag;
            break;
        }
    }
}
// Example usage for each button click
void fourGame::on_click1_clicked() {handleColumnClick(1);}
void fourGame::on_click2_clicked() {handleColumnClick(2);}
void fourGame::on_click3_clicked() {handleColumnClick(3);}
void fourGame::on_click4_clicked() {handleColumnClick(4);}
void fourGame::on_click5_clicked() {handleColumnClick(5);}
void fourGame::on_click6_clicked() {handleColumnClick(6);}
void fourGame::on_click7_clicked() {handleColumnClick(7);}
