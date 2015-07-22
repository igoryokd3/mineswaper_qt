
#include <QMainWindow>
#include <QApplication>
#include "field.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QMainWindow w;
    Field field;

    w.setCentralWidget(&field);
    w.show();

    return a.exec();
}
