# ifndef GAME_H
# define GAME_H
# include <QWidget>
# include <QLabel>
#include <QDebug>

class Field;

class Game :public QWidget {
  Q_OBJECT
public:
  Game();
public slots:
  void youWin();
  void youLose();
protected:
  Field *field;

};

#endif
