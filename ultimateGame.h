#ifndef ULTIMATEGAME_H
#define ULTIMATEGAME_H

#include <QDialog>

namespace Ui {
class ultimateTicTacToe;
}

class ultimateTicTacToe : public QDialog
{
Q_OBJECT

public:
    explicit ultimateTicTacToe(QWidget *parent = nullptr);
    ~ultimateTicTacToe();

// signals:
//     void backToMainWindow(); // Signal to notify return to MainWindow

private:
    Ui::ultimateTicTacToe *ui;
};

#endif // ULTIMATEGAME_H
