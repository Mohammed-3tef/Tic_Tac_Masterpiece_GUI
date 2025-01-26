#ifndef DRAW_H
#define DRAW_H

#include <QMainWindow>

namespace Ui {
class Draw;
}

class Draw : public QMainWindow
{
    Q_OBJECT

public:
    explicit Draw(QWidget *parent = nullptr);
    ~Draw();

signals:
    void backToManuWindow(); // Signal to notify return to ManuWindow

private slots:
    void on_backPtn_clicked();

private:
    Ui::Draw *ui;
};

#endif // DRAW_H
