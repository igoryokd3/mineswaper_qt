#include "field.h"
#include "game.h"
#include <QMessageBox>

Game::Game()
{
    field = new Field(this);
    connect(field, SIGNAL (Win()), this, SLOT(youWin()));
    connect(field, SIGNAL (Lose()), this, SLOT(youLose()));
}
void Game::youWin()
{
    QMessageBox::information(0, "Information", "Yeah!");
}
void Game::youLose()
{
    QMessageBox::information(0, "Information", "Fuuuuuuuuuuu!!!!");
}
