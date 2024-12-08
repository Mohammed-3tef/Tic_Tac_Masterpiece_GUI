#ifndef TIC - TAC - TOE - MASTER - PIECE - WITH - GUI_H
#define TIC -TAC - TOE - MASTER - PIECE - WITH - GUI_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class TicTacToeMasterpieceWithGUI;
}
QT_END_NAMESPACE

class TicTacToeMasterpieceWithGUI : public QMainWindow
{
    Q_OBJECT

    public:
        TicTacToeMasterpieceWithGUI(QWidget *parent = nullptr);
        ~TicTacToeMasterpieceWithGUI();

    private slots:
        void on_centralwidget_windowIconChanged(const QIcon &icon);

    private:
        Ui::TicTacToeMasterpieceWithGUI *ui;
};
#endif // TIC-TAC-TOE-MASTER-PIECE-WITH-GUI_H
