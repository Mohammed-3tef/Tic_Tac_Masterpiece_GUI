#include "ultimateGame.h"
#include "ui_ulimateGame.h"

ultimateTicTacToe::ultimateTicTacToe(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ultimateTicTacToe)
{
    ui->setupUi(this);
}

ultimateTicTacToe::~ultimateTicTacToe()
{
    delete ui;
}
