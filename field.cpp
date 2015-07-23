#include "Field.h"
#include <assert.h>
#include <ctime>
#include <QGridLayout>
#include <ctime>




Field::Field(QWidget *parent): QWidget(parent)
{
    fieldLength_ = 9;
    fieldHeight_ = 9;
    countOfMine_ = 10;
    QGridLayout *layout = new QGridLayout(this);
    layout->setHorizontalSpacing(0);
    layout->setVerticalSpacing(0);
    cell = new Cell*[fieldHeight_];
        for (int i = 0; i < fieldHeight_; ++i)
            cell[i] = new Cell[fieldLength_];
    for (int i = 0; i < fieldHeight_; ++i)
    {
        for (int j = 0; j < fieldLength_; ++j)
        {
            layout->addWidget(&cell[i][j], i, j);
            //cell[i][j].setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            cell[i][j].setFixedSize(19, 19);
            cell[i][j].setIconSize(QSize(19,19));
            cell[i][j].set_pos_x(j);
            cell[i][j].set_pos_y(i);
            connect(&cell[i][j], SIGNAL(clicked_left()), this, SLOT(on_DotClickedLeft()));
            connect(&cell[i][j], SIGNAL(clicked_right()), this, SLOT(on_DotClickedRight()));
            connect(&cell[i][j], SIGNAL(clicked_right()), this, SLOT(on_DotClickedMid()));
        }
    }

    completeField();
}
void Field::completeField()
{
    srand((unsigned)time(0));
    int pos_X, pos_Y;

for (int i = 0; i < countOfMine_; ++i)
  {
        cell[i / fieldLength_][i % fieldLength_].setMine();
  }

for (int i = 0; i < countOfMine_; ++i)
  {
    /*
        bool mine;
        pos_X = rand() % fieldLength_;
        pos_Y = rand() % fieldHeight_;
        mine = cell[i / fieldLength_][i % fieldLength_].ifMineContains();
        cell[i / fieldLength_][i % fieldLength_].setMine(cell[pos_Y][pos_X].ifMineContains());
        cell[pos_Y][pos_X].setMine(mine);
        */
    Cell tempCell;
    pos_X = rand() % fieldLength_;
    pos_Y = rand() % fieldHeight_;
    tempCell = cell[i / fieldLength_][i % fieldLength_];
    cell[i / fieldLength_][i % fieldLength_]=cell[pos_Y][pos_X];
    cell[pos_Y][pos_X]=tempCell;
  }
    for (int i = 0; i < fieldHeight_; ++i)
    {
        for (int j = 0; j < fieldLength_; ++j)
        {
            if (cell[i][j].ifMineContains()){
                if ((i - 1 >= 0) && (j - 1 >= 0) && !cell[i - 1][j - 1].ifMineContains() )
                    ++cell[i - 1][j - 1];
                if ((i - 1 >= 0) && !cell[i - 1][j].ifMineContains())
                    ++cell[i - 1][j];
                if ((i - 1 >= 0) && (j + 1 < fieldLength_) && !cell[i - 1][j + 1].ifMineContains())
                    ++cell[i - 1][j + 1];
                if ((j - 1 >= 0) && !cell[i][j - 1].ifMineContains())
                    ++cell[i][j - 1];
                if ((j + 1 <fieldLength_) && !cell[i][j + 1].ifMineContains())
                    ++cell[i][j + 1];
                if ((i + 1 <fieldHeight_) && (j - 1 >= 0) && !cell[i + 1][j - 1].ifMineContains())
                    ++cell[i + 1][j - 1];
                if ((i + 1 <fieldHeight_) && !cell[i + 1][j].ifMineContains())
                    ++cell[i + 1][j];
                if ((i + 1 <fieldHeight_) && (j + 1 < fieldLength_) && !cell[i + 1][j + 1].ifMineContains())
                    ++cell[i + 1][j + 1];
            }

        }
    }

}
void Field::openCell(int pos_X, int pos_Y)
{
    if (cell[pos_Y][pos_X].get_cellMarker()||cell[pos_Y][pos_X].get_cellOpen())//защита помеченых клеток и открытых
        return;
    cell[pos_Y][pos_X].set_cellOpen();//откроем сначала
    if (cell[pos_Y][pos_X].get_numberOfMineAround() != 0)// при натыкании на цифру выход
        return;
    if (pos_Y - 1 >= 0 && pos_X - 1 >= 0 ) //диагональ влево ввверх
        openCell(pos_X - 1, pos_Y - 1);
    if (pos_Y - 1 >= 0)     //вверх
        openCell(pos_X, pos_Y-1);
    if (pos_Y - 1 >= 0 && pos_X + 1 < fieldLength_) //диагональ вправо вверх
        openCell(pos_X + 1, pos_Y - 1);
    if (pos_X - 1 >= 0) //влево
        openCell(pos_X - 1, pos_Y);
    if (pos_X + 1 < fieldLength_) //вправо
        openCell(pos_X + 1, pos_Y);
    if (pos_Y + 1 <fieldHeight_ && pos_X - 1 >= 0)//диагональвлево вниз
        openCell(pos_X - 1, pos_Y + 1);
    if (pos_Y + 1 < fieldHeight_) // вниз
        openCell(pos_X, pos_Y + 1);
    if (pos_Y + 1 <fieldHeight_ && pos_X + 1 < fieldLength_)//диагональ вправо вниз
        openCell(pos_X + 1, pos_Y + 1);
}
void Field::on_DotClickedRight()
{
  Cell *t = reinterpret_cast<Cell*>(sender());
 // if(t->get_cellOpen())
    //  return;
  t->change_cellMarker();
}

