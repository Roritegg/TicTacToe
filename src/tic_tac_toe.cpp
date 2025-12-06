#include "tic_tac_toe.h"

TicTacToe::TicTacToe() : currentPlayer(Player::X), gameOver(false), winner(Player::None) {
    board.resize(BOARD_SIZE, std::vector<Player>(BOARD_SIZE, Player::None));
}

bool TicTacToe::makeMove(int row, int col, Player player) {
    if (gameOver || player != currentPlayer || !isValidMove(row, col)) {
        return false;
    }

    board[row][col] = player;

    if (checkWin(player)) {
        gameOver = true;
        winner = player;
    } else if (checkDraw()) {
        gameOver = true;
        winner = Player::None;
    } else {
        currentPlayer = (player == Player::X) ? Player::O : Player::X;
    }

    return true;
}

bool TicTacToe::isGameOver() const {
    return gameOver;
}

Player TicTacToe::getWinner() const {
    return winner;
}

bool TicTacToe::isDraw() const {
    return gameOver && winner == Player::None;
}

Player TicTacToe::getCurrentPlayer() const {
    return currentPlayer;
}

Player TicTacToe::getCell(int row, int col) const {
    if (row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE) {
        return board[row][col];
    }
    return Player::None;
}

void TicTacToe::resetGame() {
    board = std::vector<std::vector<Player>>(BOARD_SIZE, std::vector<Player>(BOARD_SIZE, Player::None));
    currentPlayer = Player::X;
    gameOver = false;
    winner = Player::None;
}

bool TicTacToe::checkWin(Player player) const {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        bool win = true;
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (board[i][j] != player) {
                win = false;
                break;
            }
        }
        if (win) return true;
    }

    for (int j = 0; j < BOARD_SIZE; ++j) {
        bool win = true;
        for (int i = 0; i < BOARD_SIZE; ++i) {
            if (board[i][j] != player) {
                win = false;
                break;
            }
        }
        if (win) return true;
    }

    bool diag1 = true;
    bool diag2 = true;
    for (int i = 0; i < BOARD_SIZE; ++i) {
        if (board[i][i] != player) diag1 = false;
        if (board[i][BOARD_SIZE - 1 - i] != player) diag2 = false;
    }

    return diag1 || diag2;
}

bool TicTacToe::checkDraw() const {
    for (const auto& row : board) {
        for (const auto& cell : row) {
            if (cell == Player::None) {
                return false;
            }
        }
    }
    return true;
}

bool TicTacToe::isValidMove(int row, int col) const {
    return row >= 0 && row < BOARD_SIZE &&
           col >= 0 && col < BOARD_SIZE &&
           board[row][col] == Player::None;
}
