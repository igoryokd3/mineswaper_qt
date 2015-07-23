#ifndef CELL
#define CELL
#include <QPushButton>
#include <QMouseEvent>
#include "qmybutton.h"


class Cell : public QPushButton
{
    Q_OBJECT
signals:
    void clicked_left();
    void clicked_right();
    void clicked_mid();
protected:
    int pos_x_;
    int pos_y_;
    bool cellMarker_;
    bool cellOpen_;
    int numberOfMineAround_;
    void mousePressEvent(QMouseEvent *event);
public:
    Cell();
    Cell(QWidget *parent);
    bool get_cellMarker();
   // void set_cellMarker(bool);
    void change_cellMarker();

    bool get_cellOpen();
    void set_cellOpen();
   // void change_cellOpen();

    int get_numberOfMineAround();
    void increment_numberOfMineAround();

    int get_pos_x();
    void set_pos_x(int);

    int get_pos_y();
    void set_pos_y(int);

    bool ifMineContains();
    void setMine();
    void setMine(bool);

    Cell & operator++ ();
    Cell & operator= (Cell&);

};
#endif // CELL

