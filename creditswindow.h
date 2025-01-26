#ifndef CREDITSWINDOW_H
#define CREDITSWINDOW_H

#include <QMainWindow>

namespace Ui {
class CreditsWindow;
}

class CreditsWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CreditsWindow(QWidget *parent = nullptr);
    ~CreditsWindow();

signals:
    void backToMainWindow(); // Signal to notify return to MainWindow

private slots:
    void on_creditBackPtn_clicked(); // Back button click handler

private:
    Ui::CreditsWindow *ui;
};

#endif // CREDITSWINDOW_H
