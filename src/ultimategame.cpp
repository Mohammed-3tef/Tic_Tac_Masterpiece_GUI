#include "../include/ultimategame.h"
#include "../include/help_ultimate.h"
#include "../include/win.h"
#include "../include/draw.h"
#include "ui_ultimategame.h"
#include <QMessageBox>
#include <QString>
#include <QPair>
#include <QEventLoop>
#include <QTimer>
#include <QDebug>
#include <random> // For modern randomness

int n2 = 0; // Turn counter
bool flag2 = false;

// Track the state of each small board
QString bigBoard[3][3] = { {"", "", ""},
                          {"", "", ""},
                          {"", "", ""} };

ultimateGame::ultimateGame(QWidget *parent, const QString &firstPlayer, const QString &secondPlayer)
    : QMainWindow(parent)
    , ui(new Ui::ultimateGame)
    , helpultimate(nullptr)
    , win(nullptr)
    , draw(nullptr)
{
    ui->setupUi(this);
    ui->ScoreX->setText(firstPlayer);
    ui->ScoreO->setText(secondPlayer);
}

ultimateGame::~ultimateGame()
{
    delete ui;
    delete helpultimate;
}

void ultimateGame::on_helpButton_clicked()
{
    if (!helpultimate) {
        helpultimate = new Help_Ultimate(this);
    }
    helpultimate->show();
}

void ultimateGame::on_exitButton_clicked()
{
    n2 = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            bigBoard[i][j] = "";
        }
    }

    for (int row = 1; row <= 9; ++row) {
        for (int col = 1; col <= 9; ++col) {
            QString buttonName = QString("x%1%2").arg(row).arg(col);
            QPushButton *button = this->findChild<QPushButton *>(buttonName);
            button->setText("");
        }
    }

    emit backToManuWindow();
    this->close();
}

void delay2(int milliseconds) {
    QEventLoop loop;
    QTimer::singleShot(milliseconds, &loop, &QEventLoop::quit);
    loop.exec(); // Start the event loop and wait
}

// Update button content and style
void ultimateGame::updateButton(QPushButton* button, int &turnCounter) {
    if (button->text().isEmpty()) {
        turnCounter++;
        flag2 = true;
        if (turnCounter % 2 == 0) {
            button->setText("O");
            button->setStyleSheet("color: #000; font-size: 25px; font-weight: bold; background-color: rgb(81, 220, 224);padding: 0;");
        } else {
            button->setText("X");
            button->setStyleSheet("color: #000; font-size: 25px; font-weight: bold; background-color: #cbbf7a;padding: 0;");
        }
        checkGameState();
    }
}

