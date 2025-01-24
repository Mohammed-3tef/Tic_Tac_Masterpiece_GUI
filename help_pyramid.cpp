#include "help_pyramid.h"
#include "ui_help_pyramid.h"

help_pyramid::help_pyramid(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::help_pyramid)
{
    ui->setupUi(this);
}

help_pyramid::~help_pyramid()
{
    delete ui;
}

void help_pyramid::on_backPtn_clicked()
{
    this->hide();
}

