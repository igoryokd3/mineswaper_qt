
#include <QMainWindow>
#include <QApplication>
#include "field.h"

#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QMainWindow w;
    Field field;


    w.setCentralWidget(&field);
    w.show();
    qDebug()<<"start";
    if(field.ifWin())
    {
        qDebug()<<"win/nwin/nwin/nwin";
    }
    if(field.ifGameOver())
    {
        qDebug()<<"lose/nlose/nlose/nlose";
    }
    return a.exec();
}
