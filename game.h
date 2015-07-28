#ifndef GAME_H
#define GAME_H

#include "field.h"
#include <QDebug>

class Game
{
protected:
    Field *field;
public:
    Game();
    ~Game();
protected slots:
    void youWin();
    void youLose();
};

#endif // GAME_H
