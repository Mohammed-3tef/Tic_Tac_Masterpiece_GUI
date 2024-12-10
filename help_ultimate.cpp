#include "help_ultimate.h"
#include "ui_help_ultimate.h"
#include "ultimategame.h"
#include "ui_ultimategame.h"

Help_Ultimate::Help_Ultimate(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Help_Ultimate)
{
    ui->setupUi(this);
}

Help_Ultimate::~Help_Ultimate()
{
    delete ui;
}

void Help_Ultimate::on_backPtn_clicked()
{
    this->hide();
}
