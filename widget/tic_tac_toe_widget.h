#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "D:\QDocs\TicTacToe\src\tic_tac_toe.h"

class TicTacToeWidget : public QWidget {
    Q_OBJECT

public:
    explicit TicTacToeWidget(QWidget *parent = nullptr);

private slots:
    void onCellClicked();
    void onResetClicked();

private:
    void updateBoard();
    void updateStatus();
    void createGameBoard();
    void createControlPanel();

    TicTacToe game;
    QPushButton *cellButtons[3][3];
    QPushButton *resetButton;
    QLabel *statusLabel;
    QLabel *currentPlayerLabel;

    QWidget *gameBoardWidget;
    QWidget *controlPanelWidget;
    QVBoxLayout *mainLayout;
};
