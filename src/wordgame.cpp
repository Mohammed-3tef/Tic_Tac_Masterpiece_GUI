#include "../include/wordgame.h"
#include "../include/help_word.h"
#include "../include/win.h"
#include "../include/draw.h"
#include "ui_wordgame.h"
#include <QDebug>
#include <cstdlib>
#include <ctime>
#include <QEventLoop>
#include <QTimer>

int n4 = 0;
bool flag4 = false;
char ch = ' ';

// Constructor
wordGame::wordGame(QWidget *parent, const QString &firstPlayer, const QString &secondPlayer)
    : QMainWindow(parent),
    ui(new Ui::wordGame),
    helpword(nullptr),
    lastClickedButton(nullptr),
    win(nullptr),
    draw(nullptr) {
    ui->setupUi(this);

    // Initialize random seed
    srand(static_cast<unsigned int>(time(nullptr)));

    // Set initial UI states
    ui->Score1->setText(firstPlayer);
    ui->Score2->setText(secondPlayer);
}

// Destructor
wordGame::~wordGame() {
    delete helpword; helpword = nullptr;
    delete win; win = nullptr;
    delete draw; draw = nullptr;
    delete ui;
}

// Help button
void wordGame::on_helpButton_clicked() {
    helpword = new help_word(this);
    helpword->setAttribute(Qt::WA_DeleteOnClose);
    helpword->show();
}

// Exit button
void wordGame::on_exitButton_clicked() {
    n4 = 0;

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

    emit backToManuWindow();
    this->close();
}

void delay4(int milliseconds) {
    QEventLoop loop;
    QTimer::singleShot(milliseconds, &loop, &QEventLoop::quit);
    loop.exec(); // Start the event loop and wait
}

void wordGame::regular(){
    ui->xx1->setStyleSheet("color: #000;");
    ui->xx2->setStyleSheet("color: #000;");
    ui->xx3->setStyleSheet("color: #000;");
    ui->xx4->setStyleSheet("color: #000;");
    ui->xx5->setStyleSheet("color: #000;");
    ui->xx6->setStyleSheet("color: #000;");
    ui->xx7->setStyleSheet("color: #000;");
    ui->xx8->setStyleSheet("color: #000;");
    ui->xx9->setStyleSheet("color: #000;");
    ui->xx10->setStyleSheet("color: #000;");
    ui->xx11->setStyleSheet("color: #000;");
    ui->xx12->setStyleSheet("color: #000;");
    ui->xx13->setStyleSheet("color: #000;");
    ui->xx14->setStyleSheet("color: #000;");
    ui->xx15->setStyleSheet("color: #000;");
    ui->xx16->setStyleSheet("color: #000;");
    ui->xx17->setStyleSheet("color: #000;");
    ui->xx18->setStyleSheet("color: #000;");
    ui->xx19->setStyleSheet("color: #000;");
    ui->xx20->setStyleSheet("color: #000;");
    ui->xx21->setStyleSheet("color: #000;");
    ui->xx22->setStyleSheet("color: #000;");
    ui->xx23->setStyleSheet("color: #000;");
    ui->xx24->setStyleSheet("color: #000;");
    ui->xx25->setStyleSheet("color: #000;");
    ui->xx26->setStyleSheet("color: #000;");
}

// Update button content and style
void wordGame::updateButton(QPushButton *button, int &turnCounter, char c) {
    if (button->text().isEmpty()) {
        turnCounter++;
        ch = ' ';
        flag4 = true;
        QString cc = "";
        cc += c;
        if (turnCounter % 2 != 1) {
            button->setText(cc);
            button->setStyleSheet("color: #000; font-size: 50px; font-weight: bold; background-color: rgb(81, 220, 224);");
        } else {
            button->setText(cc);
            button->setStyleSheet("color: #000; font-size: 50px; font-weight: bold; background-color: #cbbf7a;");
        }
    }
}

// Button click handlers
void wordGame::on_x11_clicked() {
    if (ch != ' '){
        updateButton(ui->x11, n4, ch);
        regular();
        checkGameState();
    }
}
void wordGame::on_x12_clicked() {
    if (ch != ' ') {
        updateButton(ui->x12, n4, ch);
        regular();
        checkGameState();
    }
}
void wordGame::on_x13_clicked() {
    if (ch != ' '){
        updateButton(ui->x13, n4, ch);
        regular();
        checkGameState();
    }
}
void wordGame::on_x21_clicked() {
    if (ch != ' ') {
        updateButton(ui->x21, n4, ch);
        regular();
        checkGameState();
    }
}
void wordGame::on_x22_clicked() {
    if (ch != ' ') {
        updateButton(ui->x22, n4, ch);
        regular();
        checkGameState();
    }
}
void wordGame::on_x23_clicked() {
    if (ch != ' ') {
        updateButton(ui->x23, n4, ch);
        regular();
        checkGameState();
    }
}
void wordGame::on_x31_clicked() {
    if (ch != ' '){
        updateButton(ui->x31, n4, ch);
        regular();
        checkGameState();
    }
}
void wordGame::on_x32_clicked() {
    if (ch != ' ') {
        updateButton(ui->x32, n4, ch);
        regular();
        checkGameState();
    }
}
void wordGame::on_x33_clicked() {
    if (ch != ' ') {
        updateButton(ui->x33, n4, ch);
        regular();
        checkGameState();
    }
}

