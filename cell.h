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

    bool ifMineContains();
    void setMine();
    void setMine(bool);

    Cell & operator++ ();

};
#endif // CELL

