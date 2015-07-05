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
   connect(pushButton_2, SIGNAL(rightClicked()), this, SLOT(changeState()));
   pushButton_2->setGeometry(150,150,64,64);
   pushButton_2->setIconSize(QSize(64,64));
   pushButton_2->setIcon(QIcon(":/image/default_cell.bmp"));
}

MainWindow::~MainWindow()
{
    delete ui;
}
/*
void MainWindow::mousePressEvent(QMouseEvent *e)
{
    if(e->button() == Qt::RightButton)
    {

        changeState();
        //emit  rClicked();
    }
}*/
void MainWindow::on_pushButton_clicked()
{
    QPushButton *button = new QPushButton(this);
    ui->gridLayout->addWidget(button);
}

void MainWindow::changeState()
{
    if(flag)
    {
        pushButton_2->setIcon(QIcon(":/image/default_cell.bmp"));
        flag = false;
    }
    else
    {
        pushButton_2->setIcon(QIcon(":/image/flag_cell.bmp"));
        flag = true;
    }
}

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