// Check for "SUS" pattern
bool wordGame::isPattern(const QString &a, const QString &b, const QString &c) {
    return ((a == "A" && b == "N" && c == "T") || (a == "N" && b == "O" && c == "P") ||
            (a == "B" && b == "O" && c == "Y") || (a == "O" && b == "T" && c == "L") ||
            (a == "C" && b == "A" && c == "T") || (a == "P" && b == "Q" && c == "D") ||
            (a == "D" && b == "U" && c == "S") || (a == "Q" && b == "X" && c == "Z") ||
            (a == "E" && b == "G" && c == "G") || (a == "R" && b == "S" && c == "B") ||
            (a == "F" && b == "I" && c == "N") || (a == "S" && b == "A" && c == "I") ||
            (a == "G" && b == "A" && c == "M") || (a == "T" && b == "D" && c == "J") ||
            (a == "H" && b == "U" && c == "S") || (a == "U" && b == "Y" && c == "S") ||
            (a == "I" && b == "N" && c == "G") || (a == "V" && b == "T" && c == "M") ||
            (a == "J" && b == "A" && c == "R") || (a == "W" && b == "I" && c == "Q") ||
            (a == "K" && b == "V" && c == "E") || (a == "X" && b == "C" && c == "F") ||
            (a == "L" && b == "A" && c == "M") ||(a == "Y" && b == "J" && c == "K") ||
            (a == "M" && b == "W" && c == "P") ||(a == "Z" && b == "E" && c == "C") );
}


