#include "win.h"
#include "ui_win.h"

Win::Win(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Win)
{
    ui->setupUi(this);
}

Win::~Win()
{
    delete ui;
}

void Win::setWinnerText(const QString &text) {
    // Ensure the winnerLabel exists in the UI (either from the UI file or created programmatically)
    ui->winnerLabel->setText(text);
}

void Win::on_backPtn_clicked()
{
    emit backToManuWindow();
    this->close();
}
