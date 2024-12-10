#include "help_sus.h"
#include "ui_help_sus.h"

Help_SUS::Help_SUS(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Help_SUS)
{
    ui->setupUi(this);
}

Help_SUS::~Help_SUS()
{
    delete ui;
}

void Help_SUS::on_backPtn_clicked()
{
    this->hide();
}
