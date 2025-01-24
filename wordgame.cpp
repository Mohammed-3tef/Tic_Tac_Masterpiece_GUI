#include "wordgame.h"
#include "ui_wordgame.h"

wordgame::wordgame(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::wordgame)
{
    ui->setupUi(this);
}

wordgame::~wordgame()
{
    delete ui;
}
