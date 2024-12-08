#include "tic-tac-toe-master-piece-with-gui.h"
#include "ullimate.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TicTacToeMasterpieceWithGUI w;
    w.show();
    return a.exec();
}
