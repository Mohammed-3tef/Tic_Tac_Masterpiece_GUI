#include "boardgame_classes.h"
#include "ui_boardgame_classes.h"

BoardGame_Classes::BoardGame_Classes(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::BoardGame_Classes)
{
    ui->setupUi(this);
}

BoardGame_Classes::~BoardGame_Classes()
{
    delete ui;
}