// Check win condition
bool wordGame::isWin() {
    ui->xx1->setStyleSheet("color:#000;""QRadioButton:hover:#fff;");
    ui->xx2->setStyleSheet("color:#000;""QRadioButton:hover:#fff;");
    ui->xx3->setStyleSheet("color:#000;""QRadioButton:hover:#fff;");
    ui->xx4->setStyleSheet("color:#000;""QRadioButton:hover:#fff;");
    ui->xx5->setStyleSheet("color:#000;""QRadioButton:hover:#fff;");
    ui->xx6->setStyleSheet("color:#000;""QRadioButton:hover:#fff;");
    ui->xx7->setStyleSheet("color:#000;""QRadioButton:hover:#fff;");
    ui->xx8->setStyleSheet("color:#000;""QRadioButton:hover:#fff;");
    ui->xx9->setStyleSheet("color:#000;""QRadioButton:hover:#fff;");
    ui->xx10->setStyleSheet("color:#000;""QRadioButton:hover:#fff;");
    ui->xx11->setStyleSheet("color:#000;""QRadioButton:hover:#fff;");
    ui->xx12->setStyleSheet("color:#000;""QRadioButton:hover:#fff;");
    ui->xx13->setStyleSheet("color:#000;""QRadioButton:hover:#fff;");
    ui->xx14->setStyleSheet("color:#000;""QRadioButton:hover:#fff;");
    ui->xx15->setStyleSheet("color:#000;""QRadioButton:hover:#fff;");
    ui->xx16->setStyleSheet("color:#000;""QRadioButton:hover:#fff;");
    ui->xx17->setStyleSheet("color:#000;""QRadioButton:hover:#fff;");
    ui->xx18->setStyleSheet("color:#000;""QRadioButton:hover:#fff;");
    ui->xx19->setStyleSheet("color:#000;""QRadioButton:hover:#fff;");
    ui->xx20->setStyleSheet("color:#000;""QRadioButton:hover:#fff;");
    ui->xx21->setStyleSheet("color:#000;""QRadioButton:hover:#fff;");
    ui->xx22->setStyleSheet("color:#000;""QRadioButton:hover:#fff;");
    ui->xx23->setStyleSheet("color:#000;""QRadioButton:hover:#fff;");
    ui->xx24->setStyleSheet("color:#000;""QRadioButton:hover:#fff;");
    ui->xx25->setStyleSheet("color:#000;""QRadioButton:hover:#fff;");
    ui->xx26->setStyleSheet("color:#000;""QRadioButton:hover:#fff;");

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
        ui->xx1->setStyleSheet("color: gray;");
        ui->xx2->setStyleSheet("color: gray;");
        ui->xx3->setStyleSheet("color: gray;");
        ui->xx4->setStyleSheet("color: gray;");
        ui->xx5->setStyleSheet("color: gray;");
        ui->xx6->setStyleSheet("color: gray;");
        ui->xx7->setStyleSheet("color: gray;");
        ui->xx8->setStyleSheet("color: gray;");
        ui->xx9->setStyleSheet("color: gray;");
        ui->xx10->setStyleSheet("color: gray;");
        ui->xx11->setStyleSheet("color: gray;");
        ui->xx12->setStyleSheet("color: gray;");
        ui->xx13->setStyleSheet("color: gray;");
        ui->xx14->setStyleSheet("color: gray;");
        ui->xx15->setStyleSheet("color: gray;");
        ui->xx16->setStyleSheet("color: gray;");
        ui->xx17->setStyleSheet("color: gray;");
        ui->xx18->setStyleSheet("color: gray;");
        ui->xx19->setStyleSheet("color: gray;");
        ui->xx20->setStyleSheet("color: gray;");
        ui->xx21->setStyleSheet("color: gray;");
        ui->xx22->setStyleSheet("color: gray;");
        ui->xx23->setStyleSheet("color: gray;");
        ui->xx24->setStyleSheet("color: gray;");
        ui->xx25->setStyleSheet("color: gray;");
        ui->xx26->setStyleSheet("color: gray;");

        ui->x11->setDisabled(ui->x11);
        ui->x12->setDisabled(ui->x11);
        ui->x13->setDisabled(ui->x11);
        ui->x21->setDisabled(ui->x11);
        ui->x22->setDisabled(ui->x11);
        ui->x23->setDisabled(ui->x11);
        ui->x31->setDisabled(ui->x11);
        ui->x32->setDisabled(ui->x11);
        ui->x33->setDisabled(ui->x11);

        ui->xx1->setEnabled(false);
        ui->xx2->setEnabled(false);
        ui->xx3->setEnabled(false);
        ui->xx4->setEnabled(false);
        ui->xx5->setEnabled(false);
        ui->xx6->setEnabled(false);
        ui->xx7->setEnabled(false);
        ui->xx8->setEnabled(false);
        ui->xx9->setEnabled(false);
        ui->xx10->setEnabled(false);
        ui->xx11->setEnabled(false);
        ui->xx12->setEnabled(false);
        ui->xx13->setEnabled(false);
        ui->xx14->setEnabled(false);
        ui->xx15->setEnabled(false);
        ui->xx16->setEnabled(false);
        ui->xx17->setEnabled(false);
        ui->xx18->setEnabled(false);
        ui->xx19->setEnabled(false);
        ui->xx20->setEnabled(false);
        ui->xx21->setEnabled(false);
        ui->xx22->setEnabled(false);
        ui->xx23->setEnabled(false);
        ui->xx24->setEnabled(false);
        ui->xx25->setEnabled(false);
        ui->xx26->setEnabled(false);

        win = new Win(this);
        QString winner = (n4 % 2 == 1) ? ui->Score1->text() + " Wins!" : ui->Score2->text() + " Wins!";
        win->setWinnerText(winner);
        win->setAttribute(Qt::WA_DeleteOnClose);

        win->showFullScreen();
        return true;
    }
    else
        return false;
}

