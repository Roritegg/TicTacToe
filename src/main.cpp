#include <QApplication>
#include "tic_tac_toe_widget.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    app.setStyle("Fusion");

    TicTacToeWidget window;
    window.show();

    return app.exec();
}
