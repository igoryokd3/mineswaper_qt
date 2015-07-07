#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <vector>
#include "mybutton.h"
#include <QMainWindow>
#include <QMouseEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
     void changeState();
    void click();
    void both();
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_2_pressed();



private:
    Ui::MainWindow *ui;
    bool flag;
    mybutton *pushButton_2;
    mybutton* arr[100];

};

#endif // MAINWINDOW_H
