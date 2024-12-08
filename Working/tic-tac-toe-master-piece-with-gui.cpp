#include "tic-tac-toe-master-piece-with-gui.h"
#include "ui_tic-tac-toe-master-piece-with-gui.h"
#include "ullimate.h"  // Include the Dialog header

TicTacToeMasterpieceWithGUI::TicTacToeMasterpieceWithGUI(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TicTacToeMasterpieceWithGUI)
{
    ui->setupUi(this);

    // Create and display the Dialog
    Dialog *dialog = new Dialog(this);
    dialog->show();
}

TicTacToeMasterpieceWithGUI::~TicTacToeMasterpieceWithGUI()
{
    delete ui;
}
