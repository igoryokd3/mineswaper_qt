#include "cell.h"


Cell::Cell(QWidget *parent):QPushButton(parent)
{
    numberOfMineAround_ = 0;
    cellOpen_ = false;
    cellMarker_ = false;
    //button = new QMybutton();
    this->setIcon(QIcon(":/image/default_cell.bmp"));
}
bool Cell::get_cellMarker()
{
    return cellMarker_;
}
// void set_cellMarker(bool);
void Cell::change_cellMarker()
{
    if (!get_cellOpen())
    {
        if(cellMarker_)
            this->setIcon(QIcon(":/image/default_cell.bmp"));
        else
            this->setIcon(QIcon(":/image/flag_cell.bmp"));
        cellMarker_ = !cellMarker_;
    }
}

bool Cell::get_cellOpen()
{
    return cellOpen_;
}
void Cell::set_cellOpen()
{
    if (!get_cellMarker())
    {
        switch (numberOfMineAround_)
        {
            case 0: this->setIcon(QIcon(":/image/open_cell.bmp"));
                break;
            case 1: this->setIcon(QIcon(":/image/1_cell.bmp"));
                break;
            case 2: this->setIcon(QIcon(":/image/2_cell.bmp"));
                break;
            case 3: this->setIcon(QIcon(":/image/3_cell.bmp"));
                break;
            case 4: this->setIcon(QIcon(":/image/4_cell.bmp"));
                break;
            case 5: this->setIcon(QIcon(":/image/5_cell.bmp"));
                break;
            case 6: this->setIcon(QIcon(":/image/6_cell.bmp"));
                break;
            case 7: this->setIcon(QIcon(":/image/7_cell.bmp"));
                break;
            case 8: this->setIcon(QIcon(":/image/8_cell.bmp"));
                break;
            case -1: this->setIcon(QIcon(":/image/mine_cell.bmp"));
                break;

        }

        cellOpen_ = true;
    }
}
// void change_cellOpen();

int Cell::get_numberOfMineAround()
{
    return numberOfMineAround_;
}
void Cell::increment_numberOfMineAround()
{
    if (!ifMineContains())
            ++numberOfMineAround_;
}

bool Cell::ifMineContains()
{
    return numberOfMineAround_ == -1;
}
void Cell::setMine()
{
    numberOfMineAround_ = -1;
}
void Cell::mousePressEvent(QMouseEvent *event)
{
  if (event->button() == Qt::LeftButton) emit clicked_left();
  if (event->button() == Qt::RightButton) emit clicked_right();
  if (event->button() == Qt::MidButton) emit clicked_mid();
}

