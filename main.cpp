
#include <QMainWindow>
#include <QApplication>
#include "field.h"
#include"game.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QMainWindow mainWindow;
    Game game;

    QMenuBar *menuBar; // меню

    mainWindow.setCentralWidget(&game);
    menuBar = mainWindow.menuBar();

    mainWindow.show();

    return a.exec();
}