// Check draw condition
bool wordGame::isDraw() {
    if (n4 == 9 && !isWin()) {
        ui->xx1->setStyleSheet("color: gray;");
        ui->xx2->setStyleSheet("color: gray;");
        ui->xx3->setStyleSheet("color: gray;");
        ui->xx4->setStyleSheet("color: gray;");
        ui->xx5->setStyleSheet("color: gray;");
        ui->xx6->setStyleSheet("color: gray;");
        ui->xx7->setStyleSheet("color: gray;");
        ui->xx8->setStyleSheet("color: gray;");
        ui->xx9->setStyleSheet("color: gray;");
        ui->xx10->setStyleSheet("color: gray;");
        ui->xx11->setStyleSheet("color: gray;");
        ui->xx12->setStyleSheet("color: gray;");
        ui->xx13->setStyleSheet("color: gray;");
        ui->xx14->setStyleSheet("color: gray;");
        ui->xx15->setStyleSheet("color: gray;");
        ui->xx16->setStyleSheet("color: gray;");
        ui->xx17->setStyleSheet("color: gray;");
        ui->xx18->setStyleSheet("color: gray;");
        ui->xx19->setStyleSheet("color: gray;");
        ui->xx20->setStyleSheet("color: gray;");
        ui->xx21->setStyleSheet("color: gray;");
        ui->xx22->setStyleSheet("color: gray;");
        ui->xx23->setStyleSheet("color: gray;");
        ui->xx24->setStyleSheet("color: gray;");
        ui->xx25->setStyleSheet("color: gray;");
        ui->xx26->setStyleSheet("color: gray;");

        ui->x11->setDisabled(ui->x11);
        ui->x12->setDisabled(ui->x11);
        ui->x13->setDisabled(ui->x11);
        ui->x21->setDisabled(ui->x11);
        ui->x22->setDisabled(ui->x11);
        ui->x23->setDisabled(ui->x11);
        ui->x31->setDisabled(ui->x11);
        ui->x32->setDisabled(ui->x11);
        ui->x33->setDisabled(ui->x11);

        ui->xx1->setEnabled(false);
        ui->xx2->setEnabled(false);
        ui->xx3->setEnabled(false);
        ui->xx4->setEnabled(false);
        ui->xx5->setEnabled(false);
        ui->xx6->setEnabled(false);
        ui->xx7->setEnabled(false);
        ui->xx8->setEnabled(false);
        ui->xx9->setEnabled(false);
        ui->xx10->setEnabled(false);
        ui->xx11->setEnabled(false);
        ui->xx12->setEnabled(false);
        ui->xx13->setEnabled(false);
        ui->xx14->setEnabled(false);
        ui->xx15->setEnabled(false);
        ui->xx16->setEnabled(false);
        ui->xx17->setEnabled(false);
        ui->xx18->setEnabled(false);
        ui->xx19->setEnabled(false);
        ui->xx20->setEnabled(false);
        ui->xx21->setEnabled(false);
        ui->xx22->setEnabled(false);
        ui->xx23->setEnabled(false);
        ui->xx24->setEnabled(false);
        ui->xx25->setEnabled(false);
        ui->xx26->setEnabled(false);

        draw = new Draw(this);
        draw->setWindowTitle("Draw!");
        draw->setAttribute(Qt::WA_DeleteOnClose);

        draw->showFullScreen();
        return true;
    }
    return false;
}

// Handle random move for computer player
void wordGame::random() {
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

    // Generate a random char.
    int num = rand() % 26;
    num += 97;
    char c = static_cast<char>(num);
    c = toupper(c);

    // Select random button and update it
    int randomIndex = rand() % emptyButtons.size();
    QPushButton *selectedButton = emptyButtons[randomIndex];

    // Delay for seconds
    delay4(100);

    updateButton(selectedButton, n4, c);
    checkGameState();
}

// Check if game is over
void wordGame::checkGameState() {
    if (isWin() || isDraw()) {
        return;
    }

    // Handle computer player
    if (flag4 && n4 % 2 == 1 && ui->Score2->text() == "Random Player") {
        random();
        checkGameState();
    }
    flag4 = false;
}

void wordGame::on_xx1_clicked(){ch = 'A';}
void wordGame::on_xx2_clicked(){ch = 'B';}
void wordGame::on_xx3_clicked(){ch = 'C';}
void wordGame::on_xx4_clicked(){ch = 'D';}
void wordGame::on_xx5_clicked(){ch = 'E';}
void wordGame::on_xx6_clicked(){ch = 'F';}
void wordGame::on_xx7_clicked(){ch = 'G';}
void wordGame::on_xx8_clicked(){ch = 'H';}
void wordGame::on_xx9_clicked(){ch = 'I';}
void wordGame::on_xx10_clicked(){ch = 'J';}
void wordGame::on_xx11_clicked(){ch = 'K';}
void wordGame::on_xx12_clicked(){ch = 'L';}
void wordGame::on_xx13_clicked(){ch = 'M';}
void wordGame::on_xx14_clicked(){ch = 'N';}
void wordGame::on_xx15_clicked(){ch = 'O';}
void wordGame::on_xx16_clicked(){ch = 'P';}
void wordGame::on_xx17_clicked(){ch = 'Q';}
void wordGame::on_xx18_clicked(){ch = 'R';}
void wordGame::on_xx19_clicked(){ch = 'S';}
void wordGame::on_xx20_clicked(){ch = 'T';}
void wordGame::on_xx21_clicked(){ch = 'U';}
void wordGame::on_xx22_clicked(){ch = 'V';}
void wordGame::on_xx23_clicked(){ch = 'W';}
void wordGame::on_xx24_clicked(){ch = 'X';}
void wordGame::on_xx25_clicked(){ch = 'Y';}
void wordGame::on_xx26_clicked(){ch = 'Z';}
