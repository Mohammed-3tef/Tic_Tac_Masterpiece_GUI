#include "boardgame_classes.h"
#include <cstdlib>
#include <ctime>
#include <QMessageBox>
#include <algorithm>


// ------------------------- Player Implementation -------------------------

Player::Player(QString name, char symbol) : name(name), symbol(symbol), boardPtr(nullptr) {}

Player::Player(char symbol) : name("Computer"), symbol(symbol), boardPtr(nullptr) {}

QString Player::getname() {
    return name;
}

char Player::getsymbol() {
    return symbol;
}

void Player::setBoard(Board* b) {
    boardPtr = b;
}

// ------------------------- RandomPlayer Implementation -------------------------

RandomPlayer::RandomPlayer(char symbol) : Player(symbol) {
    std::srand(std::time(nullptr));
}

// ------------------------- GameManager Implementation -------------------------

GameManager::GameManager(Board* board, Player* player1, Player* player2, QWidget* parent)
    : QMainWindow(parent), boardPtr(board) {
    players[0] = player1;
    players[1] = player2;

    auto mainWidget = new QWidget(this);
    auto layout = new QVBoxLayout(mainWidget);

    layout->addWidget(board);
    statusLabel = new QLabel("Game started!", this);
    layout->addWidget(statusLabel);

    setCentralWidget(mainWidget);
}

void GameManager::run() {
    int x, y;
    boardPtr->display_board();

    connect(boardPtr, &Board::boardUpdated, this, [&]() {
        for (int i : {0, 1}) {
            players[i]->getmove(x, y);
            while (!boardPtr->update_board(x, y, players[i]->getsymbol())) {
                players[i]->getmove(x, y);
            }
            if (boardPtr->is_win()) {
                QMessageBox::information(this, "Game Over", players[i]->getname() + " wins!");
                return;
            }
            if (boardPtr->is_draw()) {
                QMessageBox::information(this, "Game Over", "It's a draw!");
                return;
            }
        }
    });
}