void ultimateGame::on_x11_clicked(){ updateButton(ui->x11, n2);}
void ultimateGame::on_x12_clicked(){ updateButton(ui->x12, n2);}
void ultimateGame::on_x13_clicked(){ updateButton(ui->x13, n2);}
void ultimateGame::on_x14_clicked(){ updateButton(ui->x14, n2);}
void ultimateGame::on_x15_clicked(){ updateButton(ui->x15, n2);}
void ultimateGame::on_x16_clicked(){ updateButton(ui->x16, n2);}
void ultimateGame::on_x17_clicked(){ updateButton(ui->x17, n2);}
void ultimateGame::on_x18_clicked(){ updateButton(ui->x18, n2);}
void ultimateGame::on_x19_clicked(){ updateButton(ui->x19, n2);}
void ultimateGame::on_x21_clicked(){ updateButton(ui->x21, n2);}
void ultimateGame::on_x22_clicked(){ updateButton(ui->x22, n2);}
void ultimateGame::on_x23_clicked(){ updateButton(ui->x23, n2);}
void ultimateGame::on_x24_clicked(){ updateButton(ui->x24, n2);}
void ultimateGame::on_x25_clicked(){ updateButton(ui->x25, n2);}
void ultimateGame::on_x26_clicked(){ updateButton(ui->x26, n2);}
void ultimateGame::on_x27_clicked(){ updateButton(ui->x27, n2);}
void ultimateGame::on_x28_clicked(){ updateButton(ui->x28, n2);}
void ultimateGame::on_x29_clicked(){ updateButton(ui->x29, n2);}
void ultimateGame::on_x31_clicked(){ updateButton(ui->x31, n2);}
void ultimateGame::on_x32_clicked(){ updateButton(ui->x32, n2);}
void ultimateGame::on_x33_clicked(){ updateButton(ui->x33, n2);}
void ultimateGame::on_x34_clicked(){ updateButton(ui->x34, n2);}
void ultimateGame::on_x35_clicked(){ updateButton(ui->x35, n2);}
void ultimateGame::on_x36_clicked(){ updateButton(ui->x36, n2);}
void ultimateGame::on_x37_clicked(){ updateButton(ui->x37, n2);}
void ultimateGame::on_x38_clicked(){ updateButton(ui->x38, n2);}
void ultimateGame::on_x39_clicked(){ updateButton(ui->x39, n2);}
void ultimateGame::on_x41_clicked(){ updateButton(ui->x41, n2);}
void ultimateGame::on_x42_clicked(){ updateButton(ui->x42, n2);}
void ultimateGame::on_x43_clicked(){ updateButton(ui->x43, n2);}
void ultimateGame::on_x44_clicked(){ updateButton(ui->x44, n2);}
void ultimateGame::on_x45_clicked(){ updateButton(ui->x45, n2);}
void ultimateGame::on_x46_clicked(){ updateButton(ui->x46, n2);}
void ultimateGame::on_x47_clicked(){ updateButton(ui->x47, n2);}
void ultimateGame::on_x48_clicked(){ updateButton(ui->x48, n2);}
void ultimateGame::on_x49_clicked(){ updateButton(ui->x49, n2);}
void ultimateGame::on_x51_clicked(){ updateButton(ui->x51, n2);}
void ultimateGame::on_x52_clicked(){ updateButton(ui->x52, n2);}
void ultimateGame::on_x53_clicked(){ updateButton(ui->x53, n2);}
void ultimateGame::on_x54_clicked(){ updateButton(ui->x54, n2);}
void ultimateGame::on_x55_clicked(){ updateButton(ui->x55, n2);}
void ultimateGame::on_x56_clicked(){ updateButton(ui->x56, n2);}
void ultimateGame::on_x57_clicked(){ updateButton(ui->x57, n2);}
void ultimateGame::on_x58_clicked(){ updateButton(ui->x58, n2);}
void ultimateGame::on_x59_clicked(){ updateButton(ui->x59, n2);}
void ultimateGame::on_x61_clicked(){ updateButton(ui->x61, n2);}
void ultimateGame::on_x62_clicked(){ updateButton(ui->x62, n2);}
void ultimateGame::on_x63_clicked(){ updateButton(ui->x63, n2);}
void ultimateGame::on_x64_clicked(){ updateButton(ui->x64, n2);}
void ultimateGame::on_x65_clicked(){ updateButton(ui->x65, n2);}
void ultimateGame::on_x66_clicked(){ updateButton(ui->x66, n2);}
void ultimateGame::on_x67_clicked(){ updateButton(ui->x67, n2);}
void ultimateGame::on_x68_clicked(){ updateButton(ui->x68, n2);}
void ultimateGame::on_x69_clicked(){ updateButton(ui->x69, n2);}
void ultimateGame::on_x71_clicked(){ updateButton(ui->x71, n2);}
void ultimateGame::on_x72_clicked(){ updateButton(ui->x72, n2);}
void ultimateGame::on_x73_clicked(){ updateButton(ui->x73, n2);}
void ultimateGame::on_x74_clicked(){ updateButton(ui->x74, n2);}
void ultimateGame::on_x75_clicked(){ updateButton(ui->x75, n2);}
void ultimateGame::on_x76_clicked(){ updateButton(ui->x76, n2);}
void ultimateGame::on_x77_clicked(){ updateButton(ui->x77, n2);}
void ultimateGame::on_x78_clicked(){ updateButton(ui->x78, n2);}
void ultimateGame::on_x79_clicked(){ updateButton(ui->x79, n2);}
void ultimateGame::on_x81_clicked(){ updateButton(ui->x81, n2);}
void ultimateGame::on_x82_clicked(){ updateButton(ui->x82, n2);}
void ultimateGame::on_x83_clicked(){ updateButton(ui->x83, n2);}
void ultimateGame::on_x84_clicked(){ updateButton(ui->x84, n2);}
void ultimateGame::on_x85_clicked(){ updateButton(ui->x85, n2);}
void ultimateGame::on_x86_clicked(){ updateButton(ui->x86, n2);}
void ultimateGame::on_x87_clicked(){ updateButton(ui->x87, n2);}
void ultimateGame::on_x88_clicked(){ updateButton(ui->x88, n2);}
void ultimateGame::on_x89_clicked(){ updateButton(ui->x89, n2);}
void ultimateGame::on_x91_clicked(){ updateButton(ui->x91, n2);}
void ultimateGame::on_x92_clicked(){ updateButton(ui->x92, n2);}
void ultimateGame::on_x93_clicked(){ updateButton(ui->x93, n2);}
void ultimateGame::on_x94_clicked(){ updateButton(ui->x94, n2);}
void ultimateGame::on_x95_clicked(){ updateButton(ui->x95, n2);}
void ultimateGame::on_x96_clicked(){ updateButton(ui->x96, n2);}
void ultimateGame::on_x97_clicked(){ updateButton(ui->x97, n2);}
void ultimateGame::on_x98_clicked(){ updateButton(ui->x98, n2);}
void ultimateGame::on_x99_clicked(){ updateButton(ui->x99, n2);}

