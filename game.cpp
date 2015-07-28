#include "game.h"

Game::Game()
{
    field = new Field(10,10,10);
    connect(field, SIGNAL(Win()), this, SLOT(youWin()));
    connect(field, SIGNAL(Lose()), this, SLOT(youLose()));
}

Game::~Game()
{
    delete field;
}

void youWin()
{
    qDebug()<<"you Win!!!!!!!!!!!!!!!!";
}
void youLose()
{
    qDebug()<<"you Lose!!!!!!!!!!!!!!!";
}

