#include "../include/help_four.h"
#include "ui_help_four.h"

Help_Four::Help_Four(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Help_Four)
{
    ui->setupUi(this);
}

Help_Four::~Help_Four()
{
    delete ui;
}

void Help_Four::on_backPtn_clicked()
{
    this->hide();
}
