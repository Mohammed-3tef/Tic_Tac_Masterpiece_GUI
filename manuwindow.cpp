#include "manuwindow.h"
#include "ui_manuwindow.h"

ManuWindow::ManuWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ManuWindow)
{
    ui->setupUi(this);
}

ManuWindow::~ManuWindow()
{
    delete ui;
}
