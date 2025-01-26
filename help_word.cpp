#include "help_word.h"
#include "ui_help_word.h"

help_word::help_word(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::help_word)
{
    ui->setupUi(this);
}

help_word::~help_word()
{
    delete ui;
}

void help_word::on_backPtn_clicked()
{
    this->hide();
}

