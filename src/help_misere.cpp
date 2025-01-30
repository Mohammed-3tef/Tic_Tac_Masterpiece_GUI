#include "../include/help_misere.h"
#include "ui_help_misere.h"

Help_Misere::Help_Misere(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Help_Misere)
{
    ui->setupUi(this);
}

Help_Misere::~Help_Misere()
{
    delete ui;
}

void Help_Misere::on_backPtn_clicked()
{
    this->hide();
}
