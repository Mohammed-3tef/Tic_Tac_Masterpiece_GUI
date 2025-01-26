// #include <QApplication>
// #include <QWidget>
// #include <QPushButton>
// #include <QVBoxLayout>
// #include <QLabel>
// #include <QLineEdit>
// #include <QMessageBox>
// #include "BoardGame_Classes.h"

// //--------------------------------------- GLOBAL VARIABLES

// bool winU = false;

// //--------------------------------------- MAIN WIDGET CLASS

// class SUSGameWidget : public QWidget {
//     Q_OBJECT

// private:
//     SUS_Board board;
//     SUS_Player *player1;
//     SUS_Player *player2;
//     QLabel *boardDisplay;
//     QLineEdit *rowInput;
//     QLineEdit *columnInput;
//     QPushButton *submitMoveButton;
//     int currentPlayer;

// public:
//     SUSGameWidget(QWidget *parent = nullptr) : QWidget(parent), currentPlayer(1) {
//         QVBoxLayout *mainLayout = new QVBoxLayout(this);

//         boardDisplay = new QLabel(this);
//         updateBoardDisplay();
//         mainLayout->addWidget(boardDisplay);

//         rowInput = new QLineEdit(this);
//         rowInput->setPlaceholderText("Enter row (1-3)");
//         mainLayout->addWidget(rowInput);

//         columnInput = new QLineEdit(this);
//         columnInput->setPlaceholderText("Enter column (1-3)");
//         mainLayout->addWidget(columnInput);

//         submitMoveButton = new QPushButton("Submit Move", this);
//         connect(submitMoveButton, &QPushButton::clicked, this, &SUSGameWidget::handleMove);
//         mainLayout->addWidget(submitMoveButton);

//         setLayout(mainLayout);

//         player1 = new SUS_Player("Player S", 'S');
//         player2 = new SUS_Player("Player U", 'U');
//     }

//     ~SUSGameWidget() {
//         delete player1;
//         delete player2;
//     }

// private slots:
//     void handleMove() {
//         if (winU) {
//             QMessageBox::information(this, "Game Over", "Game is already over!");
//             return;
//         }

//         int x = rowInput->text().toInt() - 1;
//         int y = columnInput->text().toInt() - 1;

//         if (x < 0 || x >= 3 || y < 0 || y >= 3) {
//             QMessageBox::warning(this, "Invalid Move", "Please enter a valid position.");
//             return;
//         }

//         SUS_Player *current = (currentPlayer == 1) ? player1 : player2;
//         if (board.update_board(x, y, current->getSymbol())) {
//             if (board.is_win()) {
//                 updateBoardDisplay();
//                 QMessageBox::information(this, "Game Over", QString("%1 wins!").arg(current->getName().c_str()));
//                 winU = true;
//                 return;
//             }
//             if (board.is_draw()) {
//                 updateBoardDisplay();
//                 QMessageBox::information(this, "Game Over", "It's a draw!");
//                 winU = true;
//                 return;
//             }
//             currentPlayer = 3 - currentPlayer;
//         } else {
//             QMessageBox::warning(this, "Invalid Move", "Cell is already occupied.");
//         }

//         updateBoardDisplay();
//     }

//     void updateBoardDisplay() {
//         QString display;
//         for (int i = 0; i < 3; ++i) {
//             for (int j = 0; j < 3; ++j) {
//                 char cell = board.getBoard()[i][j];
//                 display += (cell == 0) ? '.' : cell;
//                 display += ' ';
//             }
//             display += '\n';
//         }
//         boardDisplay->setText(display);
//     }
// };

