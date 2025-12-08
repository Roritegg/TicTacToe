#include "tic_tac_toe_test.h"
#include <QVector>

class TestBoard {
public:
    TestBoard() {
        board.resize(3);
        for (int i = 0; i < 3; ++i) {
            board[i].resize(3, 0);
        }
    }

    bool makeMove(int row, int col, int player) {
        if (row < 0 || row >= 3 || col < 0 || col >= 3) return false;
        if (board[row][col] != 0) return false;

        board[row][col] = player;
        return true;
    }

    int getCell(int row, int col) const {
        if (row < 0 || row >= 3 || col < 0 || col >= 3) return -1;
        return board[row][col];
    }

    int checkWinner() const {
        for (int i = 0; i < 3; ++i) {
            if (board[i][0] != 0 && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
                return board[i][0];
            }
        }

        for (int j = 0; j < 3; ++j) {
            if (board[0][j] != 0 && board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
                return board[0][j];
            }
        }

        if (board[0][0] != 0 && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
            return board[0][0];
        }

        if (board[0][2] != 0 && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
            return board[0][2];
        }

        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == 0) {
                    return 0;
                }
            }
        }

        return 3;
    }

    void reset() {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                board[i][j] = 0;
            }
        }
    }

private:
    QVector<QVector<int>> board;
};

void TicTacToeTest::testBasicGameLogic()
{
    TestBoard board;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            QCOMPARE(board.getCell(i, j), 0);
        }
    }

    QVERIFY(board.makeMove(0, 0, 1));
    QCOMPARE(board.getCell(0, 0), 1);

    QVERIFY(!board.makeMove(0, 0, 2));
    QCOMPARE(board.getCell(0, 0), 1);

    QVERIFY(board.makeMove(1, 1, 2));
    QCOMPARE(board.getCell(1, 1), 2);

    qDebug() << "testBasicGameLogic пройден";
}

void TicTacToeTest::testWinConditions()
{
    {
        TestBoard board;
        board.makeMove(0, 0, 1);
        board.makeMove(0, 1, 1);
        board.makeMove(0, 2, 1);
        QCOMPARE(board.checkWinner(), 1);
    }

    {
        TestBoard board;
        board.makeMove(0, 0, 2);
        board.makeMove(1, 0, 2);
        board.makeMove(2, 0, 2);
        QCOMPARE(board.checkWinner(), 2);
    }

    {
        TestBoard board;
        board.makeMove(0, 0, 1);
        board.makeMove(1, 1, 1);
        board.makeMove(2, 2, 1);
        QCOMPARE(board.checkWinner(), 1);
    }

    {
        TestBoard board;
        board.makeMove(0, 2, 2);
        board.makeMove(1, 1, 2);
        board.makeMove(2, 0, 2);
        QCOMPARE(board.checkWinner(), 2);
    }

    qDebug() << "testWinConditions пройден";
}

void TicTacToeTest::testDrawCondition()
{
    TestBoard board;

    board.makeMove(0, 0, 1);
    board.makeMove(0, 1, 2);
    board.makeMove(0, 2, 1);

    board.makeMove(1, 0, 1);
    board.makeMove(1, 1, 2);
    board.makeMove(1, 2, 2);

    board.makeMove(2, 0, 2);
    board.makeMove(2, 1, 1);
    board.makeMove(2, 2, 1);

    QCOMPARE(board.checkWinner(), 3);

    qDebug() << "testDrawCondition пройден";
}

void TicTacToeTest::testInvalidMoves()
{
    TestBoard board;

    QVERIFY(!board.makeMove(-1, 0, 1));
    QVERIFY(!board.makeMove(0, -1, 1));

    QVERIFY(!board.makeMove(3, 0, 1));
    QVERIFY(!board.makeMove(0, 3, 1));
    QVERIFY(!board.makeMove(3, 3, 1));

    board.makeMove(0, 0, 1);
    QVERIFY(!board.makeMove(0, 0, 2));

    qDebug() << "testInvalidMoves пройден";
}

void TicTacToeTest::testGameState()
{
    TestBoard board;

    QCOMPARE(board.checkWinner(), 0);

    board.makeMove(0, 0, 1);
    QCOMPARE(board.checkWinner(), 0);

    board.reset();
    board.makeMove(0, 0, 1);
    board.makeMove(0, 1, 1);
    board.makeMove(0, 2, 1);
    QCOMPARE(board.checkWinner(), 1);

    board.reset();
    QCOMPARE(board.checkWinner(), 0);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            QCOMPARE(board.getCell(i, j), 0);
        }
    }

    qDebug() << "testGameState пройден";
}
