#include "draw.h"
#include "ui_draw.h"

Draw::Draw(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Draw)
{
    ui->setupUi(this);
}

Draw::~Draw()
{
    delete ui;
}

void Draw::on_backPtn_clicked()
{
    emit backToManuWindow();
    this->close();
}
