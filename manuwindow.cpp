#include "manuwindow.h"
#include "ui_manuwindow.h"
#include "QMessageBox"

ManuWindow::ManuWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ManuWindow)
{
    ui->setupUi(this);
    ui->onePlayerChoice->setChecked(false);
    ui->twoPlayerChoice->setChecked(false);
    ui->susGameChoice->setChecked(false);
    ui->ultimateGameChoice->setChecked(false);
    ui->firstInput->setEnabled(false);
    ui->secondInput->setEnabled(false);
}

ManuWindow::~ManuWindow()
{
    delete ui;
}

void ManuWindow::on_manuBackBtn_clicked()
{
    emit backToMainWindow();
    this->close();
}



void ManuWindow::on_nextBtn_clicked()
{
    // Check if a player mode is selected
    if (!ui->onePlayerChoice->isChecked() && !ui->twoPlayerChoice->isChecked()) {
        QMessageBox::warning(this, "Selection Missing", "Please select a player mode!");
        return;
    }

    // Check if a game mode is selected
    if (!ui->susGameChoice->isChecked() && !ui->ultimateGameChoice->isChecked()) {
        QMessageBox::warning(this, "Selection Missing", "Please select a game mode!");
        return;
    }

    // Check if the first input is filled
    if (ui->firstInput->text().isEmpty()) {
        QMessageBox::warning(this, "Input Missing", "Please fill in the first input field!");
        return;
    }

    // If two-player mode is selected, check if the second input is filled
    if (ui->twoPlayerChoice->isChecked() && ui->secondInput->text().isEmpty()) {
        QMessageBox::warning(this, "Input Missing", "Please fill in the second input field for two-player mode!");
        return;
    }


    QMessageBox::information(this, "Finally...", ui->firstInput->text()+" and "+ui->secondInput->text());

    // if (ui->susGameChoice->isChecked()) {

    // }

    // else if (ui->ultimateGameChoice->isChecked()) {

    // }
}


void ManuWindow::on_onePlayerChoice_clicked()
{
    ui->firstInput->setEnabled(true);
    ui->secondInput->setEnabled(false);
    ui->secondInput->setText("Random Computer Player");
}

void ManuWindow::on_twoPlayerChoice_clicked()
{
    ui->firstInput->setEnabled(true);
    ui->secondInput->setEnabled(true);
    ui->secondInput->clear();
}

