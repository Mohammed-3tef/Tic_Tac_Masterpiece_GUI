#ifndef MANUWINDOW_H
#define MANUWINDOW_H

#include <QMainWindow>

namespace Ui {
class ManuWindow;
}

class ManuWindow : public QMainWindow
{
    Q_OBJECT

signals:
    void backToMainWindow();

public:
    explicit ManuWindow(QWidget *parent = nullptr);
    ~ManuWindow();

private slots:
    void on_manuBackBtn_clicked();

    void on_onePlayerChoice_clicked();

    void on_nextBtn_clicked();

    void on_twoPlayerChoice_clicked();

private:
    Ui::ManuWindow *ui;
};

#endif // MANUWINDOW_H
