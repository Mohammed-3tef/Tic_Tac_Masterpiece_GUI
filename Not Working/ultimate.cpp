#include "ultimate.h"
#include "ui_ultimate.h"

Ultimate::Ultimate(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Ultimate)
{
    ui->setupUi(this);
}

Ultimate::~Ultimate()
{
    delete ui;
}