bool ultimateGame::isPattern(const QString& a, const QString& b, const QString& c) {
    return ((a == "X" && b == "X" && c == "X") || (a == "O" && b == "O" && c == "O"));
}

// Function to check for a draw on the big board
bool ultimateGame::isDrawBig() {
    int emptyCells = 0, emptyButtons = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (bigBoard[i][j].isEmpty()) emptyCells++;
        }
    }

    for (int row = 1; row <= 9; row++) {
        for (int col = 1; col <= 9; col++) {
            QString buttonName = QString("x%1%2").arg(row).arg(col);
            QPushButton* button = this->findChild<QPushButton*>(buttonName);
            if (button->isEnabled()) {
                emptyButtons++;
            }
        }
    }

    if ((emptyCells == 0 && !isWinBig()) || emptyButtons == 0) {
        return true;
    }
    return false;
}

bool ultimateGame::isWin(int startRow, int startCol, int endRow, int endCol) {
    // Check all horizontal, vertical, and diagonal patterns
    for (int row = startRow; row <= endRow; ++row) {
        for (int col = startCol; col <= endCol; ++col) {
            QString buttonName = QString("x%1%2").arg(row).arg(col);
            QPushButton* button = this->findChild<QPushButton*>(buttonName);

            // Skip empty or invalid buttons
            if (!button || button->text().isEmpty()) {
                continue;
            }

            QString currentText = button->text();

            // Horizontal check
            if (col + 2 <= endCol) {
                QPushButton* nextButton = this->findChild<QPushButton*>(QString("x%1%2").arg(row).arg(col + 1));
                QPushButton* nextNextButton = this->findChild<QPushButton*>(QString("x%1%2").arg(row).arg(col + 2));
                if (isPattern(currentText, nextButton->text(), nextNextButton->text())) {
                    return true;
                }
            }

            // Vertical check
            if (row + 2 <= endRow) {
                QPushButton* nextButton = this->findChild<QPushButton*>(QString("x%1%2").arg(row + 1).arg(col));
                QPushButton* nextNextButton = this->findChild<QPushButton*>(QString("x%1%2").arg(row + 2).arg(col));
                if (isPattern(currentText, nextButton->text(), nextNextButton->text())) {
                    return true;
                }
            }

            // Diagonal (down-right) check
            if (row + 2 <= endRow && col + 2 <= endCol) {
                QPushButton* nextButton = this->findChild<QPushButton*>(QString("x%1%2").arg(row + 1).arg(col + 1));
                QPushButton* nextNextButton = this->findChild<QPushButton*>(QString("x%1%2").arg(row + 2).arg(col + 2));
                if (isPattern(currentText, nextButton->text(), nextNextButton->text())) {
                    return true;
                }
            }

            // Diagonal (down-left) check
            if (row + 2 <= endRow && col - 2 >= startCol) {
                QPushButton* nextButton = this->findChild<QPushButton*>(QString("x%1%2").arg(row + 1).arg(col - 1));
                QPushButton* nextNextButton = this->findChild<QPushButton*>(QString("x%1%2").arg(row + 2).arg(col - 2));
                if (isPattern(currentText, nextButton->text(), nextNextButton->text())) {
                    return true;
                }
            }
        }
    }

    return false; // No win found
}

