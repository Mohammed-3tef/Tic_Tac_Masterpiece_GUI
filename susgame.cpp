#include "susgame.h"
#include "ui_susgame.h"
#include "manuwindow.h"
#include "ui_manuwindow.h"
#include "help_sus.h"


susGame::susGame(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::susGame)
    , helpsus(nullptr)
{
    ui->setupUi(this);
}

susGame::~susGame()
{
    delete ui;
    delete helpsus;
}

void susGame::on_helpButton_clicked()
{
    helpsus = new Help_SUS(this);
    helpsus->show();
}

void susGame::on_exitButton_clicked()
{
    emit backToManuWindow();
    this->close();
}

