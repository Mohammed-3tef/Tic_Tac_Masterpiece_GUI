#ifndef WIN_H
#define WIN_H

#include <QMainWindow>
#include <QLabel>

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
};

#endif // WIN_H
