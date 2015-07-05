#ifndef MYBUTTON
#define MYBUTTON
#include <QPushButton>
#include <QMouseEvent>

class mybutton : public QPushButton {
    Q_OBJECT

public:
    mybutton(QWidget *parent = 0):QPushButton(parent){};

protected:
    void mousePressEvent(QMouseEvent *e)
    {
            if(e->button() == Qt::RightButton)
                {
                    emit rightClicked();
                }
    }

signals:
    void rightClicked();
};

#endif // MYBUTTON

