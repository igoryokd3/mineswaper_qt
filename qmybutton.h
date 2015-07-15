#ifndef QMYBUTTON
#define QMYBUTTON
#include <QPushButton>
#include <QMouseEvent>

class QMybutton : public QPushButton {
    Q_OBJECT

public:
    QMybutton(QWidget *parent = 0):QPushButton(parent){};

protected:
    void mousePressEvent(QMouseEvent *e)
    {
            if(e->button() == Qt::MidButton)
                {
                   // this->setText("mid");
                    emit bothClicked();
                }
            if(e->button() == Qt::RightButton)
                {
                    //this->setText("right");
                    emit rightClicked();
                }
            if(e->button() == Qt::LeftButton)
                {
                    //this->setText("left");
                    emit leftClicked();
                }
    }

signals:
    void rightClicked();
    void leftClicked ();
    void bothClicked();
};
#endif // QMYBUTTON

