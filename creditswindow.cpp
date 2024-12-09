#include "mainwindow.h"
#include "helpwindow.h"
#include "creditswindow.h"
#include "ui_mainwindow.h"
#include "ui_helpwindow.h"
#include "ui_creditswindow.h"
#include <QIcon>

CreditsWindow::CreditsWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CreditsWindow)
{
    ui->setupUi(this);
}

CreditsWindow::~CreditsWindow()
{
    delete ui;
}

void CreditsWindow::on_creditBackPtn_clicked()
{
    emit backToMainWindow();
    this->close();
}

