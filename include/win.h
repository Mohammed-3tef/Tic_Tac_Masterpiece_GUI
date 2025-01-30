#ifndef WIN_H
#define WIN_H

#include <QMainWindow>
#include <QLabel>
#include <QMovie> // Add this for GIF handling


namespace Ui {
class Win;
}

class Win : public QMainWindow
{
    Q_OBJECT

public:
    explicit Win(QWidget *parent = nullptr);
    ~Win();

    // Method to set the winner's text
    void setWinnerText(const QString &text);


signals:
    void backToManuWindow(); // Signal to notify return to ManuWindow

private slots:
    void on_backPtn_clicked();

private:
    Ui::Win *ui;
    QMovie *gifMovie;
};

#endif // WIN_H
