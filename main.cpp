
#include <QMainWindow>
#include <QApplication>
#include "field.h"
#include"game.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QMainWindow w;
    Game game;


   // w.setCentralWidget(&field);
    w.show();

    return a.exec();
}
