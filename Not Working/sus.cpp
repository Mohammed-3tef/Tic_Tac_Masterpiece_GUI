#include "sus.h"
#include "ui_sus.h"

SUS::SUS(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SUS)
{
    ui->setupUi(this);
}

SUS::~SUS()
{
    delete ui;
}
