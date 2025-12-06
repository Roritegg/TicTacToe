#include <vector>
#include <string>

enum class Player {
    None,
    X,
    O
};

struct GameStatistics {
    int xWins = 0;
    int oWins = 0;
    int draws = 0;
    int totalGames = 0;

    double getXWinRate() const {
        return totalGames > 0 ? (static_cast<double>(xWins) / totalGames * 100) : 0;
    }

    double getOWinRate() const {
        return totalGames > 0 ? (static_cast<double>(oWins) / totalGames * 100) : 0;
    }

    double getDrawRate() const {
        return totalGames > 0 ? (static_cast<double>(draws) / totalGames * 100) : 0;
    }
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

    const GameStatistics& getStats() const { return stats; }
    void resetStats();
    int getMoveCount() const { return moveCount; }

private:
    static const int BOARD_SIZE = 3;
    std::vector<std::vector<Player>> board;
    Player currentPlayer;
    bool gameOver;
    Player winner;
    int moveCount;
    GameStatistics stats;

    bool checkWin(Player player) const;
    bool checkDraw() const;
    bool isValidMove(int row, int col) const;
    void updateStats();
};
