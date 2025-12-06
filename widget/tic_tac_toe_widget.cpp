#include "D:\QDocs\TicTacToe\widget\tic_tac_toe_widget.h"
#include <QMessageBox>
#include <QFont>

TicTacToeWidget::TicTacToeWidget(QWidget *parent)
    : QWidget(parent) {

    mainLayout = new QVBoxLayout(this);

    createControlPanel();

    createGameBoard();

    updateStatus();

    setWindowTitle("Крестики-Нолики");
    setMinimumSize(400, 500);
}

void TicTacToeWidget::createControlPanel() {
    controlPanelWidget = new QWidget(this);
    QVBoxLayout *controlLayout = new QVBoxLayout(controlPanelWidget);

    statusLabel = new QLabel("Добро пожаловать в игру!", controlPanelWidget);
    statusLabel->setAlignment(Qt::AlignCenter);
    QFont statusFont = statusLabel->font();
    statusFont.setPointSize(12);
    statusLabel->setFont(statusFont);

    currentPlayerLabel = new QLabel("Текущий игрок: X", controlPanelWidget);
    currentPlayerLabel->setAlignment(Qt::AlignCenter);

    resetButton = new QPushButton("Новая игра", controlPanelWidget);
    resetButton->setStyleSheet("QPushButton { background-color: #4CAF50; color: white; padding: 10px; }");

    controlLayout->addWidget(statusLabel);
    controlLayout->addWidget(currentPlayerLabel);
    controlLayout->addWidget(resetButton);

    mainLayout->addWidget(controlPanelWidget);

    connect(resetButton, &QPushButton::clicked, this, &TicTacToeWidget::onResetClicked);
}

void TicTacToeWidget::createGameBoard() {
    gameBoardWidget = new QWidget(this);
    QGridLayout *boardLayout = new QGridLayout(gameBoardWidget);
    boardLayout->setSpacing(5);

    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            cellButtons[row][col] = new QPushButton("", gameBoardWidget);
            cellButtons[row][col]->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            cellButtons[row][col]->setMinimumSize(80, 80);
            cellButtons[row][col]->setFont(QFont("Arial", 24));

            cellButtons[row][col]->setProperty("row", row);
            cellButtons[row][col]->setProperty("col", col);

            boardLayout->addWidget(cellButtons[row][col], row, col);

            connect(cellButtons[row][col], &QPushButton::clicked,
                    this, &TicTacToeWidget::onCellClicked);
        }
    }

    mainLayout->addWidget(gameBoardWidget);
}

void TicTacToeWidget::onCellClicked() {
    QPushButton *clickedButton = qobject_cast<QPushButton*>(sender());
    if (!clickedButton) return;

    int row = clickedButton->property("row").toInt();
    int col = clickedButton->property("col").toInt();

    Player currentPlayer = game.getCurrentPlayer();
    if (game.makeMove(row, col, currentPlayer)) {
        updateBoard();
        updateStatus();

        if (game.isGameOver()) {
            if (game.isDraw()) {
                QMessageBox::information(this, "Игра окончена", "Ничья!");
            } else {
                QString winner = (game.getWinner() == Player::X) ? "X" : "O";
                QMessageBox::information(this, "Игра окончена",
                                         QString("Игрок %1 победил!").arg(winner));
            }
        }
    }
}

void TicTacToeWidget::onResetClicked() {
    game.resetGame();
    updateBoard();
    updateStatus();
}

void TicTacToeWidget::updateBoard() {
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            Player cell = game.getCell(row, col);
            QString text;
            QString style;

            switch (cell) {
            case Player::X:
                text = "X";
                style = "QPushButton { background-color: #FF6B6B; color: white; font-size: 24px; }";
                break;
            case Player::O:
                text = "O";
                style = "QPushButton { background-color: #4ECDC4; color: white; font-size: 24px; }";
                break;
            default:
                text = "";
                style = "QPushButton { background-color: #F7F7F7; font-size: 24px; }";
                break;
            }

            cellButtons[row][col]->setText(text);
            cellButtons[row][col]->setStyleSheet(style);
        }
    }
}

void TicTacToeWidget::updateStatus() {
    if (game.isGameOver()) {
        if (game.isDraw()) {
            statusLabel->setText("Игра окончена: Ничья!");
            statusLabel->setStyleSheet("QLabel { color: #FFA500; font-weight: bold; }");
        } else {
            QString winner = (game.getWinner() == Player::X) ? "X" : "O";
            statusLabel->setText(QString("Победил игрок %1!").arg(winner));
            statusLabel->setStyleSheet("QLabel { color: #2E8B57; font-weight: bold; }");
        }
    } else {
        statusLabel->setText("Игра идет...");
        statusLabel->setStyleSheet("QLabel { color: #333; }");
    }

    QString currentPlayer = (game.getCurrentPlayer() == Player::X) ? "X" : "O";
    currentPlayerLabel->setText(QString("Текущий игрок: %1").arg(currentPlayer));
    currentPlayerLabel->setStyleSheet(
        QString("QLabel { color: %1; font-weight: bold; }")
            .arg(currentPlayer == "X" ? "#FF6B6B" : "#4ECDC4")
        );
}
