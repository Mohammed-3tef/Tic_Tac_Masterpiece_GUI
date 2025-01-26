#ifndef HELP_WORD_H
#define HELP_WORD_H

#include <QMainWindow>

namespace Ui {
class help_word;
}

class help_word : public QMainWindow
{
    Q_OBJECT

public:
    explicit help_word(QWidget *parent = nullptr);
    ~help_word();

private slots:
    void on_backPtn_clicked();

private:
    Ui::help_word *ui;
};

#endif // HELP_WORD_H
