#include <QtTest>

class TicTacToeTest : public QObject
{
    Q_OBJECT

private slots:
    void testBasicGameLogic();
    void testWinConditions();
    void testDrawCondition();
    void testInvalidMoves();
    void testGameState();
};

