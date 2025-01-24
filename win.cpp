#include "win.h"
#include "ui_win.h"

Win::Win(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Win)
    , gifMovie(nullptr) // Initialize the pointer
{
    ui->setupUi(this);

    // Load the GIF using the Qt Resource System
    gifMovie = new QMovie(":/Img/giflabel.gif", QByteArray(), this);

    // Check if the GIF was loaded successfully
    if (!gifMovie->isValid()) {
        qDebug() << "Failed to load GIF.";
        return;
    }

    // Set QLabel size policy to ensure it fits the GIF
    ui->winnerLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    // Assign the movie to the QLabel
    ui->winnerLabel->setMovie(gifMovie);

    // Ensure QLabel size is set to fit the GIF
    ui->winnerLabel->resize(gifMovie->currentPixmap().size());

    // Start the animation
    gifMovie->start();
}

Win::~Win()
{
    delete ui;
}

void Win::setWinnerText(const QString &text) {
    // Ensure the winnerLabel exists in the UI
    ui->winnerLabel->setText(text);
}

void Win::on_backPtn_clicked()
{
    emit backToManuWindow();
    this->close();
}
