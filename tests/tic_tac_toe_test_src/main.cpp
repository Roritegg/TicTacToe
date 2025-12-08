#include <QtTest>
#include "tic_tac_toe_test.h"

int main(int argc, char *argv[])
{
    TicTacToeTest test;
    return QTest::qExec(&test, argc, argv);
}
