#include "mainwindow.h"
#include "button.h"
#include "ui_mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QMyPushButton *h;
    h = new QMyPushButton();
    QObject::connect(h, SIGNAL(rClicked()),&a,SLOT(changeState()));
    w.show();
    h->setVisible(true);

    return a.exec();
}