QPair<bool, char> ultimateGame::checkBigBoardWinner() {
    // Check rows, columns, and diagonals on the big board for a winner
    for (int i = 0; i < 3; ++i) {
        // Check rows
        if (bigBoard[i][0] == bigBoard[i][1] && bigBoard[i][1] == bigBoard[i][2] && !bigBoard[i][0].isEmpty()) {
            return {true, bigBoard[i][0].toStdString()[0]}; // Return the winner's character (X or O)
        }
        // Check columns
        if (bigBoard[0][i] == bigBoard[1][i] && bigBoard[1][i] == bigBoard[2][i] && !bigBoard[0][i].isEmpty()) {
            return {true, bigBoard[0][i].toStdString()[0]}; // Return the winner's character (X or O)
        }
    }

    // Check diagonals
    if (bigBoard[0][0] == bigBoard[1][1] && bigBoard[1][1] == bigBoard[2][2] && !bigBoard[0][0].isEmpty()) {
        return {true, bigBoard[0][0].toStdString()[0]}; // Return the winner's character (X or O)
    }
    if (bigBoard[0][2] == bigBoard[1][1] && bigBoard[1][1] == bigBoard[2][0] && !bigBoard[0][2].isEmpty()) {
        return {true, bigBoard[0][2].toStdString()[0]}; // Return the winner's character (X or O)
    }

    return {false, '\0'}; // No winner
}


