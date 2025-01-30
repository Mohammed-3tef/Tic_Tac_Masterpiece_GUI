#ifndef HELPWINDOW_H
#define HELPWINDOW_H

#include <QMainWindow>

namespace Ui {
class HelpWindow;
}

class HelpWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit HelpWindow(QWidget *parent = nullptr);
    ~HelpWindow();

signals:
    void backToMainWindow(); // Signal to notify return to MainWindow

private slots:
    void on_backPtn_clicked(); // Back button click handler

private:
    Ui::HelpWindow *ui;
};

#endif // HELPWINDOW_H
