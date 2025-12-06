#include <vector>
#include <string>

enum class Player {
    None,
    X,
    O
};

class TicTacToe {
public:
    TicTacToe();

    bool makeMove(int row, int col, Player player);
    bool isGameOver() const;
    Player getWinner() const;
    bool isDraw() const;
    Player getCurrentPlayer() const;
    Player getCell(int row, int col) const;
    void resetGame();

private:
    static const int BOARD_SIZE = 3;
    std::vector<std::vector<Player>> board;
    Player currentPlayer;
    bool gameOver;
    Player winner;

    bool checkWin(Player player) const;
    bool checkDraw() const;
    bool isValidMove(int row, int col) const;
};
