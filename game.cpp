#include "field.h"
#include "game.h"
#include <QMessageBox>

Game::Game()
{
    field = new Field(this);
    connect(field, SIGNAL (Win()), this, SLOT(YouWin()));
}
void Game::youWin()
{
    QMessageBox::information(0, "Information", "win");
}
void Game::youLose()
{
    QMessageBox::information(0, "Information", "lost");
}
