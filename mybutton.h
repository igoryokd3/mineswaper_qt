#ifndef MYBUTTON
#define MYBUTTON
#include <QPushButton>
#include <QMouseEvent>

class mybutton : public QPushButton {
    Q_OBJECT

public:
    mybutton(QWidget *parent = 0):QPushButton(parent)
    {
        this->setIconSize(QSize(16,16));
       // this->resize(QSize(16,16));
        this->setIcon(QIcon(":/image/default_cell.bmp"));
    }

protected:
    void mousePressEvent(QMouseEvent *e)
    {
        if(e->button() == Qt::MidButton)
            {
                this->setIcon(QIcon(":/image/mine_cell.bmp"));
                this->setText("");
                emit bothClicked();
            }

            if(e->button() == Qt::RightButton)
                {
                    this->setIcon(QIcon(":/image/flag_cell.bmp"));
                    this->setText("");
                    emit rightClicked();
                }
            if(e->button() == Qt::LeftButton)
                {
                    this->setIcon(QIcon(":/image/open_cell.bmp"));
                    this->setText("");
                    emit leftClicked();
                }

    }

signals:
    void rightClicked();
    void leftClicked();
    void bothClicked();
};

#endif // MYBUTTON

