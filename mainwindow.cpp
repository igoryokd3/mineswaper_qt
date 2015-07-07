#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QApplication>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    flag=false;
   pushButton_2 = new mybutton(this);
   pushButton_2->setGeometry(150,150,64,64);
   pushButton_2->setIconSize(QSize(64,64));
   pushButton_2->setIcon(QIcon(":/image/default_cell.bmp"));

   for (int i = 0; i < 5; i++)
   {
        arr[i] = new mybutton(this);

        ui->gridLayout_2->addWidget(arr[i]);
        connect(arr[i], SIGNAL(rightClicked()), this, SLOT(changeState()));
        connect(arr[i], SIGNAL(leftClicked()), this, SLOT(click()));


   }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QPushButton *button = new QPushButton(this);
    ui->gridLayout->addWidget(button);
}

void MainWindow::changeState()
{

}
void MainWindow::click()
{}
void MainWindow::both()
{}

void MainWindow::on_pushButton_2_clicked()
{
    pushButton_2->setIcon(QIcon(":/image/open_cell.bmp"));
}

void MainWindow::on_pushButton_3_clicked()
{
    pushButton_2->setIcon(QIcon(":/image/1_cell.bmp"));
}

void MainWindow::on_pushButton_4_clicked()
{
    pushButton_2->setIcon(QIcon(":/image/2_cell.bmp"));
}

void MainWindow::on_pushButton_5_clicked()
{
    pushButton_2->setIcon(QIcon(":/image/3_cell.bmp"));
}

void MainWindow::on_pushButton_6_clicked()
{
    pushButton_2->setIcon(QIcon(":/image/mine_cell.bmp"));
}

void MainWindow::on_pushButton_2_pressed()
{
    pushButton_2->setIcon(QIcon(":/image/press_cell.bmp"));
}


