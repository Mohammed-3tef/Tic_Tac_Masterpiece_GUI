#ifndef BOARDGAME_CLASSES_H
#define BOARDGAME_CLASSES_H
#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QVector>
#include <QString>
#include <QMainWindow>
#include <QLabel>

// ------------------------- Board Class -------------------------

class Board : public QWidget {
    Q_OBJECT
protected:
    int rows, columns;
    QVector<QVector<QPushButton*>> boardCells;
    QVector<QVector<char>> boardState;
    int n_moves = 0;
public:
    Board(int rows, int columns, QWidget* parent = nullptr);
    virtual bool update_board(int x, int y, char symbol) = 0;
    virtual void display_board() = 0;
    virtual bool is_win() = 0;
    virtual bool is_draw() = 0;
    virtual bool game_is_over() = 0;
signals:
    void boardUpdated();
};

// ------------------------- Player Class -------------------------

class Player {
protected:
    QString name;
    char symbol;
    Board* boardPtr;
public:
    Player(QString name, char symbol);
    Player(char symbol);
    virtual void getmove(int& x, int& y) = 0;
    char getsymbol();
    QString getname();
    void setBoard(Board* b);
};

// ------------------------- RandomPlayer Class -------------------------

class RandomPlayer : public Player {
public:
    RandomPlayer(char symbol);
    virtual void getmove(int& x, int& y) = 0;
};

// ------------------------- GameManager Class -------------------------

class GameManager : public QMainWindow {
    Q_OBJECT
private:
    Board* boardPtr;
    Player* players[2];
    QLabel* statusLabel;
public:
    GameManager(Board* board, Player* player1, Player* player2, QWidget* parent = nullptr);
    void run();
};

#endif // BOARDGAME_CLASSES_H