// Function to check if the current player has won
bool ultimateGame::isWinBig() {
    struct Section {
        int startRow, startCol, endRow, endCol;
        int bigRow, bigCol;  // The big board location
    };

    Section sections[] = {
                          {1, 1, 3, 3, 0, 0}, {1, 4, 3, 6, 0, 1}, {1, 7, 3, 9, 0, 2},
                          {4, 1, 6, 3, 1, 0}, {4, 4, 6, 6, 1, 1}, {4, 7, 6, 9, 1, 2},
                          {7, 1, 9, 3, 2, 0}, {7, 4, 9, 6, 2, 1}, {7, 7, 9, 9, 2, 2}};

    // Count empty cells in this section
    for (int i = 0; i < 9; ++i) {
        Section s = sections[i];
        int emptyCells = 0;
        for (int row = s.startRow; row <= s.endRow; row++) {
            for (int col = s.startCol; col <= s.endCol; col++) {
                QString buttonName = QString("x%1%2").arg(row).arg(col);
                QPushButton* button = this->findChild<QPushButton*>(buttonName);
                if (button->text().isEmpty()) emptyCells++;
            }
        }

        // // If no empty cells are found, disable the buttons in the section and mark it as completed
        if (emptyCells == 0) {
            for (int row = s.startRow; row <= s.endRow; row++) {
                for (int col = s.startCol; col <= s.endCol; col++) {
                    QString buttonName = QString("x%1%2").arg(row).arg(col);
                    QPushButton* button = this->findChild<QPushButton*>(buttonName);
                    if (button) {
                        button->setEnabled(false);
                    }
                }
            }
        }

        // Check if the section is a winning one and if the corresponding big board position is empty
        else if (isWin(s.startRow, s.startCol, s.endRow, s.endCol) && bigBoard[s.bigRow][s.bigCol].isEmpty()) {
            QString winner = (n2 % 2 == 0) ? "O" : "X";  // Determine who won (based on the turn count)
            bigBoard[s.bigRow][s.bigCol] = winner;

            // Disable the buttons in the winning section and mark them
            for (int row = s.startRow; row <= s.endRow; row++) {
                for (int col = s.startCol; col <= s.endCol; col++) {
                    QString buttonName = QString("x%1%2").arg(row).arg(col);
                    QPushButton* button = this->findChild<QPushButton*>(buttonName);
                    if (button) {
                        button->setEnabled(false);
                        if(winner == "X") button->setStyleSheet("background-color: #cbbf7a; color: #fff; font-size: 20px; font-weight: bold; padding : 0;");
                        else button->setStyleSheet("background-color: rgb(81, 220, 224); color: #fff; font-size: 20px; font-weight: bold; padding : 0;");
                    }
                }
            }

            // Check if the big board has a winner
            if (checkBigBoardWinner().first) {
                return true;
            }
        }
    }
    return false;  // No winner yet
}

// Check if game is over
void ultimateGame::checkGameState() {
    if (isWinBig()) {
        win = new Win(this);
        QString winner = checkBigBoardWinner().second == 'X' ? ui->ScoreX->text() + " Wins!" : ui->ScoreO->text() + " Wins!";
        win->setWinnerText(winner);
        win->setAttribute(Qt::WA_DeleteOnClose);

        win->showFullScreen();
        for (int row = 1; row <= 9; ++row) {
            for (int col = 1; col <= 9; ++col) {
                QString buttonName = QString("x%1%2").arg(row).arg(col);
                QPushButton* button = this->findChild<QPushButton*>(buttonName);
                if (button) {
                    button->setEnabled(false);
                }
            }
        }
        return;
    }

    if (isDrawBig()) {
        draw = new Draw(this);
        draw->setWindowTitle("Draw!");
        draw->setAttribute(Qt::WA_DeleteOnClose);

        draw->showFullScreen();
        return;
    }

    // Handle computer player
    if (flag2 && n2 % 2 == 1 && ui->ScoreO->text() == "Random Player") {
        random();
        checkGameState();
    }
    flag2 = false;
}

void ultimateGame::random() {
    QVector<QPushButton *> emptyButtons;

    // Collect all empty buttons dynamically
    for (int row = 1; row <= 9; ++row) {
        for (int col = 1; col <= 9; ++col) {
            QString buttonName = QString("x%1%2").arg(row).arg(col);
            QPushButton *button = this->findChild<QPushButton *>(buttonName);

            if (button && button->text().isEmpty() && button->isEnabled()) {
                emptyButtons.append(button);
            }
        }
    }

    // Exit if no empty buttons are found
    if (emptyButtons.isEmpty()) {
        return;
    }

    // Use modern random number generation
    std::random_device rd;  // Seed source
    std::mt19937 gen(rd()); // Mersenne Twister RNG
    std::uniform_int_distribution<> dist(0, emptyButtons.size() - 1);

    // Select a random button
    int randomIndex = dist(gen);
    QPushButton *selectedButton = emptyButtons[randomIndex];

    // Delay for seconds
    delay2(100);

    // Update the button
    updateButton(selectedButton, n2);

    // Check the game state
    checkGameState();
}
