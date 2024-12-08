#include "boardgame_classes.h"
#include "ultimate.h"
#include "sus.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    boardgame_classes w;
    w.show();

    // Initialize the board with specific dimensions (e.g., 3x3 for a tic-tac-toe game)
    // Board w(3, 3); // Pass the required number of rows and columns
    // w.show();

    return a.exec();
}
