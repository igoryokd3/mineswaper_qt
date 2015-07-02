#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
    ui->pushButton_2->setIcon(QIcon(":/image/flag_cell.bmp"));
}
void MainWindow::on_pushButton_2_clicked()
{
    ui->pushButton_2->setIcon(QIcon(":/image/open_cell.bmp"));
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->pushButton_2->setIcon(QIcon(":/image/1_cell.bmp"));
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->pushButton_2->setIcon(QIcon(":/image/2_cell.bmp"));
}

void MainWindow::on_pushButton_5_clicked()
{
    ui->pushButton_2->setIcon(QIcon(":/image/3_cell.bmp"));
}

void MainWindow::on_pushButton_6_clicked()
{
    ui->pushButton_2->setIcon(QIcon(":/image/mine_cell.bmp"));
}

void MainWindow::on_pushButton_2_pressed()
{
    ui->pushButton_2->setIcon(QIcon(":/image/press_cell.bmp"));
}
