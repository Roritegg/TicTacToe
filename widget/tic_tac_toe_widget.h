#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QTableWidget>
#include "D:\QDocs\TicTacToe\src\tic_tac_toe.h"

class TicTacToeWidget : public QWidget {
    Q_OBJECT

public:
    explicit TicTacToeWidget(QWidget *parent = nullptr);

private slots:
    void onCellClicked();
    void onResetClicked();
    void onResetStatsClicked();

private:
    void updateBoard();
    void updateStatus();
    void updateStatsDisplay();
    void createGameBoard();
    void createControlPanel();
    void createStatsPanel();

    TicTacToe game;
    QPushButton *cellButtons[3][3];
    QPushButton *resetButton;
    QPushButton *resetStatsButton;
    QLabel *statusLabel;
    QLabel *currentPlayerLabel;

    QLabel *statsLabel;
    QTableWidget *statsTable;
    QGroupBox *statsGroupBox;

    QWidget *gameBoardWidget;
    QWidget *controlPanelWidget;
    QVBoxLayout *mainLayout;
};
