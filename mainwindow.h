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




private:
    Ui::MainWindow *ui;
    bool flag;
    mybutton* arr[10][10];

};

#endif // MAINWINDOW_H
