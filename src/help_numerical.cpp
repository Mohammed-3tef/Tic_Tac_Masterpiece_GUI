#include "../include/help_numerical.h"
#include "ui_help_numerical.h"

Help_Numerical::Help_Numerical(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Help_Numerical)
{
    ui->setupUi(this);
}

Help_Numerical::~Help_Numerical()
{
    delete ui;
}

void Help_Numerical::on_backPtn_clicked()
{
    this->hide();
}