void Field::on_DotClickedLeft()
{

 Cell *t = reinterpret_cast<Cell*>(sender());
 openCell(t->get_pos_x(), t->get_pos_y());
 //t->set_cellOpen();
}
void Field::on_DotClickedMid()
{

}

Field::~Field()
{
    for (int i = 0; i < fieldHeight_; ++i)
        delete [] (cell[i]);
}
/*
Field::Field(int fieldLength, int fieldHeight, int countOfMine){
    assert(countOfMine <  (fieldLength*fieldHeight));
    fieldLength_ = fieldLength;
    fieldHeight_ = fieldHeight;
    countOfMine_ = countOfMine;
    cell = new Cell*[fieldHeight_];
    for (int i = 0; i < fieldHeight_; ++i)
        cell[i] = new Cell[fieldLength_];
    completeField();
}



void Field::openCell(int pos_X, int pos_Y)
{
    if (cell[pos_Y][pos_X].get_cellMarker()||cell[pos_Y][pos_X].get_cellOpen())//защита помеченых клеток и открытых
        return;
    cell[pos_Y][pos_X].set_cellOpen(true);//откроем сначала
    if (cell[pos_Y][pos_X].get_numberOfMineAround() != 0)// при натыкании на цифру выход
        return;
    if (pos_Y - 1 >= 0 && pos_X - 1 >= 0 ) //диагональ влево ввверх
        openCell(pos_X - 1, pos_Y - 1);
    if (pos_Y - 1 >= 0)     //вверх
        openCell(pos_X, pos_Y-1);
    if (pos_Y - 1 >= 0 && pos_X + 1 < fieldLength_) //диагональ вправо вверх
        openCell(pos_X + 1, pos_Y - 1);
    if (pos_X - 1 >= 0) //влево
        openCell(pos_X - 1, pos_Y);
    if (pos_X + 1 < fieldLength_) //вправо
        openCell(pos_X + 1, pos_Y);
    if (pos_Y + 1 <fieldHeight_ && pos_X - 1 >= 0)//диагональвлево вниз
        openCell(pos_X - 1, pos_Y + 1);
    if (pos_Y + 1 < fieldHeight_) // вниз
        openCell(pos_X, pos_Y + 1);
    if (pos_Y + 1 <fieldHeight_ && pos_X + 1 < fieldLength_)//диагональ вправо вниз
        openCell(pos_X + 1, pos_Y + 1);
}
void Field::checkedOpenCell(int pos_X, int pos_Y){

    if (cell[pos_Y][pos_X].get_cellOpen() && cell[pos_Y][pos_X].get_numberOfMineAround()){
        int count = 0;
            if (pos_Y - 1 >= 0 && pos_X - 1 >= 0 && cell[pos_Y-1][pos_X-1].get_cellMarker()) //диагональ влево ввверх
                ++count;
            if (pos_Y - 1 >= 0 && cell[pos_Y - 1][pos_X].get_cellMarker())     //вверх
                ++count;
            if (pos_Y - 1 >= 0 && pos_X + 1 < fieldLength_ && cell[pos_Y - 1][pos_X + 1].get_cellMarker()) //диагональ вправо вверх
                ++count;
            if (pos_X - 1 >= 0 && cell[pos_Y][pos_X - 1].get_cellMarker()) //влево
                ++count;
            if (pos_X + 1 < fieldLength_&& cell[pos_Y][pos_X + 1].get_cellMarker()) //вправо
                ++count;
            if (pos_Y + 1 <fieldHeight_ && pos_X - 1 >= 0 && cell[pos_Y + 1][pos_X - 1].get_cellMarker())//диагональвлево вниз
                ++count;
            if (pos_Y + 1 < fieldHeight_&& cell[pos_Y + 1][pos_X].get_cellMarker()) // вниз
                ++count;
            if (pos_Y + 1 <fieldHeight_ && pos_X + 1 < fieldLength_ && cell[pos_Y + 1][pos_X + 1].get_cellMarker())//диагональ вправо вниз
                ++count;

            if (count == cell[pos_Y][pos_X].get_numberOfMineAround()){
                if (pos_Y - 1 >= 0 && pos_X - 1 >= 0) //диагональ влево ввверх
                    openCell(pos_X - 1, pos_Y - 1);
                if (pos_Y - 1 >= 0)     //вверх
                    openCell(pos_X, pos_Y - 1);
                if (pos_Y - 1 >= 0 && pos_X + 1 < fieldLength_) //диагональ вправо вверх
                    openCell(pos_X + 1, pos_Y - 1);
                if (pos_X - 1 >= 0 ) //влево
                    openCell(pos_X - 1, pos_Y);
                if (pos_X + 1 < fieldLength_) //вправо
                    openCell(pos_X + 1, pos_Y);
                if (pos_Y + 1 <fieldHeight_ && pos_X - 1 >= 0)//диагональвлево вниз
                    openCell(pos_X - 1, pos_Y + 1);
                if (pos_Y + 1 < fieldHeight_) // вниз
                    openCell(pos_X, pos_Y + 1);
                if (pos_Y + 1 <fieldHeight_ && pos_X + 1 < fieldLength_ )//диагональ вправо вниз
                    openCell(pos_X + 1, pos_Y + 1);
            }
    }
}


int Field::get_closedCell(){
    int tempCounter=0;
    for (int i = 0; i < fieldLength_; ++i){
        for (int j = 0; j < fieldHeight_; ++j){
            if (!cell[i][j].get_cellOpen())
                ++tempCounter;
        }
    }
    return tempCounter;
}


int Field::get_fieldLength(){
    return fieldLength_;
}
int Field::get_fieldHeight(){
    return fieldHeight_;
}
int Field::get_countOfMine(){
    return countOfMine_;
}


void Field::set_fieldLength(int fieldLength){
    fieldLength_ = fieldLength;
}
void Field::set_fieldWidth(int fieldWidth){
    fieldHeight_ = fieldWidth;
}
void Field::get_countOfMine(int countOfMine){
    countOfMine_ = countOfMine;
}

bool Field::ifGameOver(){
    for (int i = 0; i < fieldHeight_; ++i){
        for (int j = 0; j < fieldLength_; ++j){
            if (cell[i][j].ifMineContains() && cell[i][j].get_cellOpen())
                return true;
        }
    }
    return false;
}

void Field::output(int pos_X, int pos_Y){
    system("cls");
    cout << endl;
    for (int i = 0; i < fieldHeight_; ++i){
        for (int j = 0; j < fieldLength_; ++j){
            if (i == pos_Y&&j == pos_X){
                cout << "_ ";
                continue;
            }
            if (cell[i][j].get_cellMarker()){
                cout << "# ";
                continue;
            }
            if (!cell[i][j].get_cellOpen())
                cout << ". ";
            else{
                if (cell[i][j].get_numberOfMineAround()!=0)
                    cout<< cell[i][j].get_numberOfMineAround()<<' ';
                else
                    cout  << "  ";
            }
        }
        cout << endl;
    }
    //cout << "Count of closed cell: " << this->get_closedCell()<<endl;
    //cout << "Curent position: " << cell[pos_Y][pos_X].get_numberOfMineAround() << endl;
}

bool Field::set_Marker(int pos_X, int pos_Y){
    cell[pos_Y][pos_X].change_cellMarker();
    return cell[pos_Y][pos_X].get_cellMarker();
}

bool Field::get_ifOpenCell(int pos_X, int pos_Y){
    return cell[pos_Y][pos_X].get_cellOpen();
}

bool Field::get_ifMarkerCell(int pos_X, int pos_Y){
    return cell[pos_Y][pos_X].get_cellMarker();
}
*/

