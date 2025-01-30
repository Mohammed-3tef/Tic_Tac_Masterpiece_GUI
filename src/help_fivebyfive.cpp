#include "../include/help_fivebyfive.h"
#include "../forms/ui_help_fivebyfive.h"

Help_Fivebyfive::Help_Fivebyfive(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Help_Fivebyfive)
{
    ui->setupUi(this);
}

Help_Fivebyfive::~Help_Fivebyfive()
{
    delete ui;
}

void Help_Fivebyfive::on_backPtn_clicked()
{
    this->hide();
}
