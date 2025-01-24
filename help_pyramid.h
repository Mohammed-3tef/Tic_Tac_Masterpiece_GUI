#ifndef HELP_PYRAMID_H
#define HELP_PYRAMID_H

#include <QMainWindow>

namespace Ui {
class help_pyramid;
}

class help_pyramid : public QMainWindow
{
    Q_OBJECT

public:
    explicit help_pyramid(QWidget *parent = nullptr);
    ~help_pyramid();

private slots:
    void on_backPtn_clicked();

private:
    Ui::help_pyramid *ui;
};

#endif // HELP_PYRAMID_H
