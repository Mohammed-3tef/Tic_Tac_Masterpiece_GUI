#include <QApplication>
#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QMessageBox>
#include "BoardGame_Classes.h"

//--------------------------------------- CLASSES

// Qt-based Ultimate Tic-Tac-Toe board
class UltimateTicTacToeWidget : public QWidget {
    Q_OBJECT

private:
    QPushButton* smallBoards[3][3][3][3]; // Buttons for the 3x3 grid of smaller boards
    char bigBoard[3][3];
    char currentPlayer;

public:
    UltimateTicTacToeWidget(QWidget* parent = nullptr);

private slots:
            void handleCellClick();

private:
    void updateSmallBoard(int bigX, int bigY, int cellX, int cellY, char symbol);
    bool checkWin(const char board[3][3]);
    bool checkDraw(const char board[3][3]);
    void switchPlayer();
};

//--------------------------------------- IMPLEMENTATION

UltimateTicTacToeWidget::UltimateTicTacToeWidget(QWidget* parent)
        : QWidget(parent), currentPlayer('X') {
    QGridLayout* mainLayout = new QGridLayout(this);

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            QGridLayout* smallBoardLayout = new QGridLayout();
            for (int x = 0; x < 3; ++x) {
                for (int y = 0; y < 3; ++y) {
                    QPushButton* cell = new QPushButton(".", this);
                    smallBoards[i][j][x][y] = cell;
                    smallBoardLayout->addWidget(cell, x, y);

                    connect(cell, &QPushButton::clicked, this, &UltimateTicTacToeWidget::handleCellClick);
                }
            }

            QWidget* smallBoardWidget = new QWidget(this);
            smallBoardWidget->setLayout(smallBoardLayout);
            mainLayout->addWidget(smallBoardWidget, i, j);

            bigBoard[i][j] = 0; // Initialize big board as empty
        }
    }

    setLayout(mainLayout);
}

void UltimateTicTacToeWidget::handleCellClick() {
    QPushButton* clickedButton = qobject_cast<QPushButton*>(sender());
    if (!clickedButton || clickedButton->text() != ".") return;

    // Find the button's coordinates in the small board
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int x = 0; x < 3; ++x) {
                for (int y = 0; y < 3; ++y) {
                    if (smallBoards[i][j][x][y] == clickedButton) {
                        updateSmallBoard(i, j, x, y, currentPlayer);
                        if (checkWin(bigBoard)) {
                            QMessageBox::information(this, "Game Over", QString("Player %1 wins!").arg(currentPlayer));
                            return;
                        } else if (checkDraw(bigBoard)) {
                            QMessageBox::information(this, "Game Over", "It's a draw!");
                            return;
                        }
                        switchPlayer();
                        return;
                    }
                }
            }
        }
    }
}

void UltimateTicTacToeWidget::updateSmallBoard(int bigX, int bigY, int cellX, int cellY, char symbol) {
    QPushButton* button = smallBoards[bigX][bigY][cellX][cellY];
    button->setText(QString(symbol));

    // Check if small board is won or drawn
    char smallBoard[3][3] = {0};
    for (int x = 0; x < 3; ++x) {
        for (int y = 0; y < 3; ++y) {
            smallBoard[x][y] = smallBoards[bigX][bigY][x][y]->text().toLatin1();
        }
    }

    if (checkWin(smallBoard)) {
        bigBoard[bigX][bigY] = symbol;
    } else if (checkDraw(smallBoard)) {
        bigBoard[bigX][bigY] = '-';
    }
}

bool UltimateTicTacToeWidget::checkWin(const char board[3][3]) {
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] != 0 && board[i][0] == board[i][1] && board[i][1] == board[i][2]) ||
            (board[0][i] != 0 && board[0][i] == board[1][i] && board[1][i] == board[2][i])) {
            return true;
        }
    }
    return (board[0][0] != 0 && board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
           (board[0][2] != 0 && board[0][2] == board[1][1] && board[1][1] == board[2][0]);
}

bool UltimateTicTacToeWidget::checkDraw(const char board[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == 0) return false;
        }
    }
    return true;
}

void UltimateTicTacToeWidget::switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

