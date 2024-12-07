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

private:
    Ui::ManuWindow *ui;
};

#endif // MANUWINDOW_H
