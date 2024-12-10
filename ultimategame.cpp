#include "ultimategame.h"
#include "ui_ultimategame.h"
#include "manuwindow.h"
#include "ui_manuwindow.h"
#include "help_ultimate.h"


ultimateGame::ultimateGame(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ultimateGame)
    , helpultimate(nullptr)
{
    ui->setupUi(this);
}

ultimateGame::~ultimateGame()
{
    delete ui;
    delete helpultimate;
}

void ultimateGame::on_helpButton_clicked()
{
    helpultimate = new Help_Ultimate(this);
    helpultimate->show();
}

void ultimateGame::on_exitButton_clicked()
{
    emit backToManuWindow();
    this->close();
}
