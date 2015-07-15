#pragma once
#ifndef FIELD_H
#define FIELD_H
#include "Cell.h"
#include <QWidget>
class Cell;
class Field:public QWidget
{
 Q_OBJECT
protected:
    const static int fieldLength_=10;
    const static int fieldHeight_=10;
    int countOfMine_;
    Cell* cell[fieldHeight_][fieldLength_];
    void completeField();
public:
    Field(QWidget *parent = 0);
  /*  Field(int, int, int);

    void openCell(int, int);
    void checkedOpenCell(int, int);

    int get_closedCell();
    int get_fieldLength();
    int get_fieldHeight();
    int get_countOfMine();

    void set_fieldLength(int);
    void set_fieldWidth(int);
    void get_countOfMine(int);

    bool ifGameOver();

    void output(int, int);
    bool set_Marker(int, int);
    bool get_ifOpenCell(int, int);
    bool get_ifMarkerCell(int, int);*/
protected slots:
    void on_DotClickedLeft();
    void on_DotClickedRight();



};

#endif
