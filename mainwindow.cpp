#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QApplication>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    flag=false;
    for (int i = 0; i < 10; i++)
    {
           for (int j = 0; j < 10; j++)
           {
                arr[i][j] = new mybutton(this);

                ui->gridLayout_2->addWidget(arr[i][j],i,j);
               // QString str = QString::number(i) + QString::number(j);
               // arr[i][j]->setText(str);
               // arr[i][j]->resize(16,16);
               // connect(arr[i], SIGNAL(rightClicked()), this, SLOT(changeState()));
                //connect(arr[i], SIGNAL(leftClicked()), this, SLOT(click()));
           }
    }
   // ui->gridLayout_2->

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::changeState()
{

}
void MainWindow::click()
{}
void MainWindow::both()
{}


