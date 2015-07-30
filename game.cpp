#include "field.h"
#include "game.h"

Game::Game()
{
    field = new Field(this);
    connect(field, SIGNAL (Win()), this, SLOT(YouWin()));
}
void Game::youWin()
{
    qDebug()<<"You Win!!!!!!!!!!!!!!!!!!!!!!!1";
}
void Game::youLose()
{
    qDebug()<<"You Lose!!!!!!!!!!!!!!!1!1!";
}
